// Name: Andrew Martin
// Seneca Student ID: 124904178
// Seneca email: amartin35@myseneca.ca
//Lab 1: @home
// Date of completion: 2020-01-20
// I confirm that the content of this file is created by me,
//  with the exception of the parts provided to me by my professor.

#pragma once
#include <iostream>
#include <ctime>

using namespace std;


inline unsigned long int g_sysClock;

namespace sdds {

	class Event {

	private:
		char* event;
		unsigned int time;
	public:
		Event();
		Event(const Event &event);
		Event& operator=(const Event& event);
		~Event();
		void display();
		void setDescription(const char* event);
		void setEmpty();
	};
}


