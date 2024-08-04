#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

void hints(bool hint, int num, int num_guessed){
    if(hint){
        if (abs(num_guessed - num) < 10)
            cout << "You're very close!" << endl;
        else if (abs(num_guessed - num) < 20)
            cout << "You're getting warm." << endl;
        else 
            cout << "You're cold." << endl;
    }
    else{
        num % 2 == 0 ? cout << "Hint: The number is even.\n" : cout << "Hint: The number is odd.\n";
    }
}

void game(){
    srand(time(NULL));
    int num_to_guess = rand() % 100 + 1; // generating a number between 1 - 100.
    int num_guessed; //user input
    int attempts = 0; // no of attemps to guess the no.
    bool hint = rand() % 2; // to generate 0/1 hints in a random order.
    int hintcounter = 2;

    cout << "I have generated a number between 1 and 100. Try to Guess it!" << endl;

    while(true){
        cout << "Enter your Guess: ";

        // Checking for invalid input.
        while (!(cin >> num_guessed) || num_guessed < 1 || num_guessed > 100) {
            cout << "Invalid input. Please enter a number between 1 and 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input.
        }

        attempts++;

        if(num_guessed == num_to_guess){
            cout << "Congratulations! You Guess the number in " << attempts << " attempts." << endl;
            break;
        }else if (num_guessed < num_to_guess){
            cout << "Guess Higher" << endl;
        } else{
            cout << "Guess Lower" << endl;
        }

        // Hints
        if(hintcounter){
            char yn;
            cout << "Do you Want a Hint? (Enter 'y' for hint)" << endl;
            cin >> yn;
            if(yn == 'y' || yn  == 'Y'){
                hints(hint, num_to_guess, num_guessed);
                hint = !hint;
                hintcounter--;
            }
        }
    }
}


int main() {

    char running = 'y'; // state of game -> running/stop.
    
    cout << "Welcome to the Number Guess Game!" << endl;
    
    // Game loop
    do{
        game();

        // checking that if the player wants to play again after guessing the right no.
        cout << "Do you want to play again? (Enter 'y' to continue playing): ";
        cin >> running;
    }while(running == 'y' || running == 'Y');

    return 0;
}