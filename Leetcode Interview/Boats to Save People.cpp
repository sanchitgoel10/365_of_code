class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if(people.size()==0)return 0;
        sort(people.begin(),people.end());
        int i=0;
        int j=people.size()-1;
        int ans=0;
        while(i<=j){
            ans++;
            if(people[i]+people[j]<=limit){     //boat limit hai 2
                i++;
            }
            j--;
        }   
        return ans;
    }
};