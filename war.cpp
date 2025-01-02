// Name: Aryan Chhabra
// Class: (CECS 325-01)
// Project Name: (Prog 2 – More War [Vector])
// Due Date: (09/30/2024)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

// Card class representing the individual cards
class Card {
private:
    char suit;
    char rank;

public:
    
    Card(char r, char s) : rank(r), suit(s) {}

    // Prints card in format "AC", "10S", "KD", etc.
    void print() {
        if (rank == 'T') {
            cout << "10" << suit;  // Outputs a special case for rank '10'
        } else {
            cout << rank << suit;
        }
    }

    // Compares this card to another card (1 = this card wins, 0 = tie, -1 = other card wins)
    int compare(Card other) {
        string ranks = "23456789TJQKA";  // Rank order
        int thisRankValue = ranks.find(rank);
        int otherRankValue = ranks.find(other.rank);

        if (thisRankValue > otherRankValue) {
            return 1;  // this card wins
        } else if (thisRankValue < otherRankValue) {
            return -1; // other card wins
        } else {
            return 0;  // tie
        }
    }
};

// Deck class representing a deck of 52 cards
class Deck {
private:
    vector<Card> cards;

public:
    
    Deck() {
        char suits[] = { 'H', 'D', 'C', 'S' };
        char ranks[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };

        // Populates the deck with 52 cards
        for (char suit : suits) {
            for (char rank : ranks) {
                cards.emplace_back(rank, suit);
            }
        }
    }

    // Deals a card, and raises an exception if the deck is empty
    Card deal() {
        if (isEmpty()) {
            throw runtime_error("ERROR -> Deck is empty, cannot deal more cards.");
        }
        Card dealtCard = cards.back();
        cards.pop_back();
        return dealtCard;
    }

    // Prints all cards in the deck
    void print() {
        for (Card card : cards) {
            card.print();
            cout << " ";
        }
        cout << endl;
    }

    
    void shuffle() {
        // Uses a random number generator
        random_device rd;
        mt19937 g(rd());

        // Shuffles the deck
        std::shuffle(cards.begin(), cards.end(), g);
    }

    
    bool isEmpty() {
        return cards.empty();
    }
};


int main() {
    // Seed for random shuffle
    srand(time(0));

    // Step 1: Creates a new deck
    Deck deck;

    // Step 2: Asks for the names of the two players
    string player1, player2;
    cout << "Enter Player 1 name: ";
    cin >> player1;
    cout << "Enter Player 2 name: ";
    cin >> player2;

    // Step 3: Asks for the number of games to play
    int numGames;
    cout << "How many games do you want to play? ";
    cin >> numGames;

    // Step 4: Displays the unshuffled deck
    cout << "Unshuffled deck:" << endl;
    deck.print();

    // Step 5: Shuffles the deck
    deck.shuffle();

    // Step 6: Displays the shuffled deck
    cout << "Shuffled deck:" << endl;
    deck.print();

    // Step 7: Plays the requested number of games
    int player1Wins = 0;
    int player2Wins = 0;
    int ties = 0;

    try {
        for (int i = 0; i < numGames; ++i) {
            cout << "Game " << i + 1 << ": " << endl;

            // Deal one card to each player
            Card card1 = deck.deal();
            Card card2 = deck.deal();

            
            cout << player1 << " has ";
            card1.print();
            cout << endl;

            cout << player2 << " has ";
            card2.print();
            cout << endl;

            // Compares the cards
            int result = card1.compare(card2);
            if (result == 1) {
                cout << player1 << " wins this round!" << endl;
                player1Wins++;
            } else if (result == -1) {
                cout << player2 << " wins this round!" << endl;
                player2Wins++;
            } else {
                cout << "It's a tie!" << endl;
                ties++;
            }
            cout << endl;
        }
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    // Step 8: Print the final statistics
    cout << "Game over! Final results:" << endl;
    cout << player1 << " won " << player1Wins << " games." << endl;
    cout << player2 << " won " << player2Wins << " games." << endl;
    cout << "There were " << ties << " ties." << endl;

    return 0;
}
