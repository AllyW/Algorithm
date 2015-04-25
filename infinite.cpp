//
//  Created by Ally Wang on 20/04/15.
//  Copyright (c) 2015 Ally Wang. All rights reserved.
//
// Find all the distance from child (0) to the closest police(1), but cannot get across the wall(2)  

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void bfs(int row, int col, int M, int N, vector<vector<int>> grid, vector<vector<int>> &res)
    {
		queue<pair<int, int>> po;
		po.push(make_pair(row,col));
		po.push(make_pair(-5,-5)); // mark the boundary
		int dist = 0;
		while(!po.empty())
		{
			pair<int, int> p = po.front();
			po.pop();
			cout << row << " " << col << endl;
			int i = p.first;
			int j = p.second;
			cout << i << " " << j << endl;
			if(i == -5)
			{
				if(po.empty()) break;
				dist++;
				po.push(make_pair(-5,-5));
			}
			else{
				if( i < 0 || i >= M || j < 0 || j >= N) continue;
				if(grid[i][j] == 2) continue;
				if(grid[i][j] == 1)
				{
					res[i][j] = 0;
				}
				else
				{
					if(res[i][j] == 0)
					{
						res[i][j] = dist;
					}else{
						res[i][j] = min(dist, res[i][j]);
					}
				}
				po.push(make_pair(i-1, j));
				po.push(make_pair(i+1, j));
				po.push(make_pair(i, j-1));
				po.push(make_pair(i, j+1));
			}
		}
    }

vector<vector<int>> smallestDistance(vector<vector<int>> &grid) {
    	//if(grid.size() <= 0 || grid[0].size() <= 0) return 0;
        int M = grid.size();
        int N = grid[0].size();
		queue<pair<int, int> > q;
		vector<vector<int>> res(M, vector<int>(N, -1));
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(grid[i][j] == 1)
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
		{0, 1, 0},
		{0, 2, 0}, 
		{0, 0, 0}
	};
	vectorDisplay(grid);
	vector<vector<int>> res(3, vector<int> (3, 0));
	res = smallestDistance(grid);
	cout << "the smallest distance from child(0) to police(1): "<<endl;
	vectorDisplay(res);
	cout << endl;
	grid = {
		{0, 2, 0},
		{0, 2, 0}, 
		{0, 2, 1}
	};
	vectorDisplay(grid);
	res = smallestDistance(grid);
	cout << "the smallest distance from child(0) to police(1): "<<endl;
	vectorDisplay(res);
	cout <<endl;
    return 0;
}
