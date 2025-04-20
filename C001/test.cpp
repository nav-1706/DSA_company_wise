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

int main(){

    vector<int> nums = {1,2,3,4,5,6,7,8};
    reverse(nums.begin()+1, nums.end());

    for(int i=0; i<nums.size(); i++) cout<<nums[i]<<" ";
}