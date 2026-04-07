#include "MermaidCard.h"
#include <iostream>
#include "Game.h"
#include "Player.h"

std::string MermaidCard::str() const {
	return "Mermaid(" + std::to_string(getPointValue()) + ")";
}

void MermaidCard::play(Game& game, Player& player) {
	std::cout << "\tNo effect but Mermaids are worth more." << std::endl;
}