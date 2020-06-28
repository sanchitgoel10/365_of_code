//Approach-1
//Use a map to store the frequencies of remainders and then travel the array and check one by one.

//(x%k + k)%k is done to counter negative integers in the array.

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if(arr.size()&1) return false;
        unordered_map<int,int>m;
        for(auto x:arr) m[(x%k + k)%k]++;          //store the count of remainders in a map.
        for(auto x:arr)
        {
            int rem=(x%k + k)%k;
            if(rem==0)                         //if the remainder for an element is 0 then the count of numbers that give this remainder must be even.
            { 
                if(m[rem] & 1) return false;            //if count of numbers that give this remainder is odd all pairs can't be made hence return //false.
            }         
            else if(m[rem] != m[k - rem]) return false;    //if the remainder rem and k-rem do not have the same count then pairs can not be made 
        }
        return true;
    }
};
//Approach-2
//This approach also works fine only if there are no duplicates in the array.
//it works for this question

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        long long res = 0;
        for(int x:arr) res +=x; 
        return (res % k == 0);  // if the sum of all elements is divisible by k then all pairs exists
    }
};