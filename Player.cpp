
#include "Player.h"
#include <iostream>

Player::Player() {
	std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
	_name = names[rand() % 10];
}

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

void Player::addToBank(Game& game) {
	for (auto& pair : playArea) {
		for (Card* card : pair.second) {
			card->willAddToBank(game, *this);
			bank[pair.first].push_back(card);
		}
	}

	playArea.clear();
}

bool Player::isBust(Card* card) const {
	return playArea.count(card->type()) > 0;
}

void Player::printPlayArea() {
	std::cout << _name << "'s Play Area:" << std::endl;
	for (auto& pair : playArea) {
		for (Card* card : pair.second) {
			std::cout << "        " << card->str() << std::endl;
		}
	}
	std::cout << std::endl;
}

void Player::clearPlayArea(CardCollection& discardPile) {
	for (auto& pair : playArea) {
		for (Card* card : pair.second) {
			discardPile.push_back(card);
		}
	}
	playArea.clear();
}

void Player::printBank() {
	std::cout << _name << "'s Bank:" << std::endl;
	for (auto& pair : bank) {
		std::cout << pair.second.front()->str() << std::endl;
	}
	std::cout << "| Score: " << getScore() << std::endl;
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
	if (bank[suit].empty()) { 
		bank.erase(suit); 
		return nullptr; 
	}

	Card* card = bank[suit].front();
	bank[suit].erase(bank[suit].begin());
	if (bank[suit].empty()) {
		bank.erase(suit);
	}

	return card;

}

