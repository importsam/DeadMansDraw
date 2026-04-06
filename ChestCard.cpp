#include "ChestCard.h"

ChestCard::str() const {
	return "Chest(" + std::to_string(getPointValue()) + ")";
}

ChestCard::play(Game& game, Player& player) {
	// Discard the top card (i.e. the highest value) of any suit from
	//the other player’s Bank to the Discard Pile.


}