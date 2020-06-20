class ProductOfNumbers {
public:
    vector<int> A={1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num){
            A.push_back(A.back()*num);
        }else{
            A={1};
        }
    }
    
    int getProduct(int k) {
        if(k>=A.size())return 0;
        else return A.back()/A[A.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */