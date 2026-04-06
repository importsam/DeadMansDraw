
#include "Player.h"

bool Player::playCard(Card* card, Game& game) {
	

	if (isBust(card)) {
		std::cout << "BUST! " << _name << " loses all cards in play area." << std::endl;
		return true;
	}

	addToPlayArea(card);

	card->play(game, *this);
	return false;
}

void Player::addToPlayArea(Card* card) {
	playArea[card->type()].push_back(card);
}

void Player::addToBank(std::map<CardType, std::vector<Card*>>& playArea) {
	for (auto& pair : playArea) {
		for (Card* card : pair.second) {
			card->willAddToBank(game, *this);
			bank[pair.first].push_back(card);
		}
	}

	// move cards from play area to bank
	for (auto& pair : playArea) {
		for (Card* card : pair.second) {
			bank[pair.first].push_back(card);
		}
	}

	playArea.clear();
}

void Player::isBust(Card* card) const {
	return playArea.count(card->type()) > 0;
}

void Player::printPlayArea() {
	return;
}

void Player::clearPlayArea(std::map<CardType, std::vector<Card*>>& discardPile) {
	for (auto& pair : playArea) {
		for (Card* card : pair.second) {
			discardPile[card->type()].push_back(card);
		}
	}
	playArea.clear();
}

void Player::printBank() {
	cout << _name << "'s Bank:" << endl;
	for (Card* card : bank) {
		cout << card->str() << endl;
	}
}

std::string Player::getName() const {
	return _name;
}

int Player::getScore() const {
	int score = 0;
	for (auto& pair : bank) {
		for (Card* card : pair.second) {
			score += card->getPointValue();
		}
	}
	return score;
}

Card* Player::removeTopCardFromBank(CardType suit) {
	if (bank.count(suit) == 0) { return nullptr; }
	if (bank[suit].empty()) { bank.erase(suit) }

	Card* card = bank[suit].front();

	return card;

}

