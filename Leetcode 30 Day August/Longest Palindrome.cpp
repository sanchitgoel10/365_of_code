class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        unordered_map<char,int> m;
        for(auto c:s){
            m[c]++;
        }
        
        for(auto &[k,v]:m){
            if(v%2){
                ans+=ans%2?v-1:v;    //if odd then if already added an odd we subtract 1 to make ot even and then add otherwise just add
            }else{
                ans+=v;    //if even just add
            }
        }
        return ans;
    }
};