#include "ChestCard.h"

ChestCard::str() const {
	return "Chest(" + std::to_string(getPointValue()) + ")";
}

ChestCard::play(Game& game, Player& player) {
	std::cout << "        No immediate effect. If banked with a key, draw as many bonus cards from the Discard pile as you moved into your Bank." << std::endl;
}