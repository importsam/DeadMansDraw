#include "OracleCard.h"

OracleCard::str() const {
	return "Oracle(" + std::to_string(getPointValue()) + ")";
}

OracleCard::play(Game& game, Player& player) {
	// Discard the top card (i.e. the highest value) of any suit from
	//the other player’s Bank to the Discard Pile.


}