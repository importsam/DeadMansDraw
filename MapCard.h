#pragma once
#include "MapCard.h"

class MapCard : public Card {
public:
	MapCard(int pointValue) : Card(CardType::Map, pointValue) {};
	std::string str() const override;
	void play(Game& game, Player& player) override;


}