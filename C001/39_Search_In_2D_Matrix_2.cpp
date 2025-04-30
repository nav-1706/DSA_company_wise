// LEETCODE 240

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

/*

NOTE: ONLY APPLICABLE when:
1. Integers in each row are sorted in ascending from left to right.
2. Integers in each column are sorted in ascending from top to bottom.

---------------- ALGORITHM ----------------

[[ 1,  4,  7, 11, 15],
 [ 2,  5,  8, 12, 19], 
 [ 3,  6,  9, 16, 22],
 [10, 13, 14, 17, 24],
 [18, 21, 23, 26, 30]]

Suppose we want to search for 12 in the above matrix. compare 12 with the top-right element nums[0][4] = 15. Since 12 < 15, 12 cannot appear in the column of 15 since all elements in that column are greater than or equal to 15. Now we reduce the search space by one column (the last column).

We further compare 12 with the top-right element of the remaining matrix, which is nums[0][3] = 11. Since 12 > 11, 12 cannot appear in the row of 11 since all elements in this row are less than or equal to 11 (the last column has been discarded). Now we reduce the search space by one row (the first row).

We move on to compare 12 with the top-right element of the remaining matrix, which is nums[1][3] = 12. Since it is equal to 12, we return true.

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n-1;

        while(row < m && col >= 0){

            if(matrix[row][col] == target) return true;

            if(matrix[row][col] > target){ // discard column;
                col--;
            }

            else row++; // discard row
        }

        return false;
    }
};