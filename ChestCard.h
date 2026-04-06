#pragma once
#include "Card.h"

class ChestCard : public Card {


public:
	ChestCard(int pointValue) : Card(CardType::Chest, pointValue) {};

	std::string str() const override;

	void play(Game& game, Player& player) override;
};