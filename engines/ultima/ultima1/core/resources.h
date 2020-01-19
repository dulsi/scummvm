/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef ULTIMA_ULTIMA1_CORE_RESOURCES_H
#define ULTIMA_ULTIMA1_CORE_RESOURCES_H

#include "ultima/shared/engine/resources.h"

namespace Ultima {
namespace Ultima1 {

#define LOCATION_COUNT 84

class GameResources : public Shared::LocalResourceFile {
protected:
	/**
	 * Synchronize resource data
	 */
	virtual void synchronize();
public:
	const char *STATUS_TEXT[4];
	const char *DIRECTION_NAMES[4];
	const char *DUNGEON_MOVES[4];
	const char *LOCATION_NAMES[LOCATION_COUNT];
	byte LOCATION_X[LOCATION_COUNT];
	byte LOCATION_Y[LOCATION_COUNT];
	int LOCATION_PEOPLE[150][4];
	byte DUNGEON_DRAW_DATA[1964];
	const char *DUNGEON_ITEM_NAMES[2];
	const char *BLOCKED;
	const char *ENTER_QUESTION;
	const char *ENTERING;
	const char *THE_CITY_OF;
	const char *DUNGEON_LEVEL;
	const char *PASS;
	const char *HUH;
	const char *ATTACKED_BY;
	const char *ARMOR_DESTROYED;
	const char *GREMLIN_STOLE;
	const char *MENTAL_ATTACK;
	const char *MISSED;
public:
	GameResources();
	GameResources(Shared::Resources *resManager);
};

} // End of namespace Ultima1
} // End of namespace Ultima

#endif