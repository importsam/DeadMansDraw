#include "HookCard.h"

HookCard::str() const {
	return "Hook(" + std::to_string(getPointValue()) + ")";
}

HookCard::play(Game& game, Player& player) {
	// Discard the top card (i.e. the highest value) of any suit from
	//the other player’s Bank to the Discard Pile.


}