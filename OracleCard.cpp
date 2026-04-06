#include "OracleCard.h"

std::string OracleCard::str() const {
	return "Oracle(" + std::to_string(getPointValue()) + ")";
}

void OracleCard::play(Game& game, Player& player) {
	if (game.getDeck().empty()) {
		std::cout << "        The Oracle sees nothing, the deck is empty." << std::endl;
		return;
	}
	
	Card* card = game.getDeck().back();

	std::cout << "        The Oracle sees a " << card->str() << std::endl;

}