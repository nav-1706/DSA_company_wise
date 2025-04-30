// LEETCODE 200

#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:

    vector<vector<int>>dir = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    void dfs(int currX, int currY, int rows, int cols, vector<vector<char>>& grid,  vector<vector<bool>>&visited){

        visited[currX][currY] = true;

        for(auto d: dir){

            int newX = currX + d[0];
            int newY = currY + d[1];

            if(newX < 0 || newX >= rows || newY < 0 || newY >= cols || visited[newX][newY] == true || grid[newX][newY] == '0') continue;

            dfs(newX, newY, rows, cols, grid, visited);
        }
    }

    int count_island(vector<vector<char>>& grid, vector<vector<bool>>&visited, int rows, int cols){

        int count = 0;
        for(int i=0; i<rows; i++){

            for(int j=0; j<cols; j++){

                if(visited[i][j] == false && grid[i][j] == '1'){

                    count++;
                    dfs(i, j, rows, cols, grid, visited);
                }
            }
        }

        return count;
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>>visited(rows, vector<bool>(cols, false));

        return count_island(grid, visited, rows, cols);
    }
};