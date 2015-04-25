//
//  Created by Ally Wang on 25/04/15.
//
// Find all the distance from child (0) to the closest police(1), but cannot get across the wall(2)  
// Mind visited to mark visited node.
//
#include <iostream>
#include <vector>
#include <queue>
#include <utility>  // make_pair and pair
using namespace std;

void bfs(int row, int col, int M, int N, vector<vector<int>> grid, vector<vector<int>> &res)
    {
		vector<vector<bool>> visited(M, vector<bool>(N, false));
        // keyword to mark the repeated node 
		queue<pair<int, int>> po;
		po.push(make_pair(row,col));
		po.push(make_pair(-5,-5)); // mark the boundary
		int dist = 0;
		while(!po.empty())
		{
			pair<int, int> p = po.front();
			po.pop();
			int i = p.first;
			int j = p.second;
			//cout << i << " " << j << endl;
			if(i == -5)
			{
				if(po.empty()) break;
				dist++;
				po.push(make_pair(-5,-5));
			}
			else{
				if( i < 0 || i >= M || j < 0 || j >= N) continue;
				if(visited[i][j]) continue; // !! avoid repeated node pushed in 
				visited[i][j] = true;
				if(grid[i][j] == 2) continue;
				if(grid[i][j] == 1)
				{
					res[i][j] = 0;
				}
				else
				{
					if(res[i][j] == -1)
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
		vector<vector<int>> res(M, vector<int>(N, -1));
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(grid[i][j] == 1)
					bfs(i, j, M, N, grid, res);
            }
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
	cout << "grid: " << endl;
	vectorDisplay(grid);
	vector<vector<int>> outp(3, vector<int> (3, 0));
	outp = smallestDistance(grid);
	cout << "the smallest distance from child(0) to police(1): "<<endl;
	vectorDisplay(outp);
	cout << endl;
	grid = {
		{0, 2, 0},
		{0, 2, 0}, 
		{0, 2, 1}
	};
	cout << "grid: " <<endl;
	vectorDisplay(grid);
	outp = smallestDistance(grid);
	cout << "the smallest distance from child(0) to police(1): "<<endl;
	vectorDisplay(outp);
	cout <<endl;
    return 0;
}
