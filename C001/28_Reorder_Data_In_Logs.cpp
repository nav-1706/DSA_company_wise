// LEETCODE 937

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

    bool is_digit_log(string s){

        if( isdigit(s[s.find(" ")+1]) ) return true;
        return false;
    }

    static bool custom_sort(string s1, string s2){

        if(s1.substr(s1.find(" ")+1) == s2.substr(s2.find(" ")+1)) return s1 < s2;

        return s1.substr(s1.find(" ")+1) < s2.substr(s2.find(" ")+1);
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string>letter_logs;
        vector<string>digit_logs;
        int n = logs.size();

        for(int i=0; i<n; i++){

            if(is_digit_log(logs[i])) digit_logs.push_back(logs[i]);
            else letter_logs.push_back(logs[i]);
        }

        sort(letter_logs.begin(), letter_logs.end(), custom_sort);

        for(int i=0; i<digit_logs.size(); i++) letter_logs.push_back(digit_logs[i]);

        return letter_logs;
    }
};