#ifndef __HASHTABLE__H
#define __HASHTABLE__H
#include <algorithm>
#include <iterator>
#include <list>
#include <queue>

#define TRESHOLD 0.75

template <typename Tkey, typename Tvalue>
struct elem_info {
	Tkey key;
	Tvalue value;
};

template <typename Tkey, typename Tvalue>
class Hashtable {
	private:
		std::list<struct elem_info<Tkey, Tvalue>>* H; // pointer to buckets
		int HMAX; // number of buckets
		unsigned int (*hash)(Tkey); // pointer to hash function
		unsigned int size; // number of elements in hashtable

	public:
		// Constructor
		Hashtable(int hmax, unsigned int (*h)(Tkey))
		{
			this->HMAX = hmax;
			this->hash = h;
			this->size = 0;
			this->H = new std::list<struct elem_info<Tkey, Tvalue>>[this->HMAX];
		}

		// Destructor
		~Hashtable()
		{
			delete[] this->H;
		}

		// Check if item is in list
		bool in_list(std::list<struct elem_info<Tkey, Tvalue>> list, Tkey key)
		{
			// Check if we find the key
			for(auto& element : list) {
				if(element.key == key)
					return true;
			}
			
			return false;
		}

		// Return element if is in list
		Tvalue Tvalue_of_key(std::list<struct elem_info<Tkey, Tvalue>> list, Tkey key)
		{
			// Check if we find the key
			for(auto& element : list) {
				if(element.key == key)
					return element.value;
			}

			return (Tvalue) -1;
		}

		// Put element in the hashtable
		void put(Tkey key, Tvalue value)
		{
			// Get the key's index
			std::int_fast16_t index = this->hash(key) % HMAX;

			// Create element to be inserted
			struct elem_info<Tkey, Tvalue> my_element = {key, value};

			// Append it to the bucket (but don't allow duplicates)
			if(!in_list(this->H[index], key))
				this->H[index].push_back(my_element);
			
			// Increase size
			this->size++;
		}
		
		// Remove element from the hashtable
		void remove(Tkey key)
		{
			// Get the key's index
			std::int_fast16_t index = this->hash(key) % HMAX;

			// If is in the list, remove it
			this->H[index].remove_if([key](struct elem_info<Tkey, Tvalue>& element)
			{
				if(key == element.key) 
					return true;
				else
					return false;
			});

			// Decrease size
			this->size--;
		}

		// Retrieve a value by key
		Tvalue get(Tkey key)
		{
			// Get the key's index
			std::int_fast16_t index = this->hash(key) % HMAX;

			// Search for it and return in
			if(in_list(this->H[index], key)) {
				return Tvalue_of_key(this->H[index], key);
			}
			
			// We we didn't find the element
			return (Tvalue) -1;
		}

		// Check if the specified item is in the hashtable
		bool has_key(Tkey key)
		{
			// Get the key's index
			std::int_fast16_t index = this->hash(key) % HMAX;

			// Return output
			return in_list(this->H[index], key);
		}


		// Resize the hashtable
		void resize()
		{
			// Create a qeuue which will hold the elements of the hashtable
			std::queue<struct elem_info<Tkey, Tvalue>> my_queue;
			for(int i = 0; i < HMAX; ++i) {

				// Get all the elements on each row into the queue
				for(typename std::list<struct elem_info<Tkey, Tvalue>>::iterator it = this->H[i].begin(); it != this->H[i].end(); ++it) {
					struct elem_info<Tkey, Tvalue> my_element = {it->key, it->value};
					my_queue.push(my_element);
				}

				// After getting the elements from the 'i' row, clear it
				if(!this->H[i].empty())
					this->H[i].clear();
			}

			// Double the size of the hashtable
			delete[] H;
			H = new std::list<struct elem_info<Tkey, Tvalue>>[this->HMAX * 2];
			this->HMAX = this->HMAX * 2;

			// Rehash the elements and put them back
			while(!my_queue.empty()) {
				struct elem_info<Tkey, Tvalue> my_element = my_queue.front();
				my_queue.pop();
				put(my_element.key, my_element.value);
			}
		}

		// Return a whole row from the hashtable
		std::list<struct elem_info<Tkey, Tvalue>> get_row(int index) {
			return this->H[index];
		}

		int get_size() {
			return size;
		}

		int get_capacity() {
			return HMAX;
		}

		float current_factor(){
			return (float)(size) / (float)(HMAX);
		}
};

#endif //__HASHTABLE__
