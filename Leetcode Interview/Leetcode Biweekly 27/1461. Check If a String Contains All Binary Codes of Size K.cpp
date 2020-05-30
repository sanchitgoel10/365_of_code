class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.length()) return false;
   
        unordered_map<string, int>mp;                //map makes sure you only unique subtrings increase the size of map 
        for (int i = 0; i < s.length()-k+1; i++)
            mp[s.substr(i, k)]++;
         
        return mp.size() == pow(2, k);
    }
};