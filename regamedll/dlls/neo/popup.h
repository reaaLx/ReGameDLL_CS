/* Generated from Counter-Strike NEO DWARF (cs_i486.so). Declarations only.
   Member layout is not reconstructed. Stub bodies live in neo/popup.cpp.
   Clean-room: names and signatures from debug info, no code transcribed. */
#ifndef NEO_POPUP_H
#define NEO_POPUP_H

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "gamerules.h"
#include <list>
#include <vector>
#include <map>
#include <string>



struct PopupCustomData {
public:
    int number;
    int flags;
    char data[20][256];
};

struct CPopup {
public:
    enum POPUP { INFOWINDOW_DUMMY = 0, INFOWINDOW_MOVE = 1, INFOWINDOW_ANGLE = 2, INFOWINDOW_ATTACK = 3, INFOWINDOW_RELOAD = 4, INFOWINDOW_SWITCHWEAPON = 5, INFOWINDOW_CHANGEWEAPON = 6, INFOWINDOW_UPLADDER = 7, INFOWINDOW_DOWNLADDER = 8, INFOWINDOW_DUCKWALK = 9, INFOWINDOW_WALK = 10, INFOWINDOW_JUMP = 11, INFOWINDOW_BURST = 12, INFOWINDOW_SCOPE = 13, INFOWINDOW_SILENCER = 14, INFOWINDOW_SWITCHGRENADE = 15, INFOWINDOW_THROWGRENADE = 16, INFOWINDOW_SETC4 = 17, INFOWINDOW_DEFUSEC4 = 18, INFOWINDOW_BUYWEAPON = 19, ASSISTPOP_HAVETHEBOMB = 20, ASSISTPOP_SETC4 = 21, ASSISTPOP_SETC4COMPLETEDFORCSF = 22, ASSISTPOP_SETC4COMPLETEDFORNEO = 23, ASSISTPOP_DEFUSEC4 = 24, ASSISTPOP_DROPC4 = 25, ASSISTPOP_GETC4 = 26, INFOWINDOW_AUTOBALANCE1 = 27, INFOWINDOW_AUTOBALANCE2 = 28, INFOWINDOW_SETRIVAL = 29, INFOWINDOW_RESETRIVAL = 30, INFOWINDOW_MEMBERCHANGE = 31, INFOWINDOW_ESCAPE = 32, NUM_POPUP = 33 };
    struct SShowPopupData {
    public:
        bool bShowNow;
        bool bSendDelete;
        int iCount;
        int iCountThisRound;
        int iRoundCount;
    };
private:
    static const char* _SCENENAME[33];
    static const char* _TARGETNAME[33];
    int m_iDisable;
    CBasePlayer* m_pPlayer;
    Vector m_angles;
    CBasePlayerItem* m_pActiveItem;
    int m_iClip;
    bool m_bCreatePopupByEntity;
    bool m_bAssistPop;
    float m_fNoReloadStartTime;
    float m_fNoUpLadderStartTime;
    float m_fNoDownLadderStartTime;
    float m_fNoDuckWalkStartTime;
    float m_fNoWalkStartTime;
    float m_fNoJumpStartTime;
    int m_iHaveGrenadeCount;
    int m_iSwitchGrenadeCount;
    int m_iReloadCount;
    CPopup::SShowPopupData m_ShowPopup[33];
    char m_scenename[256];
    CPopup();
    CPopup(const CPopup&);
    CPopup& operator=(CPopup&);
    bool AccessCheck() const;
    int GetPopupNumber(const char*) const;
    void ResetTime(int);
    void _RoundEnd();
public:
    CPopup(CBasePlayer*);
    void Reset();
    static void ResetAll();
    static void RoundEnd();
    void Think();
    void HandleSignals(int, int);
    void HaveGrenadeEvent();
    void SwitchGrenadeEvent();
    void ReloadEvent();
    void ShowPopupEvent(const char*);
    void EndPopupEvent(const char*);
    void SendCreateMessage(int, float, float, int, const char*, int, int, const char*, const PopupCustomData*, bool);
    static void SendCreateMessageAll(int, float, float, int, const char*, int, int, const char*, const PopupCustomData*, bool);
    void SendDeleteMessage(int, int, const char*, bool);
    static void SendDeleteMessageAll(int, int, const char*, bool);
    bool CanSwitchWeapon();
    bool CanSwitchGrenade();
    static bool HaveBurst(int);
    static bool HaveScope(int);
    static bool HaveSilencer(int);
    void EnableAssistPop();
    void DisableAssistPop();
};

struct CNEO2Popup : public CBaseEntity {
private:
    static const char* COLUMN_NAME[20];
    float m_fLifeTime;
    float m_fMinTime;
    int m_iStyle;
    string_t m_iszSceneName;
    int m_x;
    int m_y;
    string_t m_iszSound;
    PopupCustomData m_custom[8];
    float m_fDelay;
    bool m_bUsed;
public:
    static TYPEDESCRIPTION m_SaveData[8];
    virtual void KeyValue(KeyValueData_s*);
    virtual void Spawn();
    virtual void Restart();
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
    virtual void Think();
    virtual int Save(CSave&);
    virtual int Restore(CRestore&);
    void EndPopupEvent(const char*);
};

struct CNEO2PopupDelete : public CBaseEntity {
private:
    int m_iStyle;
    string_t m_iszSceneName;
    int m_iCheckMinTime;
public:
    virtual void KeyValue(KeyValueData_s*);
    virtual void Use(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
};

struct CNEO2BeginnerModeEntity : public CBaseTrigger {
private:
    Vector m_vecAnglesMin;
    Vector m_vecAnglesMax;
protected:
    int m_flSignal;
public:
    virtual void KeyValue(KeyValueData_s*);
    virtual void Spawn();
    virtual void Touch(CBaseEntity*);
};

#endif  // NEO_POPUP_H
