#include <iostream>
#include <memory>
#include <string.h>

namespace std_X
{
	// Create own implementation for shared_ptr
	template <typename pointerType>
	class shared_ptr
	{
		public:
			// Value
			pointerType* data;

			shared_ptr() : data(NULL) {} 					    // NULL Constructor
			shared_ptr(pointerType* element) : data(element) {} // Constructor
			~shared_ptr() {} 								    // Destructor

			// Create unique 
			shared_ptr make_unique(pointerType* data)
			{
				shared_ptr<pointerType> my_unique;
				my_unique->data = data;
				return my_unique;
			}

			// Return data
			pointerType getData()
			{
				return (*data);
			}

			// Operators overloaded
			void operator=(pointerType* element)
			{
				data = element;
			}

			// Return data
			pointerType operator*()
			{
				return (*data);
			}

			void operator=(const shared_ptr& second_unique)
			{
				std::move(this->data, second_unique->data);
			}
	};
}

class Student
{
	private:
		char* name;
		std::int_fast32_t age;
		float grade_average;
	public:
		// Constructors
		// Default constructor
		Student()
		{
			// Set default values
			this->age = 0;
			this->grade_average = 0;
			this->name = NULL;
		}

		// Constructor
		Student(const char* name, std::int_fast32_t age, float grade_average)
		{
			// Set values
			this->age = age;
			this->grade_average = grade_average;

			this->name = new char[strlen(name) + 1];
			memmove(this->name, name, strlen(name));
		}

		// Destructors
		~Student()
		{
			delete name;
		}

		// Getters
		char* getName() const { return name; }
		std::int_fast32_t getAge() { return age; }
		float getGradeAverage() { return grade_average; }

		// Setters
		void setName(char* new_text) { this->name = new_text; }
		void setAge(std::int_fast32_t new_Age) { this->age = new_Age; }
		void setGradeAverage(float new_grade) { this->grade_average = new_grade; }

		// Copy constructor
		Student(Student& second_student) {
			this->grade_average = second_student.grade_average;
			this->age = second_student.age;
			this->name = std::move(second_student.name);

			free(second_student.name);
			second_student.setName(NULL);
		}

		// Assignment operator
		void operator=(Student& second_student) {
			this->grade_average = second_student.grade_average;
			this->age = second_student.age;
			this->name = std::move(second_student.name);
			
			free(second_student.name);
			second_student.setName(NULL);
		}

		// Print student
		friend std::ostream& operator<<(std::ostream& out, const Student& my_student);
};

std::ostream& operator<<(std::ostream& out, const Student& my_student)
{
	out<<"Student name: "<<my_student.name<<"\n";
	out<<"Student age: "<<my_student.age<<"\n";
	out<<"Student grade average: "<<my_student.grade_average<<"\n";
	return out;
}

int main(void)
{
	// Create student
	std::cout << "Created student:\n";
	Student* my_student = new Student("Alex", 18,  10);
	std::cout << *my_student;

	// Create pointer to the student
	std::cout << "\nCopy student unique pointer:\n";
	std_X::shared_ptr<Student> my_shared_ptr = my_student;
	std::cout << *my_shared_ptr.data;

	// Create new student
	std::cout << "\nCreated new student:\n";
	Student* my_student_2 = new Student("Maria", 13, 9);
	std::cout << *my_student_2;

	// Move pointer
	std::cout << "\nMove unique pointer:\n";
	my_shared_ptr = my_student_2;
	std::cout<<*my_shared_ptr.data;

	// Add second pointer
	std_X::shared_ptr<Student> my_second_ptr = my_shared_ptr;
	std::cout<<"\nShared pointer:\n";
	std::cout << *my_second_ptr.data;

	// Release memory
	delete my_student;
	delete my_student_2;

	return 0;
}