#include <iostream>
#include <vector>
#include <list>

#define NMAX 100

// Bitmask for efficient memory usage
typedef struct __attribute__((packed))
{
  int x : 5;
  int y : 5;
  int z : 6;
} Coords;

// Display the whole structure with only one 'cout'
std::ostream &operator<<(std::ostream &out, const Coords &my_Coords)
{
  out << "x: " << my_Coords.x << " y: " << my_Coords.y << " z: " << my_Coords.z
      << std::endl;
  return out;
}

// Print the whole vector and delete it
template <typename T> void print_and_clear_Vector(std::vector<T> &my_vector)
{
  std::cout << "\nPrinting and erasing vector!\n";
  int index = 1;

  // Print each element and delete it
  for (auto &element : my_vector) {
    std::cout << "Vector element " << index << ": " << element;
    my_vector.erase(my_vector.begin());
    index++;
  }

  // Check if the vector is cleared
  if (my_vector.size() == 0)
    std::cout << "Cleared vector!\n";
}

// Display the whole list with only one 'cout'
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::list<T> &my_list)
{
  return out;
}

// Print the whole list
template <typename T> 
void print_and_clear_List(std::list<T> &my_list)
{
  std::cout << "\nPrinting and erasing list!\n";
  int index = 1;

  // Print list and release it's elements
  for (auto list_element : my_list) {
    std::cout << "Object type: \"" << list_element.first
              << "\" with coordinates: ";
    for (auto vector_element : list_element.second)
      std::cout << vector_element << " ";
    std::cout << "\n";
  }
}

int main(void)
{
  /*
   *
   * STD::VECTOR
   *
  */

  // Add elements
  std::cout << "Created vector!\n";
  std::vector<Coords> objects_coords;
  objects_coords.push_back({0, 0, 25});
  objects_coords.push_back({5, 5, 20});

  // Display the added elements
  for (auto &object : objects_coords)
    std::cout << object;

  // Clear the elements
  objects_coords.clear();
  if (objects_coords.size() == 0)
    std::cout << "Cleared vector!\n\n";

  // Create new vector with predefined size
  // and print from certain positions
  std::cout << "Created new vector!\n";
  std::vector<Coords> new_objects_coords(0);
  new_objects_coords.push_back({1, 2, 3});
  new_objects_coords.push_back({4, 5, 6});
  new_objects_coords.push_back({7, 8, 9});
  std::cout << "First element\n";
  std::cout << new_objects_coords.front();
  std::cout << "Last element\n";
  std::cout << new_objects_coords.back();
  std::cout << "Element at index 1:\n";
  std::cout << new_objects_coords.at(1);

  // Print the whole vector and then clear it
  print_and_clear_Vector(new_objects_coords);

  /*
   *
   * STD::LIST
   *
  */

  // Create list and insert items
  std::cout << "\nCreating list of objects associated with vectors.\n";
  std::list<std::pair<std::string, std::vector<float>>> my_list;
  my_list.push_back({"Table", {5, 1, 13}});
  my_list.insert(my_list.begin(), {"Chair", {2, 0, 1}});
  my_list.insert(my_list.begin(), {"Chandelier", {0, 100, 0}});

  // Display list
  print_and_clear_List(my_list);

  return 0;
}
