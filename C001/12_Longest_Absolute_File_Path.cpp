// LEETCODE 388

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
#include <sstream>

using namespace std;

class Solution {
public:

    typedef pair<int,int> P;

    int lengthLongestPath(string input) {
        
        stack<P>st; // char_count, tab_count;
        int longest = 0;

        stringstream ss(input);
        string line;

        while (getline(ss, line, '\n')) {
            
            int last_tab_idx = (int)line.rfind('\t'); // here '\t' is actual tab char not string // type casting to int, coz .find(), .rfind() gives t_type
            int tab_char_count = 0;

            if (last_tab_idx != string::npos) { // we use string::npos, when to check not_found, so != string::npos == not of not_found ==> found
                tab_char_count = last_tab_idx+1;
            }

            int char_count = line.size()-tab_char_count;

            while(!st.empty() && st.top().second >= tab_char_count) st.pop();
            
            if(st.empty()) st.push({char_count, tab_char_count});
            else st.push({st.top().first+char_count, tab_char_count});

            if(line.find('.') != string::npos) longest = max(longest, st.top().first+(int)st.size()-1);
        }

        return longest;
    }
};