/* Stub implementations for neo/crm.h. Each stub logs and returns a default value. */
#include "precompiled.h"
#include "neo/crm.h"
#include "neo/neo_stub.h"

CCRM::CCRM() { NEO_STUB("CCRM::CCRM"); }
CCRM::CCRM(const CCRM&) { NEO_STUB("CCRM::CCRM"); }
CCRM& CCRM::operator=(CCRM&) { NEO_STUB("CCRM::operator="); abort(); }
bool CCRM::AccessCheck(int) const { NEO_STUB("CCRM::AccessCheck"); return {}; }
void CCRM::_RoundEnd(int, int) { NEO_STUB("CCRM::_RoundEnd"); }
float CCRM::P(float) { NEO_STUB("CCRM::P"); return {}; }
float CCRM::CalcRate(int, int) const { NEO_STUB("CCRM::CalcRate"); return {}; }
void CCRM::UpdateRate(int) { NEO_STUB("CCRM::UpdateRate"); }
CCRM::CCRM(CBasePlayer*) { NEO_STUB("CCRM::CCRM"); }
void CCRM::Reset() { NEO_STUB("CCRM::Reset"); }
void CCRM::ResetStatic() { NEO_STUB("CCRM::ResetStatic"); }
void CCRM::ResetAll() { NEO_STUB("CCRM::ResetAll"); }
void CCRM::Init(const CCRM::SInitData*) { NEO_STUB("CCRM::Init"); }
void CCRM::RoundEnd(int, int) { NEO_STUB("CCRM::RoundEnd"); }
bool CCRM::GetBool(int) const { NEO_STUB("CCRM::GetBool"); return {}; }
int CCRM::GetInt(int) const { NEO_STUB("CCRM::GetInt"); return {}; }
float CCRM::GetFloat(int) const { NEO_STUB("CCRM::GetFloat"); return {}; }
void CCRM::SetBool(int, bool) { NEO_STUB("CCRM::SetBool"); }
void CCRM::SetInt(int, int) { NEO_STUB("CCRM::SetInt"); }
void CCRM::SetFloat(int, float) { NEO_STUB("CCRM::SetFloat"); }
void CCRM::AddInt(int, int) { NEO_STUB("CCRM::AddInt"); }
void CCRM::AddFloat(int, float) { NEO_STUB("CCRM::AddFloat"); }
void CCRM::CountUp(int) { NEO_STUB("CCRM::CountUp"); }
void CCRM::Think() { NEO_STUB("CCRM::Think"); }
void CCRM::TakeDamage(CBasePlayer*, int, bool) { NEO_STUB("CCRM::TakeDamage"); }
bool CCRM::CheckRate() { NEO_STUB("CCRM::CheckRate"); return {}; }
void CCRM::Escape() { NEO_STUB("CCRM::Escape"); }
void CCRM::Send(int, bool) { NEO_STUB("CCRM::Send"); }
void CCRM::SendAll(int, bool) { NEO_STUB("CCRM::SendAll"); }
int CCRM::GetNumTempRatePlayer(int) { NEO_STUB("CCRM::GetNumTempRatePlayer"); return {}; }
float CCRM::GetTeamRate(int) { NEO_STUB("CCRM::GetTeamRate"); return {}; }
int CCRM::GetDamageDirection(Vector, Vector, Vector) { NEO_STUB("CCRM::GetDamageDirection"); return {}; }
void CCRM::TogglePrintData() { NEO_STUB("CCRM::TogglePrintData"); }
