// LEETCODE 4

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
***************** METHOD 1: BRUTE FORCE **************************

https://youtu.be/6D9T2ZY8h5c?si=tkSM1BTdjOGBmKis

TC = O(m+n)
SC = O(m+n)
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        vector<int>nums;

        int i=0;
        int j=0;

        while(i < n && j < m){

            if(nums1[i] < nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }

            else if(nums1[i] > nums2[j]){
                nums.push_back(nums2[j]);
                j++;
            }

            else{
                nums.push_back(nums1[i]);
                nums.push_back(nums2[j]);
                i++;
                j++;
            }
        }

        while(i < n){
            nums.push_back(nums1[i]);
            i++;
        }

        while(j < m){
            nums.push_back(nums2[j]);
            j++;
        }

        if( (m+n) % 2 == 0) return (nums[(n+m)/2]+nums[(n+m)/2 - 1])/2.0;
        return nums[(n+m)/2];
    }
};

//--------------------------------------------------------------------------

/*
***************** METHOD 2: BETTER APPROACH **************************

https://youtu.be/6D9T2ZY8h5c?si=tkSM1BTdjOGBmKis

TC = O(m+n)
SC = O(1)

Instead of mainating a seprate array nums, we will just maintain two varable element_1(idx: m+n/2) and element_2(idx: m+n/2 - 1), where idx(k) is the index of nums array
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        int element_1_idx = (n+m)/2;
        int element_2_idx = (n+m)/2 - 1;
        int element_1 = -1;
        int element_2 = -1;
        int i = 0; // to itterate on nums1
        int j = 0; // to itterate on nums2
        int k = 0; // to itterate on nums

        while(i < n && j < m){

            if(nums1[i] < nums2[j]){

                if(k == element_1_idx) element_1 = nums1[i];
                if(k == element_2_idx) element_2 = nums1[i]; 

                i++;
            }

            else{

                if(k == element_1_idx) element_1 = nums2[j];
                if(k == element_2_idx) element_2 = nums2[j]; 

                j++;
            }

            k++;
        }

        while(i < n){

            if(k == element_1_idx) element_1 = nums1[i];
            if(k == element_2_idx) element_2 = nums1[i]; 

            i++;
            k++;
        }

        while(j < m){

            if(k == element_1_idx) element_1 = nums2[j];
            if(k == element_2_idx) element_2 = nums2[j]; 

            j++;
            k++;
        }

        if((m+n)% 2 == 0) return (element_1 + element_2)/2.0;
        return element_1;
    }

};


//--------------------------------------------------------------------------

/*
***************** METHOD 3: BEST APPROACH **************************

https://youtu.be/7nABqJCEMuY?si=n3YsdduprDJoB3nq

TC = log(m+n)
SC = O(1)

We will dividide rusultant array in 2 parts: left and right
Left will have: (n+m+1)/2 elements for both odd and even
ex: n = 3, m = 3, (n+m+1)/2 = 7/2 = 3 elements (3 + 3)
ex: n = 5, m = 2, (n+m+1)/2 = 6/2 = 4 elements (4 + 3)
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()){

            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int l = 0;
        int r = m;

        while(l <= r){

            int Px = l + (r-l)/2; // numbers of elements on left side from nums1;
            int Py = (m+n+1)/2 - Px; // numbers of elements on left side from nums2;

            // Left Half
            int x1 = (Px == 0)? INT_MIN : nums1[Px-1]; // last of the elements picked from nums1 on left side of resultant array
            int x2 = (Py == 0)? INT_MIN : nums2[Py-1]; // last of the elements picked from nums2 on left side of resultant array

            // Right Half
            int x3 = (Px == m)? INT_MAX : nums1[Px]; // first of the elements picked from nums1 on right side of resultant array
            int x4 = (Py == n)? INT_MAX : nums2[Py]; // first of the elements picked from nums2 on right side of resultant array

            if(x1 <= x4 && x2 <= x3){ // correct partition

                if((m+n)%2 == 0){ // even

                    return ( max(x1, x2) + min(x3, x4) )/2.0;
                }

                return max(x1, x2);
            }

            if(x1 > x4){

                r = Px-1; // left side se elements kam karne padenge of nums1
            }

            else l = Px+1;
        }

        return -1;
    }
};