#include "HookCard.h"
#include <iostream>
#include <limits>
#include "Game.h"
#include "Player.h"
std::string HookCard::str() const {
	return "Hook(" + std::to_string(getPointValue()) + ")";
}

void HookCard::play(Game& game, Player& player) {

	if (player.getBank().empty()) {
		std::cout << "        No cards in your Bank. Play continues." << std::endl;
		return;
	}

	std::cout << "        Select a highest-value card from any of the suits in your Bank:" << std::endl;
	int i = 1;
	for (auto& pair : player.getBank()) {
		std::cout << "        (" << i << ") " << pair.second.front()->str() << std::endl;
		i++;
	}

	int min = 1;
	int max = player.getBank().size();
	int choice;
	while (1) {
		std::cin >> choice;
		if (choice >= min && choice <= max) {
			break;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		std::cout << "\tInvalid input.";
	}

	auto itr = player.getBank().begin();
	std::advance(itr, choice - 1);

	Card* removedCard = player.removeTopCardFromBank(itr->first);

	bool bustStatus = player.playCard(removedCard, game);
	if (bustStatus) {
		game.bustPlayer(player);
	}

}