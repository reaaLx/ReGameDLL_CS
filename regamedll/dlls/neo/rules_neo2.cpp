/*
 * NEO 2 rule helpers on CHalfLifeMultiplay.
 *
 * Written from the observed behaviour of NEO's SetNEO2RuleMode,
 * CheckNEO2RuleforChargeOnly5, InitializeNEO2Rule and the rule predicates.
 * Clean-room: no code transcribed from disassembly.
 */
#include "precompiled.h"
#include "gamerules.h"
#include "neo/rules.h"
#include "neo/crm.h"
#include "neo/popup.h"

// NEO's charge check multiplies the threshold by this constant (60.0).
static const float NEO2_CHARGE_WINDOW = 60.0f;

// Team index used by the team-battle helpers (matches TeamName::CT).
// NEO 2 rule modes used by the predicates below.
enum
{
	NEO2_MODE_TEAM_FIRST = 1,	// team battle modes are 1..3
	NEO2_MODE_TEAM_LAST = 3,
	NEO2_MODE_NORMAL = 4,
	NEO2_MODE_BEGINNER_FIRST = 5,	// beginner modes are 5..7
	NEO2_MODE_BEGINNER_LAST = 7,
	NEO2_MODE_TRAINING = 8,
	NEO2_MODE_STORE_WAR = 9,
	NEO2_MODE_CLAN = 10,
};

void CHalfLifeMultiplay::SetNEO2RuleMode(int mode)
{
	m_iNEO2RuleMode = mode;
	g_engfuncs.pfnSetNEO2Rule(mode);

	// NEO also broadcasts a "GameRule" user message carrying the mode in one byte.
	// Not sent yet: the NEO-only message list needs a decision first (see
	// NEO_PORT_SCOPE.md).
}

int CHalfLifeMultiplay::CheckNEO2RuleforChargeOnly5()
{
	if (m_iNEO2RuleMode != 3)
		return 0;

	if (m_bRoundTerminating)
		return 0;

	float elapsed = (m_flNEO2ChargeAnchor + gpGlobals->time) - m_fRoundStartTime;
	float first = (m_flNEO2ChargeThreshold + m_flNEO2ChargeThreshold) * NEO2_CHARGE_WINDOW;
	float second = m_flNEO2ChargeThreshold * NEO2_CHARGE_WINDOW;

	if (elapsed >= first && m_iNEO2ChargeFlag != 0)
		return 2;

	if (elapsed >= second && m_iNEO2ChargeFlag == 0)
		return 1;

	return 0;
}

bool CHalfLifeMultiplay::IsBeginnerMode()
{
	return m_iNEO2BeginnerMode != 0;
}

bool CHalfLifeMultiplay::IsClanBattleRule()
{
	return m_iNEO2RuleMode == NEO2_MODE_CLAN;
}

bool CHalfLifeMultiplay::IsNormalBattleRule()
{
	return m_iNEO2RuleMode == NEO2_MODE_NORMAL;
}

bool CHalfLifeMultiplay::IsStoreWarRule()
{
	return m_iNEO2RuleMode == NEO2_MODE_STORE_WAR;
}

bool CHalfLifeMultiplay::IsTeamBattleRule()
{
	return m_iNEO2RuleMode >= NEO2_MODE_TEAM_FIRST && m_iNEO2RuleMode <= NEO2_MODE_TEAM_LAST;
}

bool CHalfLifeMultiplay::IsTrainingMode()
{
	return m_iNEO2TrainingMode != 0;
}

