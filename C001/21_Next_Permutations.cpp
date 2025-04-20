// LEETCODE 

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

The following algorithm generates the next permutation lexicographically after a given permutation. It changes the given permutation in-place.

    - Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation. (step 1)
    - Find the largest index l greater than k such that a[k] < a[l]. (step 2)
    - Swap the value of a[k] with that of a[l]. (step 3)
    - Reverse the sequence from a[k + 1] up to and including the final element a[n]. (step 4)

For example, given the sequence [1, 2, 3, 4] (which is in increasing order), and given that the index is zero-based, the steps are as follows:

    - Index k = 2, because 3 is placed at an index that satisfies condition of being the largest index that is still less than a[k + 1] which is 4.
    - Index l = 3, because 4 is the only value in the sequence that is greater than 3 in order to satisfy the condition a[k] < a[l].
    - The values of a[2] and a[3] are swapped to form the new sequence [1, 2, 4, 3].
    - The sequence after k-index a[2] to the final element is reversed. Because only one value lies after this index (the 3), the sequence remains unchanged in this instance. Thus the lexicographic successor of the initial state is permuted: [1, 2, 4, 3].


// BONUS C++:   next_permutation(nums.begin(),nums.end());


*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int k = -1;

        for(int i=0; i<n-1; i++){ // step 1

            if(nums[i] < nums[i+1]) k = i; // equal par same is permuatation aa jaaegi
        }

        if(k == -1){ // no next permutations exist, nums is greatest
            
            reverse(nums.begin(), nums.end());
            return;
        }

        int l = -1;
        for(int i = k+1; i<n; i++){ // step 2

            if(nums[i] > nums[k]) l = i;
        }

        swap(nums[k], nums[l]); // step 3 
        // now from idx: [k+1, n-1] array will be sorted in decending order

        reverse(nums.begin()+k+1, nums.end()); // step 4: Reverse from idx:[k+1, n-1];
    }
};