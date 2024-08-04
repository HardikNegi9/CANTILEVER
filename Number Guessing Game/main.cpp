#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    int num_to_num_guessed = rand() % 100 + 1;
    int num_guessed = 0;
    int attempts = 0;
    char running = 'y';


    cout << "Welcome to the Number Guess Game!" << endl;
    cout << "I have generated a number between 1 and 100. Try to Guess it!" << endl;

    do{
        cout << "Enter your Guess: ";
        cin >> num_guessed;
        
        attempts++;
        if(num_guessed == num_to_num_guessed){
            cout << "Congratulations! You Guess the number in " << attempts << " attempts." << endl;
            running = 'n'; 
        }else if (num_guessed < num_to_num_guessed){
            cout << "Guess Higher" << endl;
        } else{
            cout << "Guess Lower" << endl;
        }
        if(running == 'n'){
            cout << "Do you want to play again? (y/n): ";
            cin >> running;
        }
    }while(running == 'y' || running == 'Y');

    return 0;
}