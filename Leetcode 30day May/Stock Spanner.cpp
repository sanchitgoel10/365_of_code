class StockSpanner {
public:
    stack<pair<int,int> > s;
    int i=0;
    StockSpanner() {
    }
    
    int next(int price) {
        while(!s.empty()&&price>=s.top().first){
            s.pop();
        }
        int ans=s.empty()?(i+1):i-s.top().second;
        s.push({price,i});
        i++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */