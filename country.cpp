#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool safe(int i, int j, vector<vector<bool>> &visited)
{
	if ((i >= 0) and (i < visited.size()) and (j >= 0) and (j < visited[0].size()) and (visited[i][j] == false))
	{
		// debug
		//cout << "i: " << i << " j: " << j << " is safe!" << endl; 

		return true;
	}

	return false;
}


int solution(vector<vector<int> > A) 
{
	int M = A[0].size();
	int N = A.size();

	queue<int> location;
	int position = 0;
	int country = 0;
	int country_num = 0;
	int new_i = 0, new_j = 0;

	// init
	vector <bool> visited_(A[0].size(), false);
	vector <vector<bool> > visited(A.size(), vector <bool>(A[0].size(), false));


	// debug	
	/*for(int i=0; i<visited.size(); i++)
	{
		for (int j=0; j<visited[i].size(); j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;	
	}
	*/

	// debug
	//cout << "M: " << M << " N: " << N << endl; 

	for (int i=0; i<N; i++)
	{
		for (int j=0; j<M; j++)
		{
			if (!visited[i][j])
			{
				visited[i][j] = 1;
				country = A[i][j];

				location.push(i * M + j);
				country_num++;

				// debug
				//cout << "new loc: " << (i * M + j) << " country_num: " << country_num << endl;
				
				// bfs
				while(!location.empty())
				{
					position = location.front();
					location.pop();

					new_i = position / M;
					new_j = position % M;
					
					// debug
					//cout << "new pos: " << new_i << ", " << new_j << endl;

					// top
					if (safe(new_i-1, new_j, visited) and (A[new_i-1][new_j] == country))
					{
						visited[new_i-1][new_j] = true;
						location.push((new_i-1) * M + new_j);

						// debug
						//printf("Top! (%d, %d)\n", new_i-1, new_j);
					}	

					//left
					if (safe(new_i, new_j-1, visited) and (A[new_i][new_j-1] == country))
					{
						visited[new_i][new_j-1] = true;
						location.push(new_i * M + (new_j-1));

						// debug
						//printf("Left! (%d, %d)\n", new_i, new_j-1);
					}	
	
					//down
					if (safe(new_i+1, new_j, visited) and (A[new_i+1][new_j] == country))
					{
						visited[new_i+1][new_j] = true;
						location.push((new_i+1) * M + new_j);

						// debug
						//printf("Down! (%d, %d)\n", new_i+1, new_j);
					}	

					//right
					if (safe(new_i, new_j+1, visited) and (A[new_i][new_j+1] == country))
					{
						visited[new_i][new_j+1] = true;
						location.push(new_i * M + (new_j+1));

						// debug
						//printf("Right! (%d, %d)\n", new_i, new_j+1);
					}
				}	
			}	
		}	
	}

	return country_num;	
}

int main()
{
	//test1 ans: 11
	vector<vector<int> > A{{5, 4, 4}, {4, 3, 4}, {3, 2, 4}, {2, 2, 2}, {3, 3, 4}, {1, 4, 4}, {4, 1, 1}};
	
	cout << solution(A) << endl;

	return 0;
}