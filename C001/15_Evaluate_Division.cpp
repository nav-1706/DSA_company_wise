// LEETCODE 399

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

    unordered_map<string, vector<pair<string, double>>>graph;

    double find_division(string &numi, string &deno, unordered_set<string>&visited, double numi_deno_division, bool &canReach){

        visited.insert(numi);
        if(numi == deno){
            
            canReach = true;
            return numi_deno_division;
        }

        double division = 0;
        for(auto neighbour: graph[numi]){
            
            if(canReach) return division;
            if(visited.count(neighbour.first) == 0){

                division = numi_deno_division*find_division(neighbour.first, deno, visited, neighbour.second, canReach);
            }
        }

        return division;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double>ans;

        for(int i=0; i<equations.size(); i++){

            string from_node = equations[i][0];
            string to_node = equations[i][1];

            double from_to_division = values[i];
            double to_from_division = 1/values[i];

            graph[from_node].push_back({to_node, from_to_division});
            graph[to_node].push_back({from_node, to_from_division}); 
        }

        for(auto query: queries){

            string numi = query[0];
            string deno = query[1];

            if(graph.find(numi) == graph.end() || graph.find(deno) == graph.end()){

                ans.push_back(-1);
                continue;
            }

            if(numi == deno){
                ans.push_back(1);
                continue;
            }

            unordered_set<string>visited;
            bool canReach = false;
            double numi_deno_divison = find_division(numi, deno, visited, 1, canReach);

            if(canReach == false) ans.push_back(-1);
            else ans.push_back(numi_deno_divison);
        }

        return ans;
    }
};