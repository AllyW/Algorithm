// 
// Ally Wang   04/20/2015
//
// Q: grid: q w e r
//          t r e s 
//          y t r a 
//          a b c d
         
// input: trert output: yes/no
//         trat no
// yty no
// ytra
#include <iostream>
#include <vector>
using namespace std;

bool dfs(int i, int j, int pos, string s, vector<vector<char>> grid, vector<vector<bool>> &visited)
{
    if(visited[i][j]) return false;
    if(pos == s.size()) return true;
    if(grid[i][j] == s[pos])
    {
        visited[i][j] = true;  
        if(i > 0 && dfs(i-1, j, pos+1, s, grid, visited)) return true;
        if(i < 3 && dfs(i+1, j, pos+1, s, grid, visited)) return true;
        if(j > 0 && dfs(i, j-1, pos+1, s, grid, visited)) return true;
        if(j < 3 && dfs(i, j+1, pos+1, s, grid, visited)) return true;
        visited[i][j] = false;
    }
    
    return false;
}

bool findWord(vector<vector<char>> grid, string target)
{
    int M = 4; 
    int N = 4;
    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(grid[i][j] == target[0])
            {
                vector<vector<bool>> visited(4, vector<bool> (4, false)); 
                if(dfs(i, j, 0, target, grid, visited))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> grid = 
    {
        {'q', 'w', 'e', 'r'},
        {'t', 'r', 'e', 's'},
        {'y', 't', 'r', 'a'},
        {'a', 'b', 'c', 'd'}
    };
    
    string target;
    cin >> target;
    if(findWord(grid, target))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
} 
