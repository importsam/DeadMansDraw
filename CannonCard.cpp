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
	Player& otherPlayer = game.getOtherPlayer(player);

	if (otherPlayer.getBank().empty()) {
		std::cout << "        No cards in other player's Bank. Play continues." << std::endl;
		return;
	}

	// Discard the highest value card from the other player's bank 
	cout << "        Shoot the top card of any suit from the other player's Bank into the Discard Pile:" << endl;
	int i = 1;
	for (auto& pair : otherPlayer.getBank()) {
		cout << "        (" << i << ") " << pair.second.front()->str() << endl;
		i++;
	}


	int choice;
	cout << "        Which card do you pick? ";
	cin >> choice;

	auto itr = otherPlayer.getBank().begin();
	std::advance(itr, choice - 1);
	
	Card* removedCard = other.removeTopCardFromBank(itr->first);

	game.addToDiscardPile(removedCard);

	cout << "        You shoot the " << removedCard->str() << " out of the other player's Bank." << endl;

}