#include <iostream>
#include <time.h>

#define START 0
#define BIG_NUMBER 99999

// ArrayList
template <typename dataType>
struct ArrayList
{
	private:
		std::int_fast32_t length;
		std::int_fast32_t capacity;
		std::int_least32_t position;
	public:
		// Content
		dataType* content;

		// Constructors
		ArrayList() : length(0), capacity(1), position(-1), content(NULL) {}

		// Destructor
		~ArrayList() { delete[] content; }
		
		// Methods
		// Allocate initial content
		dataType* allocate_content()
		{
			dataType* new_content = new dataType[this->capacity];
			return new_content;
		}
		
		// Grow size
		void Grow_Content_Size()
		{
			this->capacity <<= 1;
			this->content = (dataType*) realloc(this->content, this->capacity * sizeof(dataType));
		}

		// Shrink size
		void Shrink_Content_Size()
		{
			this->capacity >>= 1;
			this->content = (dataType*) realloc(this->content, this->capacity * sizeof(dataType));
		}

		void Add_First(dataType new_element)
		{
			// Check if the content exists
			if(!content)
				content = allocate_content();
			
			// Check if we can execute this operation, and else resize
			if(this->length >= this->capacity) 
				Grow_Content_Size();

			// Move elements
			for(int i = length; i > 0; i--) {
				content[i] = content[i-1];
			}

			// Add new element
			content[0] = new_element;
			++length;
			++position;

		}

		void Add_Last(dataType new_element)
		{
			// Check if the content exists
			if(!content)
				content = allocate_content();
			
			// Check if we can execute this operation, and else resize
			if(this->length >= this->capacity) 
				Grow_Content_Size();

			this->content[length] = new_element;
			++length;
			++position;
		}

		void Remove_First()
		{
			--length;
			--position;
			// Check if we can execute this operation, and else resize
			if(this->length >= this->capacity) 
				Grow_Content_Size();

			// Move elements
			for(int i = 0; i < length; i++) {
				content[i] = content[i+1];
			}

			// Check if we need to shink
			if(this->capacity > 2 * this->length) {
				Shrink_Content_Size();
			}
		}

		void Remove_Last()
		{
			--position;
			--length;

			// Check if we need to shink
			if(this->capacity > 2 * this->length) {
				Shrink_Content_Size();
			}
		}

		// Get element at 'posx' position
		dataType Get(int posx)
		{
			// Get position
			if(posx < 0)
				posx = 0;

			if(posx >= length)
				posx = length - 1;

			return this->content[posx];
		}

		// Modify a element's value at 'posx' position
		void Update(dataType element, int posx)
		{
			// Get position
			if(posx < 0)
				posx = 0;

			if(posx >= length)
				posx = length - 1;

			if(posx >= 0 && posx < length)
				this->content[posx] = element;
		}

		// Print the whole array
		void Print_Contents()
		{
			std::cout << "\n";
			for(int i = 0; i < this->length; ++i) {
				std::cout << "Element: " << this->content[i] << "\n";
			}
		}
		
};

int main(void)
{
	// Create int array
	srand(time(0));
	ArrayList<int> my_ArrayList;
	for(int i = 0; i < 5; i++) {
		my_ArrayList.Add_Last(rand()%100);
	}

	// Add first and last elements
	my_ArrayList.Add_First(1000);
	my_ArrayList.Add_Last(1000);

	// Remove some elements from the beginning and add one more
	my_ArrayList.Remove_First();
	my_ArrayList.Remove_First();
	my_ArrayList.Add_First(1000);

	// Remove some elements from the end and add one more
	my_ArrayList.Remove_Last();
	my_ArrayList.Remove_Last();
	my_ArrayList.Add_Last(1000);

	// Update first element
	my_ArrayList.Update(9999, START);
	my_ArrayList.Update(9999, BIG_NUMBER);

	// Remove more
	my_ArrayList.Remove_Last();
	my_ArrayList.Remove_First();

	// Get last element
	std::cout << "Last element: " << my_ArrayList.Get(BIG_NUMBER) << std::endl;

	// Print elements
	my_ArrayList.Print_Contents();
}