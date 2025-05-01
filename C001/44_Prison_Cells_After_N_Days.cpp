// LEETCODE 957 --> Simple pattern observation

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
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        
        int pattern_day = n%7;
        bool rev = false;
        if( (n/7) % 2 != 0) rev = true; // for n%7 != 0 if n/7 is odd the result will be reversed;  

        if(n%7 == 0){
            
            pattern_day = 7;
            if( (n/7) % 2 != 0) rev = false;
            else rev = true;
        }
       
        vector<int>updated_cells = cells;

        for(int i=1; i<=pattern_day; i++){

            for(int j=1; j<=6; j++){

                if(
                    (cells[j-1] == 0 && cells[j+1] == 0) ||
                    (cells[j-1] == 1 && cells[j+1] == 1)
                ){
                    updated_cells[j] = 1;
                }

                else updated_cells[j] = 0;
            }
            updated_cells[0] = 0;
            updated_cells[7] = 0;

            cells = updated_cells;
        }

        if(rev == true) reverse(cells.begin(), cells.end());
        return cells;

    }
};