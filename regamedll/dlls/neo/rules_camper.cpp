/*
 * CCamperRules methods that are small enough to implement directly.
 * Written from the observed behaviour of the NEO binary. Clean-room: no code
 * transcribed from disassembly.
 *
 * Initialize and Think are still stubs (see rules.cpp).
 */
#include "precompiled.h"
#include "neo/rules.h"

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
