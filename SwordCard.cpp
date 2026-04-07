#include "SwordCard.h"
#include <iostream>
#include "Game.h"
#include "Player.h"
std::string SwordCard::str() const {
	return "Sword(" + std::to_string(getPointValue()) + ")";
}

void SwordCard::play(Game& game, Player& player) {
	Player& otherPlayer = *game.getOtherPlayer();

	//        No cards in other player's Bank. Play continues.
	if (otherPlayer.getBank().empty()) {
		std::cout << "        No cards in other player's Bank. Play continues." << std::endl;
		return;
	}

	std::cout << "        Steal the top card of any suit from the other player's Bank into your Play Area:" << std::endl;
	int i = 1;
	for (auto& pair : otherPlayer.getBank()) {
		std::cout << "        (" << i << ") " << pair.second.front()->str() << std::endl;
		i++;
	}

	int choice;
	std::cout << "        Which card do you pick? ";
	choice = game.getValidChoice(1, otherPlayer.getBank().size());

	auto itr = otherPlayer.getBank().begin();
	std::advance(itr, choice - 1);

	Card* removedCard = otherPlayer.removeTopCardFromBank(itr->first);

	bool bustStatus = player.playCard(removedCard, game);
	if (bustStatus) {
		game.bustPlayer(player);
	}
}