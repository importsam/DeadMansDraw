#include "CannonCard.h"
#include <iostream>
#include "Game.h"
#include "Player.h"
std::string CannonCard::str() const {
	return "Cannon(" + std::to_string(getPointValue()) + ")";
}

void CannonCard::play(Game& game, Player& player) {
	// Discard the top card (i.e. the highest value) of any suit from
	//the other player’s Bank to the Discard Pile.
	Player& otherPlayer = *game.getOtherPlayer();

	if (otherPlayer.getBank().empty()) {
		std::cout << "        No cards in other player's Bank. Play continues." << std::endl;
		return;
	}

	// Discard the highest value card from the other player's bank 
	std::cout << "        Shoot the top card of any suit from the other player's Bank into the Discard Pile:" << std::endl;

	int i = 1;
	for (auto& pair : otherPlayer.getBank()) {

		std::cout << "\t(" << i << ") " << pair.second.front()->str() << std::endl;
		i++;
	}

	int choice;
	std::cout << "        Which card do you pick? " << std::flush;
	choice = game.getValidChoice(1, otherPlayer.getBank().size());

	auto itr = otherPlayer.getBank().begin();
	std::advance(itr, choice - 1);
	
	Card* removedCard = otherPlayer.removeTopCardFromBank(itr->first);

	game.addToDiscardPile(removedCard);

	std::cout << "        You shoot the " << removedCard->str() << " out of the other player's Bank." << std::endl;
}