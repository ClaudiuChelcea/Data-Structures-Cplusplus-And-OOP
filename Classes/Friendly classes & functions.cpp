#include <iostream>

namespace Players 
{
    class Character {
        private:
            int health;
            int stamina;
        public:
            // Constructors and destructor
            Character() { health = 100; stamina = 100; }
            Character(int new_health, int new_stamina) : health(new_health), stamina(new_stamina) {}
            ~Character() {}
            
            // Retrieve private variables
            int getHealth() { return health; }
            int getStamina() { return stamina; }
            
            // Methods
            void displayCharacter();
            friend class Second_Character;
            friend void displayCharacterStatus(Character & myCharacter);
    };


    // Display character and stamina
    void Character::displayCharacter() {
        std::cout << "Character's health: " << health << "\nCharacter's stamina: " << stamina << std::endl;
    }

    class Second_Character {
        private:
            int health;
            int stamina;
            bool ally;
        public:
            // Constructors and destructors
            Second_Character() {}
            Second_Character(Character mainCharacter) : health(mainCharacter.health), stamina(mainCharacter.stamina), ally(true) {}
            ~Second_Character() {}

            // Get private variables
            int getHealth() { return health; }
            int getStamina() { return stamina; }
           
            // Methods
            bool relation_2_Character() {
                if (ally) return 1;
                else return 0;
            }
            void displaySecondCharacter() {
                if (relation_2_Character())
                    std::cout << "I'm a friend!\n";
                else
                    std::cout << "i'm an enemy!\n";
                std::cout << "Second's character health: " << health << "\nCharacter's stamina: " << stamina << std::endl;
            }
    };

    // Display character's status
    void displayCharacterStatus(Character & myCharacter) {
        if (myCharacter.health > 0 && myCharacter.stamina > 0)
            std::cout << "Is alive and ready!\n";
        else if (myCharacter.health > 0 && myCharacter.stamina < 0)
            std::cout << "Is alive and tired!\n";
        else if (!myCharacter.health)
            std::cout << "Is dead!\n";
        myCharacter.health -= 5;
    }
}
int main(void)
{
    // Create first character
    std::cout<<"Main character:\n";
    Players::Character mainCharacter;
    mainCharacter.displayCharacter();
    displayCharacterStatus(mainCharacter);

    // Create more second characters
    Players::Second_Character* secondaryCharacters = new Players::Second_Character[5];  
    for(int i = 0; i < 5; i++) {
        std::cout << "\nAssignment constructor:\n";
        secondaryCharacters[i] = mainCharacter;
        secondaryCharacters[i].displaySecondCharacter();
    }
    
    // Copy constructor
    std::cout << "\nCopy constructor:\n";
    Players::Second_Character copy_player(mainCharacter);
    copy_player.displaySecondCharacter();

    // Release memory
    delete[] secondaryCharacters;

    return 0;
}
