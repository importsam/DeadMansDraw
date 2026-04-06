#include "MapCard.h"

std::string MapCard::str() const {
	return "Map(" + std::to_string(getPointValue()) + ")";
}

void MapCard::play(Game& game, Player& player) {
	CardCollection cards;

	for (int i = 0; i < 3; i++) {
		Card* card = game.drawCard();
		if (card == nullptr) { break; }
		cards.push_back(card);
	}

	if (cards.empty()) {
		std::cout << "\t\tDiscard pile empty. Continue playing." << std::endl;
	}

	cout << "\t\tDraw 3 cards from the discard and pick one to add to the play area:" << endl;

	int choice;
	cout << "\t\tWhich card do you pick? ";
	cin >> choice;

	i = 1;
	for (Card* card : cards) {
		cout << "        (" << i << ") " << card->str() << endl;
		i++
	}

	Card* chosen = drawn[choice - 1];
	bool bustStatus = player.playCard(chosen, game);

	if (bustStatus) {
		game.bustPlayer(player);
	}

	for (int i = 0; i < drawn.size(); i++) {
		if (drawn[i] != chosen) {
			game.addToDiscardPile(drawn[i]);
		}
	}

}