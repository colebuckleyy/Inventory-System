#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

class Item {
private:
	//Aspects of items
	//ID of item
	int id;
	//Name of item
	std::string name;
	//Stock of item
	int stock;
public:
	//Default constructor
	Item() {
		id = -1;
		name = "";
	}

	//1 parameter constructor
	Item(std::string _name) {
		name = _name;
	}

	//Getter and setter functions for item variables
	int getID() {
		return id;
	}

	std::string getName() {
		return name;
	}

	void setID(int val) {
		id = val;
	}

	void setName(std::string _name) {
		name = _name;
	}

	void setStock(int val) {
		stock = val;
	}

	int getStock() {
		return stock;
	}
};

class Inventory {
private:
	//Growable array of items representing inventory
	std::vector<Item> inv;
	//Hash map of categories to filter items
	std::unordered_map<int, std::string> categories;
	//Id of each item represented by an integer, corresponding to index of vector for fast access
	int ids = 0;
public:
	void createItem(std::string name, int stock, std::string category) {
		//Create item object with name
		Item item = Item(name);
		//Set id of item
		item.setID(ids);
		//Set stock of item
		item.setStock(stock);
		//Set items category
		categories[ids] = category;
		//Add item to inventory
		inv.push_back(item);
		ids++;
	}

	void editItem(int id, std::string newName, int stock, std::string category) {
		//Check if id is greater than size of inventory or less than 0
		if (id > inv.size() || id < 0) {
			std::cout << "ERROR: Invalid ID";
			return;
		}
		//Edit item by setting new name
		if (newName != "")
			inv[id].setName(newName);
		//Edit category name
		if (category != "") {
			categories[id] = category;
		}
		//Edit item by setting stock
		if (stock > -1)
			inv[id].setStock(stock);
	}

	void deleteItem(int id) {
		//Erase item from inventory array
		inv.erase(inv.begin() + id);
		//Decrement ids of items following item deleted
		for (int i = id; i < inv.size(); i++) {
			inv[i].setID(inv[i].getID() - 1);
		}
		//Decrement total ids value
		ids--;
	}

	void viewInventory() {
		//Loop through inventory array and print item attributes
		for (int i = 0; i < inv.size(); i++) {
			std::cout << "Item ID: " << inv[i].getID() << " | Item name: " << inv[i].getName() << " | Item category: " << categories[i] << std::endl;
		}
	}

	void viewItem(int id) {
		//If ID is valid display item at ID
		if (id >= 0) {
			std::cout << "Item ID: " << inv[id].getID() << " | Item name: " << inv[id].getName() << " | Item category: " << categories[id] << std::endl;
		}
		//Else error and return
		else {
			std::cout << "ERROR: Invalid ID" << std::endl;
			return;
		}
	}

	   void viewCategory(int id) {
		//If ID is valid display category
		if (id >= 0) {
			std::cout << "Item category: " << categories[id] << std::endl;
		}
		//Else error and return 
		else {
			std::cout << "ERROR: Invalid ID" << std::endl;
			return;
		}
	}
};


int main()
{
	Inventory inventory;
	//Flag for exiting loop when user wants
	bool flag = true;
	//Input to choose task
	int input;
	while (flag) {
		//List tasks
		std::cout << "\nEnter number based on what you would like to do: \n";
		std::cout << "\n1: Create item\n";
		std::cout << "\n2: Edit item\n";
		std::cout << "\n3: Delete item\n";
		std::cout << "\n4: View full inventory\n";
		std::cout << "\n5: View item\n";
		std::cout << "\n6: View item category\n";
		std::cout << "\n7: Stop\n";
		std::cout << std::endl;

		//Input task
		std::cin >> input;

		//Declare variables
		std::string name, category;
		int stock, idCheck;


		//Switch case loop of inputs
		switch (input) {
			//Creating item
		case 1:
			//Enter aspects of item
			std::cout << "Enter item name: ";
			std::cin >> name;
			std::cout << std::endl;
			std::cout << "Enter item stock: ";
			std::cin >> stock;
			std::cout << std::endl;
			std::cout << "Enter item category: ";
			std::cin >> category;
			std::cout << std::endl;
			//Create item
			inventory.createItem(name, stock, category);
			break;
			//Edit item
		case 2:
			//Input item id
			std::cout << "Enter item ID: ";
			std::cin >> idCheck;
			std::cout << std::endl;
			//Enter new values
			std::cout << "Enter new item name: ";
			std::cin >> name;
			std::cout << std::endl;
			std::cout << "Enter new item stock: ";
			std::cin >> stock;
			std::cout << std::endl;
			std::cout << "Enter new item category: ";
			std::cin >> category;
			std::cout << std::endl;
			inventory.editItem(idCheck, name, stock, category);
			break;
			//Deleting item
		case 3:
			//Enter id of item to be deleted
			std::cout << "Enter ID of item to be deleted: ";
			std::cin >> idCheck;
			std::cout << std::endl;
			//Delete item
			inventory.deleteItem(idCheck);
			break;
			//Viewing inventory
		case 4:
			std::cout << "Inventory list: " << std::endl;
			inventory.viewInventory();
			break;
			//Viewing singular item based on id
		case 5:
			//Input id
			std::cout << "Enter item ID: ";
			std::cin >> idCheck;
			std::cout << std::endl;
			//View item
			inventory.viewItem(idCheck);
			break;
			//Viewing category
		case 6:
			//Input id
			std::cout << "Enter item ID: ";
			std::cin >> idCheck;
			std::cout << std::endl;
			//View category
			inventory.viewCategory(idCheck);
			break;
			//Exiting inventory system
		case 7:
			//Exit
			std::cout << "Exiting..." << std::endl;
			flag = false;
			break;
		}
	}
	std::cout << "Thank you! Goodbye";
}
