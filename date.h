#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>


namespace std {
namespace Chrono {
	enum Month {
	  jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};
	
	class Date {
	public:
	  class Invalid{};
		Date(int y, Month m, int d);
		Date();
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }
		
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);

	private:
		int y;
		Month m;
		int d;
	};

	bool is_date(int y, Month m, int d);
	bool leapyear(int y);

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	std::ostream& operator<<(std::ostream& os, const Date& d);
	std::istream& operator>>(std::istream& is, Date& dd);

	
	enum class Day {
		sunday=0, monday=1, tuesday, wednesday, thursday, friday, saturday
	};
	
	Day day_of_week(const Date& d);
	//Date next_Sunday(const Date& d);
	//Date next_weekday(const Date& d);

	Date::Date(int yy, Month mm, int dd)
      :y(yy),m(mm),d(dd)
    {
      if (!is_date(yy,mm,dd)) throw Invalid();
    }

  const Date& default_date() {
    static Date dd(2001,jan,1);
    return dd;
  }

  Date::Date()
    :y(default_date().year()),
     m(default_date().month()),
     d(default_date().day()) {}
  int days_in_month(int y, Month m);

  void Date::add_day(int n) {
    int dd = days_in_month(y, m);
    if (d +  n > dd) {
      d = (d+n)%dd;
      add_month(1);
    }
    else d += n;
  }

  void Date::add_month(int n) {
    int mm = m;
    if (mm+n > 12) {
      add_year(1);
      m=Month((mm+n)%12);
    }
    else {
      m = Month(mm+n);
    }
  }

  void Date::add_year(int n) {
    if (m == feb && d == 29 && !leapyear(y+n)) {
      m=mar;
      d=1;
    }
    y+=n;
  }

  // helper functions:
  int days_in_month(int y, Month m) {
    int days = 31;
    switch(m) {
    case feb:
      days = leapyear(y)?29:28;
      break;
    case apr:
    case jun:
    case sep:
    case nov:
      days = 30;
      break;
    default:
      break;
    }
    return days;
  }
  
  bool is_date(int y, Month m, int d) {
    if (d<=0) return false;
    if (m<jan||dec<m) return false;
    
    if (days_in_month(y,m)<d) return false;

    return true;
  }

  bool leapyear(int y) {
    if (y % 400 == 0) return true;
    else if (y % 100 == 0) return false;
    else if (y % 4 == 0) return true;
    else return false;
  }

  bool operator==(const Date& a, const Date& b) {
    return a.year() == b.year()
      && a.month() == b.month()
      && a.day() == b.day();
  }

  bool operator!=(const Date& a, const Date& b) {
    return !(a==b);
  }

  ostream& operator<<(ostream& os, const Date& d) {
    return os <<'(' << d.year()
	      <<','<< d.month()
	      << ',' << d.day() << ')';
  }

  istream& operator>>(istream& is, Date& dd) {
    int y,m,d;
    char ch1,ch2,ch3,ch4;
    is>>ch1>>y>>ch2>>m>>ch3>>d>>ch4;
    if (!is) return is;
    if(ch1!='('||ch2!=','||ch3!=','||ch4!=')') {
      is.clear(ios_base::failbit);
      return is;
    }
    dd=Date(y,Month(m),d);

    return is;
  }


  Day day_of_week(const Date& d) {
    int dd = d.day();
    return (Day(dd%7));
  }

  //Date next_Sunday(const Date d) {}

  //Date next_weekday(const Date& d) {}
 
}
}
