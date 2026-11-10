/* Generated from Counter-Strike NEO DWARF (cs_i486.so). Declarations only.
   Member layout is not reconstructed. Stub bodies live in neo/rules.cpp.
   Clean-room: names and signatures from debug info, no code transcribed. */
#ifndef NEO_RULES_H
#define NEO_RULES_H

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "gamerules.h"
#include <list>
#include <vector>
#include <map>
#include <string>



struct CBeginnerRule : public CBaseEntity {
private:
    bool m_bCreatePopup;
public:
    virtual void KeyValue(KeyValueData_s*);
    virtual void Spawn();
    void BeginUse(CBaseEntity*, CBaseEntity*, USE_TYPE, float);
};

struct CCamperRules {
private:
    BOOL m_bAble;
    int m_iFlag;
    Vector m_sCoord[32][5];
    float m_fCamp[32][4];
    int m_iCampLevel[32][4];
    float m_fNextThink;
    int m_iPrevCampType[32];
    float m_fNoCampTime[32][4];
public:
    void Initialize(CBasePlayer*);
    void Enable();
    void Disable();
    void Start(int);
    void End(int);
    void Think();
};

#endif  // NEO_RULES_H
