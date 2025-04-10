// LEETCODE 14

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
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.empty()) return "";
        if(strs.size() == 1) return strs[0];

        int n = strs.size();
        sort(strs.begin(), strs.end());
        int check_len = min(strs[0].length(), strs[n-1].length());

        string ans = "";

        for(int i=0; i<check_len; i++){

            if(strs[0][i] == strs[n-1][i]) ans.push_back(strs[0][i]);
            else break;
        }

        return ans;
    }
};

