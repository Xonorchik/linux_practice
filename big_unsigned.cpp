#include <iostream>
#include <string>
#include <vector>

class BigUnsigned {
public:
  std::vector <unsigned long long> _sum;
  int last;
  BigUnsigned(const std::string &s) {
    unsigned long long x = 1;
    int j = 0;
    last = s.size()/19;
    last++;
    for(int k = 0;k<last;++k) {
      for(int l = 0;l<19 && l<s.size()-j;++l) {
      if(l != 0) {
        x *= 10;
      }
    }
      _sum.push_back(0);
      for(int i = 0;i<19&& i<s.size();++i) {
        if(i != 0) {
          x /= 10;
        } 
        _sum[k] = _sum[k] + ((s[j] - 48) * x);
        ++j;
      }
      std::cout << _sum[k];
    }
    std::cout << std::endl;
  }
};
  BigUnsigned operator +(BigUnsigned &a, BigUnsigned &b) {
    int last = a.last;
    int last_b = b.last;
    
    BigUnsigned sum(0);
    sum._sum[0] = a._sum[0];
    sum._sum[1] = a._sum[last] + b._sum[last_b];
    return sum;
  }
  BigUnsigned operator *(BigUnsigned &a, BigUnsigned &b) {
    BigUnsigned mult = a * b;
    return mult;
  }
  int main() {
    BigUnsigned A("123456789012345678901234567890");
    BigUnsigned B("7");
    //A+B;
    return 0;
  }