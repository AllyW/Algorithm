//
// Ally Wang 17/04/2015
//

#include <iostream>
#include <vector>
using namespace std;

 bool dfs(int i, int j, int M, int N, vector<vector<char>> grid, vector<vector<bool>> &visited)
    {
        if(!visited[i][j])
        {
            visited[i][j] = true;
            if(grid[i][j] == '1'){
                if(i>0) dfs(i-1, j, M, N, grid, visited);
                if(i<M-1) dfs(i+1, j, M, N, grid, visited);
                if(j>0) dfs(i, j-1, M, N, grid, visited);
                if(j < N-1) dfs(i, j+1, M, N, grid, visited);
                return true;
            }else{
                return false;
            }
        }
        else
        {
            return false;
        }
    }

int numIslands(vector<vector<char>> &grid) {
        if(grid.size() <= 0 || grid[0].size() <= 0) return 0;
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        int res = 0;
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(dfs(i, j, M, N, grid, visited)) res++;
            }
        }
        return res;
}

void vectorDisplay(vector<vector<char>> grid)
{
	int M = grid.size();
	int N = grid[0].size();
	for(int i = 0; i < M; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			cout << grid[i][j]<< " ";
		}
		cout << endl;
	}
	return;
}

int main() {
    vector<vector<char>> grid(5, vector<char> (5, '0'));
	grid = {
		{'0', '1', '1', '1', '0'},
		{'0', '1', '0', '0', '0'}, 
		{'0', '0', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'1', '0', '1', '1', '1'}
	};
	vectorDisplay(grid);
	int res = numIslands(grid);
	cout << "number of islands: " << res <<endl;
	cout << endl;
	grid = {
		{'1', '1', '1', '1', '0'},
		{'1', '1', '0', '1', '0'}, 
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'}
	};
	vectorDisplay(grid);
	res = numIslands(grid);
	cout << "number of islands: " << res <<endl;
	cout <<endl;

	grid = {
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'}, 
		{'0', '0', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'}
	};
	vectorDisplay(grid);
	res = numIslands(grid);
	cout << "number of islands: " << res <<endl;
	cout << endl;
    return 0;
}
