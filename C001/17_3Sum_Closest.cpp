// LEETCODE 16

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

Algorithm:

    1. n1+n2+n3 should be close to target, so abs( (n1+n2) - (target-n3) ) should be minimum
    2. name target-n3 as rhs

*/

class Solution {
public:

    void minimize_rhs_two_sum_diff(vector<int>&nums, int &min_diff, int &sum_of_triplet, int s, int e, int target, int n3){

        while(s < e){

            int diff = abs( (nums[s]+nums[e]) - (target-n3) );

            if(diff < min_diff){

                min_diff = diff;
                sum_of_triplet = nums[s]+nums[e]+n3;
            }

            if(min_diff == 0) break;

            if(nums[s] + nums[e] < (target-n3)) s++;
            else e--;
        }
    }

    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int min_diff = INT_MAX; // abs(n1+n2-rhs);
        int sum_of_triplet = 0;

        for(int i=0; i<=n-3; i++){

            if(i != 0 && nums[i] == nums[i-1]) continue;

            // nums[i] = n3
            minimize_rhs_two_sum_diff(nums, min_diff, sum_of_triplet, i+1, n-1, target, nums[i]);

            if(min_diff == 0) break;
        }

        return sum_of_triplet;
    }
};