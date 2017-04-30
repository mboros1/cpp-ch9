#include <vector>
#include <string>
#include <iostream>
#include "date.h"

using namespace std;

int main() {
  Chrono::Date a = Chrono::Date(1984,Chrono::nov,24);
  cout << a << '\n';
  a.add_day(5);
  cout << a << '\n';
  a.add_day(50);
  cout << a << '\n';
  a.add_month(10);
  cout << a << '\n';
  a.add_month(10);
  cout << a << '\n';
  a.add_year(50);
  cout << a << '\n';
  
  return 0;
}
