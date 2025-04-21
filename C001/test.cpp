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
#include<bitset>
using namespace std;

int main(){

    int decimal = 237;

    bitset<8> binary8(decimal);
    cout<<binary8<<endl;

    bitset<9> binary9(decimal);
    cout<<binary9<<endl;

    cout<<binary9[4]<<endl;

    int decima2 = 25;
    bitset<8>binary_88(decima2);
    string toBinary = binary_88.to_string();

    cout<<toBinary<<endl;
    cout<<toBinary[0]<<endl;
    cout<<toBinary[3]<<endl;
}