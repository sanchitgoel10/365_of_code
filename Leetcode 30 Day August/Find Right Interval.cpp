/*
	[[1,12],[2,9],[3,10],[13,14],[15,16],[16,17]]   <= Input array
	Map Will be     
m [ 1 ]  = 0     m [ 2 ] = 1    m [ 3 ] =  2     m [ 13 ] =  3 	m [ 15 ]  = 4     m [ 16 ] = 5
Now,
lower_bound of    12   is   13 [ in map key ]   now m [ 13 ] =  3  put it in answer array     ans => [ 3 ]  
lower_bound of    9   is   13 [ in map key ]   now m [ 9 ] =  3  put it in answer array     ans => [ 3, 3 ]  
lower_bound of    10   is   13 [ in map key ]   now m [ 10 ] =  3  put it in answer array     ans => [ 3, 3, 3 ]  
lower_bound of    14   is   15 [ in map key ]   now m [ 14 ] =  4  put it in answer array     ans => [ 3, 3, 3, 4 ]  
lower_bound of    17   is   none or You can say It reachs end of map so  put  -1 in answer array     ans => [ 3, 3, 3, 4, -1 ]  

at last return [ 3, 3, 3, 4, -1 ] 
Time Complexcity

As insertion of each element in map take O (log N) Time
so For N number of element it takes O ( N log N) Time
lower_bound  takes O (log N) Time
so For N number of element it takes O ( N log N) Time
So total Time Complexcity Would Been O (2*N log N)     ~ O ( N log N )
Space Complexcity

It will be ~ O ( N ) approx  
*/
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size());
        map<int, int> m;
        for(int i = 0; i < intervals.size(); i++)
            m[intervals[i][0]] = i;
        for(int i = 0; i < intervals.size(); i++) 
               ans[i]  = m.lower_bound(intervals[i][1])!=end(m)?m.lower_bound(intervals[i][1]) -> second:-1;
        return ans;
    }
};