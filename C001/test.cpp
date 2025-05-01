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

    int pattern_day = 7;
    vector<int>cells = {0,1,0,1,1,0,0,1};
    vector<int>updated_cells = cells;

    for(int i=1; i<=pattern_day; i++){

        for(int j=1; j<=6; j++){

            if(
                (cells[j-1] == 0 && cells[j+1] == 0) ||
                (cells[j-1] == 1 && cells[j+1] == 1)
            ){
                updated_cells[j] = 1;
            }

            else updated_cells[j] = 0;
        }
        updated_cells[0] = 0;
        updated_cells[7] = 0;

        cells = updated_cells;
    }

    for(int i=0; i<8; i++) cout<<cells[i]<<" ";

}