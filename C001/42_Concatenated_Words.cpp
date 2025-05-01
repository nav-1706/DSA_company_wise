// LEETCODE 472

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

    bool solve(int i, string &s){ // this function is to check if a string 's' is concatenated word or not
 
        if(i == s.length()) return true;

        if(dp[i] != -1) return dp[i];

        bool res = false;
        string temp = "";

        for(int k=i; k<s.length(); k++){

            temp.push_back(s[k]);
            if(dict.count(temp) != 0){

                res = res || solve(k+1, s);
                if(res == true) break;
            }
        }

        return dp[i] = res;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        for(auto &w: words) dict.insert(w);
        dp.resize(35, -1);

        vector<string>ans;
        for(auto &w: words){
            
            dp.clear();
            dp.resize(35, -1);
            dict.erase(w);
            if(solve(0, w)) ans.push_back(w);
            dict.insert(w);
        }

        return ans;
    }
};