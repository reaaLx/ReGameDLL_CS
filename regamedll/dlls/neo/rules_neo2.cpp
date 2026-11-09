/*
 * NEO 2 rule helpers on CHalfLifeMultiplay.
 *
 * Behaviour observed from NEO's CHalfLifeMultiplay::SetNEO2RuleMode and
 * CHalfLifeMultiplay::CheckNEO2RuleforChargeOnly5. Clean-room: written from the
 * observed logic, not transcribed from disassembly.
 */
#include "precompiled.h"
#include "gamerules.h"

// NEO's charge check multiplies the threshold by this constant (60.0, from the NEO
// binary's read-only data).
static const float NEO2_CHARGE_WINDOW = 60.0f;

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
