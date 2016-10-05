#include <iostream>
void byValue(int a) {
  a *= 2;
}
void byPointer(int * a) {
  *a *= 2;
}
void byReference(int & a) {
  a *= 2;
}
int main(int argc, char const *argv[]) {
  int a = 50;
  std::cout << "Original: " << a <<std::endl;
  byValue(a);
  std::cout << "By value: " <<a<< std::endl;
  byPointer(&a);
  std::cout << "By pointer: " << a<<std::endl;
  byReference(a);
  std::cout << "By reference" << a<<std::endl;
  return 0;
}
