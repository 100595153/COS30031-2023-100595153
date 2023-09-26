#include <iostream>
#include "Inventory.h"
#include "Item.h"

int main()
{
	Inventory* inv = new Inventory();

	inv->add(new Item("fork"));
	inv->add(new Item("knife"));
	inv->add(new Item("plate"));
	inv->add(new Item("smaller plate"));

	cout << "Testing Adding" << endl;
	cout << inv->add(new Item("gun")) << endl;
	cout << inv->add(new Item("gun")) << endl;

	cout << "Testing Removing" << endl;
	cout << inv->remove("gun") << endl;
	cout << inv->remove("gun") << endl;
	

	cout << "Testing Finding" << endl;
	cout << inv->find("plate") << endl;
	cout << inv->find("gun") << endl;

	cout << "Testing Getting" << endl;
	cout << inv->get("plate")->getName() << endl;
	cout << inv->get("gun")->getName() << endl;

	cout << "Testing Viewing" << endl;
	inv->view();

	cout << "Testing Edge Cases" << endl;
	cout << inv->add(nullptr) << endl;
}