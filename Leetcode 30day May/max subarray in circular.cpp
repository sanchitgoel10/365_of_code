
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& v) {
      int n = v.size();
      if(n==1)return v[0];
      vector <int> leftSum(n),leftSumMax(n),rightSum(n), rightSumMax(n);
      leftSum[0] = v[0];
      leftSumMax[0] = max((int)0,v[0]);
      for(int i =1;i<n;i++){
         leftSum[i] = leftSum[i-1] + v[i];
         leftSumMax[i] = max(leftSum[i],leftSumMax[i-1]);
      }
      rightSum[n-1] = v[n-1];
      rightSumMax[n-1] = max((int)0,v[n-1]);
      for(int i =n-2;i>=0;i--){
         rightSum[i] = rightSum[i+1]+v[i];
         rightSumMax[i] = max(rightSumMax[i+1],rightSum[i]);
      }
      int leftAns=leftSum[0]+rightSumMax[1];
      for(int i =1;i<n-1;i++){
         leftAns = max(leftAns,leftSum[i]+rightSumMax[i+1]);
      }
      int rightAns = rightSum[n-1]+leftSumMax[n-2];
      for(int i =n-2;i>=1;i--){
         rightAns = max(rightAns,rightSum[i]+leftSumMax[i-1]);
      }
      int curr=v[0];
      int kadane = v[0];
      for(int i =1;i<n;i++){
         curr = max(v[i],curr+v[i]);
         kadane = max(curr,kadane);
      }
      return max(leftAns,max(rightAns,kadane));
    }
};