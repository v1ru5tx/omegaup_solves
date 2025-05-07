#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

std::string to_string(__int128 value) {
  if (value == 0) {
      return "0";
  }

  bool is_negative = false;
  if (value < 0) {
      is_negative = true;
      value = -value;
  }

  std::string result = "";
  while (value > 0) {
      result += (char)('0' + (value % 10));
      value /= 10;
  }

  if (is_negative) {
      result += '-';
  }

  std::reverse(result.begin(), result.end());
  return result;
}


int main () {
  __uint128_t i=1, j=1, next=0;
  
  std::cout << to_string(i) << std::endl;
  std::cout << to_string(j) << std::endl;
  
  while( next < pow(2,64) ){
    next = i + j;
    std::cout << to_string(next) << std::endl;
    i = j;
    j = next;
  }
  return 0;
}