void CHalfLifeMultiplay::InitializeNEO2Rule()
{
	m_iNEO2RoundCount = 0;
	m_flNEO2ChargeAnchor = 0.0f;
	m_iNEO2ChargeFlag = 0;
	m_bNEO2Flag = false;
	for (int i = 0; i < 8; i++)
		m_iNEO2Tallies[i] = 0;
	m_iNEO2Parameter = 3;
	for (int i = 0; i < 6; i++)
		m_iNEO2Counters[i] = 0;

	SetNEO2RuleMode(g_engfuncs.pfnGetNEO2Rule());

	m_iNEO2BeginnerMode = (m_iNEO2RuleMode >= NEO2_MODE_BEGINNER_FIRST && m_iNEO2RuleMode <= NEO2_MODE_BEGINNER_LAST) ? 1 : 0;
	m_iNEO2TrainingMode = (m_iNEO2RuleMode == NEO2_MODE_TRAINING) ? 1 : 0;

	if (m_iNEO2VIPFlag != 0)
		ResetCurrentVIP();
	m_iNEO2VIPFlag = 0;
	m_iNEO2VIPSlot0 = 0;
	m_iNEO2VIPSlot1 = 0;

	static CCamperRules camper;
	camper.Initialize(NULL);
	if (IsNormalBattleRule())
		camper.Enable();
	else
		camper.Disable();

	g_engfuncs.pfnCVarSetFloat("mp_clanbattle", (m_iNEO2RuleMode == NEO2_MODE_CLAN) ? 1.0f : 0.0f);
	g_engfuncs.pfnCVarSetString("mp_neoclanname", "");
	g_engfuncs.pfnCVarSetString("mp_neoclancode", "");
	g_engfuncs.pfnCVarSetFloat("mp_neoclanrate", 2000.0f);
	g_engfuncs.pfnCVarSetString("mp_csfclanname", "");
	g_engfuncs.pfnCVarSetString("mp_csfclancode", "");
	g_engfuncs.pfnCVarSetFloat("mp_csfclanrate", 2000.0f);

	CCRM::ResetAll();
	CPopup::ResetAll();

	if (IsTeamBattleRule() || IsClanBattleRule())
	{
		g_engfuncs.pfnCVarSetFloat("mp_maxaccount", 25000.0f);
		g_engfuncs.pfnCVarSetFloat("mp_startmoney", 25000.0f);
		g_engfuncs.pfnCVarSetFloat("mp_autokick", 0.0f);
		g_engfuncs.pfnCVarSetFloat("mp_tkpunish", 0.0f);
	}
	else if (IsBeginnerMode())
	{
		g_engfuncs.pfnCVarSetFloat("mp_maxaccount", 25000.0f);
		g_engfuncs.pfnCVarSetFloat("mp_startmoney", 25000.0f);
	}
	else if (IsTrainingMode())
	{
		g_engfuncs.pfnCVarSetFloat("mp_maxaccount", 25000.0f);
	}
	else if (IsStoreWarRule())
	{
		g_engfuncs.pfnCVarSetFloat("mp_maxaccount", 16000.0f);
		g_engfuncs.pfnCVarSetFloat("mp_startmoney", 15000.0f);
	}
	else
	{
		g_engfuncs.pfnCVarSetFloat("mp_maxaccount", 16000.0f);
		g_engfuncs.pfnCVarSetFloat("mp_startmoney", 800.0f);
	}
	// Round limit and win threshold come from cvars. The beginner modes read tr_maxrounds.
	m_iNEO2RoundLimit = static_cast<int>(g_engfuncs.pfnCVarGetFloat(IsBeginnerMode() ? "tr_maxrounds" : "mp_maxrounds"));
	m_iNEO2Threshold = static_cast<int>(g_engfuncs.pfnCVarGetFloat("mp_winlimit"));
}

int CHalfLifeMultiplay::GetAddTeamPointNum(int team)
{
	// Returns the count for the opposite team: the terrorist count for CT, else the CT count.
	return (team == CT) ? m_iNumTerrorist : m_iNumCT;
}

int CHalfLifeMultiplay::GetTeamBattlePoint(int team, bool current)
{
	if (m_iNEO2RoundCount == 0)
		return 0;

	int total;
	if (current)
	{
		if (team == CT)
		{
			total = m_iNEO2Extra[3] + m_iNEO2Extra[2] + m_iNEO2Tallies[6] + m_iNEO2Tallies[7];
			m_sNEO2BattlePoint[0] = static_cast<short>(total);
		}
		else
		{
			total = m_iNEO2Tallies[4] + m_iNEO2Tallies[5] + m_iNEO2Extra[0] + m_iNEO2Extra[1];
			m_sNEO2BattlePoint[1] = static_cast<short>(total);
		}
		return total;
	}

	return (team == CT) ? m_sNEO2BattlePoint[0] : m_sNEO2BattlePoint[1];
}

