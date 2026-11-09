/* Generated from Counter-Strike NEO DWARF (cs_i486.so). Declarations only.
   Member layout is not reconstructed. Stub bodies live in neo/training.cpp.
   Clean-room: names and signatures from debug info, no code transcribed. */
#ifndef NEO_TRAINING_H
#define NEO_TRAINING_H

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "gamerules.h"
#include <list>
#include <vector>
#include <map>
#include <string>

#include "neo/popup.h"


struct CTrainingArmoury : public CBaseEntity {
public:
    static TYPEDESCRIPTION m_SaveData[2];
private:
    int m_iItem;
    int m_iDefaultAmmo;
    float m_bMessaged[32];
public:
    virtual void Spawn();
    virtual void Precache();
    virtual void KeyValue(KeyValueData_s*);
    virtual void Restart();
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    void Give(CBaseEntity*);
    void GiveAmmo(CBasePlayer*, int, int);
    char* GetItemName();
    BOOL RemovePlayerItem(CBasePlayer*, int);
    void GiveNamedItemWithAmmo(CBasePlayer*, char*);
    void SpawnPlayerItem();
    char* GetCSModelName();
    virtual int Save(CSave&);
    virtual int Restore(CRestore&);
};

struct CTrainingBreakable : public CBreakable {
private:
    float m_flMinBreakTime;
    float m_flBreakDelay;
public:
    virtual void Spawn();
    virtual void KeyValue(KeyValueData_s*);
    virtual void Restart();
    virtual int TakeDamage(entvars_s*, entvars_s*, float, int);
    BOOL IsBreakable();
    void DieHard(entvars_s*);
};

struct CTrainingC4 : public CBaseEntity {
public:
    virtual void Spawn();
    virtual void KeyValue(KeyValueData_s*);
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
};

struct CTrainingCamera : public CBaseEntity {
public:
    static TYPEDESCRIPTION m_SaveData[9];
private:
    BOOL m_bActive;
    EHANDLE m_hViewTarget;
    EHANDLE m_hMoveTarget;
    string_t m_sFirstTarget;
    float m_flAcceleration;
    float m_flDeceleration;
    float m_flDelayTime;
    float m_flSpeed;
    float m_flInitialSpeed;
    BOOL m_bIgnoreView;
    float m_flChangeOverDist;
public:
    virtual void Spawn();
    virtual void KeyValue(KeyValueData_s*);
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    void Setup();
    virtual void Restart();
    void CameraThink();
    void CalculateMove();
    void ReleasePlayers();
    void ReleaseView();
    void AcquirePlayers();
    virtual int Save(CSave&);
    virtual int Restore(CRestore&);
};

struct CTrainingCorner : public CPointEntity {
public:
    static TYPEDESCRIPTION m_SaveData[2];
    string_t m_sWatchTarget;
private:
    float m_flWait;
public:
    virtual void KeyValue(KeyValueData_s*);
    virtual float GetDelay();
    virtual int Save(CSave&);
    virtual int Restore(CRestore&);
};

struct CTrainingDelayTrigger : public CBaseDelay {
private:
    BOOL bActive;
    BOOL bTriggered;
    USE_TYPE triggerType;
    float m_fDelayTime;
public:
    virtual void KeyValue(KeyValueData_s*);
    virtual void Spawn();
    virtual void Think();
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    virtual void Restart();
    virtual int ObjectCaps();
};

struct CTrainingDoor : public CBaseDoor {
public:
    static TYPEDESCRIPTION m_SaveData[1];
private:
    float m_flHealth;
public:
    virtual void Spawn();
    virtual void Restart();
    virtual void Killed(entvars_s*, int);
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    void DoorHitTop();
    void DoorHitBottom();
    virtual int Save(CSave&);
    virtual int Restore(CRestore&);
};

struct CTrainingGroupTrigger : public CBaseEntity {
private:
    BOOL m_bTouching[32];
    float m_flWait;
    int m_iTeam;
public:
    virtual void Spawn();
    virtual void KeyValue(KeyValueData_s*);
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    virtual void Touch(CBaseEntity*);
    virtual void Think();
};

struct CTrainingInvulnerable : public CBaseEntity {
public:
    static TYPEDESCRIPTION m_SaveData[1];
private:
    BOOL m_bActive;
public:
    virtual void Spawn();
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    void SetDamageFlag(CBaseEntity*, int);
    void ProtectThink();
    virtual int Save(CSave&);
    virtual int Restore(CRestore&);
};

struct CTrainingMapInfo : public CBaseEntity {
public:
    static TYPEDESCRIPTION m_SaveData[1];
private:
    float m_flStartTime;
    float m_flRoundTime;
public:
    virtual void Spawn();
    virtual void Restart();
    virtual void KeyValue(KeyValueData_s*);
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    virtual int Save(CSave&);
    virtual int Restore(CRestore&);
};

