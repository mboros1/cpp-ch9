#include <vector>
#include <string>
#include <iostream>
#include "date.h"

namespace std {
	namespace Book {
		class Book {
		public:
			string isbn() { return ISBN; }
			string title() { return Title; }
			string author() { return Author; }
			Chrono::Date copyright() { return Copyright; }
			bool is_out() { return Is_Out; }
			void check_in() { Is_Out = false; }
			void check_out() { Is_Out = true; }

		private:
			string ISBN;
			string Title;
			string Author;
			Chrono::Date Copyright;
			bool Is_Out;
		};


	}
}
