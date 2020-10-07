#include <iostream>

#include "a.h"

// compile and run:
// g++ -c b.cpp && g++ -c a.cpp && g++ a.o b.o && ./a.out

void sayHi() {
  std::cout << "Hi!" << std::endl;
}

int main () {
  int b = a_func(5);
  std::cout << b << std::endl;
  sayHi();
}
