// Name: Andrew Martin
// Seneca Student ID: 124904178
// Seneca email: amartin35@myseneca.ca
// Date of completion: 2020-01-17
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "event.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace sdds {
	// constructor to set values 
	Event::Event() {
		this->time = 0;
		this->event[0] = '\0';
		g_sysClock = 0;
	}

	void Event::display() {
		//local to function variable
		static int counter;
		counter++;
		cout << setw(3) << setfill (' ') << counter << ". ";
		if (this->event[0] != '\0') {
			//forumla for the times
			cout << setw(2) << setfill('0') << this->time / 60 / 60 <<":" << setw(2) << setfill('0') << (this->time /60) % 60 << ":" << setw(2) << setfill('0') << time % 60 << " -> " << this->event << endl;
			
		}
		else {
			cout << setw(2) << "[ No Event]" << endl;
		}
	}
	//checks if the event has a value or not
	void Event::setDescription(const char* event) {
		if (event != 0 ) {
			//copy the text from source to destiantion
			strcpy(this->event, event);
			this->time = g_sysClock;

		}
		else {
			//function call to safe empty safe
			this->setEmpty();
		}
	}
	//function to set the values to a safe empty sate
	void Event::setEmpty() {
		this->time = 0;
		this->event[0] = '\0';
	}
}