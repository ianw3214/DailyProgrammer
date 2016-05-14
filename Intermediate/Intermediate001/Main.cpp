/*	Event Organizaton Program
*/

#define line std::cout << std::endl

#include <iostream>
#include <string>
#include <vector>

// function declarations
void addEvent();
void editEvent();
void deleteEvent();
void showEvents();
void sort();

// structure for the event element
struct sEvent {
	int time;
	std::string description;
};

// global variable to store the events
std::vector<sEvent> eventList;

int main(int argc, const char* argv[]) {

	int userInput;

	do {
		line;
		std::cout << "+-------------------------+" << std::endl;
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "[0]Add an event" << std::endl;
		std::cout << "[1]Edit an event" << std::endl;
		std::cout << "[2]Delete an event" << std::endl;
		std::cout << "[3]Show the events" << std::endl;
		std::cout << "[4]Quit" << std::endl;
		std::cin >> userInput;
		line;

		// run different commands depending on the user input
		if (userInput == 0) {
			addEvent();
		}
		else if (userInput == 1) {
			editEvent();
		}
		else if (userInput == 2) {
			deleteEvent();
		}
		else if (userInput == 3) {
			showEvents();
		}
		else if (userInput == 4) {
			std::cout << "Quitting the application...";
			line;
		}
		else {
			std::cout << "Sorry that was not a valid command...";
			line;
		}
		line;
	} while (userInput != 4);

	system("PAUSE");
	return 0;

}

// function to add an event to the event vector
void addEvent() {

	std::cout << " - ADD AN EVENT - ";
	line;

	// the variables to store the user input
	int iTime;
	std::string iDescription;

	// prompt the user to input the information
	std::cout << "What time is the event?";
	line;
	std::cin >> iTime;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		// ignore the empty line so it doesn't mess up getline
	std::cout << "Please give a brief description of the event.";
	line;
	std::getline(std::cin, iDescription);

	// assign the data to a temporary event
	sEvent myEvent;
	myEvent.time = iTime;
	myEvent.description = iDescription;

	// push the event structure into the vector
	eventList.push_back(myEvent);

	line;
	return;
}

// function to edit events in the event vector
void editEvent() {

	int key;	// the number key that the user will input into to decide which event to delete
	int iTime;					// the variables to store the users inputs
	std::string  iDescription;

	// ask the user for the number key of the event to delete
	std::cout << "Which event would you like to edit?";
	line;
	std::cout << "use the number key in the []";
	line;

	showEvents();	// give the user a reference to work off of
	std::cin >> key;	// the user inputs the number key
	line;

	// ask the user for the new information
	std::cout << "What would you like to change the time into?";
	line;
	std::cin >> iTime;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		// ignore the empty line so it doesn't mess up getline
	std::cout << "What would you like to change the description into?";
	line;
	std::getline(std::cin, iDescription);

	// replace the current data with the new inputs
	eventList[key - 1].time = iTime;
	eventList[key - 1].description = iDescription;

	line;
	return;
}

// function to delete events from the event vector
void deleteEvent() {

	int key;	// the number key that the user will input into to decide which event to delete

	// ask the user for the number key of the event to delete
	std::cout << "Which event would you like to delete?";
	line;
	std::cout << "use the number key in the []";
	line;

	showEvents();	// give the user a reference to work off of
	std::cin >> key;	// the user inputs the number key
	line;

	eventList.erase(eventList.begin()+key-1);

	line;
	return;
}

// function to show the data of the vector to the user
void showEvents() {

	// sort the event list before showing it to the user
	sort();

	// loop through the events vector
	for (int i = 0; i < eventList.size(); i++) {
		std::cout << "[" << i + 1 << "]  ";
		std::cout << eventList[i].time << ": ";
		std::cout << eventList[i].description << std::endl;
	}

	line;

	return;
}

// function to sort the order of the events in the event list
void sort() {

	for (int j = 0; j < eventList.size(); j++){
		for (int i = 0; i < eventList.size()-1; i++) {
			int a, b;
			a = eventList[i].time;
			b = eventList[i + 1].time;
			if (a > b) {
				sEvent temp = eventList[i + 1];
				eventList[i+1] = eventList[i];
				eventList[i] = temp;
			}
		}
	}

	return;
}