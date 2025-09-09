#include <iostream>
#include <ctime>

using namespace std;

int main(){
    cout << "**********************************" << endl;
    cout << "******** BATTLESHIP WAR **********" << endl;
    cout << "**********************************" << endl;

    cout << "This is a sample of the Battlefield." << 
            endl << "The No 1-8 represent the Coordinates of Ships '0'. " << 
            endl << "There are 16 Ships on the Battlefield, Hit your opponent's ship to gain points." << endl; 

    int sampleBoard[][9] = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 0, 0},
        {4, 0, 0, 0, 0, 0, 0, 0, 0},
        {5, 0, 0, 0, 0, 0, 0, 0, 0},
        {6, 0, 0, 0, 0, 0, 0, 0, 0},
        {7, 0, 0, 0, 0, 0, 0, 0, 0},
        {8, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int boardRow = sizeof(sampleBoard) / sizeof(sampleBoard[0]);
    int boardCol = sizeof(sampleBoard[0]) / sizeof(sampleBoard[0][0]);

    for(int i=0; i<boardRow; i++){
        for(int j=0; j<boardCol; j++){
            cout << sampleBoard[i][j] << "   ";

            
        }
        cout << endl;
    }
    cout << endl;
    
    // Battleships's Coordinates: '1' indicates presence of a ship while '0' indicates absecnce 
    bool userPlane[][8] ={
        {0, 1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0}
    };

    bool computerPlane[][8] ={
        {1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1}
    };
    
    srand(time(NULL));
    int usersHit = 0; //Number of battleships the user has hit
    int usersTurns = 0; // Number of times the user has played
    int computersHit = 0;
    int computersTurn = 0;
 
    cout << "Enter co-ordinate values between 0 and 7" << endl;
    
    while(usersHit < 16 || computersHit < 16){
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
        int c_row = rand() % 8; //Computer's coordinates
        int c_col = rand() % 8;
        
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

    if(usersHit == 16){
        cout << "\nYou win!" << endl;
        cout << "You hit " << usersHit << " Battleships." << endl;
        cout << "Computer hit " << computersHit << " Battleships";
    }
    else if(computersHit == 16){
        cout << "\nYou lose!" << endl;
        cout << "You hit " << usersHit << " Battleships." << endl;
        cout << "Computer hit " << computersHit << " Battleships";
    }

    return 0;
}
