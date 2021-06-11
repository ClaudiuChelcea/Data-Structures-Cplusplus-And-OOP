#include <iostream>
#include "stack.h"
#include "queue.h"
#include <string.h>

int main(void)
{
	// Test stack
	std_X::stack<int> my_stack;

    // Add elements
    std::cout << "===========STACK==============\n";
    for (int i = 0; i < 5; ++i) {
        my_stack.push(i);
        std::cout << "Added on top of stack: " << my_stack.peek() << '\n';
    }

    // Remove two elements, add one element, check if the stack is empty
    std::cout << "\nRemove two elements, add '100' element and check if it is empty!\n";
    my_stack.pop();
    my_stack.pop();
    my_stack.push(100);

    if(my_stack.isEmpty()) {
        std::cout << "The stack is empty!" << '\n';
    } else {
        std::cout << "My stack is not empty! It`s size is: " << my_stack.size() <<  " and the top element is " << my_stack.peek();
    }

    // Check sentences using stack
    std::cout << "\n\nChecking sentence parentheses using stack!\n";

    // Prepare sentences
    std::string sentence_1 = "a + b * ( c + ( d * e )" ; // not valid
    std::string sentence_2 = " } 2 + 3 + ( 4 + 5 )" ; // not valid
    std::string sentence_3 = "(a + b * ( c + ( d * e )))" ; // valid
    std::string sentence_4 = "a + b[3] + { * ( c + ( d * e ) ) }" ; // valid

    std::cout <<  sentence_1 << ": " << std::boolalpha << isValidSentence(sentence_1)  << "\n";
    std::cout <<  sentence_2 << ": " << std::boolalpha << isValidSentence(sentence_2)  << "\n";
    std::cout <<  sentence_3 << ": " << std::boolalpha << isValidSentence(sentence_3)  << "\n";
    std::cout <<  sentence_4 << ": " << std::boolalpha << isValidSentence(sentence_4)  << "\n";

	// Test queue
	std_X::queue<std::string> my_queue;

	// Add elements
	std::cout << "\n\n===========QUEUE==============\n";
	std::string names[5] = {"Claudiu", "Alex", "Maria", "Andreea", "George"};
	for (int i = 0; i < 5; ++i) {
        my_queue.enqueue(names[i]);
        std::cout << "Queue's last element is: " << my_queue.back() <<  ".\n";
	}
	std::cout << "\nQueue's first element is: " << my_queue.peek() <<  ".\n";

	// Remove two elements
	std::cout << "\nRemove two elements and show first element:";
	my_queue.dequeue();
	my_queue.dequeue();
	std::cout << "\nQueue's NEW first element is: " << my_queue.peek() <<  ".\n";

	// Release queue
	std::cout << "\nReleasing queue...\n";
	while(!my_queue.isEmpty()) {
        my_queue.dequeue();
	}

    my_queue.size() == 0 ? std::cout << "My queue is now empty!\n" : std::cout <<  "My queue is not empty!\n";

	return 0;
}
