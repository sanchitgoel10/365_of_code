/*
Initial the result res to include the case of empty string "".
res include all possible combinations we find during we iterate the input.

Itearte the the input strings,
but skip the word that have duplicate characters.
The examples is kind of misleading,
but the input string can have duplicate characters,
no need to considerate these strings.

For each string,
we check if it's conflit with the combination that we found.
If they have intersection of characters, we skip it.
If not, we append this new combination to result.

return the maximum length from all combinations.
*/
class Solution {
public:
    int maxLength(vector<string>& A) {
        vector<bitset<26>> dp = {bitset<26>()}; //empty string wala ek bitset daal diya
        int res = 0;
        for (auto& s : A) {
            bitset<26> a;
            for (char c : s)
                a.set(c - 'a');
            int n = a.count();
            if (n < s.size()) continue;         //same characters in string itselt ex: hello here there are 2 l 

            for (int i = 0; i <dp.size();i++ ) {
                bitset c = dp[i];
                if ((c & a).any()) continue;
                dp.push_back(c | a);
                res = max(res, (int)c.count() + n);
            }
        }
        return res;
        
    }
};


//Other Solutions

//Recursive(dfs) slow without bitset solution 
class Solution {
public:
    int maxLength(vector<string>& arr, string str = "", int index = 0) {
	    //Use set to check if the string contains all unique characters
        unordered_set<char>s(str.begin(), str.end());
        if (s.size() != ((int)str.length())) 
            return 0;
        
        int ret = str.length();
        for (int i = index; i < arr.size(); i++)
            ret = max(ret, maxLength(arr, str+arr[i], i+1));

        return ret;
    }
};
//with Bitset
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> bits; 
        for (auto s : arr) {
            bitset<26> a;
            for (char c : s) a.set(c - 'a');
            if (a.count() == s.size()) bits.push_back(a);
        }
        return maxLength(bits, bitset<26>(), 0);
    }
    
    int maxLength(vector<bitset<26>>& bits, bitset<26> bs, int index) {
        int res = bs.count();
        for (int i = index; i < bits.size(); i++) 
            if (!(bits[i] & bs).any()) res = max(res, maxLength(bits, bs | bits[i], i+1));
        
        return res;
    }
};