// Name: Andrew Martin
// Seneca Student ID: 124904178
// Seneca email: amartin35@myseneca.ca
// Date of completion: 2020-01-17
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#include <iostream>
#include <ctime>

using namespace std;

//time_t today = time(NULL);
//tm* time_obj = localtime(&today);
inline unsigned long int g_sysClock;

namespace sdds {

	class Event {
	
	private:
		 char event [128];
		 unsigned int time;
	public:
		Event();
		void display();
		void setDescription(const char* event);
		void setEmpty();
	};
} 

