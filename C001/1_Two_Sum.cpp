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
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>visited; // <num, idx>
        for(int i=0; i<nums.size(); i++){

            if(visited.find(target-nums[i]) != visited.end()) return {i, visited[target-nums[i]]};
            visited[nums[i]] = i;
        }

        return {-1,-1};
    }
};