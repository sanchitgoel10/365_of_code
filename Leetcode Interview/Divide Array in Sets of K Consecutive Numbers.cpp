/*
If the smallest number in the possible-to-split array is V, then numbers V+1, V+2, ... V+k-1 must contain there as well.
You can iteratively find k sets and remove them from array until it becomes empty.
Failure to do so would mean that array is unsplittable.
*/

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto &i:nums){
            m[i]++;
        }
        sort(nums.begin(),nums.end());
        for(int &i:nums){
            if(!m[i])continue;
            m[i]--;
            int flag=0;
            int s=i+1;
            for(int x=1;x<k;x++){
                if(!m[s]){
                    return 0;
                }else{
                    m[s]--;
                    s++;
                }
            }
        }
        return 1;
    }
};