#include "SwordCard.h"

SwordCard::str() const {
	return "Sword(" + std::to_string(getPointValue()) + ")";
}

SwordCard::play(Game& game, Player& player) {
	// Discard the top card (i.e. the highest value) of any suit from
	//the other player’s Bank to the Discard Pile.


}