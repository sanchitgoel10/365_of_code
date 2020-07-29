class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       // two states:
        // "hold" state: represent the max profit when we hold a stock at time i - 1.
        // "empty" state: represent the max profit when we do not hold a stock at time i - 1.
        // initialization:
        // for "hold" state, we hold one stock, so the profit is -prices[0]
        // for "empty" state, we do not hold stock, so the profit is 0
        int hold = -prices[0], empty = 0;
        for (int i = 1; i < prices.size(); i++) {
            // on current time i
            // the max profit of hold state is either we still hold the stock we hold at the i-1 time(hold)
            // or we buy new stock(empty - prices[i])
            hold = max(hold, empty - prices[i]);
            // the max profit of enpty state is eighter we still keep our hand empty(empty)
            // or we sell the stock we already hold(hold + prices[i] - fee)
            empty = max(empty, hold + prices[i] - fee);
        }
        // return must be empty, because selling is better than holding one stock that has not been sold
        return empty; 
    }
};