/*
 *   Copyright (c) 2026
 *   All rights reserved.
 */

#include <iostream>
using namespace std;


// consteval:
consteval int get_value(){
  return 3;
}
// entryPoint of program normally is main(), using the snippet runner I WRAP this in a main
int runIt() {

  cout << "Hello World!" << endl;
  return 0;
}