// Stack implementation with vector
#ifndef __STACK_H
#define __STACK_H
#define STARTING_ELEMENTS 10
#define EMPTY -1
#include <iostream>
#include <stack>

namespace std_X
{
	template <typename dataType>
	class stack
	{
	private:
		dataType* stackArray;
		int topLevel;
		int capacity;
	public:

		stack() { stackArray = init_Stack(); } // Constructor
		~stack() { delete[] stackArray; };     // Destructor

		// Methods
		dataType* init_Stack()
		{
			// Create capacity and allocate memory for it
			this->capacity = STARTING_ELEMENTS;
			this->topLevel = EMPTY;
			dataType* emptyArray = new dataType[STARTING_ELEMENTS];
			return emptyArray;
		}

		// Double stack's size
		void expand_stack()
		{
			this->capacity <<= 2;
			this->stackArray = (dataType*) realloc(this->stackArray, sizeof(dataType) * capacity);
		}

		// Halve the stack's size
		void shrink_stack()
		{

			this->capacity >>= 2;
			this->stackArray = (dataType*) realloc(this->stackArray, sizeof(dataType) * capacity);
		}

		// Add an element to the top
		void push(const dataType& element)
		{
			// Check if the stack exists
			if (!stackArray)
				this->stackArray = init_Stack();

			// Check if we have enough space or resize
			if (capacity == topLevel) {
				expand_stack();
			}

			// Add the item to the stack
			this->stackArray[++topLevel] = element;
		}

		// Delete the element on the top
		void pop()
		{
			// Check if the stack exists
			if (!stackArray)
				return;

			// Release the element
			--topLevel;

			// Check if we need to shrink the stack
			if (this->capacity > 2 * this->topLevel)
				shrink_stack();
		}

		// Return the top element
		dataType peek()
		{
			return stackArray[topLevel];
		}

		// Check if the stack is empty
		bool isEmpty()
		{
			if (topLevel == -1)
				return true;
			else
				return false;
		}

		// Return the number of elements in the size
		int size()
		{
			return topLevel + 1;
		}
	};
}

// Check if a sentence is correct
bool isValidSentence(std::string s)
{
    std::stack<char> mystack;

    // Add left parentheses
    // If we find a right parenthesis, the left one must match it
    // Otherwise return false
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '[' || s[i] == '{' || s[i] == '(') {
            mystack.push(s[i]);
        }

        if(s[i] == ')') {
            if(!mystack.empty() && mystack.top() == '(') {
                mystack.pop();
            } else {
                return false;
            }
        }
        if(s[i] == ']') {
            if(!mystack.empty() && mystack.top() == '[') {
                mystack.pop();
            } else {
                return false;
            }
        }

        if(s[i] == '}') {
            if(!mystack.empty() && mystack.top() == '{') {
                mystack.pop();
            } else {
                return false;
            }
        }
    }

    // The stack must be empty meaning all brackets have been removed
    // Otherwise return false
    if(!mystack.empty())
        return false;

    return true;
}

#endif // __STACK_H
