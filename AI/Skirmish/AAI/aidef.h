// -------------------------------------------------------------------------
// AAI
//
// A skirmish AI for the Spring engine.
// Copyright Alexander Seizinger
//
// Released under GPL license: see LICENSE.html for more information.
// -------------------------------------------------------------------------

#ifndef AAI_DEF_H
#define AAI_DEF_H

#include <string>

#include "System/float3.h"

#ifdef _MSC_VER
#pragma warning(disable: 4244 4018) // signed/unsigned and loss of precision...
#endif

// The following two helper functions implementations are in AAIBuildTable.cpp

void ReplaceExtension(const char *n, char *dst, int s, const char *ext);

#define AAI_VERSION aiexport_getVersion()
#define MAP_CACHE_VERSION "MAP_DATA_0_89"
#define MAP_LEARN_VERSION "MAP_LEARN_0_89"
#define MOD_LEARN_VERSION "MOD_LEARN_0_90"
#define CONTINENT_DATA_VERSION "MOVEMENT_MAPS_0_87"

#define AILOG_PATH "log/"
#define MAP_CACHE_PATH "cache/"
#define MAP_LEARN_PATH "learn/mod/"
#define MOD_LEARN_PATH "learn/mod/"


class AAIMetalSpot
{
public:
	AAIMetalSpot(float3 pos, float amount) {this->pos = pos; this->amount = amount; occupied = false; extractor = -1; extractor_def = -1;}
	AAIMetalSpot() {pos = ZeroVector; amount = 0; occupied = false; extractor = -1; extractor_def = -1;}

	float3 pos;
	bool occupied;
	int extractor;		// -1 if unocuppied
	int extractor_def;	// -1 if unocuppied
	float amount;
};

// movement types (for bitfield)
#define MOVE_TYPE_GROUND (unsigned int) 1
#define MOVE_TYPE_AIR (unsigned int) 2
#define MOVE_TYPE_HOVER (unsigned int) 4
#define MOVE_TYPE_SEA (unsigned int) 8
#define MOVE_TYPE_AMPHIB (unsigned int) 16
#define MOVE_TYPE_STATIC (unsigned int) 32
#define MOVE_TYPE_FLOATER (unsigned int) 64
#define MOVE_TYPE_UNDERWATER (unsigned int) 128
#define MOVE_TYPE_STATIC_LAND (unsigned int) 256
#define MOVE_TYPE_STATIC_WATER (unsigned int) 512


#define MOVE_TYPE_UNIT (unsigned int) 31	// used to filter out unit movement type (e.g. only MOVE_TYPE_SEA for sumarines (that also have MOVE_TYPE_UNDERWATER set))
#define MOVE_TYPE_CONTINENT_BOUND (unsigned int) 9


// unit types (for bitfield)
#define UNIT_TYPE_BUILDER (unsigned int) 1
#define UNIT_TYPE_FACTORY (unsigned int) 2
#define UNIT_TYPE_ASSISTER (unsigned int) 4
#define UNIT_TYPE_RESURRECTOR (unsigned int) 8
#define UNIT_TYPE_COMMANDER (unsigned int) 16
#define UNIT_TYPE_ASSAULT (unsigned int) 32
#define UNIT_TYPE_ANTI_AIR (unsigned int) 64
#define UNIT_TYPE_ARTY (unsigned int) 128
#define UNIT_TYPE_FIGHTER (unsigned int) 256
#define UNIT_TYPE_BOMBER (unsigned int) 512
#define UNIT_TYPE_GUNSHIP (unsigned int) 1024


enum UnitCategory {UNKNOWN, STATIONARY_DEF, STATIONARY_ARTY, STORAGE, STATIONARY_CONSTRUCTOR, AIR_BASE,
STATIONARY_RECON, STATIONARY_JAMMER, STATIONARY_LAUNCHER, DEFLECTION_SHIELD, POWER_PLANT, EXTRACTOR, METAL_MAKER,
COMMANDER, GROUND_ASSAULT, AIR_ASSAULT, HOVER_ASSAULT, SEA_ASSAULT, SUBMARINE_ASSAULT, GROUND_ARTY, SEA_ARTY, HOVER_ARTY,
SCOUT, MOBILE_TRANSPORT, MOBILE_JAMMER, MOBILE_LAUNCHER, MOBILE_CONSTRUCTOR};

enum UnitType {UNKNOWN_UNIT, ASSAULT_UNIT, ANTI_AIR_UNIT, BOMBER_UNIT, ARTY_UNIT};
enum UnitTask {UNIT_IDLE, UNIT_ATTACKING, DEFENDING, GUARDING, MOVING, BUILDING, SCOUTING, ASSISTING, RECLAIMING, HEADING_TO_RALLYPOINT, UNIT_KILLED, ENEMY_UNIT, BOMB_TARGET};
enum MapType {LAND_MAP, LAND_WATER_MAP, WATER_MAP, UNKNOWN_MAP};

class AAIGroup;
class AAIConstructor;

struct AAIUnit
{
	int unit_id;
	int def_id;
	AAIGroup *group;
	AAIConstructor *cons;
	UnitTask status;
	int last_order;
};

#endif

