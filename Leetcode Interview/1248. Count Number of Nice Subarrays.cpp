//Lee way Exactly K times = at most K times - at most K - 1 times
int numberOfSubarrays(vector<int>& A, int k) {
        return atMost(A, k) - atMost(A, k - 1);
    }

    int atMost(vector<int>& A, int k) {
        int res = 0, i = 0, n = A.size();
        for (int j = 0; j < n; j++) {
            k -= A[j] % 2;
            while (k < 0)
                k += A[i++] % 2;
            res += j - i + 1;
        }
        return res;
    }


 /*
 After replacing each even by zero and every odd by one can we use prefix sum to find answer
 If you transform the input array into binary, then the problem becomes the 'Subarray Sum Equals K' problem. You can think of k odd numbers means sum of then is k.
 */
 class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        const int n = nums.size();
        int rst = 0;
        int acc = 0;
        m[0] = 1;
        for (int i = 0; i < n; ++i) {
            acc += (nums[i]%2);
            rst += m[acc-k];
            m[acc]++;
        }
        return rst;
    }
};
//Same idea as above
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size());
        
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] % 2 == 1){
                prefixSum[i] = 1;
            }
        }
        
        for(int i = 1; i < nums.size(); i++){
            prefixSum[i] += prefixSum[i - 1];
        }
        
        unordered_map<int,int> map;
        
        map[0] = 1;         //0 sum wala ek hai jisme kuch nhi liya 
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if (prefixSum[i] - k >= 0){
                ans += map[prefixSum[i] - k];
            }
            map[prefixSum[i]]++;
        }
        

        return ans;
    }
};

 //Deque
 /*When we find k odd numbers, we have one nice subarray, plus an additional subarray for each even number preceding the first odd number. This is also true for each even number that follows.

For example, in the picture below we found k == 2 odd numbers at index 4. We have 3 nice subarrays therefore: [2, 4], [1, 4], [0, 4]. For even number at index 5, we also have 3 nice subarrays: [2, 5], [1, 5], [0, 5]. Plus 3 subarrays for index 6.

When we encounter k + 1 odd number at index 7, we need to get rid of the first odd number (at index 2) to have exactly k odd numbers. So, we count nice subarrays as if the array starts at index 3.
*/
 int numberOfSubarrays(vector<int>& nums, int k, int res = 0) {
  deque<int> deq = { -1 };
  for (auto i = 0; i < nums.size(); ++i) {
    if (nums[i] % 2) deq.push_back(i);
    if (deq.size() > k + 1) deq.pop_front();
    if (deq.size() == k + 1) res += deq[1] - deq[0];
  }
  return res;
}