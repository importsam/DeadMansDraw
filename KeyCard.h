#pragma once
#include "Card.h"

class KeyCard : public Card {

public:
	KeyCard(int pointValue) : Card(CardType::Key, pointValue) {};

	std::string str() const override;

	void play(Game& game, Player& player) override;

	void willAddToBank(Game& game, Player& player) override;
};