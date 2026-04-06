#include "MermaidCard.h"
#include <iostream>
#include "Game.h"
#include "Player.h"
std::string MermaidCard::str() const {
	return "Cannon(" + std::to_string(getPointValue()) + ")";
}

void MermaidCard::play(Game& game, Player& player) {
	std::cout << "\t\tNo effect but Mermaids are worth more." << std::endl;
}