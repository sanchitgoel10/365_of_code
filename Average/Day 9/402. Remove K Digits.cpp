#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
      stack<char> st;
      string ret = "";
      int n = num.size();
      for(int i = 0; i < n; i++){
         while(k && !st.empty() && st.top() > num[i]){
            st.pop();
            k--;
         }
         st.push(num[i]);
      }
      while(k--)st.pop();     //if k is left is needed to handle the cases in which the numbers are in the ascending order and the last few characters need to be erased to get the right answer. For example input ("112" , 1) in this case output expected is "11" and if resize is not used then the output will be "112". If the output size is more than the expected size then return just the starting num.size() - k characters.
      while(!st.empty()){
         ret += st.top();
         st.pop();
      }
      reverse(ret.begin(), ret.end());     
      string ans = "";
      int i = 0;
      while(i <ret.size() && ret[i] == '0')i++;    //remove leading zeroes
      for(; i < ret.size(); i++)ans += ret[i];
      ret = ans;
      return ret.size() == 0? "0" : ret;           //string nul hai to return 0
    }
};