struct CTrainingNEO2DownLadder : public CNEO2BeginnerModeEntity {
public:
    virtual void Spawn();
    virtual void Touch(CBaseEntity*);
};

struct CTrainingNEO2HalfSitting : public CNEO2BeginnerModeEntity {
public:
    virtual void Spawn();
};

struct CTrainingNEO2Jumping : public CNEO2BeginnerModeEntity {
public:
    virtual void Spawn();
};

struct CTrainingNEO2UpLadder : public CNEO2BeginnerModeEntity {
public:
    virtual void Spawn();
    virtual void Touch(CBaseEntity*);
};

struct CTrainingNEO2Walking : public CNEO2BeginnerModeEntity {
public:
    virtual void Spawn();
};

struct CTrainingNPC : public CBasePlayer {
public:
    static TYPEDESCRIPTION m_SaveData[1];
    string_t m_sWatchTarget;
private:
    Vector m_vecStartPos;
    Vector m_vecStartAngles;
    ModelName m_iBotModel;
    int m_iPrimaryWeapon;
    int m_iSecondaryWeapon;
    int m_iTertiaryWeapon;
    int m_iArmour;
    TeamName m_iBotTeam;
    float m_flMaxSearchDist;
    int m_iSkill;
    BOOL m_bFirstUpdate;
    BOOL m_bWaiting;
    float m_flLastThink;
    float m_flSearchTime;
    float m_flUpdateMoveTime;
    float m_flTraceTime;
    float m_flMoveTime;
    float m_flFireTime;
    float m_flCeaseFireTime;
    float m_flFireWait;
    float m_flCeaseFireWait;
    int m_iShotCount;
    int m_iHitShotCount;
    EHANDLE m_hBotEnemy;
    int m_iInitialState;
    int m_iCurrentState;
    float m_flEnemyLastHealth;
    float m_flRespawnTime;
    string_t m_strPainTarget;
    float m_flPainTargetDelay;
    float m_flPainTargetTime;
    int m_iStepLeft;
    float m_flStepTime;
    int m_iSkipStep;
    float m_flStartTime;
    int m_iDamageScore;
    int m_iHitScore;
    int m_iKillScore;
    int m_iTimeScore;
    float m_flMinTime;
    float m_flMaxTime;
public:
    EHANDLE m_hWeaponModel;
    EHANDLE m_hSequenceEnt;
    BOOL m_bMoveCompleted;
    BOOL m_bPlayedSequence;
    string_t m_szSquadname;
    BOOL m_bDidShot;
    int m_iDidDamage;
    BOOL m_bDormant;
    virtual void Spawn();
    void ReSpawn();
    virtual void Precache();
    virtual void KeyValue(KeyValueData_s*);
    char* GetModelName();
    void GetModel();
    void GetItem(int);
    virtual int Classify();
    virtual void Killed(entvars_s*, int);
    virtual void Restart();
    void FindTarget();
    virtual void PreThink();
    virtual void PostThink();
    void IdleThink();
    void DisappearThink();
    void NPCRespawnThink();
    void SetSequence(char*);
    void SetActivity(Activity);
    void SetAnimation(PLAYER_ANIM);
    virtual float ChangeYaw(int);
    void MakeIdealYaw(Vector);
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    virtual int TakeDamage(entvars_s*, entvars_s*, float, int);
    virtual void TraceAttack(entvars_s*, float, Vector, TraceResult*, int);
    int StepMaterial();
    void StepSound(int, float);
    virtual BOOL IsNetClient();
    virtual int Save(CSave&);
    virtual int Restore(CRestore&);
};

struct CTrainingNPCCorner : public CPointEntity {
public:
    static TYPEDESCRIPTION m_SaveData[1];
    int m_iAction;
private:
    float m_flWait;
public:
    virtual void KeyValue(KeyValueData_s*);
    virtual float GetDelay();
    virtual int Save(CSave&);
    virtual int Restore(CRestore&);
};

struct CTrainingRandomTrigger : public CBaseEntity {
private:
    int m_iMin;
    int m_iMax;
    int m_iCount;
    int m_iMasterMin;
    int m_iMasterMax;
    int m_iMasterCount;
    char m_sTargetName[513];
    EHANDLE m_hActivator;
    bool m_bFired[256];
    bool m_bTriggerOnce;
public:
    virtual void Spawn();
    virtual void KeyValue(KeyValueData_s*);
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    BOOL RandomTarget();
    virtual void Restart();
};

struct CTrainingRestart : public CBaseEntity {
public:
    virtual void Spawn();
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
};

