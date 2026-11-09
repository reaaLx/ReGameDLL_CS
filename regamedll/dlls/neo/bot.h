/* Generated from Counter-Strike NEO DWARF (cs_i486.so). Declarations only.
   Member layout is not reconstructed. Stub bodies live in neo/bot.cpp.
   Clean-room: names and signatures from debug info, no code transcribed. */
#ifndef NEO_BOT_H
#define NEO_BOT_H

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "gamerules.h"
#include <list>
#include <vector>
#include <map>
#include <string>



struct CMtCsvParser {
protected:
    char m_str[256];
    int m_index;
public:
    CMtCsvParser();
    CMtCsvParser(const char*);
    ~CMtCsvParser();
    void SetStr(const char*);
    void SetIndex(int);
    int Parse(char*);
};

struct SMtTacGrenade {
public:
    int m_numGren;
    int m_ai;
        struct  {
    public:
        WeaponIdType wpn_id;
        char ent_target[64];
    } m_gren[4];
    void Clear();
    void ReadCsv(CMtCsvParser&);
    int IsUse(WeaponIdType) const;
};

struct SMtTacMoveTo {
public:
    enum _wpntype { WPN_PRIMARY = 0, WPN_SECONDARY = 1, WPN_KNIFE = 2, WPN_HE = 3, WPN_FB = 4, WPN_SG = 5 };
    enum _movetype { MOVE_RUN = 0, MOVE_WALK = 1, MOVE_CROUCH = 2 };
    int m_weapon_type;
    int m_move_type;
    char m_ent_target[64];
    void Clear();
    void ReadCsv(CMtCsvParser&);
};

struct SMtTacWait {
public:
    float m_time;
    int m_end_term;
    char m_look_ent[64];
    float m_toggle_time;
    char m_ent_enemy_touch[64];
    char m_ent_friend_touch[64];
    void Clear();
    void ReadCsv(CMtCsvParser&);
};

struct SMtTacInfo {
public:
    char m_tac[64];
    char m_ent[64];
    int m_team;
    int m_bot_id;
    SMtTacGrenade m_greninfo;
    SMtTacMoveTo m_moveinfo;
    SMtTacWait m_waitinfo;
    void Clear();
    void ReadCsv(CMtCsvParser&);
    int GetTeam() const;
    int GetBotId() const;
    const char* GetTacName() const;
    const char* GetEntName() const;
    const char* GetNextEntName() const;
    int GetNumGrenades(WeaponIdType) const;
};

struct CMtGodEyeInfo {
private:
    CBasePlayer* m_player;
    float m_timestamp;
public:
    CMtGodEyeInfo();
    ~CMtGodEyeInfo();
    void Clear();
    void SetInfo(CBasePlayer*, float);
    CBasePlayer* GetPlayer() const;
    const float GetTimestamp() const;
};

struct CMtGodEyeMan {
private:
    std::list<CMtGodEyeInfo*,std::allocator<CMtGodEyeInfo*> > m_ter_lst;
    std::list<CMtGodEyeInfo*,std::allocator<CMtGodEyeInfo*> > m_ct_lst;
    std::list<CMtGodEyeInfo*,std::allocator<CMtGodEyeInfo*> > m_empty_lst;
    CMtGodEyeInfo m_info[32];
public:
    CMtGodEyeMan();
    ~CMtGodEyeMan();
    void Init();
    void Register(CBasePlayer*);
    void Update();
    CBasePlayer* GetTarget(TeamName, int);
private:
    void RegisterSub(CBasePlayer*, std::list<CMtGodEyeInfo*,std::allocator<CMtGodEyeInfo*> >&);
    void UpdateSub(std::list<CMtGodEyeInfo*,std::allocator<CMtGodEyeInfo*> >&);
    CBasePlayer* GetTargetSub(std::list<CMtGodEyeInfo*,std::allocator<CMtGodEyeInfo*> >&, int);
};

