#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        int*indegree = new int[numCourses]();
        
        vector<int> adj[numCourses];
        
        for(auto i:prerequisites){
            indegree[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }
        stack<int> stk;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                stk.push(i);
            }
        }
        
        while(!stk.empty()){
            int curr=stk.top();
            stk.pop();
            ans.push_back(curr);
            
            for(auto i:adj[curr]){
                indegree[i]--;
                if(indegree[i]==0){
                    stk.push(i);
                }
            }
            
        }
        if(ans.size()<numCourses){
            ans.clear();
        }
        return ans;
    }
};