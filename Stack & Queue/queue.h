// Queue implementation with lists
#ifndef __QUEUE_H
#define __QUEUE_H
#include<list>

namespace std_X
{
	template <typename dataType>
	class queue
	{
    private:
        std::list<dataType> queueList;

	public:
	    // Constructor and destructor
		queue() {};
		~queue()
		{
            while(!queueList.empty()) {
                queueList.pop_front();
            }
		}

		// Methods
		// Put an element at the end
		void enqueue(const dataType& my_data)
        {
		    this->queueList.push_back(my_data);
		}

        // Remove the first element
		void dequeue()
		{
            if(this->queueList.size() > 0)
                    this->queueList.remove(this->queueList.front());
		}

		// Display the first element
		dataType peek()
		{
            return this->queueList.front();
		}

		// Display the last element (not included in the queue data structure)
		dataType back()
		{
            return this->queueList.back();
		}

		// Check if the queue is empty
		bool isEmpty()
		{
		    return this->queueList.empty();
		}

		// Returns the size of the queue
		int size()
		{
            return this->queueList.size();
		}
	};
}

#endif // __QUEUE_H
