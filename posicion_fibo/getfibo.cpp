#include <iostream>
#include <cmath>
#include <string>

using namespace std; 

int main () {
  unsigned long long i=1, j=1, next=0;
  cout << to_string(i) << endl;
  cout << to_string(j) << endl;
  while( next < pow(2,63) ){
    next = i + j;
    cout << to_string(next) << endl;
    i = j;
    j = next;
  }
  return 0;
}
