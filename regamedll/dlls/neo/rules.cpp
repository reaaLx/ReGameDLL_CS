/* Stub implementations for neo/rules.h. Each stub logs and returns a default value. */
#include "precompiled.h"
#include "neo/rules.h"
#include "neo/neo_stub.h"

void CBeginnerRule::KeyValue(KeyValueData_s*) { NEO_STUB("CBeginnerRule::KeyValue"); }
void CBeginnerRule::Spawn() { NEO_STUB("CBeginnerRule::Spawn"); }
void CBeginnerRule::BeginUse(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CBeginnerRule::BeginUse"); }
void CCamperRules::Think() { NEO_STUB("CCamperRules::Think"); }
