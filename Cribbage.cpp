
#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>
#include "player.h"
using namespace std;
// Defined the decksize

const int DECK_SIZE = 52;

// Array of the decks cards
const array<string, DECK_SIZE> cards{
         "AH", "AC", "AD", "AS",
         "2H", "2C", "2D", "2S",
         "3H", "3C", "3D", "3S",
         "4H", "4C", "4D", "4S",
         "5H", "5C", "5D", "5S",
         "6H", "6C", "6D", "6S",
         "7H", "7C", "7D", "7S",
         "8H", "8C", "8D", "8S",
         "9H", "9C", "9D", "9S",
         "10H", "10C", "10D", "10S",
         "JH", "JC", "JD", "JS",
         "QH", "QC", "QD", "QS",
         "KH", "KC", "KD", "KS",
};


void initializeDeck(array<const string*, DECK_SIZE>* deck);
void displayDeck(array<const string*, DECK_SIZE> deck);
void shuffleDeck(array<const string*, DECK_SIZE>* deck);
void rules();
void seeRules();
void playerNames(Player player1, Player player2);
void playersSetCrib(Player player1, Player player2, int who);

/// <summary>
/// Cribbage game play 
/// </summary>
/// <returns>0 to indicate at the end of main</returns>
int main()
{
    const int endGamePoints = 121;
    seeRules();
    // make players
    Player player1, player2;
    playerNames(player1, player2);
    
    bool isGameWon = false;
    
    array<const string*, DECK_SIZE> deck;
    initializeDeck(&deck);
    shuffleDeck(&deck);
    /*displayDeck(deck);*/
    int counter = 0;
    int whoseCrib = 0;
    while (!isGameWon) {
        if (counter / 2 == 0) {
            whoseCrib = 0;
        }
        else {
            whoseCrib = 1;
        }
        string playCard;
        // deal 6 cards to each player face down
        // pick 2 cards to set to crib
        playersSetCrib(player1, player2, whoseCrib);
        player1.seeCrib();// for testing 
        cout << endl;
        player2.seeCrib();// for testing 

        // flip over the play card
        // playCard =
        // play cards till empty hands
        // calculate end of round points
        // calculate cribbage points
        counter++;
    }

    // deal 6 cards to each player face down
    
    string cards1[6] = {};
    for (int i = 0; i < 6; i++) {
        // take the cards form the deck and assign to cards1
        cards1[i] = cards[i]; // not proper
        cout << cards1[i] << endl;
    }
    player1.setCards(cards1);
   
    string playCard; // card that is flipped in the deck
    return 0;
}
void playersSetCrib(Player player1, Player player2, int who) {
    // will assign to player crib 
    
    cout << "Please place two cards into the crib " << endl;
    string card1;
    string card2; 
    string card3;
    string card4;
    cout << "Which is your first card pick for the crib? " << flush;
    cin >> card1;
    cout << "Which is your second card pick for the crib? " << flush;
    cin >> card2;
    string cribCards[4] = {};
    //// each player puts 2 cards into crib
    cribCards[0] = card1;
    cribCards[1] = card2;
    cribCards[2] = card3; // comp pick
    cribCards[3] = card4; // comp pick
    if (who == 1) {
        player1.setCrib(cribCards);
    }
    else {
        player2.setCrib(cribCards);
    }
}

/// <summary>
/// This will get and assign the player names
/// </summary>
/// <param name="player1">Player 1</param>
/// <param name="player2">Player 2 - computer</param>
void playerNames(Player player1, Player player2) {
    string player1Name;
    cout << "This game will have one computer player along with you" << endl;
    cout << "What is the name of player 1? " << flush;
    cin >> player1Name;
    player1.setName(player1Name);
    string names[] = { "Bob", "Draven", "Kellan", "Amie", "Ace", "Charlene", "Leann", "Dan" };
    srand(time(0));
    player2.setName(names[(rand() % 7) + 1]);
    cout << "Welcome " << player1.getName() << " you are playing against " << player2.getName() << endl;
}

// This method will shuffle the deck of cards
void shuffleDeck(array<const string*, DECK_SIZE>* deck) {
    static default_random_engine engine(static_cast<unsigned int>(time(0)));
    for (unsigned int i = DECK_SIZE - 1; i > 0; --i)
    {
        uniform_int_distribution<unsigned int> randomInt{ 0, i };
        // sets up what number to swap with 
        unsigned int j = randomInt(engine);
        // swaps card with randomly chosen card
        swap((*deck)[i], (*deck)[j]);
    }
    // Tells the user the deck is shuffled
    cout << "Shuffled the deck!" << endl << endl;
}
// This method will display the deck of cards
void displayDeck(array<const string*, DECK_SIZE> deck) {
    cout << "This is the deck of Cards" << endl << endl;
    // Will print out the cards
    for (size_t i = 0; i < DECK_SIZE; ++i)
    {
        // prints out the card in order
        cout << *deck[i] << " ";
        // checks what card it is and if its the 13th, 16th or 39th it inserts an endline
        if (i == 12 || i == 25 || i == 38) {
            cout << endl;
        }
    }
    // prints two blank lines for spacing to make it look better visually
    cout << endl << endl;
}

