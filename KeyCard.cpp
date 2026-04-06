#include "KeyCard.h"

KeyCard::str() const {
	return "Key(" + std::to_string(getPointValue()) + ")";
}

KeyCard::play(Game& game, Player& player) {
	// Discard the top card (i.e. the highest value) of any suit from
	//the other player’s Bank to the Discard Pile.


}