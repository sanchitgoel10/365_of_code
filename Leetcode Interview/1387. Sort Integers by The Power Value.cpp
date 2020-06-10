class Solution {
public:
    int power(int num){
        if(num<2)return 0;
        return 1+(num%2?power(num*3+1):power(num/2));
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> v;
        for(int i=lo;i<=hi;i++){
            v.push_back({power(i),i});
        }
        nth_element(v.begin(),v.begin()+k-1,v.end());    //this is partial sort time comp O(n) rather than full sorting
        return v[k-1].second;
    }
    
};