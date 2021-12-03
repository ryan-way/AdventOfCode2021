#include <iostream>
#include <vector>

int main() {
  int first = -1, second = -1, third = -1, fourth = -1;
  int count = 0;

  while(std::cin >> first) {

    if(fourth != -1) {
      count += first > fourth;
    }

    fourth = third;
    third = second;
    second = first;
    /* std::cout << first << " " << second << " " << third << " " << fourth<< " " << count << std::endl; */
  }

  std::cout << count << std::endl;
}
