
#include "Player.h"

Player::playCard(Card* card, Game& game) {
	playArea.push_back(card);

	if (isBust(card)) {
		std::cout << "BUST! " << _name << " loses all cards in play area." << std::endl;
		return true;
	}

	card->play(game, *this);
	return false;
}

Player::isBust(Card* card) {
	return playArea.count(card->type()) > 0;
}

Player::printPlayArea() {
	cout << _name << "'s Play Area:" << endl;
	for (auto& pair : playArea) {
		for
	}
}

Player::getScore() {
	int score = 0;
	for (auto& pair : playArea) {
		for (std::vector<Card*> cards : pair.second) {
			score += cards.front()->getPointValue();
		}
	}
	return score;
}