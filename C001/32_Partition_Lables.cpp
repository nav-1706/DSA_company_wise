// LEETCODE 763

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
    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int>lastOccurrence;

        for(int i=0; i<s.length(); i++) lastOccurrence[s[i]] = i;

        int partitionStart = 0;
        int partitionEnd = 0;

        vector<int> partitionSizes;

        for (int i = 0; i < s.size(); i++) {

            partitionEnd = max(partitionEnd, lastOccurrence[s[i]]);

            // End of the current partition
            if (i == partitionEnd) {
                partitionSizes.push_back(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }

        return partitionSizes;
    }
};