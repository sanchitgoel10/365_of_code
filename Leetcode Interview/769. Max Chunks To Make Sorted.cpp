/*
The basic idea is to use max[] array to keep track of the max value until the current position, and compare it to the sorted array (indexes from 0 to arr.length - 1). If the max[i] equals the element at index i in the sorted array, then the final count++.

For this question, what this algorithm wants us to do is finding some splitting line so that numbers being left of this line are all small than numbers right of this line. The idea is very similar to quick sort. What the answer of this question is how many lines you can find. So that is why we want the max array, or we can only need a number for storing the maximum number up to now(because original array is 0 to len-1), as long as the max number equals the index, we know that all numbers left to this point are smaller than this point and numbers right to this point are larger than this point, then we count add one.

For example,

original: 0, 2, 1, 4, 3, 5, 7, 6
max:      0, 2, 2, 4, 4, 5, 7, 7
sorted:   0, 1, 2, 3, 4, 5, 6, 7
index:    0, 1, 2, 3, 4, 5, 6, 7
The chunks are: 0 | 2, 1 | 4, 3 | 5 | 7, 6
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int mx=0;
        for(int i=0;i<arr.size();i++){
            mx=max(mx,arr[i]);
            if(mx==i){
                ans++;
            }
        }
        return ans;
    }
};