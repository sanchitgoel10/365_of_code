class Solution {
public:
    vector<int> merge(vector<int>& left, vector<int>& right, vector<int>& nums, vector<int>& res){
        int l = 0, lsize = left.size(),
            r = 0, rsize = right.size();
        int smaller = 0; // count number of smaller on right
        vector<int> index;
        while(l<lsize && r<rsize){
            if(nums[left[l]] > nums[right[r]]){
                smaller++;// increment count when left > right
                index.push_back(right[r++]);
            }
            else{
                res[left[l]] += smaller; // put when left <= right
                index.push_back(left[l++]);
            }
        }
        while(l<lsize){
            res[left[l]] += smaller;
            index.push_back(left[l++]);
        }
        while(r<rsize){
            index.push_back(right[r++]);
        }
                
        return index;        
    }
    
    void merge_sort(vector<int>& index, vector<int>& nums, vector<int>& res){
        int size = index.size();
        if(size<2) return;
        vector<int> left, right;
        left.assign(index.begin(), index.begin()+size/2);
        right.assign(index.begin()+size/2, index.end());
        merge_sort(left, nums, res);
        merge_sort(right, nums, res);
		// now comes the merge step;
        index = merge(left, right, nums, res);
        return;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        vector<int> oldIdx(nums.size(),0);
        iota(oldIdx.begin(), oldIdx.end(), 0);
        merge_sort(oldIdx, nums, res);
        return res;
    }
    
};