#include "days.h"
#include <sstream>
#include <iostream>
#include <vector>
#include "logging.h"

int d8p1(std::ifstream &ifile) {
  std::string input;
  int count = 0;;
  while(std::getline(ifile, input)) {
    std::stringstream ss(input);
    std::string token = "";

    while(token != "|") ss >> token;
    while(ss >> token) {
      count += (token.size() == 2) || (token.size() == 3)
        || (token.size() == 4) || (token.size() == 7);
    }
  }

  return count;
}

bool areEqual(std::vector<int> &first, std::vector<int> &second) {
  for(unsigned int i = 0; i < first.size(); i++) {
    if(first[i] != second[i]) return false;
  }

  return true;
}

std::vector<int> fromString(std::string &in) {
  std::vector<int> res(7, 0);
  for(const char c : in) {
    res[c-'a']++;
  }

  return res;
}

int countOverlap(std::vector<int> &first, std::vector<int> &second) {
  int count = 0;
  for(unsigned int i = 0; i < first.size(); i++) {
    count += first[i] && second[i];
  }

  return count;
}

int d8p2(std::ifstream &ifile) {
  std::string input;
  int count = 0;

  while(std::getline(ifile, input)) {
    std::vector<std::vector<int>> keys(10, std::vector<int>(0, 0));
    std::stringstream ss(input);
    std::string token = "";
    std::vector<std::string> codes;
    ss >> token;
    while(token != "|") {
      if(token.size() == 2) {
        keys[1] = fromString(token);
      }
      else if(token.size() == 7) {
        keys[8] = fromString(token);
      }
      else if(token.size() == 3) {
        keys[7] = fromString(token);
      }
      else if(token.size() == 4) {
        keys[4] = fromString(token);
      }
      else {
        codes.push_back(token);
      }
      ss >> token;
    }

    for(std::string code : codes) {
      std::vector<int> map = fromString(code);
      if(code.size() == 6) {
        if(countOverlap(map, keys[1]) == 1) {
          keys[6] = map;
        }
        else if(countOverlap(map, keys[4]) == 4) {
          keys[9] = map;
        }
        else keys[0] = map;
      }
      if(code.size() == 5) {
        if(countOverlap(map, keys[1]) == 2) {
          keys[3] = map;
        }
        else if(countOverlap(map, keys[4]) == 3) {
          keys[5] = map;
        }
        else keys[2] = map;
      }
    }
    int mCount = 0;
    while(ss >> token) {
      std::vector<int> code = fromString(token);
      for(unsigned int i = 0; i < keys.size(); i++) {
        if(areEqual(code, keys[i])) {
          mCount *= 10;
          mCount += i;
          break;
        }
      }
    }
    count += mCount;
  }
  return count;
}
