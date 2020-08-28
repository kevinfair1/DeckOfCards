#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
   
    const int SuitNum = 4; 
    const int FacesNum = 13;
    int CardNum = 0;
    string card = ""; 
    int gameMode;
    bool gameContinue = true;

    //create arrays for card labels
    const string suits[] = { "Hearts", "Clubs", "Diamonds", "Spades" };
    const string face[] = { "2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace" };

    //Create vectors to store the decks in.
    vector<string> Cards;
    vector<string> faceValueCards;
    vector<string> suitTypeCards;


    //Generate full card deck
    for (int i = 0; i < SuitNum; i++) { //iterate through suits

        for (int j = 0; j < FacesNum; j++) {//iterate through faces

            card = face[j] + " of " + suits[i]; //declare card

            Cards.push_back(card);  // add card to vector
            CardNum++;// raise card number for every card added to deck
        }
    }
    //Generate the deck for suits only
    for (int i = 0; i < SuitNum; i++)
    {
        card = suits[i];
        suitTypeCards.push_back(card);
        CardNum++;        
    }
    //Generate the deck for face values only
    for (int i = 0; i < FacesNum; i++)
    {
        card = face[i];
        faceValueCards.push_back(card);
        CardNum++;        
    }
    //time operator to make sure every time the program is run, it produces different random values   
    srand(time(0));    
   
    //Description of game and user input required
        cout << "Card Guessing Game!" << endl << endl;
        cout << "Please choose which of the following game modes you would like to play! (Choose number)" << endl << endl;
        cout << "1. Guess face value only!" << endl << "2. Guess suit type only!" << endl << "3. Guess both face and suit!" << endl << endl;
        cin >> gameMode;

        while (gameContinue == true)
        {
            if (gameMode == 1)
            {
                random_shuffle(faceValueCards.begin(), faceValueCards.end());
                int RCard = rand() % 13;
                string DrawCard = faceValueCards.at(RCard);
                cout << DrawCard << endl;

                string faceGuess;

                cout << "Please choose face value! (Enter 2-10, 'Jack', 'Queen', 'King', or 'Ace')" << endl;
                cin >> faceGuess;

                if (faceGuess == DrawCard)
                {
                    cout << "Congratulations! You picked the correct face value! WINNER!";
                    //gameContinue = false;
                }
                else if (faceGuess != DrawCard)
                {
                    cout << "Im sorry! You picked the incorrect face value. Please try again!" << endl << endl;
                }
            }

            else if (gameMode == 2)
            {
                random_shuffle(suitTypeCards.begin(), suitTypeCards.end());
                int RCard = rand() % 4;
                string DrawCard = suitTypeCards.at(RCard);
                cout << DrawCard << endl;

                string suitGuess;

                cout << "Please choose suit! (Enter 'Hearts', 'Clubs', 'Diamonds', or 'Spades')" << endl;
                cin >> suitGuess;

                if (suitGuess == DrawCard) 
                {
                    cout << "Congratulations! You picked the correct face value! WINNER!" << endl;
                    //gameContinue = false;
                }
                else if (suitGuess != DrawCard)
                {
                    cout << "Im sorry! You picked the incorrect suit. Please try again!" << endl << endl;
                }
            }
            else if (gameMode == 3)
            {
                random_shuffle(Cards.begin(), Cards.end());
                int RCard = rand() % 52;
                string DrawCard = Cards.at(RCard);
                cout << DrawCard << endl;

                string cardGuess;

                cout << "Please choose face and suit value of card!" << endl << "(Please enter in the following format:";
                cout << " '(2-10, Jack, Queen, King, Ace) of (Hearts, Clubs, Diamonds, Spades)'" << endl;
                cin.ignore();
                getline(cin, cardGuess);                

                if (cardGuess == DrawCard)
                {
                    cout << "Congratulations winner! You picked the correct face and suit, wow how lucky!!" << endl;
                    //gameContinue = false;
                }
                else if (cardGuess != DrawCard)
                {
                    cout << "Im sorry! You picked the wrong card, please try again!" << endl << endl;                    
                }


            }
        }
    return 0;
}
