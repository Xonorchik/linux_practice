#include <iostream>
#include <list>
#include <unordered_map>

class LRU {
  int capacity = 3;
  std::list<int> cache;
  std::unordered_map<int, std::list<int>::iterator> names;

public:
  void insert(int viewNumber) {
    if (names.find(viewNumber) == names.end()) {
      if (cache.size() == capacity) {
        names.erase(cache.back());
        cache.pop_back();
      }
    } else {
      cache.erase(names[viewNumber]);
    }
    cache.push_front(viewNumber);
    names[viewNumber] = cache.begin();
  }

  void print_cache() {
    for (auto v: cache) {
      std::cout << v << std::endl;
    }
  }
};

int main() {
    LRU l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(2);
    l.insert(2);
    l.insert(2);
    l.insert(2);
    l.print_cache();
    return 0;
}