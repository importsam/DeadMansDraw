#include "Game.h"
#include "Player.h"
#include "Card.h"

Game::Game() {
	round = 1;
	turn = 1;
	player1 = Player();
	player2 = Player();
	currentPlayer = &player1;
	otherPlayer = &player2; // non-playing player
	initDeck();
	std::cout << GAME_TITLE << std::endl;
	printf("Starting Dead Man's Draw++\n");
}

void Game::takeTurn() {
	turnInitPrint();
	Card* card = drawCard();
	cardDrawMessage(card);

	bool bustStatus = currentPlayer->playCard(card, *this);

	while (!bustStatus) {
		currentPlayer->printPlayArea();

		std::string response;

		std::cout << "Draw again? (y/n): ";
		std::cin >> response;

		// doesnt handle invalid input
		if (response == "y") {
			card = drawCard();
			cardDrawMessage(card);
			bustStatus = currentPlayer->playCard(card, *this);
		}
		else if (response == "n") break;

	}

	if (bustStatus) {
		currentPlayer->clearPlayArea(discardPile);
	}
	else {
		currentPlayer->addToBank(*this);
	}

	std::swap(currentPlayer, otherPlayer);
	turn++;
	if (turn % 2 == 1) { round++; }
}

Card* Game::drawCard() {
	// what if deck empty 

	Card* card = deck.back();
	deck.pop_back();
	return card;
}

void Game::cardDrawMessage(Card* card) {
	std::cout << currentPlayer->getName() << " Draws a " << card->str() << std::endl;
	//std::cout << "        " << card->specialAbility() << std::endl;
}

void Game::turnInitPrint() {
	std::cout << currentPlayer->getName() << "'s turn." << std::endl;
	std::cout << currentPlayer->getName() << "'s Bank:" << std::endl << currentPlayer->printBank() << std::endl;
	currentPlayer->printBank();
}

void Game::initDeck() {
	int cardValues[] = { 2, 3, 4, 5, 6, 7 };
	int mermaidValues[] = { 4, 5, 6, 7, 8, 9 };

	for (int val : cardValues) {
		deck.push_back(new Cannon(val));
		deck.push_back(new Chest(val));
		deck.push_back(new Key(val));
		deck.push_back(new Sword(val));
		deck.push_back(new Hook(val));
		deck.push_back(new Oracle(val));
		deck.push_back(new Map(val));
	}

	for (int val : mermaidValues) {
		deck.push_back(new Mermaid(val));
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

void Game::bustPlayer(Player& player) {
	std::cout << "BUST! " << player.getName() << "loses all cards in play area." << std::endl;
	player.clearPlayArea(discardPile);
}

Game::~Game() {}