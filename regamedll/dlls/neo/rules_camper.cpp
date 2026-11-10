/*
 * CCamperRules methods that are small enough to implement directly.
 * Written from the observed behaviour of the NEO binary. Clean-room: no code
 * transcribed from disassembly.
 *
 * Think is still a stub (see rules.cpp).
 */
#include "precompiled.h"
#include "neo/rules.h"

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
