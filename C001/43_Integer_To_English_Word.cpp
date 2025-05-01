// LEETCODE 273

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
    unordered_map<int, string> mp;

    // Initialize the mapping
    void setValue() {
        mp[0] = "Zero";
        mp[1] = "One";
        mp[2] = "Two";
        mp[3] = "Three";
        mp[4] = "Four";
        mp[5] = "Five";
        mp[6] = "Six";
        mp[7] = "Seven";
        mp[8] = "Eight";
        mp[9] = "Nine";
        mp[10] = "Ten";
        mp[11] = "Eleven";
        mp[12] = "Twelve";
        mp[13] = "Thirteen";
        mp[14] = "Fourteen";
        mp[15] = "Fifteen";
        mp[16] = "Sixteen";
        mp[17] = "Seventeen";
        mp[18] = "Eighteen";
        mp[19] = "Nineteen";
        mp[20] = "Twenty";
        mp[30] = "Thirty";
        mp[40] = "Forty";
        mp[50] = "Fifty";
        mp[60] = "Sixty";
        mp[70] = "Seventy";
        mp[80] = "Eighty";
        mp[90] = "Ninety";
        mp[100] = "Hundred";
        mp[1000] = "Thousand";
        mp[1000000] = "Million";
        mp[1000000000] = "Billion";
    }

    // Helper function to process blocks of three digits
    string processBlock(int num) {
        string result = "";

        int a = num / 100;       // Hundreds place
        int b = (num / 10) % 10; // Tens place
        int c = num % 10;        // Units place

        if (a > 0) result += mp[a] + " Hundred ";

        if (b == 1) { // Special case for numbers 10–19
            result += mp[b * 10 + c] + " ";
        } else {
            if (b > 0) result += mp[b * 10] + " ";
            if (c > 0) result += mp[c] + " ";
        }

        return result;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        setValue();

        string res = "";
        vector<string> units = {"", "Thousand", "Million", "Billion"};

        int i = 0;
        while (num > 0) {
            int block = num % 1000;
            if (block > 0) {
                string blockStr = processBlock(block);
                if (!units[i].empty()) blockStr += units[i] + " ";
                res = blockStr + res;
            }
            num /= 1000;
            i++;
        }

        // Remove trailing space
        while (!res.empty() && res.back() == ' ') res.pop_back();

        return res;
    }
};
