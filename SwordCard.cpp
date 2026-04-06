#include "SwordCard.h"

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

	cout << "        Steal the top card of any suit from the other player's Bank into your Play Area:" << endl;
	int i = 1;
	for (auto& pair : otherPlayer.getBank()) {
		cout << "        (" << i << ") " << pair.second.front()->str() << endl;
		i++;
	}

	int choice;
	std::cout << "        Which card do you pick? ";
	std::cin >> choice;

	auto itr = otherPlayer.getBank().begin();
	std::advance(itr, choice - 1);

	Card* removedCard = other.removeTopCardFromBank(itr->first);

	bool bustStatus = player.playCard(removedCard, player);
	if (bustStatus) {
		game.bustPlayer(player);
	}
}