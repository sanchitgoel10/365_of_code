class Solution {
public:
    int dp[101][101][21]={};
    
    int helper(vector<int>&houses,vector<vector<int>>&cost,int i,int target,int last_color){
        if(i>=houses.size()){      //ind range ke bahar 
            if(target==0)return 0; //target match ho gaya 
            return 1000001;        //range khatam but target match nhi hua
        }
        if(target<0){            //exact target neighbourhood chahiye
            return 1000001;    //This is 10^6+1   (m==100*cost[i][j]==10^4=10^6)
        }
        if(houses[i]!=0){        //painted last year
            return helper(houses,cost,i+1,target-(last_color!=houses[i]),houses[i]);     //target - 1 agar color alag hua to warna target - 0
        }
        if(dp[i][target][last_color])return dp[i][target][last_color];
        
        auto res=1000001;
        for(int clr=1;clr<=cost[i].size();clr++){                    //trying every color
            
            res=min(res,cost[i][clr-1]+helper(houses,cost,i+1,target-(last_color!=clr),clr));
        }
        return dp[i][target][last_color]=res;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        auto res=helper(houses,cost,0,target,0);
        return res>1000000?-1:res;
    }
};