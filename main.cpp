#include <vector>
#include <string>
#include <iostream>
//#include "date.h"
#include "book.h"

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
  Book::Book asdf = Book::Book("123-123-12-vbfg", "asadfdsafsdf", "aasdfsdsdf", a);
  cout << asdf.isbn();
  return 0;
}
