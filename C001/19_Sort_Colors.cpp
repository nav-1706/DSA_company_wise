// LEETCODE 75

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

DNF Algorithm:

    1. Push high value at last, low value at begining and don't care about the mid value

    2. We will use 3 pointers: low, mid, high and will keep 4 invariants

        - Everything at the left of low is low-values
        - From the low pointer(included) to the left of middle pointer are mid-values
        - From the mid pointer(included) to the high pointer(includes) are unknow-values
        - Everything to the right og hight pointer has high-values 

    3. Low-pointer is always the first mid-value after the low-value, so when we find a low-value, we will replace it with the low-pointer

    4. Mid_pointer will point to first unknown and depending on this unknow we will swap
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();

        int low = 0; // for 0
        int mid = 0; // for 1
        int high = n-1; // for 2

        while(mid <= high){

            if(nums[mid] == 1) mid++;

            else if(nums[mid] == 0){

                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }

            else{ // nums[mid] == 2

                swap(nums[mid], nums[high]);
                high--;
            }   
        }
    }
};