#include <iostream>

// Vehicle abstract class to manage vehicles from parking lot
class Vehicle {
private:
    // Private members
    int vehicle_id{ 0 };
    int num_empty_parking_spaces{ 0 };
    int inventory_value{ 0 };
    int person_capacity{ 0 };

public:
    // Public members
    std::string vehicle_type{ "" };

    // Destructor and constructor
    ~Vehicle(){};
    Vehicle(int arg_vehicle_id, int arg_empty_parking_lots, int arg_inv_value,
        std::string arg_vehicle_type, int arg_person_capacity, std::string arg_veh_color)
    {
        this->vehicle_id = arg_vehicle_id;
        this->num_empty_parking_spaces = arg_empty_parking_lots;
        this->inventory_value = arg_inv_value;
        this->vehicle_type = arg_vehicle_type;
        this->person_capacity = arg_person_capacity;
        this->vehicle_color = arg_veh_color;
    }
    Vehicle() = default;

    // Getters
    auto getID() const { return vehicle_id; }
    auto getEmptySpaces() const { return num_empty_parking_spaces; }
    auto getInvValue() const { return inventory_value; }
    auto getPersonCapacity() const { return person_capacity; }
    auto getColor() const { return vehicle_color; }

    // Display
    friend std::ostream& operator<<(std::ostream& out, const Vehicle& my_vehicle);

protected:
    // Protected members
    std::string vehicle_color{ "" };
};

// Display vehicle object
std::ostream& operator<<(std::ostream& out, const Vehicle& my_vehicle)
{
    out << "Vehicle ID: " << my_vehicle.getID() << "\n";
    out << "Vehicle type: " << my_vehicle.vehicle_type << "\n";
    out << "Vehicle color: " << my_vehicle.getColor() << "\n";
    out << "Person Capacity: " << my_vehicle.getPersonCapacity() << "\n";
    out << "Empty spaces: " << my_vehicle.getEmptySpaces() << "\n";

    return out;
}

// Keep the same access specifiers
class Bus : public Vehicle {
private:
    int cilindrical_capacity{ 0 }; // square meters
public:
    // Constructor and destructor
    Bus(int arg_vehicle_id = 0, int arg_empty_parking_lots = 0, int arg_inv_value = 0,
        std::string arg_vehicle_type = "", int arg_person_capacity = 0, std::string arg_veh_color = "",
        int arg_cilindrical_capacity = 0)
        : Vehicle{ arg_vehicle_id, arg_empty_parking_lots, arg_inv_value, arg_vehicle_type, arg_person_capacity, arg_veh_color }
    {
        this->cilindrical_capacity = arg_cilindrical_capacity;
    }

    ~Bus() = default;

    friend std::ostream& operator<<(std::ostream& out, const Bus& my_bus);
};

// Display bus object
std::ostream& operator<<(std::ostream& out, const Bus& my_bus)
{
    out << "Vehicle ID: " << my_bus.getID() << "\n";
    out << "Vehicle type: " << my_bus.vehicle_type << "\n";
    out << "Vehicle color: " << my_bus.vehicle_color << "\n";
    out << "Person Capacity: " << my_bus.getPersonCapacity() << "\n";
    out << "Empty spaces: " << my_bus.getEmptySpaces() << "\n";
    out << "Engine cilindrical capacity: " << my_bus.cilindrical_capacity << "\n";

    return out;
}

// Everything is protected or private
class Tram : protected Vehicle {
private:
    int nr_wagons{ 0 };

public:
    // Constructor and destructor
    ~Tram() = default;
    Tram(int arg_vehicle_id = 0, int arg_empty_parking_lots = 0, int arg_inv_value = 0,
        std::string arg_vehicle_type = "", int arg_person_capacity = 0, std::string arg_veh_color = "",
        int arg_nr_wagons = 0)
        : Vehicle{ arg_vehicle_id, arg_empty_parking_lots, arg_inv_value, arg_vehicle_type, arg_person_capacity, arg_veh_color }
    {
        this->nr_wagons = arg_nr_wagons;
    }

    // Display
    friend std::ostream& operator<<(std::ostream& out, const Tram& my_tram);
};

// Display tram object
std::ostream& operator<<(std::ostream& out, const Tram& my_tram)
{
    out << "Vehicle ID: " << my_tram.getID() << "\n";
    out << "Vehicle type: " << my_tram.vehicle_type << "\n";
    out << "Vehicle color: " << my_tram.vehicle_color << "\n";
    out << "Person Capacity: " << my_tram.getPersonCapacity() << "\n";
    out << "Empty spaces: " << my_tram.getEmptySpaces() << "\n";
    out << "Number of wagons: " << my_tram.nr_wagons << "\n";

    return out;
}

// Everything is private
class TrolleyBus : private Vehicle {
private:
    int engine_power; // hp
public:
    // Constructor and destructor
    ~TrolleyBus() = default;
    TrolleyBus(int arg_vehicle_id = 0, int arg_empty_parking_lots = 0, int arg_inv_value = 0,
        std::string arg_vehicle_type = "", int arg_person_capacity = 0, std::string arg_veh_color = "",
        int arg_engine_power = 0)
        : Vehicle{ arg_vehicle_id, arg_empty_parking_lots, arg_inv_value, arg_vehicle_type, arg_person_capacity, arg_veh_color }
    {
        this->engine_power = arg_engine_power;
    }

    // Display
    friend std::ostream& operator<<(std::ostream& out, const TrolleyBus& my_trolleybus);
};

// Display trolleybus object
std::ostream& operator<<(std::ostream& out, const TrolleyBus& my_trolleybus)
{
    out << "Vehicle ID: " << my_trolleybus.getID() << "\n";
    out << "Vehicle type: " << my_trolleybus.vehicle_type << "\n";
    out << "Vehicle color: " << my_trolleybus.vehicle_color << "\n";
    out << "Person Capacity: " << my_trolleybus.getPersonCapacity() << "\n";
    out << "Empty spaces: " << my_trolleybus.getEmptySpaces() << "\n";
    out << "Engine power: " << my_trolleybus.engine_power << "\n";

    return out;
}

int main(void)
{
    // Create objects
    std::cout << "Create bus object:\n";
    Bus my_bus(0, 15, 15, "BUS", 15, "RED", 3200);
    std::cout << my_bus << "\n";

    std::cout << "Create tram object:\n";
    Tram my_tram(1, 25, 25, "TRAM", 40, "BLUE", 10);
    std::cout << my_tram << "\n";

    std::cout << "Create trolleybus object:\n";
    TrolleyBus my_trolleybus(2, 30, 30, "TROLLEYBUS", 60, "GREEN", 560);
    std::cout << my_trolleybus << "\n";

    // Test upcasting
    std::cout << "Upcasted object to vehicle:\n";
    Vehicle my_vehicle = my_bus;
    std::cout << my_vehicle << "\n";

    return 0;
}
