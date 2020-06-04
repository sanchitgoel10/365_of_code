/*We can track how many frogs are 'singing' each letter in cnt:

Increase number of frogs singing this letter, and decrease number singing previous letter.
When a frog sings 'c', we increase the number of (simultaneous) frogs.
When a frog sings 'k', we decrease the number of (simultaneous) frogs.
If some frog is singing a letter, but no frog sang the previous letter, we return -1.

Track and return the maximum number of frogs ever signing together.

Catch: if some frog hasn't finished croaking, we need to return -1.


Count maximum number of ongoing state machines (This is the problem)

*/
int minNumberOfFrogs(string croakOfFrogs) {
    int cnt[5] = {}, frogs = 0, max_frogs = 0;
    for (auto ch : croakOfFrogs) {
        auto n = string("croak").find(ch);
        ++cnt[n];
        if (n == 0)
            max_frogs = max(max_frogs, ++frogs);     //new frog in town 
        else if (--cnt[n - 1] < 0)                 //previous letter 
            return -1;
        else if (n == 4)       //reached letter k
            --frogs;
    }
    return frogs == 0 ? max_frogs : -1;     //this is the catch
}
