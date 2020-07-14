#include <iostream>

int* twoSum(int* nums, int target) {
  int find[2]={-1};
  for (int i=0; i < 4; i++) {
    for (int j = i+1; j < 4; j++) {
      if (nums[j] == target - nums[i]) {
        find[0] = i;
        find[1] = j;
        return find;
      }
    }
  }
  return find;
}

int main() {
  int num_arr[] = {3,1,3,6};
  int tar = 6;
  auto ret = twoSum(num_arr, tar);
  std::cout << ret[0] << std::endl;
  std::cout << ret[1] << std::endl;
  return 0;
}

