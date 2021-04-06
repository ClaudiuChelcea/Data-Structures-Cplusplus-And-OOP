#include <iostream>

// Class for robots
class Robot
{
	// Fields
	private:
		int fuel;
	int health;
	int bullets;
	std::string name;
	public:
		// Getters
		int &get_fuel()
		{
			return this->fuel;
		}

	int &get_health()
	{
		return this->health;
	}

	int &get_bullets()
	{
		return this->bullets;
	}

	std::string &get_name()
	{
		return this->name;
	}

	// Setters
	void set_fuel(int value)
	{
		this->fuel = value;
	}

	void set_health(int value)
	{
		this->health = value;
	}

	void set_bullets(int value)
	{
		this->bullets = value;
	}

	void set_name(std::string value)
	{
		this->name = value;
	}

	// Constructors &Destructors
	Robot();
	Robot(std::string name, int fuel, int health, int bullets);
	~Robot() {}

	// Methods
	virtual void display_Robot();
};

// Default constuctor
Robot::Robot()
{
	this->fuel = 0;
	this->health = 0;
	this->bullets = 0;
	this->name = "DEFAULT";
}

// Custom Constructor
Robot::Robot(std::string name, int fuel, int health, int bullets)
{
	this->fuel = fuel;
	this->health = health;
	this->bullets = bullets;
	this->name = name;
}

// Display method
void Robot::display_Robot()
{
	if (this->name == "DEFAULT")
		std::cout << "Please give values to this robot!\n";
	else
		std::cout << "Robot " << name << " with health of " << health << ", fuel of " << fuel << ", and " << bullets << " bullets!\n";
}

// Inherit the robot class
class Enemy_Robot: public Robot
{
	private: bool is_Alive;
	public: bool get_status()
	{
		return this->is_Alive;
	}

	void set_status(bool value)
	{
		this->is_Alive = value;
	}

	// Override display method
	void display_Robot() override
	{
		if (is_Alive)
			std::cout << "Enemy robot with health of " << get_health() << ", fuel of " << get_fuel() << ", and " << get_bullets() << " bullets!\n";
		else
			std::cout << "Enemy is dead!\n";
	}

	// Create default constructor
	Enemy_Robot()
	{
		set_status(0);
		set_fuel(0);
		set_health(0);
		set_bullets(0);
	}

	// Create custom constructor
	Enemy_Robot(bool is_Alive, int fuel, int health, int bullets)
	{
		set_status(is_Alive);
		set_fuel(fuel);
		set_health(health);
		set_bullets(bullets);
	}~Enemy_Robot() {}
};

// Multilevel inheritance
class Friendly_Robot: Enemy_Robot
{
	public:
		// Override display method
		void display_Robot() override
		{
			if (get_status())
				std::cout << "\nMultilevel-inherited friend robot has been spawned!\n";
			else
				std::cout << "Friend is dead!\n";
		}

	Friendly_Robot()
	{
		set_status(1);
	}
};

int main(void)
{
	// Use defualt constructor
	class Robot my_robot;
	my_robot.display_Robot();

	// Use custom constructor
	my_robot = Robot("RobotBoy", 100, 100, 3);
	my_robot.display_Robot();

	// Display inherited enemy robot
	std::cout << "\n";
	class Enemy_Robot my_enemy;
	my_enemy.display_Robot();

	// Modify fields
	my_enemy = Enemy_Robot(1, 100, 100, 3);
	my_enemy.display_Robot();

	// Create multilevel inherited robot
	class Friendly_Robot my_friend;
	my_friend.display_Robot();

	return 0;
}
