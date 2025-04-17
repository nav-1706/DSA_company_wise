// LEETCODE 1007

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
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        bool is_possible = false;
        int n = tops.size();

        unordered_map<int,int>top_row; // <element, freq>
        unordered_map<int,int>bottom_row; // <element, freq>
        unordered_map<int,int>same_top_bottom; // <element, number_of_times>

        /*
        for(int t: tops) top_row[t]++;
        for(int b: bottoms) bottom_row[b]++;
        for(int i=0; i<n; i++) if(tops[i] == bottoms[i]) same_top_bottom[tops[i]]++;
        */

        for(int i=0; i<n; i++){

            top_row[tops[i]]++;
            bottom_row[bottoms[i]]++;
            if(tops[i] == bottoms[i]) same_top_bottom[tops[i]]++;
        }

        int min_moves = INT_MAX;

        for(auto &p: top_row){

            int element = p.first;
            int freq_top = p.second;
            int freq_bottom = bottom_row[element];

            int total_freq_in_unique_row = freq_top + freq_bottom - same_top_bottom[element];

            if(total_freq_in_unique_row < n) continue;

            is_possible = true;
            min_moves = min(min_moves, min(freq_top, freq_bottom)-same_top_bottom[element]);
        }   

        if(is_possible == false) return -1;
        return min_moves;
    }
};