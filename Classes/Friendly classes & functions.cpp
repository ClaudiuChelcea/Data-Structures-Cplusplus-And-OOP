#include <iostream>

class Character {
    private:
        int health;
    int stamina;
    public:
        int getHealth() {
            return health;
        }
    int getStamina() {
        return stamina;
    }
    Character();
    ~Character();
    void displayCharacter();
    friend class Second_Character;
    friend void displayCharacterStatus(Character & myCharacter);
};

void Character::displayCharacter() {
    std::cout << "Character's health: " << health << "\nCharacter's stamina: " << stamina << std::endl;
}

class Second_Character {
    private:
        int health;
    int stamina;
    bool ally;
    public:
        int getHealth() {
            return health;
        }
    int getStamina() {
        return stamina;
    }
    Second_Character(Character mainCharacter) {
        health = mainCharacter.health;
        stamina = mainCharacter.stamina;
        ally = 1;
    }~Second_Character() {}
    bool relation_2_Character() {
        if (ally)
            return 1;
        else
            return 0;
    }
    void displaySecondCharacter() {
        if (relation_2_Character())
            std::cout << "I'm a friend!\n";
        else
            std::cout << "i'm an enemy!\n";
        std::cout << "Second's character health: " << health << "\nCharacter's stamina: " << stamina << std::endl;
    }
};

Character::Character() {
    health = 100;
    stamina = 100;
}

Character::~Character() {}

void displayCharacterStatus(Character & myCharacter) {
    if (myCharacter.health > 0 && myCharacter.stamina > 0)
        std::cout << "Is alive and ready!\n";
    else if (myCharacter.health > 0 && myCharacter.stamina < 0)
        std::cout << "Is alive and tired!\n";
    else if (!myCharacter.health)
        std::cout << "Is dead!\n";
    myCharacter.health -= 5;
}

int main(void) {
    // Create first character
    Character mainCharacter;
    mainCharacter.displayCharacter();
    displayCharacterStatus(mainCharacter);

    // Create second character
    std::cout << "\n";
    Second_Character secondaryCharacter(mainCharacter);
    secondaryCharacter.displaySecondCharacter();

    return 0;
}
