#pragma once
#include "Card.h"


/*No immediate effect.If banked with a Key card, draw as
many bonus cards from the Discard pile as you moved into
your Bank.*/

class ChestCard : public Card {

public:
	ChestCard(int pointValue) : Card(CardType::Chest, pointValue) {};

	std::string str() const override;

	void play(Game& game, Player& player) override;
};