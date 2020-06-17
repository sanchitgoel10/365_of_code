class Solution {
public:
    
    static bool cmp(int&a,int&b){
        return __builtin_popcount(a)==__builtin_popcount(b)?a<b:__builtin_popcount(a)<__builtin_popcount(b);
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};
//Anther way of writing cmp function withing sort function
vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(),[](const int& a, const int& b){
            int countA = __builtin_popcount(a), countB = __builtin_popcount(b);
            return countA==countB ? a<b:countA<countB;});
        return arr;
    }