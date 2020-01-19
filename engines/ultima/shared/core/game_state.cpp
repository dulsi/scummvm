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

#include "ultima/shared/early/ultima_early.h"
#include "ultima/shared/early/game_base.h"
#include "ultima/shared/core/game_state.h"
#include "ultima/ultima1/game.h"
#include "ultima/ultima1/map/map.h"

namespace Ultima {
namespace Shared {

GameState::GameState(Game *game) : _videoMode(EGA), _dungeonExitHitPoints(0), _randomSeed(0) {
	_gameId = g_vm->getGameId();
	setupParty();

	switch (_gameId) {
	case GAME_ULTIMA1:
		_map = new Ultima1::Map::Ultima1Map(static_cast<Ultima1::Ultima1Game *>(game));

		// Load the default overworld map
		_map->load(Ultima1::Map::MAPID_OVERWORLD);
		//_map->setPosition(Point(49, 40));
		_map->setPosition(Point(62, 49));
		break;
	default:
		error("Unspported game");
		break;
	}
}

void GameState::setupParty() {
	switch (_gameId) {
	case GAME_ULTIMA1:
		// Setup characters array
		_characters.resize(1);
		_currentCharacter = &_characters.front();
		_currentCharacter->_armor.resize(5);
		_currentCharacter->_weapons.resize(15);
		_currentCharacter->_spells.resize(10);
		break;
	default:
		break;
	}
}

GameState::~GameState() {
	delete _map;
}

bool GameState::isPartyDead() const {
	for (uint idx = 0; idx < _characters.size(); ++idx) {
		if (_characters[idx]._hitPoints > 0)
			return false;
	}

	return true;
}

bool GameState::isPartyFoodless() const {
	for (uint idx = 0; idx < _characters.size(); ++idx) {
		if (_characters[idx]._food > 0)
			return false;
	}

	return true;
}

} // End of namespace Shared
} // End of namespace Ultima