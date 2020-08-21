//Tushar roy video please 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m){
            swap(n,m);
            swap(nums1,nums2);
        }
        int left = 0;
        int right = n;
        int total = (n+m+1)/2;
        int x,y;
        while(left<=right){
            x = (left+right)/2;
            y = total-x;
            if((x?nums1[x-1]:INT_MIN)>(y<m?nums2[y]:INT_MAX)){
                right = x-1;
            }else if((y?nums2[y-1]:INT_MIN)>(x<n?nums1[x]:INT_MAX)){
                left = x+1;
            }else{
                break;    
            }
        }
        if((n+m)&1)
            return max(x?nums1[x-1]:INT_MIN,y?nums2[y-1]:INT_MIN);
        return (max(x?nums1[x-1]:INT_MIN,y?nums2[y-1]:INT_MIN)+
                min((x<n?nums1[x]:INT_MAX),(y<m?nums2[y]:INT_MAX)))/2.0;
    }
};