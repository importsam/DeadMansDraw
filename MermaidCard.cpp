#include "MermaidCard.h"

MermaidCard::str() const {
	return "Cannon(" + std::to_string(getPointValue()) + ")";
}

MermaidCard::play(Game& game, Player& player) {
	// Discard the top card (i.e. the highest value) of any suit from
	//the other player’s Bank to the Discard Pile.


}