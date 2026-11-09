/* Stub implementations for neo/bot.h. Each stub logs and returns a default value. */
#include "precompiled.h"
#include "neo/bot.h"
#include "neo/neo_stub.h"

void SMtTacInfo::Clear() { NEO_STUB("SMtTacInfo::Clear"); }
void SMtTacInfo::ReadCsv(CMtCsvParser&) { NEO_STUB("SMtTacInfo::ReadCsv"); }
int SMtTacInfo::GetTeam() const { NEO_STUB("SMtTacInfo::GetTeam"); return {}; }
int SMtTacInfo::GetBotId() const { NEO_STUB("SMtTacInfo::GetBotId"); return {}; }
const char* SMtTacInfo::GetTacName() const { NEO_STUB("SMtTacInfo::GetTacName"); return {}; }
const char* SMtTacInfo::GetEntName() const { NEO_STUB("SMtTacInfo::GetEntName"); return {}; }
const char* SMtTacInfo::GetNextEntName() const { NEO_STUB("SMtTacInfo::GetNextEntName"); return {}; }
int SMtTacInfo::GetNumGrenades(WeaponIdType) const { NEO_STUB("SMtTacInfo::GetNumGrenades"); return {}; }
void SMtTacGrenade::Clear() { NEO_STUB("SMtTacGrenade::Clear"); }
void SMtTacGrenade::ReadCsv(CMtCsvParser&) { NEO_STUB("SMtTacGrenade::ReadCsv"); }
int SMtTacGrenade::IsUse(WeaponIdType) const { NEO_STUB("SMtTacGrenade::IsUse"); return {}; }
CMtCsvParser::CMtCsvParser() { NEO_STUB("CMtCsvParser::CMtCsvParser"); }
CMtCsvParser::CMtCsvParser(const char*) { NEO_STUB("CMtCsvParser::CMtCsvParser"); }
CMtCsvParser::~CMtCsvParser() { NEO_STUB("CMtCsvParser::~CMtCsvParser"); }
void CMtCsvParser::SetStr(const char*) { NEO_STUB("CMtCsvParser::SetStr"); }
void CMtCsvParser::SetIndex(int) { NEO_STUB("CMtCsvParser::SetIndex"); }
int CMtCsvParser::Parse(char*) { NEO_STUB("CMtCsvParser::Parse"); return {}; }
void SMtTacMoveTo::Clear() { NEO_STUB("SMtTacMoveTo::Clear"); }
void SMtTacMoveTo::ReadCsv(CMtCsvParser&) { NEO_STUB("SMtTacMoveTo::ReadCsv"); }
void SMtTacWait::Clear() { NEO_STUB("SMtTacWait::Clear"); }
void SMtTacWait::ReadCsv(CMtCsvParser&) { NEO_STUB("SMtTacWait::ReadCsv"); }
CMtGodEyeInfo::CMtGodEyeInfo() { NEO_STUB("CMtGodEyeInfo::CMtGodEyeInfo"); }
CMtGodEyeInfo::~CMtGodEyeInfo() { NEO_STUB("CMtGodEyeInfo::~CMtGodEyeInfo"); }
void CMtGodEyeInfo::Clear() { NEO_STUB("CMtGodEyeInfo::Clear"); }
void CMtGodEyeInfo::SetInfo(CBasePlayer*, float) { NEO_STUB("CMtGodEyeInfo::SetInfo"); }
CBasePlayer* CMtGodEyeInfo::GetPlayer() const { NEO_STUB("CMtGodEyeInfo::GetPlayer"); return {}; }
const float CMtGodEyeInfo::GetTimestamp() const { NEO_STUB("CMtGodEyeInfo::GetTimestamp"); return {}; }
CMtGodEyeMan::CMtGodEyeMan() { NEO_STUB("CMtGodEyeMan::CMtGodEyeMan"); }
CMtGodEyeMan::~CMtGodEyeMan() { NEO_STUB("CMtGodEyeMan::~CMtGodEyeMan"); }
void CMtGodEyeMan::Init() { NEO_STUB("CMtGodEyeMan::Init"); }
void CMtGodEyeMan::Register(CBasePlayer*) { NEO_STUB("CMtGodEyeMan::Register"); }
void CMtGodEyeMan::Update() { NEO_STUB("CMtGodEyeMan::Update"); }
CBasePlayer* CMtGodEyeMan::GetTarget(TeamName, int) { NEO_STUB("CMtGodEyeMan::GetTarget"); return {}; }
void CMtGodEyeMan::RegisterSub(CBasePlayer*, std::list<CMtGodEyeInfo*,std::allocator<CMtGodEyeInfo*> >&) { NEO_STUB("CMtGodEyeMan::RegisterSub"); }
void CMtGodEyeMan::UpdateSub(std::list<CMtGodEyeInfo*,std::allocator<CMtGodEyeInfo*> >&) { NEO_STUB("CMtGodEyeMan::UpdateSub"); }
CBasePlayer* CMtGodEyeMan::GetTargetSub(std::list<CMtGodEyeInfo*,std::allocator<CMtGodEyeInfo*> >&, int) { NEO_STUB("CMtGodEyeMan::GetTargetSub"); return {}; }
CMtTacInfoMan::CMtTacInfoMan() { NEO_STUB("CMtTacInfoMan::CMtTacInfoMan"); }
CMtTacInfoMan::~CMtTacInfoMan() { NEO_STUB("CMtTacInfoMan::~CMtTacInfoMan"); }
int CMtTacInfoMan::LoadTacInfo(const char*) { NEO_STUB("CMtTacInfoMan::LoadTacInfo"); return {}; }
int CMtTacInfoMan::LoadSelTac(const char*) { NEO_STUB("CMtTacInfoMan::LoadSelTac"); return {}; }
const SMtTacInfo* CMtTacInfoMan::GetTacInfo(int, int, const char*, const char*) const { NEO_STUB("CMtTacInfoMan::GetTacInfo"); return {}; }
const SMtTacInfo* CMtTacInfoMan::GetNextTacInfo(const SMtTacInfo*) const { NEO_STUB("CMtTacInfoMan::GetNextTacInfo"); return {}; }
const char* CMtTacInfoMan::SelectTactics(int, int) const { NEO_STUB("CMtTacInfoMan::SelectTactics"); return {}; }
int CMtTacInfoMan::GetNumGrenades(int, int, const char*, WeaponIdType) const { NEO_STUB("CMtTacInfoMan::GetNumGrenades"); return {}; }
void CMtTacInfoMan::Clear() { NEO_STUB("CMtTacInfoMan::Clear"); }
void SMtSelectTac::Clear() { NEO_STUB("SMtSelectTac::Clear"); }
void SMtSelectTac::Register(const char*, int, int) { NEO_STUB("SMtSelectTac::Register"); }
int SMtSelectTac::LoadCsvFile(const char*) { NEO_STUB("SMtSelectTac::LoadCsvFile"); return {}; }
const char* SMtSelectTac::SelectTactics(int, int) const { NEO_STUB("SMtSelectTac::SelectTactics"); return {}; }
int SMtSelectTac::GetNumTacs() const { NEO_STUB("SMtSelectTac::GetNumTacs"); return {}; }
const char* SMtSelectTac::GetName(int) const { NEO_STUB("SMtSelectTac::GetName"); return {}; }
int SMtSelectTac::GetPer(int) const { NEO_STUB("SMtSelectTac::GetPer"); return {}; }
int SMtSelectTac::IsEco(int) const { NEO_STUB("SMtSelectTac::IsEco"); return {}; }
CMtBotTacticalBuy::CMtBotTacticalBuy() { NEO_STUB("CMtBotTacticalBuy::CMtBotTacticalBuy"); }
CMtBotTacticalBuy::~CMtBotTacticalBuy() { NEO_STUB("CMtBotTacticalBuy::~CMtBotTacticalBuy"); }
void CMtBotTacticalBuy::Clear() { NEO_STUB("CMtBotTacticalBuy::Clear"); }
void CMtBotTacticalBuy::SelectPlan(int, int, int) { NEO_STUB("CMtBotTacticalBuy::SelectPlan"); }
int CMtBotTacticalBuy::GetPlan(int) const { NEO_STUB("CMtBotTacticalBuy::GetPlan"); return {}; }
int CMtBotTacticalBuy::GetRank() const { NEO_STUB("CMtBotTacticalBuy::GetRank"); return {}; }
int CMtBotTacticalBuy::IsSniperRifle(int) const { NEO_STUB("CMtBotTacticalBuy::IsSniperRifle"); return {}; }
void CMtBotTacticalBuy::SelectEquipmentsRank(int, int, int) { NEO_STUB("CMtBotTacticalBuy::SelectEquipmentsRank"); }
int CMtBotTacticalBuy::GetBuyWeaponId(int) { NEO_STUB("CMtBotTacticalBuy::GetBuyWeaponId"); return {}; }
bool CMtBotTacticalBuy::IsBuyVest() const { NEO_STUB("CMtBotTacticalBuy::IsBuyVest"); return {}; }
bool CMtBotTacticalBuy::IsBuyHelm() const { NEO_STUB("CMtBotTacticalBuy::IsBuyHelm"); return {}; }
bool CMtBotTacticalBuy::IsBuyDefuser() const { NEO_STUB("CMtBotTacticalBuy::IsBuyDefuser"); return {}; }
void CTacticalZone::KeyValue(KeyValueData_s*) { NEO_STUB("CTacticalZone::KeyValue"); }
void CTacticalZone::Spawn() { NEO_STUB("CTacticalZone::Spawn"); }
void CTacticalZone::TacticalTouch(CBaseEntity*) { NEO_STUB("CTacticalZone::TacticalTouch"); }
void CTacticalZone::SetName(int) { NEO_STUB("CTacticalZone::SetName"); }
void TacticalBuyState::OnEnter(CCSBot*) { NEO_STUB("TacticalBuyState::OnEnter"); }
void TacticalBuyState::OnUpdate(CCSBot*) { NEO_STUB("TacticalBuyState::OnUpdate"); }
void TacticalBuyState::OnExit(CCSBot*) { NEO_STUB("TacticalBuyState::OnExit"); }
const char* TacticalBuyState::GetName() const { NEO_STUB("TacticalBuyState::GetName"); return {}; }
void TacticalMoveToState::OnEnter(CCSBot*) { NEO_STUB("TacticalMoveToState::OnEnter"); }
void TacticalMoveToState::OnUpdate(CCSBot*) { NEO_STUB("TacticalMoveToState::OnUpdate"); }
void TacticalMoveToState::OnExit(CCSBot*) { NEO_STUB("TacticalMoveToState::OnExit"); }
const char* TacticalMoveToState::GetName() const { NEO_STUB("TacticalMoveToState::GetName"); return {}; }
int TacticalMoveToState::InitTactics(const SMtTacInfo*) { NEO_STUB("TacticalMoveToState::InitTactics"); return {}; }
void TacticalMoveToState::Equip(CCSBot*) { NEO_STUB("TacticalMoveToState::Equip"); }
void TacticalWaitState::OnEnter(CCSBot*) { NEO_STUB("TacticalWaitState::OnEnter"); }
void TacticalWaitState::OnUpdate(CCSBot*) { NEO_STUB("TacticalWaitState::OnUpdate"); }
void TacticalWaitState::OnExit(CCSBot*) { NEO_STUB("TacticalWaitState::OnExit"); }
const char* TacticalWaitState::GetName() const { NEO_STUB("TacticalWaitState::GetName"); return {}; }
int TacticalWaitState::InitTactics(const SMtTacInfo*) { NEO_STUB("TacticalWaitState::InitTactics"); return {}; }
void TacticalWaitState::Equip(CCSBot*) { NEO_STUB("TacticalWaitState::Equip"); }
