#include "KeyCard.h"

std::string KeyCard::str() const {
	return "Key(" + std::to_string(getPointValue()) + ")";
}

void KeyCard::play(Game& game, Player& player) {
	std::cout << "        No immediate effect. If banked with a chest, draw as many bonus cards from the Discard pile as you moved into your Bank." << std::endl;
}

void KeyCard::willAddToBank(Game& game, Player& player) {
	// check if chest is in play area
	auto& playArea = player.getPlayArea();
	int numToDraw = 0;
	if (playArea.count(CardType::Chest) > 0) {
		numToDraw = playArea.size();
	}
	for (int i = 0; i < numToDraw; i++) {
		Card* card = game.drawFromDiscardPile();
		player.addToPlayArea(card);
	}
}

