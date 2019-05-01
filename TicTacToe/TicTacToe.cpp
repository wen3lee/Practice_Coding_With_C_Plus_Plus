#include <iostream>
#include "TicTacToe.hpp"

using namespace std;

int main()
{
    TicTacToe T;
    string user1, user2;
    int pos;
    int total_loop = SIZE*SIZE-1;

    int i = 0, k = 0;
    int count = 0;
    
    cout << "Please enter the first user's (the 'x' user) name: \n";
    getline(cin, user1);
    
    
    cout << "Please enter the second user's (the 'o' user) name: \n";
    getline(cin, user2);
    
    // loop for input
    for (i=0; i<total_loop; i++)
    {	
	    // Prompt the 'x' user to select a grid position where they would like to place an 'x'. 
		// Prompt the 'o' user to select a grid position where they would like to place an 'o'.
		if (i % 2 == 0) // first user
	    {
		    cout << user1; 
		}
		else// (i % 2 == 1) // second user
		{
			cout << user2; 
		}

		cout << ", please select a grid position (0-" << total_loop << ")\n" ;	
	
	    //check the pos
		cin >> pos;

		if (T.board[pos / SIZE][pos % SIZE] != '-')
		{
			T.printInfo();
			cout << "The position occupied, please select another grid position (0-15)\n";
		}
		else
		{
			if (i % 2 == 0) // first user
		    {
			    T.board[pos / SIZE][pos % SIZE] = 'x';

			    // win?
			    // row
			    count = 0;

			    for (k=0; k<SIZE; k++)
			    {	
			    	if ((T.board[pos / SIZE][k]) == 'x')
			    		count++;  
				}

				if (count >= SIZE)
				{
					cout << user1 << "is the winner!\n";
					return 0;
				}	

			    // column
			    count = 0;

			    for (k=0; k<SIZE; k++)
			    {	
			    	if ((T.board[k][pos % SIZE]) == 'x')
			    		count++;  
				}

				if (count >= SIZE)
				{
					cout << user1 << "is the winner!\n";
					return 0;
				}	
			}
			else// (i % 2 == 1) // second user
			{
				T.board[pos / SIZE][pos % SIZE] = 'o';

				//win?
				// row
			    count = 0;

			    for (k=0; k<SIZE; k++)
			    {	
			    	if ((T.board[pos / SIZE][k]) == 'o')
			    		count++;  
				}

				if (count >= SIZE)
				{
					cout << user2 << "is the winner!\n";
					return 0;
				}	

			    // column
			    count = 0;

			    for (k=0; k<SIZE; k++)
			    {	
			    	if ((T.board[k][pos % SIZE]) == 'o')
			    		count++;  
				}

				if (count >= SIZE)
				{
					cout << user2 << "is the winner!\n";
					return 0;
				}	
			}
		}	
	}

	cout << "The game is tied!\n" 	   
}