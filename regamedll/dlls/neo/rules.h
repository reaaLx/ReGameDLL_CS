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

#endif  // NEO_RULES_H