struct CTrainingRotDoor : public CRotDoor {
public:
    static TYPEDESCRIPTION m_SaveData[1];
private:
    float m_flHealth;
public:
    virtual void Spawn();
    virtual void Restart();
    virtual void Killed(entvars_s*, int);
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    virtual int Save(CSave&);
    virtual int Restore(CRestore&);
};

struct CTrainingRotating : public CFuncRotating {
public:
    virtual void Spawn();
    virtual void Restart();
    void OnOffUse(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
};

struct CTrainingSequence : public CBaseMonster {
public:
    static TYPEDESCRIPTION m_SaveData[6];
    string_t m_iszIdle;
    string_t m_iszPlay;
    string_t m_iszEntity;
    float m_flRange;
    int m_iMoveTo;
    int m_iUseState;
    virtual void Spawn();
    virtual void KeyValue(KeyValueData_s*);
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    virtual int ObjectCaps();
    virtual int Save(CSave&);
    virtual int Restore(CRestore&);
};

struct CTrainingSetAmmo : public CBaseEntity {
public:
    static TYPEDESCRIPTION m_SaveData[3];
private:
    int m_iClipCount;
    int m_iStoreCount;
    int m_iAmmoType;
public:
    virtual void Spawn();
    virtual void KeyValue(KeyValueData_s*);
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    void SetClipAmmo(CBasePlayer*);
    void SetStoredAmmo(CBasePlayer*);
    virtual int Save(CSave&);
    virtual int Restore(CRestore&);
};

struct CTrainingSetTime : public CBaseEntity {
private:
    int m_iTime;
public:
    virtual void Spawn();
    virtual void KeyValue(KeyValueData_s*);
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
};

struct CTrainingSleep : public CBaseEntity {
private:
    BOOL m_bSleeping;
public:
    virtual void Spawn();
    virtual void Restart();
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    void FlipFlop(CBaseEntity*);
    BOOL Touching(CBaseEntity*);
    string_t Append(char*, unsigned int);
    string_t Remove(char*, unsigned int);
};

struct CTrainingStuckTrigger : public CBaseToggle {
private:
    float m_flTouchTime[32];
    float m_flLastTouchTime[32];
    float m_flWait;
    float m_flResetTime;
    float m_flWaitMaster;
    bool m_bFirstTimer;
public:
    virtual void Spawn();
    virtual void KeyValue(KeyValueData_s*);
    virtual void Restart();
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    virtual void Touch(CBaseEntity*);
    virtual void Think();
};

struct CTrainingTank : public CFuncTankGun {
public:
    virtual void Restart();
    virtual Vector UpdateTargetPosition(CBaseEntity*);
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
};

struct CTrainingTarget : public CGunTarget {
public:
    static TYPEDESCRIPTION m_SaveData[3];
private:
    string_t m_strFirstTarget;
    Vector m_vecStartPos;
    string_t m_strDamageTarget;
    int m_iMaterial;
    int m_iExplodeMagnitude;
    int m_iExplodeDir;
    string_t m_strGibModel;
    short int m_iShard;
public:
    virtual void Spawn();
    virtual void Precache();
    virtual void KeyValue(KeyValueData_s*);
    virtual void Restart();
    virtual int TakeDamage(entvars_s*, entvars_s*, float, int);
    void Break(Vector);
    virtual int Save(CSave&);
    virtual int Restore(CRestore&);
};

struct CTrainingTeleporter : public CBaseEntity {
private:
    int m_iTeam;
public:
    virtual void Spawn();
    virtual void KeyValue(KeyValueData_s*);
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    virtual void Touch(CBaseEntity*);
};

struct CTrainingTrain : public CFuncTrain {
private:
    string_t m_strFirstTarget;
public:
    virtual void Spawn();
    virtual void Restart();
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
};

struct CTrainingTriggerOnce : public CTriggerOnce {
private:
    BOOL bTriggered;
    int m_iTriggerEffect;
public:
    virtual void Spawn();
    virtual void KeyValue(KeyValueData_s*);
    void OnceTouch(CBaseEntity*);
    void ActivateOnceTrigger(CBaseEntity*);
    virtual void Restart();
};

struct CTrainingWallToggle : public CFuncWallToggle {
public:
    virtual void Restart();
};

struct CTrainingWheelTrain : public CFuncTrackTrain {
public:
    static TYPEDESCRIPTION m_SaveData[1];
private:
    float m_flRadius;
public:
    virtual void Spawn();
    virtual void KeyValue(KeyValueData_s*);
    void NextThink(float, int);
    virtual void Think();
    virtual int Save(CSave&);
    virtual int Restore(CRestore&);
};

#endif  // NEO_TRAINING_H
