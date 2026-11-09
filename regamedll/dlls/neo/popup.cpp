/* Stub implementations for neo/popup.h. Each stub logs and returns a default value. */
#include "precompiled.h"
#include "neo/popup.h"
#include "neo/neo_stub.h"

CPopup::CPopup() { NEO_STUB("CPopup::CPopup"); }
CPopup::CPopup(const CPopup&) { NEO_STUB("CPopup::CPopup"); }
CPopup& CPopup::operator=(CPopup&) { NEO_STUB("CPopup::operator="); abort(); }
bool CPopup::AccessCheck() const { NEO_STUB("CPopup::AccessCheck"); return {}; }
int CPopup::GetPopupNumber(const char*) const { NEO_STUB("CPopup::GetPopupNumber"); return {}; }
void CPopup::ResetTime(int) { NEO_STUB("CPopup::ResetTime"); }
void CPopup::_RoundEnd() { NEO_STUB("CPopup::_RoundEnd"); }
CPopup::CPopup(CBasePlayer*) { NEO_STUB("CPopup::CPopup"); }
void CPopup::Reset() { NEO_STUB("CPopup::Reset"); }
void CPopup::ResetAll() { NEO_STUB("CPopup::ResetAll"); }
void CPopup::RoundEnd() { NEO_STUB("CPopup::RoundEnd"); }
void CPopup::Think() { NEO_STUB("CPopup::Think"); }
void CPopup::HandleSignals(int, int) { NEO_STUB("CPopup::HandleSignals"); }
void CPopup::HaveGrenadeEvent() { NEO_STUB("CPopup::HaveGrenadeEvent"); }
void CPopup::SwitchGrenadeEvent() { NEO_STUB("CPopup::SwitchGrenadeEvent"); }
void CPopup::ReloadEvent() { NEO_STUB("CPopup::ReloadEvent"); }
void CPopup::ShowPopupEvent(const char*) { NEO_STUB("CPopup::ShowPopupEvent"); }
void CPopup::EndPopupEvent(const char*) { NEO_STUB("CPopup::EndPopupEvent"); }
void CPopup::SendCreateMessage(int, float, float, int, const char*, int, int, const char*, const PopupCustomData*, bool) { NEO_STUB("CPopup::SendCreateMessage"); }
void CPopup::SendCreateMessageAll(int, float, float, int, const char*, int, int, const char*, const PopupCustomData*, bool) { NEO_STUB("CPopup::SendCreateMessageAll"); }
void CPopup::SendDeleteMessage(int, int, const char*, bool) { NEO_STUB("CPopup::SendDeleteMessage"); }
void CPopup::SendDeleteMessageAll(int, int, const char*, bool) { NEO_STUB("CPopup::SendDeleteMessageAll"); }
bool CPopup::CanSwitchWeapon() { NEO_STUB("CPopup::CanSwitchWeapon"); return {}; }
bool CPopup::CanSwitchGrenade() { NEO_STUB("CPopup::CanSwitchGrenade"); return {}; }
bool CPopup::HaveBurst(int) { NEO_STUB("CPopup::HaveBurst"); return {}; }
bool CPopup::HaveScope(int) { NEO_STUB("CPopup::HaveScope"); return {}; }
bool CPopup::HaveSilencer(int) { NEO_STUB("CPopup::HaveSilencer"); return {}; }
void CPopup::EnableAssistPop() { NEO_STUB("CPopup::EnableAssistPop"); }
void CPopup::DisableAssistPop() { NEO_STUB("CPopup::DisableAssistPop"); }
void CNEO2Popup::KeyValue(KeyValueData_s*) { NEO_STUB("CNEO2Popup::KeyValue"); }
void CNEO2Popup::Spawn() { NEO_STUB("CNEO2Popup::Spawn"); }
void CNEO2Popup::Restart() { NEO_STUB("CNEO2Popup::Restart"); }
void CNEO2Popup::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CNEO2Popup::Use"); }
void CNEO2Popup::Think() { NEO_STUB("CNEO2Popup::Think"); }
int CNEO2Popup::Save(CSave&) { NEO_STUB("CNEO2Popup::Save"); return {}; }
int CNEO2Popup::Restore(CRestore&) { NEO_STUB("CNEO2Popup::Restore"); return {}; }
void CNEO2Popup::EndPopupEvent(const char*) { NEO_STUB("CNEO2Popup::EndPopupEvent"); }
void CNEO2PopupDelete::KeyValue(KeyValueData_s*) { NEO_STUB("CNEO2PopupDelete::KeyValue"); }
void CNEO2PopupDelete::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CNEO2PopupDelete::Use"); }
void CNEO2BeginnerModeEntity::KeyValue(KeyValueData_s*) { NEO_STUB("CNEO2BeginnerModeEntity::KeyValue"); }
void CNEO2BeginnerModeEntity::Spawn() { NEO_STUB("CNEO2BeginnerModeEntity::Spawn"); }
void CNEO2BeginnerModeEntity::Touch(CBaseEntity*) { NEO_STUB("CNEO2BeginnerModeEntity::Touch"); }
