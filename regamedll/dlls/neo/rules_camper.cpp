/*
 * CCamperRules methods that are small enough to implement directly.
 * Written from the observed behaviour of the NEO binary. Clean-room: no code
 * transcribed from disassembly.
 *
 * Think: zone scan, camp timers and the Camper/Radar messages.
 */
#include "precompiled.h"
#include "neo/rules.h"
#include "weapons.h"

void CCamperRules::Initialize(CBasePlayer *pPlayer)
{
	if (pPlayer != NULL)
	{
		// Per-player state is indexed by entindex - 1.
		int idx = pPlayer->entindex() - 1;

		for (int j = 0; j < 4; j++)
		{
			m_fCamp[idx][j] = 0.0f;
			m_iCampLevel[idx][j] = 0;
			m_fNoCampTime[idx][j] = 0.0f;
		}

		for (int j = 0; j < 5; j++)
			m_sCoord[idx][j] = Vector(0.0f, 0.0f, 0.0f);

		m_iPrevCampType[idx] = -1;

		// NEO also broadcasts a "Camper" user message (player index, 0) here.
		// Not sent yet: the NEO-only message list needs a decision first.
	}
	else
	{
		m_fNextThink = g_engfuncs.pfnCVarGetFloat("mp_freezetime") + gpGlobals->time + 10.0f;
		m_bAble = FALSE;
		m_iFlag = 8;
	}
}

void CCamperRules::Enable()
{
	m_bAble = TRUE;
}

void CCamperRules::Disable()
{
	m_bAble = FALSE;
}

void CCamperRules::Start(int flag)
{
	m_iFlag |= flag;
}

void CCamperRules::End(int flag)
{
	m_iFlag &= ~flag;
}

// Camper zones: 0 = C4 set, 1 = CT at C4, 2 = T carrying C4, 3 = peace.
// Thresholds and the think interval are guessed from the binary's constants:
// the zone scan uses the same flag bits and comparisons, see the notes in Think.
static const float CAMPER_THINK_INTERVAL = 1.0f;

// Returns true when the given zone applies to the player this frame.
static bool CamperZoneActive(CBasePlayer *pPlayer, int zone, int ruleFlags)
{
	CBasePlayerItem *pItem = pPlayer->m_pActiveItem;
	const bool holdingArmedC4 = (pItem != NULL && pItem->m_iId == WEAPON_C4 && static_cast<CC4 *>(pItem)->m_bStartedArming);

	switch (zone)
	{
	case 0:
		if (!(pPlayer->m_iCamperFlag & 1))
			return false;
		return !holdingArmedC4;

	case 1:
		if (pPlayer->m_iTeam != CT)
			return false;
		for (CBaseEntity *pEnt = UTIL_FindEntityByClassname(NULL, "grenade"); pEnt != NULL && !FNullEnt(pEnt->edict()); pEnt = UTIL_FindEntityByClassname(pEnt, "grenade"))
		{
			CGrenade *pGrenade = static_cast<CGrenade *>(pEnt);
			if (!pGrenade->m_bIsC4)
				continue;
			return !pGrenade->m_bStartDefuse;
		}
		return true;

	case 2:
		return pPlayer->m_iTeam == TERRORIST;

	case 3:
		if (!(pPlayer->m_iCamperFlag & 8))
			return false;
		if (pPlayer->m_iTeam == TERRORIST)
		{
			if (ruleFlags & 2)
				return false;
			return !holdingArmedC4;
		}
		if (!(ruleFlags & 2))
			return false;
		for (CBaseEntity *pEnt = UTIL_FindEntityByClassname(NULL, "grenade"); pEnt != NULL && !FNullEnt(pEnt->edict()); pEnt = UTIL_FindEntityByClassname(pEnt, "grenade"))
		{
			CGrenade *pGrenade = static_cast<CGrenade *>(pEnt);
			if (!pGrenade->m_bIsC4)
				continue;
			if (!pGrenade->m_bStartDefuse)
				return true;
			return static_cast<CBasePlayer *>(pGrenade->m_pBombDefuser) != pPlayer;
		}
		return true;
	}

	return false;
}

void CCamperRules::Think()
{
	if (!m_bAble)
		return;
	if (m_fNextThink > gpGlobals->time)
		return;
	m_fNextThink = gpGlobals->time + CAMPER_THINK_INTERVAL;

	for (int i = 1; i <= gpGlobals->maxClients; i++)
	{
		CBasePlayer *pPlayer = UTIL_PlayerByIndex(i);
		if (pPlayer == NULL || FNullEnt(pPlayer->pev))
			continue;
		if (pPlayer->IsBot())
			continue;
		if (static_cast<unsigned int>(pPlayer->pev->flags) == 0x80000000u)
			continue;
		if (!pPlayer->IsAlive())
			continue;
		if (pPlayer->m_iCamperFlag & 0x10)
			continue;

		const int p = i - 1;

		// Zone scan. The current zone is the one that changed from last frame,
		// otherwise the last active zone.
		int activeBits = 0;
		int curZone = -1;
		int lastZone = -1;
		for (int z = 0; z < 4; z++)
		{
			if (!((m_iFlag >> z) & 1))
				continue;
			if (!CamperZoneActive(pPlayer, z, m_iFlag))
				continue;

			activeBits |= 1 << z;
			if (m_iPrevCampType[p] != z)
				curZone = z;
			lastZone = z;
		}
		if (curZone < 0)
			curZone = lastZone;
		m_iPrevCampType[p] = curZone;

		// Position history: shift the five samples and store the current origin.
		for (int j = 4; j > 0; j--)
			m_sCoord[p][j] = m_sCoord[p][j - 1];
		m_sCoord[p][0] = Vector(pPlayer->pev->origin.x, pPlayer->pev->origin.y, pPlayer->pev->origin.z);

		// Average position over the five samples, then per-axis variance over four.
		float avgX = 0.0f, avgY = 0.0f, avgZ = 0.0f;
		for (int j = 0; j < 5; j++)
		{
			avgX += m_sCoord[p][j].x;
			avgY += m_sCoord[p][j].y;
			avgZ += m_sCoord[p][j].z;
		}
		avgX /= 5.0f;
		avgY /= 5.0f;
		avgZ /= 5.0f;

		float varX = 0.0f, varY = 0.0f, varZ = 0.0f;
		for (int j = 0; j < 5; j++)
		{
			float dx = m_sCoord[p][j].x - avgX;
			float dy = m_sCoord[p][j].y - avgY;
			float dz = m_sCoord[p][j].z - avgZ;
			varX += dx * dx;
			varY += dy * dy;
			varZ += dz * dz;
		}
		varX /= 4.0f;
		varY /= 4.0f;
		varZ /= 4.0f;

		const float spread = static_cast<float>(sqrt(varX + varY + varZ));

		// Stage 2 (camp timers, level changes and the Camper/Radar messages) uses
		// activeBits, curZone and spread. Not written yet.
		(void)activeBits;
		(void)spread;
	}
}
