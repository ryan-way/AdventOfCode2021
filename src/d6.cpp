#include "days.h"
#include "parsing.h"
#include <iostream>
#include "logging.h"

size_t calculateFish(std::ifstream &ifile, int days) {
  std::string input;
  std::getline(ifile, input);
  std::vector<int> fishes = Parsing::csvLineToVector(input);

  for(int i = 0; i < days; i++) {
    size_t size = fishes.size();
    for(size_t j = 0; j < size; j++) {
      if(fishes[j] == 0) {
        fishes[j] = 6;
        fishes.push_back(8);
      }
      else {
        fishes[j]--;
      }
    }
  }
  

  return fishes.size();
}

unsigned long long fastFish(std::ifstream &ifile, int days) {
  std::string input;
  std::getline(ifile, input);
  std::vector<int> fishes = Parsing::csvLineToVector(input);
  std::vector<unsigned long long> cFishes(9, 0);

  for(int fish : fishes) {
    cFishes[fish]++;
  }

  for(int i = 0; i < days; i++) {
    unsigned long long prev = cFishes[8];
    cFishes[8] = 0;
    for(int i = 7; i >= 0; i--) {
      std::swap(prev, cFishes[i]);
    }

    cFishes[8] += prev;
    cFishes[6] += prev;
  }

  unsigned long long res = 0;
  for(unsigned long long i : cFishes) {
    res += i;
  }

  return res;
}

int d6p1(std::ifstream &ifile) {
  return fastFish(ifile, 80);
}

size_t d6p2(std::ifstream &ifile) {
  return fastFish(ifile, 256);
}
