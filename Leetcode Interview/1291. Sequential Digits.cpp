vector<int> sequentialDigits(int low, int high) {
	set <int> sequential;
    int i=1, j=1, seq=0;
    while(i<10) {
        seq = seq * 10 + j;
        sequential.insert(seq);
        if(j==9) { i++; seq=0; j=i;continue;}
        j++;
    }        
    auto firstIter = upper_bound(sequential.begin(), sequential.end(),low-1);
    auto lastIter = lower_bound(sequential.begin(), sequential.end(), high);
    return vector(firstIter, lastIter);
}

//Basically it generates numbers like this{12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,
//                               1234,2345,3456,4567,5678, 6789,12345,23456,34567,45678,56789,
//                             123456,234567,345678,456789,1234567,2345678,3456789,
//                               12345678,23456789,123456789}