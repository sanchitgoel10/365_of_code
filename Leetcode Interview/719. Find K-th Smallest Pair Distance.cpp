//Bucket sort, O(n^2)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size(), N = 1000000;
        vector<int> cnt(N, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) 
                cnt[abs(nums[i]-nums[j])]++;
        }
        for (int i = 0; i < N; i++) {
            if (cnt[i] >= k) return i;
            k -= cnt[i];
        }
        return 0;
    }
};
//Binary search, O(nlogn)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), low = 0, high = 1000000;
        while (low < high) {
            int mid = (low + high)/2, cnt = 0;
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n && nums[j]-nums[i] <= mid) j++;
                cnt += j-i-1;
            }
            if (cnt < k) 
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};