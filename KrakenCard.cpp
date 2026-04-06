#include "KrakenCard.h"

KrakenCard::str() const {
	return "Kraken(" + std::to_string(getPointValue()) + ")";
}

KrakenCard::play(Game& game, Player& player) {
	// Discard the top card (i.e. the highest value) of any suit from
	//the other player’s Bank to the Discard Pile.


}