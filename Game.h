#ifndef GAME_TITLE_H
#define GAME_TITLE_H
#define GAME_TITLE \
"______ _ ___ ___ _ \n" \
"| _ \\ | | | \\/ | ( ) \n" \
"| | | | ___ __ _ __| | | . . | __ _ _ __ |/ ___ \n" \
"| | | |/ _ \\ / _` | / _` | | |\\/| | / _` || '_ \\ / __|\n" \
"| |/ /| __/| (_| || (_| | | | | || (_| || | | | \\__ \\ \n" \
"______ \\___| \\__,_| \\__,_| \\_| |_/ \\__,_||_| |_| |___/\n" \
"| _ \\ _ _\n" \
"| | | | _ __ __ _ __ __ _| |_ _| |_\n" \
"| | | || '__|/ _` |\\ \\ /\\ / /|_ _||_ _|\n" \
"| |/ / | | | (_| | \\ V V / |_| |_|\n" \
"|___/ |_| \\__,_| \\_/\\_/\n"
#endif //GAME_TITLE_H

#include <map>
#include <string>

class Game {
	Player player1;
	Player player2;
	CardCollection deck;
	CardCollection discardPile;
	int round;
	int turn;
	Player* currentPlayer;
	Player* otherPlayer;

	void cardDrawMessage(Card* card);

public:
	/* When you initialise a game, you have to init two players. All their belongings ie play area and deck should be in their own class. */

	Game();
	void takeTurn();
	Card* drawCard();
	void initDeck();
	void shuffleDeck(CardCollection& cards);
	Player* getCurrentPlayer() const { return currentPlayer; }
	Player* getOtherPlayer() const { return otherPlayer; }
	Card* drawFromDiscardPile();
	void bustPlayer(Player& player);
	~Game();

};

/*

Game — The Game object drives the game. The Game object:
• Is responsible for initialising and starting a new game.
• Is responsible for ending a game and printing final scores.
• Is responsible for creating the card deck.
• Is responsible for shuffling the deck.
• Is responsible for initialising players.
• Is responsible for controlling a turn in the game:
	o Drawing a card.
	o Asking if the player wants to draw another card.
	o Handing the game to the other player if the current player busts.
• Knows the current turn and round of the game.
• Knows the current player.
There should only be a single instance of Game at any one time.

*/