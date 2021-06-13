#include <iostream>
#include "hash_functions.h"
#include "hashtable.h"

int main(void)
{
	// Create hashtable
	Hashtable<int, int> my_table(10, &hashingFunction);

	// Put elements
	std::cout << "Inserting elements 1 2 3 4 at random positions (that will be hashed)...\n";
	my_table.put(34588, 1);
	my_table.put(3458, 2);
    my_table.put(8345, 3);
    my_table.put(13459, 4);

	// Get elements
	std::cout << "Retrieving elements by key...\n";
	int a {0}, b {0}, c {0}, d {0};
    a = my_table.get(34588);  // 1
    b = my_table.get(3458);  // 2
    c = my_table.get(8345);  // 3
    d = my_table.get(13459);  // 4

	// Display values
	std::cout << "Retrieved elements: ";
	std::cout << a << " " << b << " " << c << " " << d << "\n\n";

	// Check if elements exists
	std::cout << "Checking if some elements exist:\n";
	bool check1 = my_table.has_key(3458); //exista
    bool check2 = my_table.has_key(1001); //nu exista
    std::cout << std::boolalpha <<  "Key 3458 - true: " << check1 << "\nKey 1001 - false: " << check2 << std::endl;

	// Remove elements
	std::cout << "\nRemoving some elements by key...\n";
	my_table.remove(8345);  // remove 3
    my_table.remove(1111);  // nothing to remove
    my_table.remove(13459);  // remove 4

	// Check again
	check1 = my_table.has_key(34588);  // true
    check2 = my_table.has_key(8345);  // false
	std::cout << std::boolalpha << "This should be true: "<< check1 << " " << "\nThis should be false: " << check2 << "\n";

	// Resize hashtable
	std::cout << "\nCurrent fill factor: " << my_table.current_factor() <<"\nResizing hashtable and rehashing elements...\n"; 
	my_table.resize();
	std::cout << "Done! New fill factor: "<< my_table.current_factor() << "\n\n";

	// Check if the resize has worked correctly
	std::cout << "Check hashtable after resizing:\n";
	check1 = my_table.has_key(34588);  // true
    check2 = my_table.has_key(8345);  // false
	std::cout << std::boolalpha << "This should be true: "<< check1 << " " << "\nThis should be false: " << check2 << "\n";
}
