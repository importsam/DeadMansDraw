#ifndef CANNONCARD_H
#define CANNONCARD_H

#include "Card.h"
#include <iterator>
class CannonCard : public Card {


public:
	CannonCard(int pointValue) : Card(CardType::Cannon, pointValue) {};

	std::string str() const override;

	void play(Game& game, Player& player) override;
};

#endif //CANNONCARD_H