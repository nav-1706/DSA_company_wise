// LEETCODE 11

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

// https://youtu.be/KVU4JNNJkVg?si=7i01oUo-0lrgR3R_

/*

Algorithm:

    1. Suppose we find area between height h1(i-idx) and h2(j-idx) (i < j), and get area A1
    2. So if (h1 < h2) we will move i to i++, so that be can retain the higher(h2) rod, as we are reducing the width, the height should inclrease to have a grater area

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        
        int n = height.size();

        int i = 0;
        int j = n-1;
        int max_area = 0;

        while(i < j){

            int area = (j-i)*min(height[i], height[j]);
            max_area = max(max_area, area);

            if(height[i] <= height[j]) i++;
            else j--;
        }

        return max_area;
    }
    
};