float CHalfLifeMultiplay::TimeRemaining()
{
	return GetRoundRemainingTime();
}

void CHalfLifeMultiplay::UpdateTeamC4PlantedTime(bool planted_by_ct)
{
	if (m_iNEO2RoundCount == 0)
		return;

	int remaining = static_cast<int>(TimeRemaining());
	int side = planted_by_ct ? 1 : 0;

	m_sNEO2PlantTime[side] = static_cast<short>(m_sNEO2PlantTime[side] + remaining);
	m_sNEO2PlantCount[side] = static_cast<short>(m_sNEO2PlantCount[side] + 1);
}

int CHalfLifeMultiplay::CheckAliveCount(int team)
{
	int count = 0;
	CBaseEntity *pEntity = UTIL_FindEntityByClassname(NULL, "player");
	while (pEntity && !FNullEnt(pEntity->edict()))
	{
		CBasePlayer *pPlayer = static_cast<CBasePlayer *>(pEntity);
		if (pPlayer && static_cast<int>(pPlayer->m_iTeam) == team && pPlayer->IsAlive())
			count++;
		pEntity = UTIL_FindEntityByClassname(pEntity, "player");
	}
	return count;
}

void CHalfLifeMultiplay::UpdateTeamDeathCounter()
{
	if (m_iNEO2TallyGate == 1)
		return;
	if (m_iNEO2RoundCount == 0)
		return;

	// Opposing-side alive counts are subtracted from the team totals and accumulated.
	if (m_iNEO2ChargeFlag != 1)
	{
		m_iNEO2Extra[0] += m_iNumCT - CheckAliveCount(CT);
		m_iNEO2Extra[2] += m_iNumTerrorist - CheckAliveCount(TERRORIST);
	}
	else
	{
		m_iNEO2Extra[1] += m_iNumCT - CheckAliveCount(CT);
		m_iNEO2Extra[3] += m_iNumTerrorist - CheckAliveCount(TERRORIST);
	}

	// The original sends the TeamScore pair with battle points as a third field. Only the
	// fork's two-field format (team name and wins) is sent here, via UpdateTeamScores().
	UpdateTeamScores();
}

// The original reads these from a per-player CCRM (keys 0 and 1). Here they use the
// fork's existing per-player stats (frags and deaths) instead.
int CHalfLifeMultiplay::CheckKillCount(int team)
{
	int total = 0;
	CBaseEntity *pEntity = UTIL_FindEntityByClassname(NULL, "player");
	while (pEntity && !FNullEnt(pEntity->edict()))
	{
		CBasePlayer *pPlayer = static_cast<CBasePlayer *>(pEntity);
		if (pPlayer && static_cast<int>(pPlayer->m_iTeam) == team)
			total += static_cast<int>(pPlayer->pev->frags);
		pEntity = UTIL_FindEntityByClassname(pEntity, "player");
	}
	return total;
}

int CHalfLifeMultiplay::CheckDeathCount(int team)
{
	int total = 0;
	CBaseEntity *pEntity = UTIL_FindEntityByClassname(NULL, "player");
	while (pEntity && !FNullEnt(pEntity->edict()))
	{
		CBasePlayer *pPlayer = static_cast<CBasePlayer *>(pEntity);
		if (pPlayer && static_cast<int>(pPlayer->m_iTeam) == team)
			total += pPlayer->m_iDeaths;
		pEntity = UTIL_FindEntityByClassname(pEntity, "player");
	}
	return total;
}

