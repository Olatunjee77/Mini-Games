#include <iostream>
#include <ctime>

using namespace std;

int main (){

    int num; //The unknown number 
    int guess; // The user's guess
    int tries; //The amount of trial 

    cout << "********* NUMBER GUESSING GAME ************" << endl;

    srand (time(NULL));
    num = ( rand() % 50 ) + 1 ;

    do{
        cout << "Enter your guess between (1-50): ";
        cin >> guess;
        tries ++;

        if (guess < num){
            cout <<"Too low, pick a higher value" << endl <<endl;
        }
        else if (guess > num){
            cout <<"Too high, pick a lower value" << endl << endl;
        }
        else if(guess == num) {
             cout << "CORRECT!" << endl << "You had " << tries << " trials." << endl;
        }
        
    }while(num != guess);

    cout << "******************************************" << endl;


    return 0;
}