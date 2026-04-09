
#include "Player.h"
#include "Game.h"
#include <iostream>


Player::Player() {
	std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
	_name = names[rand() % 10];
}

// Plays a card into the play area and returns whether the player has busted as true or false.
bool Player::playCard(Card* card, Game& game) {
	
	// check if the card busts the player
	if (isBust(card)) {
		return true;
	}
	// add to the play area
	addToPlayArea(card);
	// perform the card's special ability
	card->play(game, *this);
	return false;
}

void Player::addToPlayArea(Card* card) {
	playArea[card->type()].push_back(card);
	// sort the play area as some abilities require the highest point value for a suit.
	sortPlayArea();
}

void Player::sortBank() {
	for (auto& pair : bank) {
		std::sort(pair.second.begin(), pair.second.end(), [](Card* a, Card* b) {
			return a->getPointValue() > b->getPointValue();
		});
	}
}

void Player::sortPlayArea() {
	for (auto& pair : playArea) {
		std::sort(pair.second.begin(), pair.second.end(), [](Card* a, Card* b) {
			return a->getPointValue() > b->getPointValue();
		});
	}
}

void Player::addToBank(Game& game) {
	/*
	This will move the cards from the play area to the bank. 
	It will need to check if there is a chest and key in the play area.
	If so we will add as many bonus cards to the bank as there were in the play area.
	*/

	// Add everything in the play area to the bank
	for (auto& pair : playArea) {
		for (Card* card : pair.second) {
			bank[pair.first].push_back(card);
		}
	}

	int bonusCards = 0;

	// Check for chest and key in the play area
	// if it's there, we count how many cards are in the play area before clearing
	if (playArea.count(CardType::Chest) > 0 && playArea.count(CardType::Key) > 0) {
		for (auto& pair : playArea) {
			bonusCards += pair.second.size();
		}
		playArea.clear();
	}
	else {
		sortBank();
		playArea.clear();
		return;
	}

	// We need to store the bonus cards somewhere so we can print them out.
	CardCollection bonusCardList;

	// now if there's a chest and key, move bonus cards from the discard pile to the bank
	for (int i = 0; i < bonusCards; i++) {
		Card* bonusCard = game.drawFromDiscardPile();
		if (bonusCard == nullptr) {
			break;
		}
		bonusCardList.push_back(bonusCard);
		bank[bonusCard->type()].push_back(bonusCard);
	}
	// sort the bank, some abilities need the highest point value for a suit to be easily accessible
	sortBank();

	if (bonusCardList.empty()) {
		std::cout << "Discard pile empty, chest and key had no effect." << std::endl;
		return;
	}

	std::cout << "Chest and Key activated. Added ";
	for (Card* card : bonusCardList) {
		std::cout << card->str() << ", ";
	}
	std::cout << "to your bank." << std::endl; 
}

// The user has bust if there are two of the same CardType in the play area.
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

void Player::printBank() const {
	std::cout << _name << "'s Bank:" << std::endl;
	for (auto& pair : bank) {
		// sort the cards for this suit for the sake of printing in order of point value
		CardCollection sortedCards = pair.second;
		std::sort(sortedCards.begin(), sortedCards.end(), [](Card* a, Card* b) {
			return a->getPointValue() > b->getPointValue();
		});

		std::cout << "\t";

		for (Card* card : sortedCards) {
			std::cout << card->str() << " ";
		}

		std::cout << std::endl;
		
	}
	std::cout << "| Score: " << getScore() << std::endl;
}

std::string Player::getName() const {
	return _name;
}

int Player::getScore() const {
	int score = 0;
	for (auto& pair : bank) {
		int maxPointValue = 0;
		for (Card* card : pair.second) {
			maxPointValue = std::max(maxPointValue, card->getPointValue());
		}
		score += maxPointValue;
	}
	return score;
}

Card* Player::removeTopCardFromBank(CardType suit) {
	if (bank.count(suit) == 0) { 
		return nullptr; 
	}
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

Player::~Player() {
	for (auto& pair : bank) {
		for (Card* card : pair.second) {
			delete card;
		}
	}

	for (auto& pair : playArea) {
		for (Card* card : pair.second) {
			delete card;
		}
	}
}
