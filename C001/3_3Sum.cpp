// LEETCODE 15

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
If we want elements instead of index, we can sort and apply 2 pointers technique
https://youtu.be/_cBWWebTVpI?si=nehNIPIRbEw5QflH --> Video is helpful

Change this question to 2_sum, n1+n2 = -n3

Algorithm:

    1. Fix an index 'i'(n1 = nums[i]), for which search in remaining array form (i+1 to n-1) such that n2+n3 = -n1
*/

class Solution {
public:

    void two_sum(vector<int>&nums, vector<vector<int>>&finalAns, int s, int e, int target){

        while(s < e){

            if(nums[s] + nums[e] >  target) e--;
            else if(nums[s] + nums[e] < target) s++;

            else{

                finalAns.push_back({-target, nums[s], nums[e]});
                while(s < e && nums[s] == nums[s+1]) s++;
                while(s < e && nums[e] == nums[e-1]) e--;
                s++;
                e--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>finalAns;

        sort(nums.begin(), nums.end());

        for(int i=0; i<=nums.size()-3; i++){ // coz atleat 2 elements to hone hi chahiye search karne ke liye

            if(i != 0 && nums[i] == nums[i-1]) continue; // v-imp: coz if fixed element is repeted the whole triplet is repeted coz the search array of smaller_idx duplicate fixed_element will be super set of larger_idx duplicate fixed_element

            two_sum(nums, finalAns, i+1, nums.size()-1, -nums[i]);
        }

        return finalAns;
    }
};