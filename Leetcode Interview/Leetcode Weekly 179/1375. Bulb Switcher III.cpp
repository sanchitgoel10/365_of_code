class Solution {
public:
    int numTimesAllBlue(vector<int>& light) 
    {
        vector<bool> on(light.size(),false);
        int maxBlue=0,result=0;
        for(int i=0;i<light.size();i++)
        {
            on[light[i]-1]=true;
            while(maxBlue<light.size()&&on[maxBlue])   //Increase the end of blue bulbs sequence starting from 0,
                maxBlue++;
            result+=maxBlue==i+1;                  		//If number of blue bulbs is equal to number of switched on bulbs.
        }
        return result;
    }
};