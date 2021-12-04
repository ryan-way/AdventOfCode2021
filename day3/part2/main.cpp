#include <iostream>
#include <string>
#include <vector>
#include <bitset>

int mostCommonBitValue(const std::vector<int>& nums, int bit) {
  unsigned int count = 0;
  
  for(int num : nums) {
    count += (num >> bit) & 1;
  }

  return count >= (nums.size()/2.0);
}

std::vector<int> filterByBitValue(
    const std::vector<int>& nums,
    int bit,
    int value) {
  std::vector<int> filtered;

  for(int num : nums) {
    if(((num >> bit) & 1) == value) {
      filtered.push_back(num);
    }
  }

  return filtered;
}

int main() {

  std::string input;
  std::vector<int> nums;
  int maxBit = 0;

  while(std::cin >> input) {
    int value = std::stoi(input, 0, 2);
    while((1 << (maxBit+1)) < value) maxBit++;
    nums.push_back(value);
  }

  std::vector<int> oxygen(nums.begin(), nums.end());
  std::vector<int> co2(nums.begin(), nums.end());

  int bit = maxBit;
  while(oxygen.size() > 1) {
    int commonValue = mostCommonBitValue(oxygen, bit);
    oxygen = filterByBitValue(oxygen, bit, commonValue);
    bit--;
  }

  bit = maxBit;
  while(co2.size() > 1) {
    int commonValue = mostCommonBitValue(co2, bit)? 0 : 1;
    co2 = filterByBitValue(co2, bit, commonValue);
    bit--;
  }

  std::cout << co2[0]*oxygen[0] << std::endl;
  return 0;
}