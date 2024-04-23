#include "Task.hpp"
#include <vector>
#include <iostream>

void GreetUser() {
	std::string name;
	std::cout << "Welcome! Enter your name: " << std::endl;
	std::cin >> name;
	std::cout << "Hi, " << name << ", welcome to your to-do list!" << std::endl;
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "(Enter one of letters a-e)" << std::endl;
}

void DisplayTasks(const std::vector<Task>& tasks)
{
	for (int i=0; i < tasks.size(); i ++)
	{
		std::string formattedTask = std::to_string(i + 1) + ". " + tasks[i].GetContent();
		std::cout << formattedTask << std::endl;
	}
}


void PresentOptionsAndTakeInput()
{
	std::cout << "a. Add a task" << std::endl;
	std::cout << "b. Remove a task" << std::endl;
	std::cout << "c. Edit a task" << std::endl;
	std::cout << "d. Mark a task as completed" << std::endl;
	std::cout << "e. Exit" << std::endl;
}


int main()
{
	std::vector<Task> tasks;
	Task task1 = Task("bing");
	Task task2 = Task("bong");

	tasks.emplace_back(task1);
	tasks.emplace_back(task2);
	DisplayTasks(tasks);
	std::cin.get();
	//SaveToJson(tasks, "tasks.json");
	return 0;
}