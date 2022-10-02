#include <iostream>
#include <string>

int BigUnsigned(const std::string &s) {
  int a = 0;
  int x = 1;
  for(int l = 0;l<s.size();++l) {
    if(l != 0) {
      x *= 10;
    }
  }
  for(int i = 0;i<s.size();++i) {
    if(i != 0) {
      x /= 10;
    } 
    a += ((s[i] - 48) * x);
  }
  return a;
}

int main() {
  std::string str1;
  std::string chr;
  std::string str2;
  std::cin >> str1;
  std::cin >> chr;
  std::cin >> str2;
  int a,b;
  a = BigUnsigned(str1);
  b = BigUnsigned(str2);
  if(chr == "+") {
    a += b;
  }
  else if(chr == "*") {
    a *= b;
  }
  std::cout << a;
return 0;
}