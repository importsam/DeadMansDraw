#pragma once
#include "Card.h"

class HookCard : public Card {


public:
	HookCard(int pointValue) : Card(CardType::Hook, pointValue) {};

	std::string str() const override;

	void play(Game& game, Player& player) override;
};