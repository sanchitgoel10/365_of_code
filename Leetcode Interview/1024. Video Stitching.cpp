/*
Observation 1: We will always pick a clip with the maximum coverage if they have same starting points.

eg: [0,3],[0,7],[0,5] -> We pick [0,7] , there is no point of picking others as the problem states that we need to minimize the number of clips picked, and this can only be done if we maximize the gap between start and end point of each clip.

Observation 2: Once we start picking the clips from the minimum starting point, we only increase the count if we find a starting point greater than previously selected clip's end, from then on we keep maximizing the reachable end without increasing count.

eg: [[0,4],[1,4],[2,6],[3,4],[4,7],[5,7],[6,9]], T=9

We select [0,4], count=1 ,selectedEnd=0,reachableEnd=4
We select [1,4], start > selectedEnd we increase count=2 and reachableEnd=4, selectedEnd=4 (Previously selected end)
We encounter [2,6], we increase rechableEnd=6, we don't increase count asthe clip's starting point is still between [0,4] (previously selected clip)
Similarly We encounter [4,7], we increase reachableEnd=7.
When we reach [5,7] increase count=3 as 5 > [0,4] interval's end (It is here that we decide that the previously selected interval is actually [4,7] and not [1,4] where we actually increased count(step 2))
We encounter [6,7] increase reachableEnd=7 and return count=3.
*/
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) 
    {
        int ends[T + 1]; memset(ends, 0, sizeof(ends)); // replace the hashmap with array, reduces run time from 8ms to 4ms.
        // Find the furthest end for each start point.
        for(auto &clip : clips) if(clip[0] <= T) ends[clip[0]] = max(ends[clip[0]], min(clip[1], T)); 
        int count = 0, i = 0, end = 0;
        for(int prev_end = 0; prev_end < T;){
            while(i <= prev_end) end = max(end, ends[i++]); // extend the end as far as possible.
            if(end == prev_end) return -1;  // according to the loop condition, prev_end < T, and we cannot go further, return -1.
            prev_end = end, count++;
        }
        return count;
    }
};