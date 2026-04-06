#pragma once
#include "Card.h"

class MermaidCard : public Card {


public:
	MermaidCard(int pointValue) : Card(CardType::Mermaid, pointValue) {};

	std::string str() const override;

	void play(Game& game, Player& player) override;
};