#pragma once
#include "Card.h"

class OracleCard : public Card {


public:
	OracleCard(int pointValue) : Card(CardType::Oracle, pointValue) {};

	std::string str() const override;

	void play(Game& game, Player& player) override;
};