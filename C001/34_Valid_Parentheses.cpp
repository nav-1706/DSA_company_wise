// LEETCODE 20

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
    bool isValid(string s) {
        
        int n = s.length();
        stack<char>st;

        int i = 0;

        while(i < n){

            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);

            else{

                if(st.empty()) return false;

                else if(st.top() == '(' && s[i] == ')') st.pop();
                else if(st.top() == '{' && s[i] == '}') st.pop();
                else if(st.top() == '[' && s[i] == ']') st.pop();

                else return false;
            }

            i++;
        }

        return st.empty();
    }
};