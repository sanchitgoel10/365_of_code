/*
A = [3,6,5,1,8]

buckets { 0, 0, 0 }
          0  1  2

A = [3,6,5,1,8]
     ^
buckets { 3, 0, 0 }
          0  1  2

A = [3,6,5,1,8]
       ^
buckets { 9, 0, 0 }
          0  1  2

A = [3,6,5,1,8]
         ^
buckets { 9, 0, 14 }
          0  1   2

A = [3,6,5,1,8]
           ^
buckets { 15, 10, 14 }
           0   1   2

A = [3,6,5,1,8]
             ^
buckets { 18, 22, 23 }
           0   1   2
           
the answer in buckets[0] is 18
Example 2:

A = [4]
buckets { 0, 0, 0 }
          0  1  2

A = [4]
     ^
buckets { 0, 4, 0 }
          0  1  2
          
the answer in buckets[0] is 0
Example 3:

A = [1,2,3,4,4]

buckets { 0, 0, 0 }
          0  1  2
          
A = [1,2,3,4,4]
     ^
buckets { 0, 1, 0 } 
          0  1  2

A = [1,2,3,4,4]
       ^
buckets { 3, 1, 2 } 
          0  1  2
          
A = [1,2,3,4,4]
         ^
buckets { 6, 4, 5 } 
          0  1  2

A = [1,2,3,4,4]
           ^
buckets { 9, 10, 8 }
          0   1  2

A = [1,2,3,4,4]
             ^
buckets { 12, 13, 14 } 
           0   1   2

the answer in buckets[0] is 12
*/
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp={0,0,0},dptemp;
        for(int i:nums){
            dptemp=dp;
            for(int j:dptemp){
                dp[(j+i)%3]=max(dp[(i+j)%3],i+j);
            }
        }
        return dp[0];
    }
};