// LEETCODE 994

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

    vector<vector<int>>dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));

        queue<pair<int,int>>qu;

        int fresh_count = 0;
        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){

                if(grid[i][j] == 2){
                    qu.push({i, j});
                    visited[i][j] = true;
                }

                else if(grid[i][j] == 1) fresh_count++;
            }
        }

        if(fresh_count == 0) return 0;

        int time = 0;

        while(!qu.empty()){

            int size = qu.size();
            for(int i=0; i<size; i++){
                
                auto curr_cell = qu.front();
                qu.pop();

                int curr_x = curr_cell.first;
                int curr_y = curr_cell.second;

                for(auto &d: dir){

                    int new_x = curr_x + d[0];
                    int new_y = curr_y + d[1];

                    if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || grid[new_x][new_y] == 0 || visited[new_x][new_y] == true){

                        continue;
                    }

                    qu.push({new_x, new_y});
                    grid[new_x][new_y] = 2;
                    visited[new_x][new_y] = true;
                    fresh_count--;
                }

            }

            time++;
        }

        cout<<fresh_count<<endl;
        if(fresh_count == 0) return time-1;
        return -1;
    }
};