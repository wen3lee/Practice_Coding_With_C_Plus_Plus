using namespace std;

const int SIZE = 4; 

class TicTacToe
{
    
    
public:
    //Create a 4x4 game board
    char board[SIZE][SIZE];

    TicTacToe();
    void printInfo();
};

//constor
TicTacToe::TicTacToe()
{
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {    
            board[i][j] = '-';    
        }
    }    
}

void TicTacToe::printInfo()
{
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {    
            cout << board[i][j] << " ";    
        }
        
        cout << "\n";
    }
}
