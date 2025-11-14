#include <ctime>
#include <cstdlib>
#include <iostream>

#include "HashSet.h"

using namespace std;

void initHashSet(HashSet &hs, int* values){
  for (int i = 0; i < 20; ++i){
    hs.add(values[i]);
  }
}

int main(){

  srand(time(0));

  auto generateValues = [](int count, int* out){
    for (int i = 0; i < count; ++i) out[i] = rand() % 100 + 1;
  };
  int values[20];
  generateValues(20, values);

  cout << "SIMPLE" << endl;
  HashSet hss(2, SIMPLE);
  initHashSet(hss, values);
  hss.printHashSet();

  cout << "LINEAR PROBING" << endl;
  HashSet hslp(2, LINEAR_PROBING);
  initHashSet(hslp, values);
  hslp.printHashSet();

  cout << "ROBIN HOOD" << endl;
  HashSet hsrh(2, ROBIN_HOOD);
  initHashSet(hsrh, values);
  hsrh.printHashSet();

  return 0;
}
