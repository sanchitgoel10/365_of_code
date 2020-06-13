class Solution {
public:
    int countLargestGroup(int n) {
        int largest_size=-1;
        int ans=0;
        map<int,int> m;
        for(int i=1;i<=n;i++){
            int sum=0;
            int num=i;
            string s=to_string(i);
            for(auto x:s){
                sum+=x-'0';
            }
            m[sum]++;
            if(m[sum]>largest_size){
                largest_size=m[sum];
                ans=1;
            }else if(m[sum]==largest_size){
                ans++;
            }
        }
        return ans;
    }
};