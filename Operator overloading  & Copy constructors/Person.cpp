#include <iostream>
#include "Person.h"
using namespace std;

int main(void) {
    Person people[5] = {
        {
            "Harvey Specter",
            40
        },
        {
            "Michael Ross",
            27
        },
        {
            "Donna Paulsen",
            35
        },
        {
            "Rachel Zane",
            25
        },
        {
            "Louis Litt",
            45
        }
    };

    // Order list and display with custom operator
    orderList(people);
    for (int i = 0; i < 5; i++)
        cout << people[i];

    return 0;
}
