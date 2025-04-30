// LEETCODE 127

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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>w_list;
        for(auto &word: wordList) w_list.insert(word);

        queue<string>qu;
        int level = 1;
        unordered_set<string>visited;
        qu.push(beginWord);
        visited.insert(beginWord);

        while(!qu.empty()){

            int n = qu.size();
            for(int i=0; i<n; i++){

                auto curr_word = qu.front();
                qu.pop();
                if(curr_word == endWord) return level;

                for(int j=0; j<curr_word.size(); j++){

                    char original_char = curr_word[j];

                    for(int k=0; k<26; k++){

                        char new_char = 'a'+k;
                        if(new_char == original_char) continue;

                        curr_word[j] = new_char;

                        if(w_list.find(curr_word) != w_list.end()){

                            if(visited.count(curr_word) == 0){

                                visited.insert(curr_word);
                                qu.push(curr_word);
                                w_list.erase(curr_word);
                            }
                        }
                    }

                    curr_word[j] = original_char;
                }
            }

            level++;
        }

        return 0;
    }
};