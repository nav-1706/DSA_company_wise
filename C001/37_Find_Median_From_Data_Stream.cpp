// LEEETCODE 295 

// ******** DO FOLLOW UP ALSO - VERY IMPORTANT *************

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

// https://youtu.be/jnj87BSi9Is?si=Cd2OIbcvkyQ4oZHp

class MedianFinder {
public:

    priority_queue<int>left_half; // max-heap --> at max one element more than right_half
    priority_queue<int, vector<int>, greater<int>>right_half; // min-heap

    MedianFinder() {
        

    }
    
    void addNum(int num) {
        
        if(left_half.empty() || num > left_half.top()){

            right_half.push(num);
            
            if(right_half.size() > left_half.size()){

                left_half.push(right_half.top());
                right_half.pop();
            }
        }

        else{

            left_half.push(num);

            if(left_half.size()-right_half.size() >= 2){

                right_half.push(left_half.top());
                left_half.pop();
            }
        }
    }
    
    double findMedian() {
         
        if( (left_half.size() + right_half.size()) % 2 == 0 ) return (left_half.top()+right_half.top())/2.0;
        return left_half.top()*1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */