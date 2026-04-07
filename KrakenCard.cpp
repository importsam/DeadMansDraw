#include "KrakenCard.h"
#include <iostream>
#include "Game.h"
#include "Player.h"

std::string KrakenCard::str() const {
	return "Kraken(" + std::to_string(getPointValue()) + ")";
}

void KrakenCard::play(Game& game, Player& player) {
	std::cout << "\tDraw 3 cards from the deck and play each:" << std::endl;
	
	for (int i = 0; i < 3; i++) {
		Card* card = game.drawCard();
		if (card == nullptr) {
			std::cout << "\tDeck is empty. No more cards to draw." << std::endl;
			return;
		}
		std::cout << player.getName() << " draws a " << card->str() << std::endl;

		bool bustStatus = player.playCard(card, game);
		if (bustStatus) {
			game.bustPlayer(player);
			return;
		}

	}

}