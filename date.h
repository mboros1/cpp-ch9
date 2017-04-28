#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>

namespace Chrono {
	enum class Month {
		jan=1, feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
	};

	class Day {
	public:
		int d;
		Day(int dd):
			d(dd) {
				if (dd < 1 || dd > 31)
					throw invalid_argument("Day out of range");
			}
	};
	
	class Date {
	public:
		Date(int y, Month m, Day d);
		Day day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }
		
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);

	private:
		int y;
		Month m;
		Day d;
	};
}
