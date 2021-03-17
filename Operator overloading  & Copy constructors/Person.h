#ifndef __PERSON_H
#define __PERSON_H
#define NAME_LENGTH_MAX 40
#include <string.h>

#include <stdlib.h>

class Person {
    public:
        char * name;
    int age;

    Person() {
        name = NULL;
        age = 0;
    }

    Person(const char * name, int age) {
            if (!name) {
                fprintf(stderr, "Couldn't receive name!\n");
                exit(EXIT_FAILURE);
            }
            this -> name = new char[NAME_LENGTH_MAX];
            strcpy(this -> name, name);
            this -> age = age;
        }

        ~Person() {
            delete name;
        }

    Person(const Person & other) {
        this -> age = other.age;
        this -> name = strdup(other.name);
    }

    void operator = (const Person & other) {
        this -> age = other.age;
        this -> name = strdup(other.name);
    }

    bool operator < (const Person & other) {
        if (this -> age < other.age)
            return 1;
        return 0;
    }

    bool operator > (const Person & other) {
        if (this -> age > other.age)
            return 1;
        return 0;
    }

    friend std::ostream & operator << (std::ostream & out,
        const Person & person);

};

void orderList(Person lista[]) {

    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < 5; j++)
            if (lista[i].age > lista[j].age) {
                Person aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }

}

std::ostream & operator << (std::ostream & out,
    const Person & person) {
    out << person.name << " is " << person.age << " years old and ";
    if (person.age < 25)
        out << "is going to the Mall.\n";
    else if (person.age >= 25 && person.age < 30)
        out << "is partying tonight.\n";
    else if (person.age >= 30 && person.age <= 40)
        out << "is going to the theatre.\n";
    else
        out << "is staying home tonight.\n";
    return out;
}

#endif