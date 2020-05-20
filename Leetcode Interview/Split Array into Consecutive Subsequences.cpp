/*The idea is , we scan the array for two times.
In first pass we count the frequencies of all numbers and record them in cnt
For the second pass, we are "building" our subsequences by the following rules:

We use a hashmap called tails to record extra information, where tails[i] means the number of consecutive subsequences we've found so far, 
who are longer than 3 , and tailed by number i,
When we meet number i, try to put it to the tail of one of found subsequences tailed by i-1. No need to worry that we might
 have a better choice to consider i as a brand new head for another subsequence, because we can always append the new subsequence 
 to a previous one tailed by i-1.
If we can't, it will cost one i+1 and one i+2 later to generate a new sequence. We just pay that right now by decrease cnt[i+1] and cnt[i+2]. 
Some one may worry that we make use of the numbers we haven't scanned so far. But actually we've already kept track of the numbers 
remained by cnt. Just imaging we grab the numbers needed from the very end of the string, and mark them as "used". If there is no
 such number available to pay, cnt will tell us by checking cnt[i+1] cnt[i+2] is positive or not
The code is short and concise, shown below:
*/
bool isPossible(vector<int>& nums) {
        unordered_map<int,int> cnt, tails;
        for(int &i : nums) cnt[i]++;
        for(int &i : nums){
            if(!cnt[i]) continue;
            cnt[i]--;
            if(tails[i-1] > 0){
                tails[i-1]--;
                tails[i]++;
            }
            else if(cnt[i+1] && cnt[i+2]){
                cnt[i+1]--;
                cnt[i+2]--;
                tails[i+2]++;
            }
            else return false;
        }
        return true;
    }