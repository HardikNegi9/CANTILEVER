#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int num_guessed = 0;
    int attempts = 0; // no of attemps to guess the no.
    char running = 'y'; // state of game -> running/stop.

    cout << "Welcome to the Number Guess Game!" << endl;
    cout << "I have generated a number between 1 and 100. Try to Guess it!" << endl;

    // Game loop
    do{
        srand(time(NULL));
        int num_to_guess = rand() % 100 + 1; // generating a number between 1 - 100.

        while(true){
            cout << "Enter your Guess: ";
            cin >> num_guessed;
            attempts++;
            if(num_guessed == num_to_guess){
                cout << "Congratulations! You Guess the number in " << attempts << " attempts." << endl;
                attempts = 0;
                break;
            }else if (num_guessed < num_to_guess){
                cout << "Guess Higher" << endl;
            } else{
                cout << "Guess Lower" << endl;
            }
        }

        // checking that if the player wants to play again after guessing the right no.
        cout << "Do you want to play again? (y/n): ";
        cin >> running;
    }while(running == 'y' || running == 'Y');

    return 0;
}