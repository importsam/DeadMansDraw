#include "HookCard.h"
#include <iostream>

#include "Game.h"
#include "Player.h"
HookCard::str() const {
	return "Hook(" + std::to_string(getPointValue()) + ")";
}

HookCard::play(Game& game, Player& player) {
	Player& otherPlayer = game.getOtherPlayer();

	if (player.getBank().empty()) {
		std::cout << "        No cards in your Bank. Play continues." << std::endl;
		return;
	}

	cout << "        Select a highest-value card from any of the suits in your Bank:" << endl;
	int i = 1;
	for (auto& pair : player.getBank()) {
		cout << "        (" << i << ") " << pair.second.front()->str() << endl;
		i++;
	}

	int choice;
	cout << "        Which card do you pick? ";
	cin >> choice;

	Card* removedCard = other.removeTopCardFromBank(itr->first);

	bool bustStatus = player.playCard(removedCard, game);
	if (bustStatus) {
		game.bustPlayer(player);
	}

}