// Per-round rule evaluation. Dispatches on m_iNEO2RuleMode (NEO 0x2d0).
// Returns the round state: 0 = none, 1..7 = decided outcome codes.
int CHalfLifeMultiplay::CheckNEO2Rule()
{
	int state = 0;
	const float now = gpGlobals->time;
	const int limit = m_iNEO2RoundLimit;
	int *t = m_iNEO2Tallies;

	if (m_iRoundWinStatus <= 0)
		return 0;

	m_iNEO2RoundCount++;

	if (m_iRoundWinStatus == 2 || m_iRoundWinStatus == 4 || m_iRoundWinStatus == 8)
	{
		if (m_iNEO2ChargeFlag == 1) t[1]++; else t[0]++;
	}
	else if (m_iRoundWinStatus == 1 || m_iRoundWinStatus == 5 || m_iRoundWinStatus == 6 || m_iRoundWinStatus == 7)
	{
		if (m_iNEO2ChargeFlag == 1) t[3]++; else t[2]++;
	}

	// Common outcome tail: record the state, mark the tallies gate, and latch the round start.
	auto decide = [&](int next) { state = next; m_iNEO2TallyGate = 1; m_fRoundStartTime = now; };
	// Charge-latch: set the charge flag, then the same tail.
	auto latchCharge = [&](int next) { m_iNEO2ChargeFlag = 1; decide(next); };
	// Compares two wins-style tallies: first > second -> 4, second > first -> 5, else 6.
	auto compareTallies = [&](int first, int second) { if (first > second) decide(4); else if (second > first) decide(5); else decide(6); };

	switch (m_iNEO2RuleMode)
	{
	case 1:
	case 10:
	{
		if (!IsBombPlanted())
		{
			if (TimeRemaining() <= 0.0f)
			{
				if (m_iNEO2ChargeFlag == 0) t[6] += GetAddTeamPointNum(CT);
				else t[7] += GetAddTeamPointNum(CT);
			}
			if (CheckAliveCount(CT) <= 0)
			{
				if (m_iNEO2ChargeFlag == 0) t[4] += GetAddTeamPointNum(TERRORIST);
				else t[5] += GetAddTeamPointNum(TERRORIST);
				UpdateTeamC4PlantedTime(m_iNEO2ChargeFlag != 0);
			}
		}

		if (m_iNEO2ChargeFlag != 1)
		{
			state = 1;
			if (limit > 0 && m_iNEO2RoundCount == limit)
			{
				UpdateTeamDeathCounter();
				latchCharge(2);
			}
		}
		else if (limit > 0)
		{
			state = 3;
			const int a = t[3] + t[0];
			const int b = t[2] + t[1];
			if (a == limit + 1)
			{
				UpdateTeamDeathCounter();
				GetTeamBattlePoint(CT, true);
				GetTeamBattlePoint(TERRORIST, true);
				decide(4);
			}
			else if (b == limit + 1)
			{
				UpdateTeamDeathCounter();
				GetTeamBattlePoint(CT, true);
				GetTeamBattlePoint(TERRORIST, true);
				decide(5);
			}
			else if (a == limit && b == limit)
			{
				UpdateTeamDeathCounter();
				const int ct = GetTeamBattlePoint(CT, true);
				const int tt = GetTeamBattlePoint(TERRORIST, true);
				if (ct > tt) state = 4;
				else if (ct < tt) state = 5;
				else
				{
					const int avg0 = (m_sNEO2PlantCount[0] != 0) ? m_sNEO2PlantTime[0] / m_sNEO2PlantCount[0] : 0;
					const int avg1 = (m_sNEO2PlantCount[1] != 0) ? m_sNEO2PlantTime[1] / m_sNEO2PlantCount[1] : 0;
					state = (avg0 > avg1) ? 4 : 5;
				}
				decide(state);
			}
		}

		UpdateTeamScores();
		return state;
	}

	case 2:
	{
		const int thr = m_iNEO2Threshold;
		if (m_iNEO2ChargeFlag != 1)
		{
			state = 1;
			if (t[0] >= thr || t[2] >= thr)
				latchCharge(2);
		}
		else
		{
			state = 3;
			if (t[1] >= thr || t[3] >= thr)
			{
				const int a = t[3] + t[0];
				const int b = t[2] + t[1];
				if (a > b) decide(4);
				else if (b > a) decide(5);
				else
				{
					const int kct = CheckKillCount(CT);
					const int kt = CheckKillCount(TERRORIST);
					if (kct > kt) state = 4;
					else if (kt > kct) state = 5;
					else
					{
						const int dct = CheckDeathCount(CT);
						const int dt = CheckDeathCount(TERRORIST);
						if (dct < dt) state = 4;
						else if (dt < dct) state = 5;
						else state = 6;
					}
					decide(state);
				}
			}
		}
		return state;
	}

	case 3:
	{
		m_flNEO2ChargeAnchor += now - m_fRoundStartTime;
		const float thr = m_flNEO2ChargeThreshold;
		if (m_iNEO2ChargeFlag != 1)
		{
			state = 1;
			if (m_flNEO2ChargeAnchor >= thr * 60.0f)
				latchCharge(7);
		}
		else
		{
			state = 3;
			if (m_flNEO2ChargeAnchor >= (thr + thr) * 60.0f)
				compareTallies(t[0], t[1]);
		}
		return state;
	}

	case 4:
	{
		m_flNEO2ChargeAnchor += now - m_fRoundStartTime;
		const float thr = m_flNEO2ChargeThreshold;
		if (m_iNEO2ChargeFlag != 1)
		{
			state = 1;
			const char *next = g_engfuncs.pfnTakaGetNextLevelName();
			if (next != NULL || m_flNEO2ChargeAnchor >= thr * 60.0f)
				latchCharge(2);
		}
		else
		{
			state = 3;
			const char *next = g_engfuncs.pfnTakaGetNextLevelName();
			const bool counts = (next != NULL && *next != '\0');
			if (counts || m_flNEO2ChargeAnchor >= (thr + thr) * 60.0f)
				compareTallies(t[3] + t[0], t[2] + t[1]);
		}
		return state;
	}

	case 5:
	{
		if (limit <= 0 || m_iNEO2RoundCount != (limit / 2) + (limit % 2))
			return 0;
		compareTallies(m_iNumTerroristWins, m_iNumCTWins);
		return state;
	}

	case 6:
	{
		if (limit <= 0 || m_iNEO2RoundCount != limit / 2)
			return 0;
		compareTallies(m_iNumTerroristWins, m_iNumCTWins);
		return state;
	}

	case 7:
	{
		if (limit <= 0 || m_iNEO2RoundCount != limit)
			return 0;
		compareTallies(m_iNumTerroristWins, m_iNumCTWins);
		return state;
	}

	case 8:
	{
		if (m_iNEO2ChargeFlag == 0)
		{
			state = 1;
			if (limit <= 0 || m_iNEO2RoundCount != limit)
				return state;
			m_iNEO2ChargeFlag = 1;
			state = 2;
			m_iNEO2TallyGate = 1;
			m_fRoundStartTime = now;
			m_iNEO2VIPFlag = 0;
			m_iNEO2Unk0bc = 0;
			return state;
		}

		if (limit <= 0 || m_iNEO2RoundCount < limit + limit)
			return 0;
		state = 3;
		const int a = t[3] + t[0];
		const int b = t[2] + t[1];
		if (a >= limit + 1)
			decide(4);
		else if (b >= limit + 1)
			decide(5);
		else if (a == limit && b == limit)
		{
			const int ka = 5 * t[6] + 10 * t[4] + CheckKillCount(CT);
			const int kb = 5 * t[7] + 10 * t[5] + CheckKillCount(TERRORIST);
			if (ka > kb) decide(4);
			else if (ka < kb) decide(5);
			else decide(6);
		}
		return state;
	}

	case 9:
	{
		if (m_iNEO2ChargeFlag != 1)
		{
			state = 1;
			if (limit <= 0 || m_iNEO2RoundCount != limit)
				return state;
			latchCharge(2);
			return state;
		}

		if (limit <= 0 || m_iNEO2RoundCount < limit + limit)
			return 0;
		state = 3;
		const int a = t[3] + t[0];
		const int b = t[2] + t[1];
		if (a >= limit + 1)
			decide(4);
		else if (b >= limit + 1)
			decide(5);
		else if (a == limit && b == limit)
		{
			const int ka = 5 * t[6] + 10 * t[4] + CheckKillCount(CT);
			const int kb = 5 * t[7] + 10 * t[5] + CheckKillCount(TERRORIST);
			if (ka > kb) decide(4);
			else if (ka < kb) decide(5);
			else decide(6);
		}
		return state;
	}

	default:
		// Mode 0 and anything above 10 exit with state 0.
		return 0;
	}
}
