#ifndef UNITSDEF_H
#define UNITSDEF_H

#include <QList>

enum UnitType{
    // structures
    ST_HQ,
    ST_FACTORY,
    ST_FACTORY_MODULE,//draw as factory 2
    ST_POWER_GEN,
    ST_POWER_MODULE,
    ST_RESOURCE_EXTRACTOR,
    ST_DEFENSE,
    ST_WALL,
    ST_WALLCORNER,                         //corner wall - no gun
    ST_BLASTDOOR,
//    ST_RESEARCH,
    ST_RESEARCH_MODULE,
    ST_REPAIR_FACILITY,
    ST_COMMAND_CONTROL,            //control centre for command droids
    ST_CYBORG_FACTORY,
    ST_VTOL_FACTORY,
    ST_LAB,
    ST_REARM_PAD,
    ST_MISSILE_SILO,
    ST_SAT_UPLINK,         //added for updates - AB 8/6/99
    ST_GATE,
    // droids
    DR_WEAPON,           ///< Weapon droid
    DR_SENSOR,           ///< Sensor droid
    DR_ECM,              ///< ECM droid
    DR_CONSTRUCT,        ///< Constructor droid
    DR_PERSON,           ///< person
    DR_CYBORG,           ///< cyborg-type thang
    DR_TRANSPORTER,      ///< guess what this is!
    DR_COMMAND,          ///< Command droid
    DR_REPAIR,           ///< Repair droid
    DR_DEFAULT,          ///< Default droid
    DR_CYBORG_CONSTRUCT, ///< cyborg constructor droid - new for update 28/5/99
    DR_CYBORG_REPAIR,    ///< cyborg repair droid - new for update 28/5/99
    DR_CYBORG_SUPER,     ///< cyborg repair droid - new for update 7/6/99
    DR_SUPERTRANSPORTER, ///< SuperTransport (MP)
    // features
    FT_HOVER,
    FT_TANK,
    FT_GEN_ARTE,
    FT_OIL_RESOURCE,
    FT_BOULDER,
    FT_VEHICLE,
    FT_BUILDING,
    FT_UNUSED,
    FT_LOS_OBJ,
    FT_OIL_DRUM,
    FT_TREE,
    FT_SKYSCRAPER
};

enum Equipment{
    // body
    BD_VIPER,
    // propulsion
    PR_WHEELED,
    PR_TRACKED,
    PR_LEGGED,
    PR_HOVER,
    PR_SKI,
    PR_LIFT,
    PR_PROPELLOR,
    PR_HALF_TRACKED,
    PR_JUMP,
    // turret
    EQ_TRUCK

};

typedef int UnitId;

struct Unit{
    UnitId id;
    int x, y, z;
    UnitType t;
    int health;
    QList<Equipment> eqs;
    UnitId lastAttacked;
};

#endif // UNITSDEF_H
