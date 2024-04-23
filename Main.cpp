#include "Task.hpp"
#include <vector>
#include <iostream>

void GreetUser() {
	std::string name;
	std::cout << "Welcome! Enter your name: " << std::endl;
	std::cin >> name;
	std::cout << "Hi, " << name << ", welcome to your to-do list!" << std::endl;
	std::cout << "What do you want to do?" << std::endl;
}

int main()
{
	std::vector<Task> tasks;
	SaveToJson(tasks, "tasks.json");
	//SaveToJson(tasks, "tasks.json");
	return 0;
}