/*
For each character in the string, check if the ith character and (i+m)th characters are matching.
If they match, increase the count by 1. Otherwise, this is a nonmatch, so reset the count variable to 0.
Because we need to find k repetitions of a pattern of length m, if there is any such pattern, the count value will be k*m at some point.
The reason why it is shifted to (k-1) * m is that if there exist k occurrences of a pattern, you will be successfully making k-1 comparisons, which is between every adjacent occurrence of the pattern.

For example, consider this:

s = 123123123
m = 3
k = 3
In this case you compare values at indices 0,1,2 with 3,4,5 (1 with 1, 2 with 2, 3 with 3)
Subsequently, you compare value at indices 3,4,5 with 6,7,8
In total, you count value reaches 6, which (k-1) * m
*/
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        
        int cnt=0;
        for(int i=0;i+m<arr.size();i++){
            if(arr[i]!=arr[i+m]){
                cnt=0;
            }else{
                cnt++;
            }
            if(cnt==(k-1)*m)return 1;
        }
        return 0;
    }
};