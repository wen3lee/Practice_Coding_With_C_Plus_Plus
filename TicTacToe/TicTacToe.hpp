using namespace std;

const int SIZE = 4; 

class TicTacToe
{
    // selected position (i,j)
    int position_i;
    int position_j;
    
public:
    // users
    string user1;
    string user2;

    //Create a 4x4 game board
    char board[SIZE][SIZE];

    TicTacToe();
    int selectAPosition(int num);
    int isAcceptedPostion();
    int isWinner(int num);
    void winnerInfo(int num);
    void printInfo();
};

//constor
TicTacToe::TicTacToe()
{
    position_i = 0;
    position_j = 0;

    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {    
            board[i][j] = '-';    
        }
    }    
}

int TicTacToe::selectAPosition(int num)
{
    int input_times = 0;

    do
    {
        input_times++; 

        // fail selection
        if(input_times >= 5)
        {    
            cout << "Input error is more than five times.\n";
            return -1;
        }  

        // Prompt the 'x' user to select a grid position where they would like to place an 'x'. 
        // Prompt the 'o' user to select a grid position where they would like to place an 'o'.
        if (num % 2 == 0) // first user
        {
            cout << user1; 
        }
        else// (i % 2 == 1) // second user
        {
            cout << user2; 
        }

        printf(", please select a position: (ex. 0 0) \n");
        printInfo();

        cin >> position_i;
        // consider input fail
        if(cin.fail())
        {
            cout << "Input error! The input should be integers.\n";
            cin.clear();
            cin.ignore();
            position_i = -1;
            position_j = -1;
            continue; 
        }

        cin >> position_j;
        // consider input fail
        if(cin.fail())
        {
            cout << "Input error! The input should be integers.\n";
            cin.clear();
            cin.ignore();
            position_i = -1;
            position_j = -1;
            continue;
        }

        // debug
        //printf("(%d, %d)\n", i, j);
    }while(isAcceptedPostion());

    // selected
    if (num % 2 == 0) // first user
    {
        board[position_i][position_j] = 'x';       
    }
    else// (i % 2 == 1) // second user
    {
        board[position_i][position_j] = 'o';
    }    

    return 0;
}

int TicTacToe::isAcceptedPostion()
{
    // out of boundary
    if (position_i < 0 || position_i >= SIZE || position_j < 0 || position_j >= SIZE)
    {
        cout << "The input position is out of boundary!\n";
        return -1;
    }

    // occupied   
    if (board[position_i][position_j] != '-')
    {
        cout << "The input position is occupied!\n";
        return -1;
    }    

    return 0;
}

int TicTacToe::isWinner(int num)
{
    int count = 0;
    int i = 0;

    // horizontal
    for (i=0; i<SIZE; i++)
    {   
        if ((board[position_i][i]) == board[position_i][position_j])
        {    
            count++;
        }
        else
        {
            break;
        }    
    }

    if (count >= SIZE)
    {
        winnerInfo(num);
     
        return 0;
    }   

    // vertical
    count = 0;

    for (i=0; i<SIZE; i++)
    {   
        if ((board[i][position_j]) == board[position_i][position_j])
        {
            count++; 
        }
        else
        {
            break;
        }         
    }

    if (count >= SIZE)
    {
        winnerInfo(num);
     
        return 0;
    }   

    // diagonally \

    // diagonally /

    return -1;
}

void TicTacToe::winnerInfo(int num)
{
    if (num % 2 == 0) // first user
    {
        cout << user1; 
    }
    else// (i % 2 == 1) // second user
    {
        cout << user2; 
    }

    cout << " is the winner!\n";
    printInfo();
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
