
/*
One great reason you can just remove the smaller numbers from stack(seen in right) is that now that we have current number larger than its right elements -> Hence for the lefter elements THIS CURRENT element will itself be the nearest largest number
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s; //First is the number while second is the position
        
        int n= temperatures.size();
        vector<int> result(n,0);
        
        for(int i=n-1;i>=0;i--)
        {
            int curr = temperatures[i];
            while(!s.empty() && s.top().first <= curr) s.pop();
            
            result[i] = s.empty() ? 0 : s.top().second - i;

            s.push({curr,i});
        }
        
        return result;
    }
};
/*
We compute the result in reverse order. Given temperatures = [73, 74, 75, 71, 69, 72, 76, 73], suppose that we already obtain number of days for i >= 3: res = [?, ?, ?, 2, 1, 1, 0, 0] where ? denotes values to be determined. In order to find the number of days for i = 2, we proceed as follows:

Let j = i + 1, i.e., j = 3. If temperatures[i] < temperatures[j], res[i] = 1;
Otherwise, temperatures[i] >= temperatures[j]. we examine the value of res[j], which is equal to 2, which means that the most recent day with higher temperature than temperatures[j] in the future is 2 days away. Since temperatures[i] >= temperatures[j], the most recent day with higher temperature than temperatures[i] should be at least 2 days away. Therefore, we can skip some days and arrive directly at day j + res[j]. This process continues until we find higher temperature or we know we should stop as descibed in the third point.
If temperatures[j] == 0, we shoud directly set res[i] to 0 since we know we cannot find higher temperature in the future.
The code is as follows. The complexity is O(n) in time and O(1) in space (since we leverage the space of the output).
*/
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; --i) {
        int j = i+1;
        while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
            if (res[j] > 0) j = res[j] + j;
            else j = temperatures.size();
        }
        // either j == size || temperatures[j] > temperatures[i]
        if (j < temperatures.size()) res[i] = j - i;
    }
    return res;
}