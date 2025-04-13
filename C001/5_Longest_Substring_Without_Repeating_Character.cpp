// LEETCODE 3

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

// Done in 1st Pass On my Own ;)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        int i = 0;
        int j = 0;
        unordered_set<char>st;

        int max_len = 0;

        while(j < n){

            if(st.find(s[j]) == st.end()){ // nahi mila

                st.insert(s[j]);
                j++;
            }   

            else{

                if(s[i] == s[j]){

                    i++;
                    j++;
                }

                else{
                    
                    
                    max_len = max((int)st.size(), max_len);
                    
                    while(i < j && s[i] != s[j]){

                        st.erase(s[i]);
                        i++;
                    }

                    i++; // ek aage gaye hai;
                    j++;
                }
            }
        }

        max_len = max((int)st.size(), max_len);

        return max_len;
    }
};