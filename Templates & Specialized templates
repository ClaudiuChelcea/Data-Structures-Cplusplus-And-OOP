#include <iostream>
#include <string.h>

// Create generic student class
template < typename myType >
    class Student {
        private:
            char * name;
        int age;
        myType grade;
        public:
            Student(char * name, int age, myType grade);
        ~Student();
        void display_me() const;

    };

// Create generic constructor
template < typename myType >
    Student < myType > ::Student(char * name, int age, myType grade) {
        this -> name = new(std::nothrow) char[30];
        if (!this -> name || !name) {
            std::cerr << "Constructor error! Quiting...\n";
            exit(-1);
        }
        strcpy(this -> name, name);
        this -> age = age;

        this -> grade = grade;
    }

// Create specialized char* constructor
template < >
    Student < char * > ::Student(char * name, int age, char * my_Grade) {
        this -> name = new(std::nothrow) char[30];
        if (!this -> name || !name) {
            std::cerr << "Constructor error! Quiting...\n";
            exit(-1);
        }
        strcpy(this -> name, name);
        this -> age = age;
        this -> grade = (char * ) malloc(5 * sizeof(char));
        strcpy(this -> grade, my_Grade);

    }

// Create generic destructor
template < typename myType >
    Student < myType > ::~Student() {
        delete[] name;
        name = NULL;
    }
	
// Create specialized char* destructor
template < >
    Student < char * > ::~Student() {}


// Create generic display function
template < typename myType >
    void Student < myType > ::display_me() const {
        std::cout << name << " is " << age << " years old and in school he gets only " << grade << "!\n";

    }

// Create specialized char* display function
template < >
    void Student < char * > ::display_me() const {
        std::cout << name << " is " << age << " years old and in school he gets only the biggest grade: " << grade << "!\n";
    }

int main(void)
{
    // Create a pointer with my name
    char * my_name = NULL;
    my_name = new char[30];
    strcpy(my_name, "Chelcea Claudiu");
    if (!my_name) {
        std::cerr << "Error creating class!";
        return -1;
    }

    // Create an object and display the saved values in it
    class Student < int > my_student(my_name, 19, 10);
    my_student.display_me();

	// Create a pointer with a char* variable named 'grade'
    char * grade = NULL;
    grade = (char * ) malloc(sizeof(char) * 3);
    strcpy(grade, "FB");
    if (!grade) {
        std::cerr << "Error creating class!";
        return -1;
    }
	
	// Create a second object based on the char* specialized template
    class Student < char * > my_second_student(my_name, 19, grade);
    my_second_student.display_me();

    // Release the memory
    free(my_name);

    return 0;
}
