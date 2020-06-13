/*
We maintain the runnig product in the prefix array. To get the product for the last k elements, we divide the lastt running product by the product that was k - 1 steps ago.

Important observation: if we add zero, we reset the prefix array. All products that includes zero will be zero. So, we can just check if k is greater than the size of our previx array, and return zero in that case.
*/
vector<long long> pr = { 1 };
void add(int num) {
    if (num == 0) pr = { 1 };
    else pr.push_back(pr.back() * num);
}
int getProduct(int k) {
    if (k >= pr.size()) return 0;          //k se chota hai matlab kahi bich me zero aa gaya tha
    return pr.back() / pr[pr.size() - k - 1];
}