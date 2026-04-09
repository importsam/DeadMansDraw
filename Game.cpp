#include "Game.h"
#include "Player.h"
#include "Card.h"
#include <iostream>
#include "CannonCard.h"
#include "ChestCard.h"
#include "KeyCard.h"
#include "SwordCard.h"
#include "HookCard.h"
#include "OracleCard.h"
#include "MapCard.h"
#include "KrakenCard.h"
#include "MermaidCard.h"
#include <algorithm>
#include <limits>
#include <random> 
#include <utility> 


Game::Game() {
	round = 1;
	turn = 1;
	busted = false;
	player1 = Player();
	player2 = Player();
	currentPlayer = &player1;
	otherPlayer = &player2; // non-playing player
	initDeck();
	std::cout << GAME_TITLE << std::endl;
	std::cout << "Starting Dead Man's Draw++!" << std::endl;
	gameStart();
}

// Continuously take turns until the deck is empty.
void Game::gameStart() {
	while (!deckEmpty()) {
		takeTurn();
	}
	gameEnd();
}

void Game::gameEnd() const {
	std::cout << "--- Game Over! ---" << std::endl;
	player1.printBank();
	std::cout << player1.getScore() << std::endl;
	
	player2.printBank();
	std::cout << player2.getScore() << std::endl;

	if (player1.getScore() > player2.getScore()) {
		std::cout << player1.getName() << " wins!" << std::endl;
	}
	else if (player2.getScore() > player1.getScore()) {
		std::cout << player2.getName() << " wins!" << std::endl;
	}
	else {
		std::cout << "It's a tie!" << std::endl;
	}
}

void Game::takeTurn() {

	busted = false;
	turnInitPrint();

	Card* card = drawCard();
	if (card == nullptr) {
		return;
	}
	cardDrawMessage(card);

	// check if the current player is busted after playing the first card they draw
	bool bustStatus = currentPlayer->playCard(card, *this);

	// while they aren't busted, they can keep drawing.
	while (!bustStatus && !busted) {
		currentPlayer->printPlayArea();

		std::string response;

		std::cout << "Draw again? (y/n): ";
		std::cin >> response;

		// doesnt handle invalid input
		if (response == "y") {
			card = drawCard();
			if (card == nullptr) {
				break;
			}
			cardDrawMessage(card);
			bustStatus = currentPlayer->playCard(card, *this);
		}
		else if (response == "n") break;

	}

	// if busted, we bust them and move all their cards to the discard pile
	if (bustStatus || busted) {
		bustPlayer(*currentPlayer);
	}
	else {
		currentPlayer->addToBank(*this);
	}

	// switch players for next turn
	std::swap(currentPlayer, otherPlayer);
	turn++;
	if (turn % 2 == 1) { round++; }
}

Card* Game::drawCard() {
	if (deck.empty()) { return nullptr; }
	Card* card = deck.back();
	deck.pop_back();
	return card;
}

void Game::cardDrawMessage(Card* card) {
	std::cout << currentPlayer->getName() << " draws a " << card->str() << std::endl;
	//std::cout << "        " << card->specialAbility() << std::endl;
}

void Game::turnInitPrint() {
	std::cout << "--- Round " << round << ", Turn " << turn << " ---" << std::endl;
	std::cout << currentPlayer->getName() << "'s turn." << std::endl;
	currentPlayer->printBank();
}

void Game::initDeck() {
	int cardValues[] = { 2, 3, 4, 5, 6, 7 };
	int mermaidValues[] = { 4, 5, 6, 7, 8, 9 };

	for (int val : cardValues) {
		deck.push_back(new CannonCard(val));
		deck.push_back(new ChestCard(val));
		deck.push_back(new KeyCard(val));
		deck.push_back(new SwordCard(val));
		deck.push_back(new HookCard(val));
		deck.push_back(new OracleCard(val));
		deck.push_back(new MapCard(val));
	}

	for (int val : mermaidValues) {
		deck.push_back(new MermaidCard(val));
	}

	shuffleDeck(deck);
}

void Game::shuffleDeck(CardCollection& cards) {
	CardCollection shuffleDeck{ cards.begin(), cards.end() };
	std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
	std::copy(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());
}

Card* Game::drawFromDiscardPile() {
	if (discardPile.empty()) {
		return nullptr;
	}

	Card* card = discardPile.back();
	discardPile.pop_back();
	return card;
}

int Game::getValidChoice(int min, int max) {
	int choice;
	while (true) {
		std::cin >> choice;
		if (choice >= min && choice <= max) {
			return choice;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\tInvalid input. Try again: ";
	}
}

void Game::bustPlayer(Player& player) {
	busted = true;
	std::cout << "BUST! " << player.getName() << " loses all cards in play area." << std::endl;
	player.clearPlayArea(discardPile);
}

void Game::addToDiscardPile(Card* card) {
	discardPile.push_back(card);
	return;
}

void Game::setBust() {
	busted = true;
	return;
}

Game::~Game() {
	for (Card* card : deck) {
		delete card;
	}

	deck.clear();
	
	for (Card* card : discardPile) {
		delete card;
	}

	discardPile.clear();


}