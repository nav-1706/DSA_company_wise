// LEETCODE 686

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

Algorithm:

    1. a ki lenght ko minium itni baar to repeat karo ki uski lenght b ke grater than equal ho jaaye (then only b can be possibly the substring of a)

    2. Then ek aur baar check kar lo, sirf ek baar hi kyoki now a.length is between [b.length(), min(b.length() + alpha - which is divisble by a.length() )], now as the length of pattern is already greater than equal to the length of string b, we can just append string a in pattern one more time, to check if b is substring, so that is starting and ending of pattern is not matching with the string b, it matches, more than doing more than once will have no use:

    Pure Pattern Observation

*/

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        if(b.length() < a.length()){

            if(a.find(b) != string::npos) return 1;

            int n = a.size();
            for(int i=0; i<n; i++) a.push_back(a[i]);
            if(a.find(b) != string::npos) return 2;

            return -1;
        }

        string pattern = "";
        int num = b.length()/a.length();
        if(b.length()%a.length() > 0) num++;

        for(int i=1; i<=num; i++){

            for(int j=0; j<a.length(); j++){

                pattern.push_back(a[j]);
            }
        }

        if(pattern.find(b) != string::npos) return num;
        for(int j=0; j<a.length(); j++) pattern.push_back(a[j]);

        if(pattern.find(b) != string::npos) return num+1;
        return -1;
    }
};