#include <vector>
#include <cmath>
#include <string>
#include <iostream>

namespace Chrono {
	enum class Month {
		jan=1, feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
	};

	class Day {
	public:
		int d;
		Day(int dd):
			d(dd) {
				if (dd < 0 || dd > 31)
					std::cout << "Invalid day";
			}
	};

}
