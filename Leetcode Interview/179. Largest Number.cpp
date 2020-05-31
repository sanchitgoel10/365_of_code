/*
The idea here is basically implement a String comparator to decide which String should come first during concatenation. Because when you have 2 numbers (let's convert them into String), you'll face only 2 cases:
For example:

String s1 = "9";
String s2 = "31";

String case1 =  s1 + s2; // 931
String case2 = s2 + s1; // 319
There is a minor edge case that comes up when the array consists of only zeroes, so if the most significant number is 00, we can simply return 00. Otherwise, we build a string out of the sorted array and return it.
*/
class Solution {
public:
    
    static bool cmp(int &a,int &b){
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string res;
        for(auto i:nums){
            res+=to_string(i);
        }
        if(res[0]=='0')return "0";
        return res;
    }
};
