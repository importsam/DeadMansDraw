#pragma once
#include "Card.h"

class KrakenCard : public Card {


public:
	KrakenCard(int pointValue) : Card(CardType::Kraken, pointValue) {};

	std::string str() const override;

	void play(Game& game, Player& player) override;
};