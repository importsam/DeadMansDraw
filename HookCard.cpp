#include "HookCard.h"
#include <iostream>
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
		CardCollection sortedCards = pair.second;

		std::cout << "\t(" << i << ") " << sortedCards.front()->str() << std::endl;
		i++;
	}

	std::cout << "        Which card do you pick? " << std::flush;
	int choice = game.getValidChoice(1, player.getBank().size());

	auto itr = player.getBank().begin();
	std::advance(itr, choice - 1);

	Card* removedCard = player.removeTopCardFromBank(itr->first);

	bool bustStatus = player.playCard(removedCard, game);
	if (bustStatus) {
		game.addToDiscardPile(removedCard);
		game.setBust();
	}

}