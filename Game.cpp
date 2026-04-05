#include "Game.h"
#include "Player.h"
#include "Card.h"

Game::Game() {
	round = 1;
	turn = 1;
	player1 = Player();
	player2 = Player();
	currentPlayer = &player1;
	initDeck();
	std::cout << GAME_TITLE << std::endl;
	printf("Starting Dead Man's Draw++\n");
}

Game::takeTurn() {
	turnInitPrint();
	Card* card = drawCard();
	cardDrawMessage(card);
	currentPlayer->printPlayArea();

	currentPlayer->playCard(card, *this);

	std::string response; 

	while (!currentPlayer->isBust(card)) {
		cin >> "Draw again? (y/n): " >> response;

		if (response == "y") {
			Card* card = drawCard();
			cardDrawMessage(card);
		}

	}
}

Game::drawCard() {
	// what if deck empty 

	Card* card = deck.back();
	deck.pop_back();
	return card;
}

Game::cardDrawMessage(Card* card) {
	std::cout << currentPlayer->getName() << " Draws a " << card->getName() << std::endl;
	std::cout << "        " << card->specialAbility() << std::endl;
}



Game::turnInitPrint() {
	std::cout << currentPlayer->getName() << "'s turn." << std::endl;
	std::cout << currentPlayer->getName() << "'s Bank:" << std::endl << currentPlayer->printBank() << std::endl;
}

Game::initDeck() {
	int cardValues = [2, 3, 4, 5, 6, 7];
	int mermaidValues = [4, 5, 6, 7, 8, 9];

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

Game::shuffleDeck(CardCollection& cards) {
	CardCollection shuffleDeck{ cards.begin(), cards.end() };
	std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
	std::copy(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());
}

Game::~Game() {}