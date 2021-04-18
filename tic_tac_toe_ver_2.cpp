// Tic Tac Toe game created by ARNAB JANA.
#include <iostream>
// Creating a tic tac toe game using C++
using namespace std;

// Function to create the board/grid.
char** createGrid(int boardSize)
{    
    cout<<"Starting the game! Get ready!"<< endl; 
    // new returns dynamically allocated array. 
    char** board = new char* [boardSize]; // new <datatype> [size]
   
   for (int i=0; i < boardSize; i++)
    {
        board[i] = new char[boardSize];
    }
    return board;
  
}

// Function to display the board.

void displayGrid(char** board,int boardSize)
{
    system("cls");
    cout<< "\n\n";
    int boundary = 3*boardSize;
    // To print the heading separation.
    for(int a=0; a< boundary; a++) 
    {
        cout<< " =";
    }
    cout<< endl;
    
    // The main logic for the board.
    for(int i=0; i< boardSize; i++)
    {    
        for(int b=0;b< 2*(boardSize - 1); b++)
            {cout<<" ";}
        for(int j=0; j< boardSize; j++)
        {
            if(j< boardSize -1)
            {
                cout<< " " << board[i][j] << " |";
            }
            else{ cout<< " "<<  board[i][j] << " "<< endl;}

        }
        if(i< boardSize - 1)
        {
           for(int a=0; a< boundary; a++) 
            {
               cout<< " -";
            }  
        cout<< endl;
        }

    }
     // To print the ending separation.
     for(int a=0; a< boundary; a++) 
    {
        cout<< " =";
    }
    cout << '\n';
 }

// Labelling the board

void fillBoard(char** board,int boardSize)
{
   char count='1';
   for(int i=0; i< boardSize; i++)
   {
       for(int j=0; j< boardSize; j++)
       {
           board[i][j] = count++;
           
       } 
   }
   //return board;
}

// Function to change the position in board from a single number to (row, col) 
// coordinates.

void choiceToRowCols(int* x, int* y, int boardSize)
{
    int pos;
    cin >> pos;
    *x = (pos - 1)/ boardSize;
    *y = (pos - 1) % boardSize;

}

// The function to check who wins/ the function for the winner checking.

int winCondition(char** board, int boardSize, int playerTurn)
{
    // left diagonal and right diagonal initialization.
    char leftDiag = board[0][0]; int leftDiagMatch = 0;
    char rightDiag  = board[boardSize - 1][0]; int rightDiagMatch = 0;
  


    for (int i=0; i< boardSize; i++)
    {
        //checking condition for left diagonal and right diagonal match.
        if(board[i][i] == leftDiag)
            { leftDiagMatch++;}
        if(board[boardSize -1 -i][i] == rightDiag)
            {rightDiagMatch++;}
        if(leftDiagMatch == boardSize || rightDiagMatch == boardSize)
            {return playerTurn;}


        // checking the rows and columns.
        char rowVal = board[i][0]; int rowMatch = 1;
        char colVal  = board[0][i]; int colMatch =1;
        for(int j=0; j< boardSize; j++)
        {
            if(board[i][j]== rowVal)
                {rowMatch++;}
            if(board[j][i]== colVal)
                {colMatch++;}
        }
        if(rowMatch == boardSize +1 || colMatch == boardSize + 1)
            {return playerTurn;}

        
    }
    return -1;



}

// RUNNING THE GAME.
void game(char** board, int boardSize, char** playersInfo)
{
    char symbols[] = {'X', 'O'};
    int playerTurn =1, round=0;
    //fillBoard(board,boardSize);
    displayGrid(board, boardSize); // showing the board before game starts.

    while(round<9)
    {
      playerTurn = (playerTurn) ? 0:1 ; // Alternate the player turns
      int x,y,pos;

      cout << playersInfo[playerTurn] << " , your turn now: " ;
      choiceToRowCols(&x, &y, boardSize);
      board[x][y] = symbols[playerTurn];

      displayGrid(board, boardSize);   // showing the board after each round.

      int winner = winCondition(board,boardSize,playerTurn);

      if(winner != -1)
         {cout << playersInfo[winner] << " has won the game!! Congrats" << endl;
         return;}
    
      round++;
    }

    cout << "It's a draw!!" << endl;
    exit(0);


}


// Fetching the player names.

char** players()
{
    char** playerNames = new char* [2];
    for(int i=0; i<2;i++)
    {
        playerNames[i] = new char[30];
        cout << "Player " << (i+1) << " enter your name: ";
        cin >> playerNames[i];
    }

    return playerNames;
}


// Main function to oraganize and maintain the game. 
int main() { 
    int boardSize;
    cout<< "Enter the board size: ";
    cin>> boardSize;
    char** board = createGrid(boardSize);
    string playAgain = "y";
    
    while(playAgain == "y" || playAgain == "yes" ||playAgain == "Y" || playAgain == "Yes" )
    {

    fillBoard(board,boardSize);
    displayGrid(board,boardSize);

    char** playersInfo = players();
    game(board,boardSize,playersInfo);

    cout << "Do you wanna play again? yes(y) or No (N) : ";
    cin >> playAgain;
    
    }


    return 0;
}
