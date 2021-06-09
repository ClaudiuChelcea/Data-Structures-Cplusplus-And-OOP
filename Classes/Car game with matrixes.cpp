#include <iostream>
#include <string.h>
#define BOARD_SIZE 10
#define COMMAND_SIZE 5

// Create the Vehicle class
class Vehicle {
    private:
        bool runningEngine;
        std::pair < int, int > coordinates;
    public:
        Vehicle();
        ~Vehicle();
        void moveStep(char * direction, int gameBoard[][BOARD_SIZE], int & running);
};

// Constructor
Vehicle::Vehicle() {
    runningEngine = false;
    coordinates.first = 0;
    coordinates.second = 0;
}

// Destructor
Vehicle::~Vehicle() {
    std::cout << "Game over!\n";
}

// Display the current game map
void displayMap(int gameBoard[][BOARD_SIZE]) {
    std::cout << "Current gameBoard:";
    for (int i = 0; i < BOARD_SIZE; i++) {
        std::cout << "\n";
        for (int j = 0; j < BOARD_SIZE; j++)
            std::cout << gameBoard[i][j] << " ";
    }

    std::cout << "\n";
}

// Update the map by the player's movement
void updateMap(int gameBoard[][BOARD_SIZE], std::pair < int, int > & coordinates, int direction_value, int & running) {
    std::pair < int, int > previous_coordinates = coordinates;

    if (direction_value == 0)
        coordinates.first -= 1;
    else if (direction_value == 1)
        coordinates.first += 1;
    else if (direction_value == 2)
        coordinates.second -= 1;
    else if (direction_value == 3)
        coordinates.second += 1;

    // Check borders
    if (coordinates.first < 0 || coordinates.first > 9 || coordinates.second < 0 || coordinates.second > 9) {
        std::cout << "Crashed in margin walls!\n";
        running = false;
        return;
    }

    // Check road_blocks
    if (gameBoard[coordinates.second][coordinates.first] == 2) {
        std::cout << "Crashed in road block!\n";
        running = false;
        return;
    }

    // Check for end_level position
    if (gameBoard[coordinates.second][coordinates.first] == 9) {
        std::cout << "Win!\n";
        exit(EXIT_SUCCESS);
    }

    // If the movement is correct, display it
    gameBoard[previous_coordinates.second][previous_coordinates.first] = 0;
    gameBoard[coordinates.second][coordinates.first] = 1;
    displayMap(gameBoard);
}

// Check the inserted command
void Vehicle::moveStep(char * direction, int gameBoard[][BOARD_SIZE], int & running) {

    if (!direction) {
        std::cerr << "Error receiving direction!\n";
        exit(EXIT_FAILURE);
    } else if (strcmp(direction, "quit") == 0) {
        running = false;
    } else if (runningEngine == false) {
        if (strcmp(direction, "start") != 0) {
            std::cout << "The engine is not started!\n";
        } else {
            std::cout << "Engine started!\n";
            runningEngine = true;
            displayMap(gameBoard);
        }
    } else if (strcmp(direction, "stop") == 0) {
        runningEngine = false;
        std::cout << "Engine stopped!\n";
    } else if (strcmp(direction, "left") == 0) {
        updateMap(gameBoard, coordinates, 0, running);

    } else if (strcmp(direction, "right") == 0) {
        updateMap(gameBoard, coordinates, 1, running);

    } else if (strcmp(direction, "up") == 0) {
        updateMap(gameBoard, coordinates, 2, running);
    } else if (strcmp(direction, "down") == 0) {
        updateMap(gameBoard, coordinates, 3, running);
    } else {
        std::cerr << "Invalid direction! Engine stopped!\n";
        runningEngine = false;
    }
}

// Display the rules of the game
void displayRules() {
    std::cout << "Insert 'quit' to exit, 'start' to start the engine or 'stop' to stop the engine!\n";
    std::cout << "Movement: press 'up' | 'down' | 'left' | 'right' to move!\n";
    std::cout << "Your position is marked with value '1'. Get to the end (value '9') while ";
    std::cout << "not hitting the borders or the obstacles (value '2').\n\n";
    std::cout << "Good luck!\n";
}

int main(void) {
    class Vehicle my_player_car;
    
    // Create static map
    int gameBoard[BOARD_SIZE][BOARD_SIZE] = {
        1, 0, 2, 2, 2, 0, 0, 0, 0, 2,
        0, 0, 0, 0, 2, 0, 0, 0, 2, 0,
        0, 0, 0, 0, 2, 0, 0, 0, 0, 2,
        0, 0, 0, 0, 2, 2, 2, 2, 0, 0,
        0, 2, 0, 0, 0, 0, 0, 2, 0, 2,
        0, 0, 0, 0, 2, 0, 0, 0, 0, 2,
        0, 0, 0, 0, 2, 2, 0, 0, 0, 0,
        0, 0, 0, 2, 0, 0, 0, 0, 0, 2,
        0, 0, 2, 0, 0, 0, 0, 2, 0, 2,
        0, 0, 0, 0, 0, 2, 2, 2, 0, 9
    };

    // Allocate the user's command
    char * command = (char *) malloc(COMMAND_SIZE * sizeof(char));
    if (!command) {
        std::cout << "Could not start game!\n";
        exit(EXIT_FAILURE);
    }
    
    // Display the game rules
    displayRules();

    // Start the game
    displayMap(gameBoard);
    int move_count = 0;
    int running = 1;
    while (running) {
        std::cout << "\nCommand:";
        std::cin >> command;
        if (!command) {
            std::cout << "Didn't receive command correctly! Exiting...\n";
            free(command);
            exit(EXIT_FAILURE);
        }
        std::cout << "<<<<<<<<<<<<<< Inserted command number: " << move_count << " >>>>>>>>>>>>>>\n";
        my_player_car.moveStep(command, gameBoard, running);
        move_count++;
       
    }

    free(command);

    return 0;
}
