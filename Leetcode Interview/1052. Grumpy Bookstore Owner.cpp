/*When the owner is not grumpy, we count all customers as satisfied.

We then use the sliding window to count additionally satisfied customers (add_satisfied) if the owner start 'behaving' at minute i. We track the maximum additional satisfied customers in m_add_satisfied.

Finally, return satisfied + m_add_satisfied as the result.
*/
int maxSatisfied(vector<int>& cs, vector<int>& grumpy, int X) {
    auto satisfied = 0, m_add_satisfied = 0, add_satisfied = 0;
    for (auto i = 0; i < cs.size(); ++i) {
        satisfied += grumpy[i] ? 0 : cs[i];                            //normal case when we dont use the sectret technique
        add_satisfied += grumpy[i] ? cs[i] : 0;                        //current additional satisfaction with use of technique
        if (i >= X) add_satisfied -= grumpy[i - X] ? cs[i - X] : 0;    //window is only of size X
        m_add_satisfied = max(m_add_satisfied, add_satisfied);         //best additional satifaction provided
    }
    return satisfied + m_add_satisfied;
}
//Complexity Analysis
//Runtime: O(n)
//Memory: O(1)