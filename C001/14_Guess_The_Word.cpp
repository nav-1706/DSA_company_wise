// LEETCODE 843

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

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

/*

METHOD: 1

1. Randomly choose a word(w) from the words
2. call Master.guess(w), we will get a number
3. Now match this word with every word in the words, and if the number is not equal to the Master.guess(w) then it can never be the secreat word, so eliminate it
4. Repear same in remaining words array

METHOD: 2

1. Choose a word(w) which don't have 0 match, coz kisi bhi 2 6-digit word ke 0 match hone ki probability 80% hai (25^6/26^6), so we will be only able to elimainate only 20% of words from the wordList, for each Master.guess() call
2. call Master.guess(w), we will get a number
3. Now match this word with every word in the words, and if the number is not equal to the Master.guess(w) then it can never be the secreat word, so eliminate it
4. Repear same in remaining words array

*/


class Solution {
public:

    int matches(string &sec, string &target){

        int match_count = 0;
        for(int i=0; i<6; i++) if(sec[i] == target[i]) match_count++;

        return match_count;
    }

    string best_guess(vector<string>&words){ // best word ko ham possible_sec_word banaenge, kyoki iski match( > 0) hone ki probability sabse jayda hai, and kisi bhi 2 words ke 0 match hone ki probability 80% hai, which me can possibly remove 80% of search space

        string best_word;
        int best_score = -1;


        for(auto &w1: words){
            
            int score = 0;
            for(auto &w2: words){

                score += matches(w1, w2);
            }

            if(score > best_score){
                best_word = w1;
                best_score = score;
            }
        }

        return best_word;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        
        for(int i=0; i<30; i++){

            string possible_sec_word = best_guess(words);

            int matches_with_sec = master.guess(possible_sec_word);
            if(matches_with_sec == 6) return;

            vector<string>filtered;
            for(auto &w: words){
                if(matches(possible_sec_word, w) == matches_with_sec) filtered.push_back(w); // only  w can be possibly secret word;
            }

            words = filtered;
        }
    }
};