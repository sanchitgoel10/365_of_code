/*
Binary search for the length of the answer. (If there's an answer of length 10, then there are answers of length 9, 8, 7, ...)
To check whether an answer of length K exists, we can use Rabin-Karp 's algorithm.(Hashing Algo)
*/
class Solution {
public:
    string longestDupSubstring(string S) {
        ans = "";
        power = vector<int>(S.length(), 1);
        int i;
		// precompute all the pow(26, k) 0 < k < S.length() modulus prime
        for (i = 1 ; i < S.length(); i++) {
            power[i] = (power[i - 1] * 26) % prime;
        }
        int low = 0, high = S.length();
		// code for the binary search, very trivial
        while (low <= high) {
            int mid = low + (high - low) / 2;
            string tmp = validate(mid, S);
            if (tmp.length() == 0) {
                high = mid - 1;
            } else {
                if (tmp.length() > ans.length()) {
                    ans = tmp;
                }
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
private:
   // large prime number
    int prime = 19260817;
    string ans;
    vector<int> power;
    string validate(int desire, string &str) {
       // if the desire length is 0, return the empty string
        if (desire == 0) return "";
        unordered_map<int, vector<int>> hash = unordered_map<int, vector<int>>();
        long long current = 0;
        int i;
		// compute the hash value of the first "length" characters
        for (i = 0 ; i < desire; i++) {
            current = ((current * 26) % prime + (str[i] - 'a')) % prime;
        }
        // store the result in a hashmap that maps from hashvalue to starting index
        hash[current] = vector<int>(1, 0);
        for (i = desire ; i < str.length(); i++) {
		    // sliding window to maintain the current substr's hash value
			// be aware of overflow
            current = ((current - (long long) power[desire - 1] * (str[i - desire] - 'a')) % prime + prime) % prime;
            current = (current * 26 + (str[i] - 'a')) % prime;
           // if that hash value is not in our set we do nothing and add the value to our map
            if (hash.find(current) == hash.end()) {
                hash[current] = vector<int>(1, i - desire + 1);
            } else {
			   // otherwise, start a string by string comparason and see if there's a match
                for (auto it : hash[current]) {
                    
                    if (strcmp((str.substr(it, desire)).data(), str.substr(i - desire + 1, desire).data()) == 0) {    //check strings when collision happens
                        return str.substr(it, desire);
                    }
                }
                
                hash[current].push_back(i - desire + 1);
            }
        }
        
        return "";
    }
};