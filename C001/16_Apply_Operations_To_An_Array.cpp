// lEETCODE 2460: Trick: Move 0 to end, while maintaing the relative order

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
    vector<int> applyOperations(vector<int>& nums) {
        
        int n = nums.size();

        for(int i=0; i<n-1; i++){

            if(nums[i] != nums[i+1]) continue;

            nums[i] *= 2;
            nums[i+1] = 0;
        }

        int i = 0;
        
        for(int j=0; j<n; j++){

            if(nums[j] != 0){

                swap(nums[j], nums[i]);
                i++;
            }
        }

        return nums;
    }
};