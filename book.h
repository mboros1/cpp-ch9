#include <vector>
#include <string>
#include <iostream>
#include "date.h"

namespace std {
	namespace Book {
		class Book {
		public:
		  class Invalid{};
			std::string isbn() { return ISBN; }
			std::string title() { return Title; }
			std::string author() { return Author; }
			Chrono::Date copyright() { return Copyright; }
			bool is_out() { return Is_Out; }
			void check_in() { Is_Out = false; }
			void check_out() { Is_Out = true; }
			Book();
			Book(std::string isbn, std::string title, std::string author, Chrono::Date copyright);

		private:
			std::string ISBN;
			std::string Title;
			std::string Author;
			Chrono::Date Copyright;
			bool Is_Out;
		};

		Book::Book(std::string isbn, std::string title, std::string author, Chrono::Date copyright)
			:ISBN(isbn), Title(title), Author(author), Copyright(copyright), Is_Out(false)
		{
		  int dash_count = 0;
		  for(char &c : isbn) {
		    switch(dash_count) {
		    case 0:
		    case 1:
		    case 2:
		      if (c == '-') dash_count++;
		      else if (!isdigit(c)) throw Invalid();
		      break;
		    case 3:
		      if (!isalpha(c)) throw Invalid();
		      break;
		    default:
		      throw Invalid();
		    }
		  }
		}
	}
}
