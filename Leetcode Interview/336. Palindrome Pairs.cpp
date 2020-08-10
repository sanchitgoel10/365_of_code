/*Assumption: No duplicated string in the given dictionary

Steps:

Traverse the array, build map. Key is the reversed string, value is index in array (0 based)

Edge case - check if empty string exists. It's interesting that for given words {"a", ""}, it's expected to return two results [0,1] and [1,0]. Since my main logic can cover [0, 1] concatenate("a", ""), so as to cover the other situation concatenate("", "a"), I need to traverse the words array again, find the palindrome word candidate except "" itself, and add pair("", palindrome word) to the final answer.

Main logic part. Partition the word into left and right, and see 1) if there exists a candidate in map equals the left side of current word, and right side of current word is palindrome, so concatenate(current word, candidate) forms a pair: left | right | candidate. 2) same for checking the right side of current word: candidate | left | right.
*/
 class Solution {
 public:
     vector<vector<int>> palindromePairs(vector<string>& words) {
         unordered_map<string, int> dict;
         vector<vector<int>> ans;
         // build dictionary
         for(int i = 0; i < words.size(); i++) {
             string key = words[i];
             reverse(key.begin(), key.end());
             dict[key] = i;
         }
         // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
         if(dict.find("")!=dict.end()){
             for(int i = 0; i < words.size(); i++){
                 if(i == dict[""]) continue;
                 if(isPalindrome(words[i])) ans.push_back({dict[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self) 
             }
         }

         for(int i = 0; i < words.size(); i++) {
             for(int j = 0; j < words[i].size(); j++) {
                 string left = words[i].substr(0, j);
                 string right = words[i].substr(j, words[i].size() - j);

                 if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) {
                     ans.push_back({i, dict[left]});     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
                 }

                 if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) {
                     ans.push_back({dict[right], i});
                 }
             }
         }

         return ans;        
     }

     bool isPalindrome(string str){
         int i = 0;
         int j = str.size() - 1; 

         while(i < j) {
             if(str[i++] != str[j--]) return false;
         }

         return true;
     }

 };
/*
The idea of establishing dict and reversing words[i] at the same time is faster compared with that of reversing left and right, which I find in some other similar posts.
 What's more, here is a little improvement for the edge case: when there exists empty string, instead of using a separate loop for traversal, we can handle it in the "magic" part. When left is empty and right is a palindrome, apart from {i, dict[left]}, we can also add {dict[left], i} to result so that no valid pair is missing.

Following is my implementation, just for the reference.
*/

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int> > result;
        unordered_map<string, int> dict;
        int i, j, size = words.size();
        string left, right, tmp;
        for(i = 0; i < size; i++) {
            tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            dict[tmp] = i;
        }
        
        for(i = 0; i < size; i++) {
            for(j = 0; j < words[i].size(); j++) {
                left = words[i].substr(0, j);
                right = words[i].substr(j);
                if(dict.find(left) != dict.end() && dict[left] != i && isPalindrome(right)) {
                    result.push_back({i, dict[left]});
                    if(left.empty())
                        result.push_back({dict[left], i});
                }
                if(dict.find(right) != dict.end() && dict[right] != i && isPalindrome(left))
                    result.push_back({dict[right], i});
            }
        }
        return result;
    }
    
private:
    bool isPalindrome(string s) {
        int start, end, size = s.size();
        for(start = 0, end = size - 1; start < end; start++, end--) {
            if(s[start] != s[end])
                return false;
        }
        return true;
    }
};