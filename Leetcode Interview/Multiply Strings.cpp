string res(num1.size() + num2.size(), '0');
  for (int i = num1.size() - 1; i >= 0; i--) {
    for (int j = num2.size() - 1; j >= 0; j--) {
        int prod =  (num1[i] - '0') * (num2[j] - '0') +  (res[i + j + 1] - '0');
        res[i+j+1] = (prod % 10) + '0';
        res[i+j] = ((prod /10) + (res[i + j] - '0')) + '0';
    }
  }
  //remove the trailing zeros
  int it = res.find_first_not_of("0");
  return ( it < 0  ? "0" : res.substr(it) );