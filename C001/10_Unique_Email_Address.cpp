// LEETCODE 929

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
    int numUniqueEmails(vector<string>& emails) {
        
        string right_email;
        unordered_set<string>e_set;

        for(auto &e: emails){

            right_email = "";
            int i = 0;
            for(i=0; i<e.size(); i++){

                if(e[i] == '@') break;
                if(e[i] == '+') break; // early break;
                if(e[i] == '.') continue;

                right_email.push_back(e[i]);
            }
            
            while(i<e.size() && e[i] != '@') i++;

            while(i < e.size()){

                right_email.push_back(e[i]);
                i++;
            }

            e_set.insert(right_email);
        }

        return e_set.size();
    }
};