// This method builds the initial deck of cards before displayed or shuffled
void initializeDeck(array<const string*, DECK_SIZE>* deck) {
    for (size_t i = 0; i < DECK_SIZE; ++i) {
        (*deck)[i] = &cards[i];
    }
}

/// <summary>
/// Asks the user if they want to see the rules
/// </summary>
void seeRules() {
    string seeRules;
    cout << "Cribbage" << endl;
    cout << endl;
    cout << "Would you like the rules, yes or no? " << flush;
    cin >> seeRules;
    transform(seeRules.begin(), seeRules.end(), seeRules.begin(), ::tolower);

    if (seeRules == "yes") {
        rules();
    }
}
/// <summary>
/// Prints the rules to the user
/// </summary>
void rules() {
    cout << "These are the rules from Bicycle Playing Cards" << endl;
    cout << "https://bicyclecards.com/how-to-play/cribbage/" << endl;
    cout << endl;
    
    cout << "NUMBER OF PLAYERS" << endl;
    cout << "Two or three people can play. Or four people can play two against two as partners. "
         << "But Cribbage is basically best played by two people, and the rules that follow are for that number." << endl;
    cout << endl;
    
    cout << "THE PACK" << endl;
    cout << "The standard 52 - card pack is used." << endl;
    cout << endl;
    
    cout << "RANK OF CARDS" << endl;
    cout << "K(high), Q, J, 10, 9, 8, 7, 6, 5, 4, 3, 2, A." << endl;
    cout << endl;
    
    cout << "THE DRAW, SHUFFLE AND CUT" << endl;
    cout << "From a shuffled pack face down, each player cuts a card, leaving at least four cards at either end of the pack. "
         << "If both players cut cards of the same rank, each draws again. "
         << "The player with the lower card deals the first hand. "
         << "Thereafter, the turn to deal alternates between the two players, except that the loser of the game deals first if another game is played. "
         << "The dealer has the right to shuffle last, and presents the cards to the non - dealer for the cut prior to the deal. (In some games, there is no cut at this time.)" << endl;
    cout << endl;
    
    cout << "THE DEAL" << endl;
    cout << "The dealer distributes six cards face down to each player, beginning with the opponent." << endl;
    cout << endl;
    
    cout << "OBJECT OF THE GAME" << endl;
    cout << "The goal is to be the first player to score 121 points. (Some games are to 61 points.) Players earn points during play and for making various card combinations." << endl;
    cout << endl;
    
    cout << "THE CRIB" << endl;
    cout << "Each player looks at their six cards and \"lays away\" two of them face down to reduce the hand to four. "
         << "The four cards laid away together constitute \"the crib\"."
         << "The crib belongs to the dealer, but these cards are not exposed or used until after the hands have been played." << endl;
    cout << endl;
    
    cout << "BEFORE THE PLAY" << endl;
    cout << "After the crib is laid away, the non - dealer cuts the pack. "
         << "The dealer turns up the top card of the lower packet and places it face up on top of the pack. " 
         << "This card is the \"starter.\" If the starter is a jack, it is called \"His Heels,\" and the dealer pegs(scores) 2 points at once. " 
         << "The starter is not used in the play phase of Cribbage, but is used later for making various card combinations that score points." << endl;
    cout << endl; 
    
    cout << "THE PLAY" << endl;
    cout << "After the starter is turned, the non - dealer lays one of their cards face up on the table. " 
         << "The dealer similarly exposes a card, then non - dealer again, and so on - the hands are exposed card by card, alternately except for a \"Go,\" as noted below. " 
         << "Each player keeps their cards separate from those of their opponent." << endl;
    cout << "As each person plays, they announce a running total of pips reached by the addition of the last card to all those previously played. "
         << "(Example: The non - dealer begins with a four, saying \"Four.\" The dealer plays a nine, saying \"Thirteen\".) "
         << "The kings, queensand jacks count 10 each; every other card counts its pip value(the ace counts one)." << endl;
    cout << endl; 
    
    cout << "THE GO" << endl;
    cout << "During play, the running total of cards may never be carried beyond 31. "
         << "If a player cannot add another card without exceeding 31, he or she says \"Go\" and the opponent pegs 1. "
         << "After gaining the Go, the opponent must first lay down any additional cards he can without exceeding 31. "
         << "Besides the point for Go, he may then score any additional points that can be made through pairsand runs(described later). "
         << "If a player reaches exactly 31, he pegs two instead of one for Go." << endl;
    cout << "The player who called Go leads for the next series of plays, with the count starting at zero. "
         << "The lead may not be combined with any cards previously played to form a scoring combination; the Go has interrupted the sequence." << endl;
    cout << "The person who plays the last card pegs one for Go, plus one extra if the card brings the count to exactly 31. "
         << "The dealer is sure to peg at least one point in every hand, for he will have a Go on the last card if not earlier." << endl;
    cout << endl; 
    
    cout << "PEGGING" << endl;
    cout << "The object in play is to score points by pegging.In addition" << endl;
    cout << "to a Go, a player may score for the following combinations :" << endl;
    cout << "Fifteen: For adding a card that makes the total 15 Peg 2" << endl;
        
    cout << "Pair : For adding a card of the same rank as the card just played Peg 2" << endl;

    cout << "(Note that face cards pair only by actual rank : jack with jack, but not jack with queen.)" << endl;
    cout << "Triplet: For adding the third card of the same rank.Peg 6" << endl;

    cout << "Four : (also called \"Double Pair\" or \"Double Pair Royal\")" << endl;

    cout << "For adding the fourth card of the same rank Peg 12" << endl;
    cout << "Run(Sequence) : For adding a card that forms, with those just played :" << endl;
    cout << "For a sequence of three Peg 3" << endl;
    cout << "For a sequence of four.Peg 4" << endl;
    cout << "For a sequence of five.Peg 5" << endl;
    cout << "(Peg one point more for each extra card of a sequence. "
         << "Note that runs are independent of suits, but go strictly by rank; to illustrate : 9, 10, J, or J, 9, 10 is a run but 9, 10, Q is not.)" << endl;
    cout << "It is important to keep track of the order in which cards are played to determine whether what looks like a sequence or a run has been interrupted by a \"foreign card.\" "
         << "Example : Cards are played in this order : 8, 7, 7, 6. " 
         << "The dealer pegs 2 for 15, and the opponent pegs 2 for pair, but the dealer cannot peg for run because of the extra seven(foreign card) that has been played. " 
         << "Example : Cards are played in this order : 9, 6, 8, 7. "
         << "The dealer pegs 2 for fifteen when he or she plays the six and pegs 4 for run when he plays the seven(the 6, 7, 8, 9 sequence). "
         << "The cards were not played in sequential order, but they form a true run with no foreign card.\"COUNTING THE HANDS\" "<< endl;
    cout << "When play ends, the three hands are counted in order : non - dealer's hand (first), dealer's hand(second), and then the crib(third). "
         << "This order is important because, toward the end of a game, the "
         << "non - dealer may \"count out\" and win before the dealer has a chance to count, even though the dealer's total would have exceeded that of the opponent. "
         << "The starter is considered to be a part of each hand, so that all hands in counting comprise five cards. "
         << "The basic scoring formations are as follows:" << endl;
    
    cout << endl;
    cout << "COMBINATION COUNTS" << endl;
    cout << "Fifteen.Each combination of cards that totals 15 2" << endl;
    cout << "Pair.Each pair of cards of the same rank 2" << endl;
    cout << "Run.Each combination of three or more 1 cards in sequence(for each card in the sequence)" << endl;
    cout << "Flush.Four cards of the same suit in hand 4 (excluding the crib, and the starter)" << endl;
    cout << "Four cards in hand or crib of the same 5 suit as the starter" << endl;
    cout << "(There is no count for four - flush in the crib that is not of same suit as the starter)" << endl;
    cout << "His Nobs.Jack of the same suit as starter in hand or crib 1" << endl;
    
    cout << endl; 
    cout << "COMBINATIONS" << endl;
    cout << "Each and every combination of two cards that make a pair, of two or more cards that make 15, or of three or more cards that make a run, count separately." << endl;
    cout << "Example: A hand(including the starter) comprised of 8, 7, 7, 6, 2 scores 8 points for four combinations that total 15 : the 8 with one 7, and the 8 with the other 7; the 6, 2 with each of the two 7s.The same hand also scores 2 for a pair, and 6 for two runs of three(8, 7, 6 using each of the two 7s).The total score is 16. An experienced player computes the hand thus : \"Fifteen 2, fifteen 4, fifteen 6, fifteen 8, and 8 for double run is 16.\"" << endl;
    cout << "Note that the ace is always low and cannot form a sequence with a king.Further, a flush cannot happen during the play of the cards; it occurs only when the handsand the crib are counted." << endl;
    cout << "Certain basic formulations should be learned to facilitate counting.For pairsand runs alone :" << endl;
    cout << "A.A triplet counts 6." << endl;
    cout << "B.Four of a kind counts 12." << endl;
    cout << "C.A run of three, with one card duplicated(double run) counts 8." << endl;
    cout << "D.A run of four, with one card duplicated, counts 10." << endl;
    cout << "E.A run of three, with one card triplicated(triple run), counts 15." << endl;
    cout << "F.A run of three, with two different cards duplicated, counts 16." << endl;
    cout << "A PERFECT 29!" << endl;
    cout << "The highest possible score for combinations in a single Cribbage deal is 29, and it may occur only once in a Cribbage fan's lifetime -in fact, experts say that a 29 is probably as rare as a hole-in-one in golf. To make this amazing score, a player must have a five as the starter (upcard) and the other three fives plus the jack of the same suit as the starter - His Nobs: 1 point - in their hand. The double pair royal (four 5s) peg another 12 points; the various fives used to hit 15 can be done four ways for 8 points; and the jack plus a 5 to hit 15 can also be done four ways for 8 points. Total = 29 points." << endl;
    cout << "Muggins(optional).Each player must count his hand(and crib) aloud and announce the total.If he overlooks any score, the opponent may say \"Muggins\" and then score the overlooked points for himself.For experienced players, the Muggins rule is always in effectand adds even more suspense to the game." << endl;
    cout << endl; 
    
    cout << "GAME" << endl;
    cout << "Game may be fixed at either 121 points or 61 points.The play ends the moment either player reaches the agreed total, whether by pegging or counting one's hand. If the non-dealer \"goes out\" by the count of his hand, the game immediately ends and the dealer may not score either his hand or the crib." << endl;
    cout << "If a player wins the game before the loser has passed the halfway mark(did not reach 31 in a game of 61, or 61 in a game of 121), the loser is \"lurched,\" and the winner scores two games instead of one.A popular variation of games played to 121, is a \"skunk\" (double game) for the winner if the losing player fails to pass the three - quarter mark - 91 points or more - and it is a \"double skunk\" (quadruple game) if the loser fails to pass the halfway mark(61 or more points)." << endl;
    cout << "THE CRIBBAGE BOARD" << endl;
    cout << "The Cribbage board(see illustration) has four rows of 30 holes each, divided into two pairs of rows by a central panel.There are usually four(or two) additional holes near one end, called \"game holes.\" With the board come four pegs, usually in two contrasting colors.Note: There are also continuous track Cribbage boards available which, as the name implies, have one continuous line of 121 holes for each player." << endl;
    cout << "The board is placed to one side between the two players, and each player takes two pegs of the same color. (The pegs are placed in the game holes until the game begins.) Each time a player scores, they advance a peg along a row on their side of the board, counting one hole per point.Two pegs are used, and the rearmost peg jumps over the first peg to show the first increment in score.After another increase in score, the peg behind jumps over the peg in front to the appropriate hole to show the player's new score, and so on (see diagram next page). The custom is to \"go down\" (away from the game holes) on the outer rows and \"come up\" on the inner rows. A game of 61 is \"once around\" and a game of 121 is \"twice around.\" As noted previously, continuous line Cribbage boards are available." << endl;
    cout << "If a Cribbage board is not available, each player may use a piece of paper or cardboard, marked thus :" << endl;
    cout << "Units 1, 2, 3, 4, 5, 6, 7, 8, 9, 10" << endl;
    cout << "Tens 10, 20, 30, 40, 50, 60" << endl;
    cout << "Two small markers, such as small coins or buttons, can substitute for pegs for counting in each row." << endl;
    cout << endl; 
    
    cout << "STRATEGY" << endl;
    cout << "The Crib.If the dealer is discarding for the crib, they should “salt” it with the best possible cards, but at the same time retain good cards in their hand that can be used for high scoring.Conversely, for the non - dealer, it is best to lay out cards that will be the least advantageous for the dealer.Laying out a five would be the worst choice, for the dealer could use it to make 15 with any one of the ten - cards(10, J, Q, K).Laying out a pair is usually a poor choice too, and the same goes for sequential cards, such as putting both a sixand seven in the crib.The aceand king tend to be good cards to put in the crib because it is harder to use them in a run." << endl;
    cout << "The Play.As expected, the five makes for the worst lead in that there are so many ten - cards that the opponent can use to make a 15. Leading from a pair is a good idea, for even if the opponent makes a pair, the leader can play the other matching card from their handand collect for a pair royal.Leading an ace or deuce is not a good idea, for these cards should be saved until later to help make a 15, a Go, or a 31. The safest lead is a four because this card cannot be used to make a 15 at the opponent’s very next turn.Finally, when the opponent leads a card that can either be paired or make 15, the latter choice is preferred." << endl;
    
    cout << "During the play, it is advisable not to try to make a count of 21, for the opponent can then play one of the many 10 - cards and make 31 to gain two points." << endl;


}
 