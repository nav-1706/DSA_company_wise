// LEETCODE 88
// A good question: https://www.youtube.com/watch?v=n7uwj04E0I4

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

    // TC = O(n+m) SC = O(1)

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // we will start filling from right to left (biggest to smallest)
        int k = m+n-1;
        int i = m-1;
        int j = n-1;

        while(i>=0 && j >= 0){

            if(nums1[i] >= nums2[j]){

                nums1[k] = nums1[i];
                i--;
                k--;
            }

            else{
                
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }

        while(i >= 0){

            nums1[k] = nums1[i];
            i--;
            k--;
        }

        while(j >= 0){

            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};