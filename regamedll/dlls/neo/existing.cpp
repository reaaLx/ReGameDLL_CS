/* Stub implementations for NEO methods on classes that already exist in the fork.
   Declarations were added to their headers. Each stub logs and returns a default. */
#include "precompiled.h"
#include "gamerules.h"
#include "bot/cs_bot.h"
#include "training_gamerules.h"
#include "neo/neo_stub.h"

void CCSBot::TacticalGrenade() { NEO_STUB("CCSBot::TacticalGrenade"); }
void CCSBot::TacticalMove() { NEO_STUB("CCSBot::TacticalMove"); }
void CCSBot::TacticalWait() { NEO_STUB("CCSBot::TacticalWait"); }
int CCSBot::SelectGodEyeTarget() { NEO_STUB("CCSBot::SelectGodEyeTarget"); return {}; }
int CCSBot::KillDeathRubberBand() { NEO_STUB("CCSBot::KillDeathRubberBand"); return {}; }
int CCSBot::SetRubberBandAim(int) { NEO_STUB("CCSBot::SetRubberBandAim"); return {}; }
