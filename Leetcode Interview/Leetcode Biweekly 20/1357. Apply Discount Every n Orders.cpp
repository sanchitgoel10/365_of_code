class Cashier {
public:
    int count=1;
    unordered_map<int,int> m;
    int num;
    double dis;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        num=n;
        dis=(double)discount;
        for(int i=0;i<products.size();i++){
            m[products[i]]=prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double bill=0;
        for(int i=0;i<product.size();i++){
            bill+=(m[product[i]]*amount[i]);
        }
        if(count==num){
            count=1;
            return (double)(bill-(dis*bill)/100);
        }else{
            count++;
            return bill;
        }
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */