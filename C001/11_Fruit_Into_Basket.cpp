// LEETCODE 904

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

// Think About the Sliding Window, whenever there is sub-aaray

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        if(fruits.size() == 1 || fruits.size() == 2) return fruits.size();

        unordered_map<int,int>mp; // <type, freq>

        int i = 0;
        int j = 0;
        int max_count = 0;
        int k = 2; // 2 basket
        int n = fruits.size();

        while(j < n){
                
            mp[fruits[j]]++;
                
            while( i < j && mp.size() > k){

                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }
            
            max_count = max(max_count, j-i+1);

            j++;
        }

        return max_count;
    }
};