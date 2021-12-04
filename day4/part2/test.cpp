#include <vector>
#include <iostream>

int main() {
  std::vector<int> v { 1, 2, 3, 4, 5 };

  for(auto it = v.begin(); it != v.end(); it++) {
    if(*it == 5) v.erase(it);
    std::cout << *it << std::endl;
  }
}
