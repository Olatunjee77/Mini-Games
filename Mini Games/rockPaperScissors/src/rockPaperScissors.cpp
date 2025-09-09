#include <iostream>
#include <ctime>
using namespace std;

char userChoice(){
    cout <<"Enter" << endl << "r for Rock " << endl << "p for Paper" << endl << "s for Scissors" << endl 
    << "0 to Exit game" << endl;
    char choice;
    cout << ">: ";
    cin >> choice;

    return choice;
}

void showUserChoice(char choice){
    switch(choice){
        case 'r':
        case 'R':
            cout << "Player's choice: Rock";
            break;
        case 'p':
        case 'P':
            cout << "Player's choice: Paper";
            break;
        case 's':
        case 'S':
            cout << "Player's choice: Scissors";
            break;
        default:
            cout << "Invalid choice! Please choose 'r', 'p', 's', or '0' to exit." << endl << endl;
            break;
        }
}

char computerChoice(){
    int choice = (rand() % 3) + 1 ;
    char computer;
    switch(choice){
        case 1:
            computer = 'r';
            break;
        case 2:
            computer = 'p';
            break;
        case 3: 
            computer = 's';
            break; 
    }
    
    return computer;
}

void showComputerChoice(char computer){
    switch(computer){
        case 'r':
            cout << "Computer's choice: Rock";
            break;
        case 'p':
            cout << "Computer's choice: Paper";
            break;
        case 's':
            cout << "Computer's choice: Scissors";
            break;
        }
}

void chooseWinner(char player, char computer){
    switch(player){
        case 'r':
        case 'R':
            if(computer == 'r'){
                cout << "It's a tie!" << endl;
            }
            else if(computer == 'p'){
                cout << "You lose!" << endl;
            }
            else{
                cout << "You win!" << endl;
            }
        break;

    case 'p':
    case 'P':
        if(computer == 'r'){
            cout << "You win!" << endl;
        }
        else if(computer == 'p'){
            cout << "It's a tie!" << endl;
        }
        else{
            cout << "You lose!" << endl;
        }
    break;

    case 's':
    case 'S':
        if(computer == 'r'){
            cout << "You lose!" << endl;
        }
        else if(computer == 'p'){
            cout << "You win!" << endl;
        }
        else{
            cout << "It'a tie!" << endl;
        }
    break;
    }
}

int main(){
    
    cout <<"*************************************" << endl;
    cout <<"***** ROCK-PAPER-SCISSORS GAMES *****" << endl ;
    cout <<"*************************************" << endl ;
    
    char player;
    char computer;
    srand(time (NULL));

    do{
        player = userChoice();
        if(player == '0') {   // ✅ exit before running game logic
            cout << "\nExiting game... Goodbye!" << endl;
            break;
        }

        cout << endl;

        showUserChoice(player);
        if(player != 'r' && player != 'R' && player != 'p' && player != 'P'
            && player != 's' && player != 'S') {
            continue;  // Skip to next iteration if input is invalid
        }

        cout << endl;

        computer = computerChoice();
        showComputerChoice(computer);

        cout << endl;

        chooseWinner(player , computer);
        cout << endl;
    }while(player != '0');
    
    return 0;

}