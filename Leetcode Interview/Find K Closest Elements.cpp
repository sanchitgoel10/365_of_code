class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>result;
    
        int low = 0;
        int high = arr.size()-1;

        while(high - low >= k)
        {
            if(abs(arr[low]-x) <= abs(arr[high]-x))
                high--;
            else
                low++;
        }

        for(int i = low; i<= high;i++)
            result.push_back(arr[i]);

        return result;
    }
};