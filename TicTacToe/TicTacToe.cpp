#include <iostream>
#include "TicTacToe.hpp"

using namespace std;

int main()
{
    TicTacToe gameT;

    int loop = SIZE * SIZE;
    int pos;
    
    cout << "Please enter the first user's (the 'x' user) name: \n";
    getline(cin, gameT.user1);
    
    
    cout << "Please enter the second user's (the 'o' user) name: \n";
    getline(cin, gameT.user2);

    // loop for input
    for (int i=0; i<loop; i++)
    {	
    	// select a position
    	if (0 != gameT.selectAPosition(i)) 
    	{
    		// fail selection
    		return -1;
    	}

    	// there is a winner and finish the game
    	if (0 == gameT.isWinner(i))
    	{
    		return 0;
    	}		
	}

	cout << "The game is tied!\n"; 
	return 0;	   
}