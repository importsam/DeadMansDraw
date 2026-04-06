#pragma once
#include "Card.h"
#include <iterator>
class CannonCard : public Card {


public:
	CannonCard(int pointValue) : Card(CardType::Cannon, pointValue) {};

	std::string str() const override;

	void play(Game& game, Player& player) override;
};