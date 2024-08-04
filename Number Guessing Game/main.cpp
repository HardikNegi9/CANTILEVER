#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void hints(bool hint, int num, int num_guessed){
    if(hint){
        if (abs(num_guessed - num) < 10)
            cout << "You're very close!" << endl;
        else if (abs(num_guessed - num) < 10)
            cout << "You're getting warm." << endl;
        else 
            cout << "You're cold." << endl;
    }
    else{
        num % 2 ? cout << "Hint: The number is even.\n" : cout << "Hint: The number is odd.\n";
    }
}

int main() {
    int num_guessed = 0;
    int attempts = 0; // no of attemps to guess the no.
    char running = 'y'; // state of game -> running/stop.
    srand(time(NULL));
    bool hint = rand() % 2; // to generate 0/1 hints in a random order.

    cout << "Welcome to the Number Guess Game!" << endl;
    cout << "I have generated a number between 1 and 100. Try to Guess it!" << endl;

    // Game loop
    do{
        int hintcounter = 2;
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

            // Hints
            if(hintcounter){
                char yn;
                cout << "Do you Want a Hint? (y/n)" << endl;
                cin >> yn;
                if(yn == 'y' || yn  == 'Y'){
                    hints(hint, num_to_guess, num_guessed);
                    hint = !hint;
                    hintcounter--;
                }

            }
        }

        
        // checking that if the player wants to play again after guessing the right no.
        cout << "Do you want to play again? (y/n): ";
        cin >> running;
    }while(running == 'y' || running == 'Y');

    return 0;
}