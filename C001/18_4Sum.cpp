// LEETCODE 18

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

Algortithm:

    1. n1 + n2 + n3 + n4 == target;
    2. We will run a loop from idx 0 to n-4, and choose every nums[i] as n1, then in nexted loop, from i+1 to n-3, we will choose a nums[j] as n2 and find n1 + n2 and then using concept of two_sum, we will find two sum equivalent to = target-(n1+n2)

*/

class Solution {
public:

    vector<vector<int>>finalAns;

    void two_sum(vector<int>&nums, int target, int s, int e, int n1, int n2){

        long long new_target = (long long)(target-n1) - n2;

        while(s < e){

            if(nums[s] + nums[e] < new_target) s++;

            else if(nums[s] + nums[e] > new_target) e--;

            else{

                finalAns.push_back({n1, n2, nums[s], nums[e]});

                while(s < e && nums[s] == nums[s+1]) s++;
                while(s < e && nums[e] == nums[e-1]) e--;

                s++;
                e--; 
            }
        }   
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<=n-4; i++){ // for selecting n1 == nums[i]

            if(i != 0 && nums[i] == nums[i-1]) continue;

            for(int j = i+1; j <= n-3; j++){ // for selecting n2 == nums[j]

                if(j != i+1 && nums[j] == nums[j-1]) continue; // important condition

                two_sum(nums, target, j+1, n-1, nums[i], nums[j]);
            }
        }

        return finalAns;
    }
};