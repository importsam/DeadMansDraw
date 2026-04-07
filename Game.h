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
        This initialises players, the deck, and starts the game.
    */ 
    Game();
    
    void gameStart();
    void gameEnd() const;
	
    //Switches the turn of the game. Manages card handling logic.
    void takeTurn();
    // Draws a card from the deck
    Card* drawCard();
    // Adds each card into the game's deck
    void initDeck();
	// Prints the current round, turn, and player's name at the start of each turn.
    void turnInitPrint();
	// Shuffles the deck of cards
    void shuffleDeck(CardCollection& cards);
	// returns a pointer to the current player and other player
    Player* getCurrentPlayer() const { return currentPlayer; }
    Player* getOtherPlayer() const { return otherPlayer; }
	// Draws a card from the discard pile
    Card* drawFromDiscardPile();
    
    int deckEmpty() const { return deck.empty(); }
    // Will change the status of a player to busted, ending their turn.
    void bustPlayer(Player& player);
    
    bool isBusted() const { return busted; }
	// Adds a card to the discard pile
    void addToDiscardPile(Card* card);
    CardCollection& getDeck() { return deck; }
	// Destructor for Game. Frees memory of cards in the deck and discard pile
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