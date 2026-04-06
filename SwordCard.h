#pragma once
#include "Card.h"

class SwordCard : public Card {


public:
	SwordCard(int pointValue) : Card(CardType::Sword, pointValue) {};

	std::string str() const override;

	void play(Game& game, Player& player) override;
};