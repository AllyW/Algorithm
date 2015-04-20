//
//  Created by Ally Wang on 20/04/15.
//  Copyright (c) 2015 Ally Wang. All rights reserved.
//
// Fidn all the distance from 1 to the closest 2 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int row, int col, int M, int N, vector<vector<int>> grid, vector<vector<int>> &res)
    {
		for(int i = 0; i < M; ++i)
		{
			for(int j = 0; j < N; ++j)
			{
				if(grid[i][j] == 1)
				{
					int dist = abs(row-i)+abs(col-j);
					if(res[i][j] == 0)
					{
						res[i][j] = -dist;
					}else
					{
						res[i][j] = max(-dist, res[i][j]);
					}
				}else if(grid[i][j] == 2)
				{
					res[i][j] = 0;
				}else
				{
					res[i][j] = 1;
				}
			}
		}

    }

vector<vector<int>> smallestDistance(vector<vector<int>> &grid) {
    	//if(grid.size() <= 0 || grid[0].size() <= 0) return 0;
        int M = grid.size();
        int N = grid[0].size();
		queue<pair<int, int> > q;
		vector<vector<int>> res(M, vector<int>(N, 0));
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(grid[i][j] == 2)
					q.push(make_pair(i, j));
            }
        }
		while(!q.empty())
		{
			pair<int, int> it = q.front(); q.pop();
			bfs(it.first, it.second, M, N, grid, res);
		}
        return res;
}

void vectorDisplay(vector<vector<int>> grid)
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
    vector<vector<int>> grid(3, vector<int> (3, 0));
	grid = {
		{1, 2, 1},
		{1, 0, 1}, 
		{1, 2, 1}
	};
	vectorDisplay(grid);
	vector<vector<int>> res(3, vector<int> (3, 0));
	res = smallestDistance(grid);
	cout << "the smallest distance from 1 to 2: "<<endl;
	vectorDisplay(res);
	cout << endl;
	grid = {
		{0, 1, 2},
		{2, 1, 0}, 
		{1, 1, 1}
	};
	vectorDisplay(grid);
	res = smallestDistance(grid);
	cout << "the smallest distance from 1 to 2: "<<endl;
	vectorDisplay(res);
	cout <<endl;
    return 0;
}
