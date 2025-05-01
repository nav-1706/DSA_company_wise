// LEETCODE 139

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

    unordered_set<string>dict;
    vector<int>dp;

    bool solve(int i, string &s){

        if(i == s.length()) return true;

        if(dp[i] != -1) return dp[i];

        bool res = false;
        string temp = "";

        for(int k=i; k<s.length(); k++){

            temp.push_back(s[k]);
            if(dict.count(temp) != 0){ // present 

                res = res || solve(k+1, s);
                if(res == true) break;
            }
        }

        return dp[i] = res;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        for(auto &w: wordDict) dict.insert(w);
        dp.resize(s.length(), -1);
        return solve(0, s);
    }
};