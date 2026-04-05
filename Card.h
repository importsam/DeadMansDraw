#pragma once 

#include <vector>
#include <string>

class Game;
class Player;

enum CardType { Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken };

typedef std::vector<Card*> CardCollection;

class Card {

	CardType suit;
	int pointValue;

public:
	Card(CardType suit, int pointValue) : suit(suit), pointValue(pointValue) {}
	
	const CardType& type() const;

	virtual std::string str() const = 0;

	virtual void play(Game& game, Player& player) = 0;

	virtual void willAddToBank(Game& game, Player& player) {}

	CardType& type() const {
		return suit;
	}

	int getPointValue() const {
		return pointValue;
	}

	virtual ~Card() {}
		
};


/*
Card — Represents the base type of a card in the game. The Card class should be an abstract
class that other types of card classes (e.g. Cannon, Chest, Key, Sword, Hook, Oracle, Map,
Mermaid, Kraken) inherit from. A card should:
• Contain an enum for the type of card it is.
• Is responsible for presenting the card type (i.e. printing the card type to screen) back
to the player.
• Is responsible for playing that type of card.
When implementing a card, define an enum for the type of card it represents:
• enum CardType {Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid,
Kraken};
Add a function that returns this type:
• const CardType& type() const
Add a function that returns the type of card and value as a string (e.g. “Oracle(7)”):
• virtual std::string str() const = 0;
The Card is responsible for executing the ability of the Card. That way, Game and Card are
loosely coupled, and it is easier to add or remove cards as needed. To enable this, we
suggest having the following function in Card:
• // play the effect of this card
virtual void play(Game &game, Player &player) = 0;
Override this function to handle each type of cards’ ability. There is one “type” of card (the
Chest and the Key together), where the ability occurs only when the player banks that card.
You will need to think carefully about the order of operations here. We recommend having
a function in Card with the following signature, called just before being added to the bank,
to handle this:
• virtual void willAddToBank(Game &game, Player &player) { }
We also recommend type def-ing a card collection:
• typedef std::vector<Card*> CardCollection;
*/