struct SMtSelectTac {
public:
    int m_numTacs;
        struct  {
    public:
        char name[64];
        int team;
        int per;
        int eco;
    } m_tacs[16];
    void Clear();
    void Register(const char*, int, int);
    int LoadCsvFile(const char*);
    const char* SelectTactics(int, int) const;
    int GetNumTacs() const;
    const char* GetName(int) const;
    int GetPer(int) const;
    int IsEco(int) const;
};

struct CMtTacInfoMan {
protected:
    SMtSelectTac m_seltac;
    int m_numtacinfo;
    SMtTacInfo m_tacinfo[600];
    std::list<SMtTacInfo*,std::allocator<SMtTacInfo*> > m_tacinfo_list;
public:
    CMtTacInfoMan();
    ~CMtTacInfoMan();
    int LoadTacInfo(const char*);
    int LoadSelTac(const char*);
    const SMtTacInfo* GetTacInfo(int, int, const char*, const char*) const;
    const SMtTacInfo* GetNextTacInfo(const SMtTacInfo*) const;
    const char* SelectTactics(int, int) const;
    int GetNumGrenades(int, int, const char*, WeaponIdType) const;
protected:
    void Clear();
};

struct CMtBotTacticalBuy {
private:
    static const int* m_plan_tbl;
    static const int* m_vest_tbl;
    static const int* m_helm_tbl;
    static const int* m_defuser_tbl;
    static const int* m_csf_weapon_tbl;
    static const int* m_neo_weapon_tbl;
    int m_CFSPlan;
    int m_NEOPlan;
    int m_rank;
    bool m_CSFSniper;
    bool m_NEOSniper;
public:
    CMtBotTacticalBuy();
    ~CMtBotTacticalBuy();
    void Clear();
    void SelectPlan(int, int, int);
    int GetPlan(int) const;
    int GetRank() const;
    int IsSniperRifle(int) const;
    void SelectEquipmentsRank(int, int, int);
    int GetBuyWeaponId(int);
    bool IsBuyVest() const;
    bool IsBuyHelm() const;
    bool IsBuyDefuser() const;
};

struct CTacticalZone : public CBaseTrigger {
private:
    string_t m_iszName;
public:
    virtual void KeyValue(KeyValueData_s*);
    virtual void Spawn();
    void TacticalTouch(CBaseEntity*);
    void SetName(int);
};

struct TacticalBuyState : public BotState {
private:
    bool m_buyVest;
    bool m_buyHelm;
    bool m_buyGrenade;
    bool m_buyDefuseKit;
    int m_buyWeaponId;
    bool m_isInitialDelay;
    bool m_doneBuying;
public:
    virtual void OnEnter(CCSBot*);
    virtual void OnUpdate(CCSBot*);
    virtual void OnExit(CCSBot*);
    virtual const char* GetName() const;
};

struct TacticalMoveToState : public BotState {
private:
    char m_dst_ent[64];
    Vector m_goalPosition;
    int m_weapon_type;
    int m_move_type;
public:
    virtual void OnEnter(CCSBot*);
    virtual void OnUpdate(CCSBot*);
    virtual void OnExit(CCSBot*);
    virtual const char* GetName() const;
    int InitTactics(const SMtTacInfo*);
    void Equip(CCSBot*);
};

struct TacticalWaitState : public BotState {
private:
    char m_look_ent[64];
    int m_weapon_type;
    float m_time;
    int m_end_term;
    float m_toggle_time;
    char m_ent_enemy_touch[64];
    char m_ent_friend_touch[64];
    Vector m_look_at;
    float m_StartTime;
public:
    virtual void OnEnter(CCSBot*);
    virtual void OnUpdate(CCSBot*);
    virtual void OnExit(CCSBot*);
    virtual const char* GetName() const;
    int InitTactics(const SMtTacInfo*);
    void Equip(CCSBot*);
};

#endif  // NEO_BOT_H
