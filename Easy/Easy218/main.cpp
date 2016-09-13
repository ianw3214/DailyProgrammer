#include <vector>
#include <string>
#include <iostream>


class toDoList {
public:
	// constructor for the TODO list
	toDoList() {
		// initialize variables
		listItems = {};
	}
	// function that adds an item to the TODO list
	void addItem(std::string item) {
		listItems.push_back(item);
	}
	// function that deletes an item from the TODO list
	bool removeItem(std::string item) {	// returns a success flag, TRUE -> success, FALSE -> error
		bool itemFound = false;					// boolean that keeps track of whether the specified item was found or not
										// loop through the list to find the specified item
		for (unsigned int counter = 0; counter < listItems.size(); counter++) {
			// remove the item if it is the same as the input
			if (listItems[counter] == item) {
				itemFound = true;
				listItems.erase(listItems.begin()+counter);
				// don't quit the loop because all the same items want to be deleted
			}
		}
		return itemFound;
	}
	// function that prints out the list
	void printList() {
		// loop through the items list
		for (unsigned int counter = 0; counter < listItems.size(); counter++) {
			// print out each item
			std::cout << listItems[counter] << std::endl;
		}
	}
private:
	std::vector<std::string> listItems;		// the vector that holds the items in the TODO list
};

// program entry point
int main(int argc, const char* argv[]) {

	toDoList Monday;
	Monday.addItem("Meet Dave");
	Monday.addItem("Buy eggs");
	Monday.printList();
	Monday.removeItem("Buy eggs");
	Monday.printList();
	if (Monday.removeItem("Eat cheese")) {
		std::cout << "that wasn't supposed to happen..." << std::endl;
	}
	else {
		std::cout << "'Eat cheese' was not found in the list..." << std::endl;
	}

	system("pause");
	return 0;

}