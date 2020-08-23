
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

//Union find
class Solution {
public:
    vector<int> arr;
    vector<int> group;
    unordered_map<int, int> gz;
    int find(int x) {
        if(arr[x] != 0) {
            if(arr[x] == x) return x;
            arr[x] = find(arr[x]);
            return arr[x];
        }
        ++group[1];
        gz[x] = 1;
        arr[x] = x;
        return x;
    }
    
    void combine(int a, int b) {
        a = find(a); b = find(b);
        if(a != b) {
            --group[gz[a]];
            --group[gz[b]];
            ++group[gz[a] + gz[b]];
            gz[a] += gz[b];
            arr[b] = a;
            gz.erase(b);
        }
    }
    
    int findLatestStep(vector<int>& arr1, int m) {
        arr.resize(100001);
        group.resize(100001);
        int ans = -1;
        int idx = 1;
        for(auto n : arr1) {
            find(n);
            if(n < arr1.size() && arr[n + 1]) {
                combine(n, n + 1);
            }
            if(n > 0 && arr[n - 1])
                combine(n, n - 1);
            if(group[m])
                ans = idx;
            ++idx;
        }
        return ans;
    }
};