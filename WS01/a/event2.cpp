// Name: Andrew Martin
// Seneca Student ID: 124904178
// Seneca email: amartin35@myseneca.ca
// Date of completion: 2020-01-20
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace sdds {
	// constructor to set values 
	Event::Event() {
		this->time = 0;
		this->event = nullptr;
	}

	Event::Event(const Event &event) {
		this->setEmpty();
		//checking to see if the event will not be null/ if it is allocate new memory
		if (event.event != nullptr) {
			//setting the size of the current event/setting blocks or memory
			this->event = new char[strlen(event.event) + 1];
			//set the time member var to the incoming objects time
			this->time = event.time;
			//copy the incoming event to the current event member variable
			strcpy(this->event, event.event);
		}
		
	}

	Event& Event::operator=(const Event& event) {
		//check to see if the current is the same as the incoming/prevents self assign
		if (this != &event) {
			//call the seEmpty function/sets to safe empty state
			this->setEmpty();
			//check to see if the current event obj is a null ptr
			if (event.event != nullptr) {
				//setting the size of the current event/setting blocks or memory
				this->event = new char[strlen(event.event) + 1];
				//copy the incoming event to the current event member variable
				strcpy(this->event, event.event);
				this->time = event.time;
			}
		}
			return *this;
	}

	void Event::display() {
		//local to function variable
		static int counter;
		counter++;
		cout << setw(3) << setfill(' ') << counter << ". ";
		if (this->event != nullptr) {
			//forumla for the times
			cout << setw(2) << setfill('0') << this->time / 60 / 60 << ":" << setw(2) << setfill('0') << (this->time / 60) % 60 << ":" << setw(2) << setfill('0') << time % 60 << " -> " << this->event << endl;

		}
		else {
			cout << setw(2) << "[ No Event]" << endl;
		}
	}
	
	void Event::setDescription(const char* event) {
		if (event != nullptr) {
			if (this->event != nullptr) {
				//set to a safe empty state
				this->setEmpty();
			}
			//setting the size of the current event/setting blocks or memory
			this->event = new char[strlen(event) + 1];
			//copy the incoming event to the current event
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
	
		if (this->event != nullptr) {
			delete [] this->event;
			this->event = nullptr;
			}
	}
	//destructor to delete dynamic memeory 
	Event::~Event() {
		if (this->event != nullptr) {
			delete[] this->event;
			this->event = nullptr;
		}
	}
}
