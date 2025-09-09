#include <iostream>
#include <ctime>

using namespace std;

int main(){
    cout << "**********************************" << endl;
    cout << "******** BATTLESHIP WAR **********" << endl;
    cout << "**********************************" << endl;
    
    // Battleships's Coordinates: '1' indicates presence of a ship while '0' indicates absecnce 
    bool userPlane[][4] ={
        {0, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 1, 0}
    };

    bool computerPlane[][4] ={
        {0, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 1, 0}
    };
    
    srand(time(NULL));
    int usersHit = 0; //Number of battleships the user has hit
    int usersTurns = 0; // Number of times the user has played
    int computersHit = 0;
    int computersTurn = 0;
 
    cout << "Enter co-ordinate values between 0 and 3" << endl;
    
    while(usersHit < 5){
        // User's Turn
        int row; 
        int col;

        cout << "\n--------------------------------------------" << endl;
        cout << "\t\tUSER'S TURN" << endl;
        cout << "--------------------------------------------" << endl;

        cout << "Enter row: ";
        cin >> row;

        cout << "Enter column: ";
        cin >> col; 
        cout <<"------------------------------------------>>" << endl;

        if(userPlane[row][col]){
            usersHit++;
            userPlane[row][col] = 0;
            
            cout << "Launching missile....You hit a Ship!" << endl;
            //cout << "You hit a Ship!" << endl;
        }
        else{
            cout << "launching missile....Splash, you missed!" << endl;
            //cout << "Splash..you missed!" << endl;
        }

        cout << "------------------------------------------>>" << endl << endl;

        // Computer's Turn 
        int c_row = rand() % 4; //Computer's coordinates
        int c_col = rand() % 4;
        
        cout << "--------------------------------------------" << endl;
        cout << "\t\tCOMPUTER'S TURN" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Computer's row: " << c_row << endl;
        cout << "Computer's column: " << c_col << endl;
        cout << "Coordinates [" << c_row << "][" << c_col << "]" << endl;
 
        cout << "------------------------------------------>>" << endl;
        if(computerPlane[c_row][c_col]){
            computersHit++;
            computerPlane[c_row][c_col] = 0;
            
            cout << "launching missile....Computer hits a Ship!" << endl;
            //cout << "Computer hits a Ship!" << endl;
        }
        else{
            cout << "launching missile....Splash, computer missed!" << endl;
            //cout << "Splash..computer missed!" << endl;
        }

        cout << "------------------------------------------>>" << endl <<endl;
        cout << "SCORE COUNT:" << endl;
        cout << "You: " << usersHit << endl;
        cout << "Computer: " << computersHit << endl;
    }

    if(usersHit == 5){
        cout << "\nYou win!" << endl;
        cout << "You hit " << usersHit << " Battleships." << endl;
        cout << "Computer hit " << computersHit << " Battleships";
    }
    else if(computersHit == 5){
        cout << "\nYou lose!" << endl;
        cout << "You hit " << usersHit << " Battleships." << endl;
        cout << "Computer hit " << computersHit << " Battleships";
    }

    return 0;
}
