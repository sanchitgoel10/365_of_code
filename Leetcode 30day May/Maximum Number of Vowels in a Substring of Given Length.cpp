/*
Just a simple sliding window pattern: count vowels moving in and out of window, and keep track of the maximum.

int vowels[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
int maxVowels(string s, int k) {
    int max_vow = 0;
    for (auto i = 0, cur_vow = 0; i < s.size(); ++i) {
        cur_vow += vowels[s[i] - 'a'];
        if (i >= k)
            cur_vow -= vowels[s[i - k] - 'a'];
        max_vow = max(max_vow, cur_vow);
    }
    return max_vow;
}
*/
//My solution
class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;
        for(int i=0;i<k;i++){
            char x=s[i];
            if(x=='a'||x=='e'||x=='o'||x=='u'||x=='i'){
                ans++;
            }
        }
        int tmp=ans;
        for(int i=k;i<s.size();i++){
            char x=s[i-k];
            if(x=='a'||x=='e'||x=='o'||x=='u'||x=='i'){
                tmp--;
            }
            x=s[i];
            if(x=='a'||x=='e'||x=='o'||x=='u'||x=='i'){
                tmp++;
            }
            ans=max(tmp,ans);
        }
        return ans;
    }
};