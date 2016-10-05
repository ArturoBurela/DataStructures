#include <iostream>
using namespace std;

class Investment {
    float rate;
    float amount;
    int years;
  public:
    void init();
    float calculateRecursive(float n, int y);
};
void Investment::init() {
  cout << "Enter yearly interest rate:" << endl;
  cin >> rate;
  cout << "Enter investment duration (in years):" << endl;
  cin >> years;
  std::cout << "Enter amount to invest:" << std::endl;
  std::cin >> amount;
  calculateRecursive(amount,0);
}
float Investment::calculateRecursive(float n, int y) {
  std::cout << "=================" << std::endl;
  cout << "Year: "<< y << endl;
  std::cout << "Total amount:"<< amount << std::endl;
  amount += amount*rate;
  if(y==years){std::cout << "=================" << std::endl;}
  if(y<years){calculateRecursive(amount,y+1);}
}
