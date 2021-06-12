#include <iostream>
#include <time.h>

#define DIE(assertion, message)			\
if (assertion) { 						\
    std::cout << message << '\n';		\
    exit(EXIT_FAILURE);					\
}

// List node
typedef struct node {
    int data;
    struct node * next;
} node_t;

// List
typedef struct ll {
    node_t * root;
    std::int_fast16_t size;
} ll;

// Create list
struct ll * ll_create() {
    // Create list
    ll * my_list = NULL;
    my_list = (ll * ) malloc(sizeof( * my_list));
    DIE(!my_list, "Couldn't create list!");

    // Initialise root
    my_list -> root = NULL;

    // Return list
    return my_list;
}

// Create and initialise node
struct node * create_node(int data) {
    // Create node
    struct node * my_node = NULL;
    my_node = (struct node * ) malloc(sizeof(struct node));
    DIE(!my_node, "Couldn't create node!");

    // Set values
    my_node -> data = data;
    my_node -> next = NULL;

    // Return node
    return my_node;
}

// Insert elements in the list
void insert_in_list(struct ll ** ll, int data) {
    // If the list doesn't exist, create it
    if (! * ll) {
        * ll = ll_create();
    }

    // If the root doesn't exist, create it
    if (!( * ll) -> root) {
        ( * ll) -> root = create_node(data);
    } else {
		// Append to the end of the list
        struct node * start = ( * ll) -> root;

        // Find end
        while (start -> next)
            start = start -> next;

        // Save node
        start -> next = create_node(data);
    }

    ( * ll) -> size++;
}

// Print the whole list
void print_list(struct ll * my_list) {
    // Get a pointer to the start of the list
    struct node * start = my_list -> root;
    while (start) {

        // Traverse nodes
        if (start -> next) {
            std::cout << start -> data << "--> ";
        } else {
            std::cout << start -> data;
        }

        // Move pointer
        start = start -> next;
    }

    std::cout << "\n\n";
}

// Return the middle element from a linked list
struct node * return_middle(struct node * root) {
    // Get a pointer to the root
    struct node * tortoise = root, * hare = root;

    // Traverse the root until the hare becomes NULL
    while (tortoise && hare && hare -> next) {
        tortoise = tortoise -> next;
        hare = hare -> next -> next;
    }

    // Return the tortoise (the pointer that moves slower)
    return tortoise;
}

// Check if we have a loop in a linked list
bool has_loop(struct node * root) {
    // Get a pointer to the root
    struct node * tortoise = root, * hare = root;

    // Traverse the list with two pointers at different speeds
    // and check if they meet
    while (tortoise && hare && hare -> next) {

        // If they meet, return true
        if (tortoise->next == hare->next->next) {
            return true;
        }

        tortoise = tortoise -> next;
        hare = hare -> next -> next;
    }

    // If they don`t meet, return false
    return false;
}

// Break singly linked list loop with tortoise & hard algorithm
void break_loop(struct node * root) {
    // Check if we have a loop
    if (!has_loop(root))
        return;

    // Second loop variable holds is set true when we traverse
    // the loop a second time
    bool second_loop = false;
    struct node * tortoise = root, * hare = root;

    // Traverse the list
    // On the first meet of the pointers, keep that as a starting position
    // and set second_loop variable to true
    // Now, if we meet again AND the second_loop variable is true, we can
    // break out of the loop
    while (tortoise && hare && hare -> next) {

        // Check if we meet a second time and break the loop
        if (tortoise -> next == hare -> next -> next && second_loop == true) {
            tortoise -> next = NULL;
            return;
        }

        // Check if we meet the first time
        if (tortoise == hare) {
            second_loop = true;
        }

        // Move pointers
        tortoise = tortoise -> next;
        hare = hare -> next -> next;
    }
}

// Removes nodes from the list
void remove_nodes(struct ll ** list, int index) {
    // Check if the list exists
    if (! * list) {
        return;
    }

    // Check if the index exists
    if (index >= (( * list) -> size) || index < 0) {
        return;
    }

    // Delete node
    if (index == 0) {
        ( * list) -> root = ( * list) -> root -> next;
    } else {
		 // Get the node before the index
		struct node * start = ( * list) -> root;
		for (int i = 0; i < index - 1; i++) {
        	start = start -> next;
    	}

		// Move pointer
        start -> next = start -> next -> next;
    }

    // Recalculate size
    ( * list) -> size--;
}
// 0 1 2 3 4 5 6 7 8 9
int main(void) {
    // Create list and insert nodes
    srand(time(0));
    struct ll * my_list = NULL; // rand() % 100
    for (int i = 0; i < 10; i++)
        insert_in_list( & my_list, i);

    // Display list
    std::cout << "Created list is: \n";
    print_list(my_list);

    // Remove random nodes
    int random_position_1 = rand() % 10;
    int random_position_2 = rand() % 10;
    int random_position_3 = rand() % 10;
    std::cout << "Remove nodes at these random generated indexes: " << random_position_1 << " " <<
        random_position_2 << " " <<
        random_position_3 << ".\n";
    remove_nodes( & my_list, random_position_1);
    remove_nodes( & my_list, random_position_2);
    remove_nodes( & my_list, random_position_3);
    std::cout << "New list is: \n";
    print_list(my_list);

    // Get middle element
    struct node * middle = return_middle(my_list -> root);
    std::cout << "Middle element is: " << middle -> data << "!\n";

    // Check if we have loop
    std::cout << "\nCheck if we have loop: ";
    has_loop(my_list -> root) == true ? std::cout << "We have loop!\n" : std::cout << "We don`t have loop!\n";

    // Add loop and break it
    std::cout << "\nAdding loop from the middle element to the beginning of the list!\n";
    middle -> next = my_list -> root;

	// Check again
	std::cout <<"\nChecking again: ";
	has_loop(my_list -> root) == true ? std::cout << "We have loop!\n" : std::cout << "We don`t have loop!\n";

    // Break the loop
    std::cout << "Breaking the loop...\n";
    break_loop(my_list -> root);

	// Check again
	std::cout <<"\nChecking again: ";
	has_loop(my_list -> root) == true ? std::cout << "We have loop!\n" : std::cout << "We don`t have loop!\n";

    // Display remaining list
    std::cout << "\nRemaining list after breaking the loop:\n";
    print_list(my_list);

    return 0;
}