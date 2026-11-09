/* Stub implementations for neo/training.h. Each stub logs and returns a default value. */
#include "precompiled.h"
#include "neo/training.h"
#include "neo/neo_stub.h"

void CTrainingArmoury::Spawn() { NEO_STUB("CTrainingArmoury::Spawn"); }
void CTrainingArmoury::Precache() { NEO_STUB("CTrainingArmoury::Precache"); }
void CTrainingArmoury::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingArmoury::KeyValue"); }
void CTrainingArmoury::Restart() { NEO_STUB("CTrainingArmoury::Restart"); }
void CTrainingArmoury::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingArmoury::Use"); }
void CTrainingArmoury::Give(CBaseEntity*) { NEO_STUB("CTrainingArmoury::Give"); }
void CTrainingArmoury::GiveAmmo(CBasePlayer*, int, int) { NEO_STUB("CTrainingArmoury::GiveAmmo"); }
char* CTrainingArmoury::GetItemName() { NEO_STUB("CTrainingArmoury::GetItemName"); return {}; }
BOOL CTrainingArmoury::RemovePlayerItem(CBasePlayer*, int) { NEO_STUB("CTrainingArmoury::RemovePlayerItem"); return {}; }
void CTrainingArmoury::GiveNamedItemWithAmmo(CBasePlayer*, char*) { NEO_STUB("CTrainingArmoury::GiveNamedItemWithAmmo"); }
void CTrainingArmoury::SpawnPlayerItem() { NEO_STUB("CTrainingArmoury::SpawnPlayerItem"); }
char* CTrainingArmoury::GetCSModelName() { NEO_STUB("CTrainingArmoury::GetCSModelName"); return {}; }
int CTrainingArmoury::Save(CSave&) { NEO_STUB("CTrainingArmoury::Save"); return {}; }
int CTrainingArmoury::Restore(CRestore&) { NEO_STUB("CTrainingArmoury::Restore"); return {}; }
void CTrainingBreakable::Spawn() { NEO_STUB("CTrainingBreakable::Spawn"); }
void CTrainingBreakable::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingBreakable::KeyValue"); }
void CTrainingBreakable::Restart() { NEO_STUB("CTrainingBreakable::Restart"); }
int CTrainingBreakable::TakeDamage(entvars_s*, entvars_s*, float, int) { NEO_STUB("CTrainingBreakable::TakeDamage"); return {}; }
BOOL CTrainingBreakable::IsBreakable() { NEO_STUB("CTrainingBreakable::IsBreakable"); return {}; }
void CTrainingBreakable::DieHard(entvars_s*) { NEO_STUB("CTrainingBreakable::DieHard"); }
void CTrainingC4::Spawn() { NEO_STUB("CTrainingC4::Spawn"); }
void CTrainingC4::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingC4::KeyValue"); }
void CTrainingC4::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingC4::Use"); }
void CTrainingCamera::Spawn() { NEO_STUB("CTrainingCamera::Spawn"); }
void CTrainingCamera::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingCamera::KeyValue"); }
void CTrainingCamera::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingCamera::Use"); }
void CTrainingCamera::Setup() { NEO_STUB("CTrainingCamera::Setup"); }
void CTrainingCamera::Restart() { NEO_STUB("CTrainingCamera::Restart"); }
void CTrainingCamera::CameraThink() { NEO_STUB("CTrainingCamera::CameraThink"); }
void CTrainingCamera::CalculateMove() { NEO_STUB("CTrainingCamera::CalculateMove"); }
void CTrainingCamera::ReleasePlayers() { NEO_STUB("CTrainingCamera::ReleasePlayers"); }
void CTrainingCamera::ReleaseView() { NEO_STUB("CTrainingCamera::ReleaseView"); }
void CTrainingCamera::AcquirePlayers() { NEO_STUB("CTrainingCamera::AcquirePlayers"); }
int CTrainingCamera::Save(CSave&) { NEO_STUB("CTrainingCamera::Save"); return {}; }
int CTrainingCamera::Restore(CRestore&) { NEO_STUB("CTrainingCamera::Restore"); return {}; }
void CTrainingCorner::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingCorner::KeyValue"); }
float CTrainingCorner::GetDelay() { NEO_STUB("CTrainingCorner::GetDelay"); return {}; }
int CTrainingCorner::Save(CSave&) { NEO_STUB("CTrainingCorner::Save"); return {}; }
int CTrainingCorner::Restore(CRestore&) { NEO_STUB("CTrainingCorner::Restore"); return {}; }
void CTrainingDelayTrigger::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingDelayTrigger::KeyValue"); }
void CTrainingDelayTrigger::Spawn() { NEO_STUB("CTrainingDelayTrigger::Spawn"); }
void CTrainingDelayTrigger::Think() { NEO_STUB("CTrainingDelayTrigger::Think"); }
void CTrainingDelayTrigger::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingDelayTrigger::Use"); }
void CTrainingDelayTrigger::Restart() { NEO_STUB("CTrainingDelayTrigger::Restart"); }
int CTrainingDelayTrigger::ObjectCaps() { NEO_STUB("CTrainingDelayTrigger::ObjectCaps"); return {}; }
void CTrainingDoor::Spawn() { NEO_STUB("CTrainingDoor::Spawn"); }
void CTrainingDoor::Restart() { NEO_STUB("CTrainingDoor::Restart"); }
void CTrainingDoor::Killed(entvars_s*, int) { NEO_STUB("CTrainingDoor::Killed"); }
void CTrainingDoor::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingDoor::Use"); }
void CTrainingDoor::DoorHitTop() { NEO_STUB("CTrainingDoor::DoorHitTop"); }
void CTrainingDoor::DoorHitBottom() { NEO_STUB("CTrainingDoor::DoorHitBottom"); }
int CTrainingDoor::Save(CSave&) { NEO_STUB("CTrainingDoor::Save"); return {}; }
int CTrainingDoor::Restore(CRestore&) { NEO_STUB("CTrainingDoor::Restore"); return {}; }
void CTrainingGroupTrigger::Spawn() { NEO_STUB("CTrainingGroupTrigger::Spawn"); }
void CTrainingGroupTrigger::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingGroupTrigger::KeyValue"); }
void CTrainingGroupTrigger::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingGroupTrigger::Use"); }
void CTrainingGroupTrigger::Touch(CBaseEntity*) { NEO_STUB("CTrainingGroupTrigger::Touch"); }
void CTrainingGroupTrigger::Think() { NEO_STUB("CTrainingGroupTrigger::Think"); }
void CTrainingInvulnerable::Spawn() { NEO_STUB("CTrainingInvulnerable::Spawn"); }
void CTrainingInvulnerable::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingInvulnerable::Use"); }
void CTrainingInvulnerable::SetDamageFlag(CBaseEntity*, int) { NEO_STUB("CTrainingInvulnerable::SetDamageFlag"); }
void CTrainingInvulnerable::ProtectThink() { NEO_STUB("CTrainingInvulnerable::ProtectThink"); }
int CTrainingInvulnerable::Save(CSave&) { NEO_STUB("CTrainingInvulnerable::Save"); return {}; }
int CTrainingInvulnerable::Restore(CRestore&) { NEO_STUB("CTrainingInvulnerable::Restore"); return {}; }
void CTrainingMapInfo::Spawn() { NEO_STUB("CTrainingMapInfo::Spawn"); }
void CTrainingMapInfo::Restart() { NEO_STUB("CTrainingMapInfo::Restart"); }
void CTrainingMapInfo::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingMapInfo::KeyValue"); }
void CTrainingMapInfo::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingMapInfo::Use"); }
int CTrainingMapInfo::Save(CSave&) { NEO_STUB("CTrainingMapInfo::Save"); return {}; }
int CTrainingMapInfo::Restore(CRestore&) { NEO_STUB("CTrainingMapInfo::Restore"); return {}; }
void CTrainingNEO2DownLadder::Spawn() { NEO_STUB("CTrainingNEO2DownLadder::Spawn"); }
void CTrainingNEO2DownLadder::Touch(CBaseEntity*) { NEO_STUB("CTrainingNEO2DownLadder::Touch"); }
void CTrainingNEO2HalfSitting::Spawn() { NEO_STUB("CTrainingNEO2HalfSitting::Spawn"); }
void CTrainingNEO2Jumping::Spawn() { NEO_STUB("CTrainingNEO2Jumping::Spawn"); }
void CTrainingNEO2UpLadder::Spawn() { NEO_STUB("CTrainingNEO2UpLadder::Spawn"); }
void CTrainingNEO2UpLadder::Touch(CBaseEntity*) { NEO_STUB("CTrainingNEO2UpLadder::Touch"); }
void CTrainingNEO2Walking::Spawn() { NEO_STUB("CTrainingNEO2Walking::Spawn"); }
void CTrainingNPC::Spawn() { NEO_STUB("CTrainingNPC::Spawn"); }
void CTrainingNPC::ReSpawn() { NEO_STUB("CTrainingNPC::ReSpawn"); }
void CTrainingNPC::Precache() { NEO_STUB("CTrainingNPC::Precache"); }
void CTrainingNPC::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingNPC::KeyValue"); }
char* CTrainingNPC::GetModelName() { NEO_STUB("CTrainingNPC::GetModelName"); return {}; }
void CTrainingNPC::GetModel() { NEO_STUB("CTrainingNPC::GetModel"); }
void CTrainingNPC::GetItem(int) { NEO_STUB("CTrainingNPC::GetItem"); }
int CTrainingNPC::Classify() { NEO_STUB("CTrainingNPC::Classify"); return {}; }
void CTrainingNPC::Killed(entvars_s*, int) { NEO_STUB("CTrainingNPC::Killed"); }
void CTrainingNPC::Restart() { NEO_STUB("CTrainingNPC::Restart"); }
void CTrainingNPC::FindTarget() { NEO_STUB("CTrainingNPC::FindTarget"); }
void CTrainingNPC::PreThink() { NEO_STUB("CTrainingNPC::PreThink"); }
void CTrainingNPC::PostThink() { NEO_STUB("CTrainingNPC::PostThink"); }
void CTrainingNPC::IdleThink() { NEO_STUB("CTrainingNPC::IdleThink"); }
void CTrainingNPC::DisappearThink() { NEO_STUB("CTrainingNPC::DisappearThink"); }
void CTrainingNPC::NPCRespawnThink() { NEO_STUB("CTrainingNPC::NPCRespawnThink"); }
void CTrainingNPC::SetSequence(char*) { NEO_STUB("CTrainingNPC::SetSequence"); }
void CTrainingNPC::SetActivity(Activity) { NEO_STUB("CTrainingNPC::SetActivity"); }
void CTrainingNPC::SetAnimation(PLAYER_ANIM) { NEO_STUB("CTrainingNPC::SetAnimation"); }
float CTrainingNPC::ChangeYaw(int) { NEO_STUB("CTrainingNPC::ChangeYaw"); return {}; }
void CTrainingNPC::MakeIdealYaw(Vector) { NEO_STUB("CTrainingNPC::MakeIdealYaw"); }
void CTrainingNPC::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingNPC::Use"); }
int CTrainingNPC::TakeDamage(entvars_s*, entvars_s*, float, int) { NEO_STUB("CTrainingNPC::TakeDamage"); return {}; }
void CTrainingNPC::TraceAttack(entvars_s*, float, Vector, TraceResult*, int) { NEO_STUB("CTrainingNPC::TraceAttack"); }
int CTrainingNPC::StepMaterial() { NEO_STUB("CTrainingNPC::StepMaterial"); return {}; }
void CTrainingNPC::StepSound(int, float) { NEO_STUB("CTrainingNPC::StepSound"); }
BOOL CTrainingNPC::IsNetClient() { NEO_STUB("CTrainingNPC::IsNetClient"); return {}; }
int CTrainingNPC::Save(CSave&) { NEO_STUB("CTrainingNPC::Save"); return {}; }
int CTrainingNPC::Restore(CRestore&) { NEO_STUB("CTrainingNPC::Restore"); return {}; }
void CTrainingNPCCorner::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingNPCCorner::KeyValue"); }
float CTrainingNPCCorner::GetDelay() { NEO_STUB("CTrainingNPCCorner::GetDelay"); return {}; }
int CTrainingNPCCorner::Save(CSave&) { NEO_STUB("CTrainingNPCCorner::Save"); return {}; }
int CTrainingNPCCorner::Restore(CRestore&) { NEO_STUB("CTrainingNPCCorner::Restore"); return {}; }
void CTrainingRandomTrigger::Spawn() { NEO_STUB("CTrainingRandomTrigger::Spawn"); }
void CTrainingRandomTrigger::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingRandomTrigger::KeyValue"); }
void CTrainingRandomTrigger::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingRandomTrigger::Use"); }
BOOL CTrainingRandomTrigger::RandomTarget() { NEO_STUB("CTrainingRandomTrigger::RandomTarget"); return {}; }
void CTrainingRandomTrigger::Restart() { NEO_STUB("CTrainingRandomTrigger::Restart"); }
void CTrainingRestart::Spawn() { NEO_STUB("CTrainingRestart::Spawn"); }
void CTrainingRestart::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingRestart::Use"); }
void CTrainingRotDoor::Spawn() { NEO_STUB("CTrainingRotDoor::Spawn"); }
void CTrainingRotDoor::Restart() { NEO_STUB("CTrainingRotDoor::Restart"); }
void CTrainingRotDoor::Killed(entvars_s*, int) { NEO_STUB("CTrainingRotDoor::Killed"); }
void CTrainingRotDoor::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingRotDoor::Use"); }
int CTrainingRotDoor::Save(CSave&) { NEO_STUB("CTrainingRotDoor::Save"); return {}; }
int CTrainingRotDoor::Restore(CRestore&) { NEO_STUB("CTrainingRotDoor::Restore"); return {}; }
void CTrainingRotating::Spawn() { NEO_STUB("CTrainingRotating::Spawn"); }
void CTrainingRotating::Restart() { NEO_STUB("CTrainingRotating::Restart"); }
void CTrainingRotating::OnOffUse(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingRotating::OnOffUse"); }
void CTrainingSequence::Spawn() { NEO_STUB("CTrainingSequence::Spawn"); }
void CTrainingSequence::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingSequence::KeyValue"); }
void CTrainingSequence::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingSequence::Use"); }
int CTrainingSequence::ObjectCaps() { NEO_STUB("CTrainingSequence::ObjectCaps"); return {}; }
int CTrainingSequence::Save(CSave&) { NEO_STUB("CTrainingSequence::Save"); return {}; }
int CTrainingSequence::Restore(CRestore&) { NEO_STUB("CTrainingSequence::Restore"); return {}; }
void CTrainingSetAmmo::Spawn() { NEO_STUB("CTrainingSetAmmo::Spawn"); }
void CTrainingSetAmmo::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingSetAmmo::KeyValue"); }
void CTrainingSetAmmo::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingSetAmmo::Use"); }
void CTrainingSetAmmo::SetClipAmmo(CBasePlayer*) { NEO_STUB("CTrainingSetAmmo::SetClipAmmo"); }
void CTrainingSetAmmo::SetStoredAmmo(CBasePlayer*) { NEO_STUB("CTrainingSetAmmo::SetStoredAmmo"); }
int CTrainingSetAmmo::Save(CSave&) { NEO_STUB("CTrainingSetAmmo::Save"); return {}; }
int CTrainingSetAmmo::Restore(CRestore&) { NEO_STUB("CTrainingSetAmmo::Restore"); return {}; }
void CTrainingSetTime::Spawn() { NEO_STUB("CTrainingSetTime::Spawn"); }
void CTrainingSetTime::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingSetTime::KeyValue"); }
void CTrainingSetTime::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingSetTime::Use"); }
void CTrainingSleep::Spawn() { NEO_STUB("CTrainingSleep::Spawn"); }
void CTrainingSleep::Restart() { NEO_STUB("CTrainingSleep::Restart"); }
void CTrainingSleep::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingSleep::Use"); }
void CTrainingSleep::FlipFlop(CBaseEntity*) { NEO_STUB("CTrainingSleep::FlipFlop"); }
BOOL CTrainingSleep::Touching(CBaseEntity*) { NEO_STUB("CTrainingSleep::Touching"); return {}; }
string_t CTrainingSleep::Append(char*, unsigned int) { NEO_STUB("CTrainingSleep::Append"); return {}; }
string_t CTrainingSleep::Remove(char*, unsigned int) { NEO_STUB("CTrainingSleep::Remove"); return {}; }
void CTrainingStuckTrigger::Spawn() { NEO_STUB("CTrainingStuckTrigger::Spawn"); }
void CTrainingStuckTrigger::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingStuckTrigger::KeyValue"); }
void CTrainingStuckTrigger::Restart() { NEO_STUB("CTrainingStuckTrigger::Restart"); }
void CTrainingStuckTrigger::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingStuckTrigger::Use"); }
void CTrainingStuckTrigger::Touch(CBaseEntity*) { NEO_STUB("CTrainingStuckTrigger::Touch"); }
void CTrainingStuckTrigger::Think() { NEO_STUB("CTrainingStuckTrigger::Think"); }
void CTrainingTank::Restart() { NEO_STUB("CTrainingTank::Restart"); }
Vector CTrainingTank::UpdateTargetPosition(CBaseEntity*) { NEO_STUB("CTrainingTank::UpdateTargetPosition"); abort(); }
void CTrainingTank::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingTank::Use"); }
void CTrainingTarget::Spawn() { NEO_STUB("CTrainingTarget::Spawn"); }
void CTrainingTarget::Precache() { NEO_STUB("CTrainingTarget::Precache"); }
void CTrainingTarget::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingTarget::KeyValue"); }
void CTrainingTarget::Restart() { NEO_STUB("CTrainingTarget::Restart"); }
int CTrainingTarget::TakeDamage(entvars_s*, entvars_s*, float, int) { NEO_STUB("CTrainingTarget::TakeDamage"); return {}; }
void CTrainingTarget::Break(Vector) { NEO_STUB("CTrainingTarget::Break"); }
int CTrainingTarget::Save(CSave&) { NEO_STUB("CTrainingTarget::Save"); return {}; }
int CTrainingTarget::Restore(CRestore&) { NEO_STUB("CTrainingTarget::Restore"); return {}; }
void CTrainingTeleporter::Spawn() { NEO_STUB("CTrainingTeleporter::Spawn"); }
void CTrainingTeleporter::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingTeleporter::KeyValue"); }
void CTrainingTeleporter::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingTeleporter::Use"); }
void CTrainingTeleporter::Touch(CBaseEntity*) { NEO_STUB("CTrainingTeleporter::Touch"); }
void CTrainingTrain::Spawn() { NEO_STUB("CTrainingTrain::Spawn"); }
void CTrainingTrain::Restart() { NEO_STUB("CTrainingTrain::Restart"); }
void CTrainingTrain::Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float) { NEO_STUB("CTrainingTrain::Use"); }
void CTrainingTriggerOnce::Spawn() { NEO_STUB("CTrainingTriggerOnce::Spawn"); }
void CTrainingTriggerOnce::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingTriggerOnce::KeyValue"); }
void CTrainingTriggerOnce::OnceTouch(CBaseEntity*) { NEO_STUB("CTrainingTriggerOnce::OnceTouch"); }
void CTrainingTriggerOnce::ActivateOnceTrigger(CBaseEntity*) { NEO_STUB("CTrainingTriggerOnce::ActivateOnceTrigger"); }
void CTrainingTriggerOnce::Restart() { NEO_STUB("CTrainingTriggerOnce::Restart"); }
void CTrainingWallToggle::Restart() { NEO_STUB("CTrainingWallToggle::Restart"); }
void CTrainingWheelTrain::Spawn() { NEO_STUB("CTrainingWheelTrain::Spawn"); }
void CTrainingWheelTrain::KeyValue(KeyValueData_s*) { NEO_STUB("CTrainingWheelTrain::KeyValue"); }
void CTrainingWheelTrain::NextThink(float, int) { NEO_STUB("CTrainingWheelTrain::NextThink"); }
void CTrainingWheelTrain::Think() { NEO_STUB("CTrainingWheelTrain::Think"); }
int CTrainingWheelTrain::Save(CSave&) { NEO_STUB("CTrainingWheelTrain::Save"); return {}; }
int CTrainingWheelTrain::Restore(CRestore&) { NEO_STUB("CTrainingWheelTrain::Restore"); return {}; }
