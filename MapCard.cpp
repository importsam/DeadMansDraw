#include "MapCard.h"
#include <iostream>
#include "Game.h"
#include "Player.h"


std::string MapCard::str() const {
	return "Map(" + std::to_string(getPointValue()) + ")";
}

void MapCard::play(Game& game, Player& player) {
	CardCollection cards;

	for (int i = 0; i < 3; i++) {
		Card* card = game.drawFromDiscardPile();
		if (card == nullptr) { break; }
		cards.push_back(card);
	}

	if (cards.empty()) {
		std::cout << "\tDiscard pile empty. Continue playing." << std::endl;
		return;
	}


	std::cout << "\tDraw 3 cards from the discard and pick one to add to the play area:" << std::endl;

	int i = 1;
	for (Card* card : cards) {
		std::cout << "        (" << i << ") " << card->str() << std::endl;
		i++;
	}

	int choice;
	std::cout << "\tWhich card do you pick? ";
	std::cin >> choice;

	Card* chosen = cards[static_cast<size_t>(choice - 1)];
	bool bustStatus = player.playCard(chosen, game);

	if (bustStatus) {
		game.bustPlayer(player);
	}

	for (Card* card : cards) {
		if (card != chosen) {
			game.addToDiscardPile(card);
		}
	}

}