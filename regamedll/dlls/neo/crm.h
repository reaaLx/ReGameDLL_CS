/* Generated from Counter-Strike NEO DWARF (cs_i486.so). Declarations only.
   Member layout is not reconstructed. Stub bodies live in neo/crm.cpp.
   Clean-room: names and signatures from debug info, no code transcribed. */
#ifndef NEO_CRM_H
#define NEO_CRM_H

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "gamerules.h"
#include <list>
#include <vector>
#include <map>
#include <string>



struct CCRM {
public:
    struct SInitData {
    public:
        bool bFirstPlay;
        bool bNoGJ;
        bool bTempRate;
        float fRate;
    };
private:
    static const int* _D;
    bool m_bInitialized;
    int m_iPrintData;
    bool m_bSend[175];
    CBasePlayer* m_pPlayer;
    int m_iKillCount;
    int m_iDeathCount;
    int m_iCSFKillCount;
    int m_iCSFDeathCount;
    int m_iNEOKillCount;
    int m_iNEODeathCount;
    static int m_iFirstHalfCSFTeamKillCount;
    static int m_iFirstHalfCSFTeamDeathCount;
    static int m_iFirstHalfNEOTeamKillCount;
    static int m_iFirstHalfNEOTeamDeathCount;
    static int m_iSecondHalfCSFTeamKillCount;
    static int m_iSecondHalfCSFTeamDeathCount;
    static int m_iSecondHalfNEOTeamKillCount;
    static int m_iSecondHalfNEOTeamDeathCount;
    int m_iPistolKillCount;
    int m_iShotgunKillCount;
    int m_iSubMachineGunKillCount;
    int m_iAssultKillCount;
    int m_iSniperKillCount;
    int m_iMachineGunKillCount;
    int m_iKnifeKillCount;
    int m_iHEGrenadeKillCount;
    int m_iHeadShotCount;
    int m_iFriendlyFireCount;
    int m_iAllResult;
    int m_iWinCount;
    int m_iLoseCount;
    int m_iCSFWinCount;
    int m_iCSFLoseCount;
    int m_iNEOWinCount;
    int m_iNEOLoseCount;
    int m_iRoundCount;
    int m_iMapConditions;
    int m_iAttackDamage;
    int m_iDamage;
    float m_fTime;
    float m_fAliveTime;
    float m_fRunTime;
    float m_fWaikTime;
    int m_iTeamMapChangeCount;
    int m_iTopKillerCount;
    int m_iKillCount2;
    int m_iGJCount;
    int m_iGJSendCount;
    int m_iRadio1Count;
    int m_iRadio2Count;
    bool m_bFirstPlay;
    bool m_bNoGJ;
    static bool m_bInitialRateSystem;
    float m_fRate;
    bool m_bTempRate;
    static float m_fMaxRate;
    static float m_fMinRate;
    int m_iRateAttackNumber;
    int m_iRateAttackDamage[32];
    int m_iRateAttackDirection[32];
    static float m_fRateAttackTime[16];
    static float m_fCSFClanRate;
    static float m_fNEOClanRate;
    static bool m_bClanBattle;
    static bool m_bTempCSFClanRate;
    static bool m_bTempNEOClanRate;
    int m_iCamperCount;
    int m_iDamageAfterC4Setting;
    int m_iCSFAttackBeforeC4Setting;
    int m_iCSFAttackAfterC4Setting;
    int m_iC4SetCount;
    int m_iC4ExplodedCount;
    int m_iNEOAttackBeforeC4Setting;
    int m_iNEOAttackAfterC4Setting;
    int m_iC4DefusedCount;
    int m_iKillC4CarrierCount;
    int m_iFirstDamage;
    int m_iFirstSlowAttackDamage;
    int m_iFirstHitCount;
    int m_iFirstAttackCount;
    int m_iFirstKillCount;
    int m_iFirstFrontHitCount;
    int m_iFirstSlowAttackCount;
    bool m_bJoinedFirstAttack;
    static bool m_bFirstHit;
    static bool m_bFirstAttack;
    static bool m_bFirstKill;
    static bool m_bFirstFrontHit;
    static bool m_bFirstSlowAttack;
    static float m_fFirstHitTime;
    static float m_fLastAttackTime;
    CCRM();
    CCRM(const CCRM&);
    CCRM& operator=(CCRM&);
    bool AccessCheck(int) const;
    void _RoundEnd(int, int);
    static float P(float);
    float CalcRate(int, int) const;
    static void UpdateRate(int);
public:
    CCRM(CBasePlayer*);
    void Reset();
    static void ResetStatic();
    static void ResetAll();
    void Init(const CCRM::SInitData*);
    static void RoundEnd(int, int);
    bool GetBool(int) const;
    int GetInt(int) const;
    float GetFloat(int) const;
    void SetBool(int, bool);
    void SetInt(int, int);
    void SetFloat(int, float);
    void AddInt(int, int);
    void AddFloat(int, float);
    void CountUp(int);
    void Think();
    void TakeDamage(CBasePlayer*, int, bool);
    bool CheckRate();
    void Escape();
    void Send(int, bool);
    static void SendAll(int, bool);
    static int GetNumTempRatePlayer(int);
    static float GetTeamRate(int);
    static int GetDamageDirection(Vector, Vector, Vector);
    void TogglePrintData();
};

#endif  // NEO_CRM_H
