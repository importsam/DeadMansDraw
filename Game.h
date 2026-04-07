#ifndef GAME_TITLE_H
#define GAME_TITLE_H
#define GAME_TITLE \
"______                  _   ___  ___              _\n" \
"|  _  \\                | |  |  \\/  |             ( )\n" \
"| | | | ___   __ _   __| |  | .  . |  __ _  _ __ |/ ___\n" \
"| | | |/ _ \\ / _` | / _` |  | |\\/| | / _` || '_ \\  / __|\n" \
"| |/ /|  __/| (_| || (_| |  | |  | || (_| || | | | \\__ \\\n" \
"|____/ \\___| \\__,_| \\__,_|  \\_|  |_/ \\__,_||_| |_| |___/\n" \
"|  _  \\                         _      _\n" \
"| | | | _ __  __ _ __      __ _| |_  _| |_\n" \
"| | | || '__|/ _` |\\ \\ /\\ / /|_   _||_   _|\n" \
"| |/ / | |  | (_| | \\ V  V /   |_|    |_|\n" \
"|___/  |_|   \\__,_|  \\_/\\_/\n"
#endif //GAME_TITLE_H

#include "Card.h"
#include "Player.h"

#include <map>
#include <string>



class Game {

    Player player1;
    Player player2;
    CardCollection deck;
    CardCollection discardPile;
    int round;
    int turn;
    bool busted;
    Player* currentPlayer;
    Player* otherPlayer;

    // Announces that the user has drawn a card with the card name
    void cardDrawMessage(Card* card);

public:
    /*
        Constructor for Game.
 
    
    */ 
    Game();
    void gameStart();
    void gameEnd() const;
    void takeTurn();
    Card* drawCard();
    void initDeck();
    void turnInitPrint();
    void shuffleDeck(CardCollection& cards);
    Player* getCurrentPlayer() const { return currentPlayer; }
    Player* getOtherPlayer() const { return otherPlayer; }
    Card* drawFromDiscardPile();
    int deckEmpty() const { return deck.empty(); }
    void bustPlayer(Player& player);
    bool isBusted() const { return busted; }
    void addToDiscardPile(Card* card);
    CardCollection& getDeck() { return deck; }
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