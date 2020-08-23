
/*
we check the length of group on the right length[a + 1]
also the length of group on the left length[a - 1].
Then we update length[a], length[a - left], length[a + right] to left + right + 1.

Note that the length value is updated on the leftmost and the rightmost bit of the group.
The length value inside the group may be out dated.

As we do this, we also update the count of length.
If count[m] > 0, we update res to current step index i + 1.
*/
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int ans=-1;
        int n=arr.size();
        vector<int> len(n+2),count(n+1);
        for(int i=0;i<n;i++){
            int a=arr[i];
            int left=len[a-1];
            int right=len[a+1];
            len[a]=len[a-left]=len[a+right]=left+right+1;
            count[left]--;
            count[right]--;
            count[len[a]]++;
            if(count[m])ans=i+1;
        }
        return ans;
    }
};