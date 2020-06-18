class Solution {
public:
    int hIndex(vector<int>& cit) {
        if(cit.size()==0)return 0;
        int l=0,r=cit[cit.size()-1];
        int ans=l;
        while(l<=r){
            int mid=(l+r)/2;
            auto lower=lower_bound(cit.begin(),cit.end(),mid);
            //cout<<mid<<" "<<cit.end()-lower<<endl;
            if((cit.end()-lower)>=mid){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};