#include "KeyCard.h"
#include <iostream>
#include "Game.h"
#include "Player.h"

std::string KeyCard::str() const {
	return "Key(" + std::to_string(getPointValue()) + ")";
}

void KeyCard::play(Game& game, Player& player) {
	std::cout << "\tNo immediate effect. If banked with a chest, draw as many bonus cards from the Discard pile as you moved into your Bank." << std::endl;
}

void KeyCard::willAddToBank(Game& game, Player& player) {}

