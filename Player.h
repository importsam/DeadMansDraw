#pragma once
#include "Card.h"
#include <string>
#include <map>
#include <vector>

class Game;

class Player {
	std::string _name;
	std::map<CardType, CardCollection> playArea;
	std::map<CardType, CardCollection> bank;

public:
	Player();
	bool isBust (Card* card) const;
	// plays the card into the play area
	// returns true if this causes the player to bust,
	// otherwise the card's ability is performed and this function returns false
	bool playCard(Card* card, Game& game);
	void addToPlayArea(Card* card);
	void addToBank(Game& game);
	void printPlayArea();
	void clearPlayArea(CardCollection& discardPile);
	void printBank();
	std::string getName() const;
	int getScore() const;
	Card* removeTopCardFromBank(CardType type);
	std::map<CardType, CardCollection>& getPlayArea() { return playArea; }
	//Card* pickTopCardFromBank();

	std::map<CardType, CardCollection>& getBank() { return bank; }

};

/*
Player — Represents a player in the game.A player object :
• Is responsible for managing and adding cards to the player’s current Play Area.
• Is responsible for knowing if the player’s current play area is bust(i.e.there are two
	of the same type of card in the play area).
	• Is responsible for managing the player’s Bank and moving cards from the play area to
	the bank.
	• Is responsible for printing the player’s play area and bank to the screen.
	• Knows the player’s current total score.
	• Knows the player’s name, randomly initialised from a fixed list.
	When implementing player, we suggest having a function that adds a card to the player’s
	play area and removes it from the deck :
• // plays the card into the play area
// returns true if this causes the player to bust,
// otherwise the card's ability is performed and this function returns false
bool playCard(Card * card, Game & game);
When selecting the name for the player, select it from a random list :
• std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue",
"Sasha", "Tina", "Marge" };
• _name = names[rand() % 10];
*/