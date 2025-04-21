// LEETCODE 393

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

// https://youtu.be/BvRl4hqOT2c?si=raQd7FuEEYt0Xxe3

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int n = data.size();
        int next_remaining_byte = 0;

        for(int i=0; i<n; i++){

            if(next_remaining_byte == 0){

                if(data[i] >> 7 == 0b0) continue;

                else if(data[i] >> 5 == 0b110) next_remaining_byte = 1;

                else if(data[i] >> 4 == 0b1110) next_remaining_byte = 2;

                else if(data[i] >> 3 == 0b11110) next_remaining_byte = 3;

                else return false;

            }

            else{

                if(data[i] >> 6 == 0b10) next_remaining_byte--;
                else return false;
            }
        }

        return true;
    }
};