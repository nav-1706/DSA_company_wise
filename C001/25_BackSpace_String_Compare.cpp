// LEETCODE 844

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

****************** METHOD: 1 (new string creation) *********************
T.C : O(m+n)
S.C : O(m+n)

*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string s_ = "";
        string t_ = "";

        int n = s.length();
        int m = t.length();

        for(int i=0; i<n; i++){

            if(s[i] == '#'){

                if(s_.length() > 0) s_.pop_back();
                else continue;
            }

            else s_.push_back(s[i]);
        }

        for(int i=0; i<m; i++){

            if(t[i] == '#'){

                if(t_.length() > 0) t_.pop_back();
                else continue;
            }

            else t_.push_back(t[i]);
        }

        // if(s_ == "" && t_ == "" ) return true;
        return s_ == t_;
    }
};

/*

****************** METHOD: 2 (two-pointer) *********************
T.C : O(max(m, n))
S.C : O(1)

*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        int i = m-1, j = n-1;
        int skip_s = 0;
        int skip_t = 0;
        
        while(i >= 0 || j >= 0) {
            
            while(i >= 0) {
                if(s[i] == '#') {
                    skip_s++;
                    i--;
                } else if(skip_s > 0) {
                    skip_s--;
                    i--;
                } else {
                    break;
                }
            }
            
            while(j >= 0) {
                if(t[j] == '#') {
                    skip_t++;
                    j--;
                } else if(skip_t > 0) {
                    skip_t--;
                    j--;
                } else {
                    break;
                }
            }
            
            char first  = i < 0 ? '$' : s[i];
            char second = j < 0 ? '$' : t[j];
            
            if(first != second)
                return false;
            
            i--;
            j--;
        }
        
        return true;
        
    }
};