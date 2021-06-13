#include <iostream>
#include <string.h>
#include <string>
#define NAME_MAX 100

namespace test_class {
    class Student {
        private:
            char * name;
        int age;
        double average_grades;
        public:
            // Constructors
            Student() {
                this -> name = new char[NAME_MAX];
                this -> age = 0;
                this -> average_grades = 0;
            }

			Student(char * getName, int getAge, double getAverageGrades) {
					this -> name = new char[NAME_MAX];
					strcpy(this -> name, getName);
					this -> age = getAge;
					this -> average_grades = getAverageGrades;
				}

            // Destructor
            ~Student() {
                delete[] name;
            }

			// Copy constructor
			Student(const Student & operand) {
				this -> age = operand.age;
				this -> average_grades = operand.average_grades;
				this -> name = strdup(operand.name);
			}

			// Assignment operator
			void operator = (const Student & operand) {
				this -> age = operand.age;
				this -> average_grades = operand.average_grades;
				this -> name = strdup(operand.name);
			}

			// Check if the student exists
			bool isAlive() {
				if (this)
					return true;
				return false;
			}

			friend std::ofstream & operator << (std::ofstream & out, Student & my_student);

			// Getters
			char * getName() {
				return this -> name;
			}
			int getAge() {
				return this -> age;
			}
			double getAverageGrade() {
				return this -> average_grades;
			}
    };

    std::ostream & operator << (std::ostream & out, Student & my_student) {
        if (!my_student.isAlive()) {
            out << "Dead";
            return out;
        }

        out << "My student's name is: " << my_student.getName() << "\n";
        out << "My student's age is: " << my_student.getAge() << "\n";
        out << "My student's average grade is: " << my_student.getAverageGrade() << "\n";

        return out;
    }
}

namespace std_X {
    // Unique pointer implementation
    template < typename dataType >
        class unique_ptr {
            private:
                dataType * ptr;
            unsigned int data_size;
            public:
                // Empty constructor
                unique_ptr() {}

				// Constructor for receiving pointer
				unique_ptr(dataType * element) {
						data_size = sizeof(dataType);
						ptr = element;
					}

					// Destructor
					~unique_ptr() {
						if (ptr != nullptr) delete ptr;
					}

				// Operators
				dataType & operator * () {
					return *ptr;
				}
				dataType operator -> () const {
					return *ptr;
				}

				// Assignment operator to pointer (to student in our case)
				void operator = (dataType * operand) {
					// Release current memory
					delete ptr;

					// Point to another memory
					ptr = operand;
				}

				// Assignment operator to unique pointer (move memory)
				void operator = (unique_ptr & operand) {
                this -> ptr = operand.ptr;
                operand.ptr = nullptr;
            	}
        };
}

int main(void)
{
    // Create test student
    std::cout << "First student";
    test_class::Student * my_student = new test_class::Student((char * )
        								   "Claudiu", 19, 8.66);
    std::cout << * my_student;

    // Create test second student
    std::cout << "\nSecond student\n";
    test_class::Student * my_student_2 = new test_class::Student((char * )
        									"Alex", 15, 10);
    std::cout << * my_student_2;

    // Create unique pointer
    std::cout << "\nCreate unique pointer to the second student.\n";
    std_X::unique_ptr < test_class::Student > my_student_pointer(my_student_2);
    std::cout << * my_student_pointer;

    // Move pointer
    std::cout << "\nMove pointer to the first student.\n";
    my_student_pointer = my_student;
    std::cout << * my_student_pointer;

    // Create new pointer to get the values from the first pointer
    std::cout << "\nPointer to take the values from the first pointer\n";
    std_X::unique_ptr < test_class::Student > steal_pointer;
    steal_pointer = my_student_pointer;
    std::cout << * steal_pointer;

    // Check if the first pointer is still alive
    std::cout << "\nCheck if the first pointer is still alive:\n";
    std::cout << "Status: " << * my_student_pointer << "\n";
    std::cout << "If status == 'Dead' --> the unique pointer worked correctly.\n";

    return 0;
}
