#include "Task.hpp"
#include <vector>
#include <iostream>

static void InitApp(std::vector<Task>& tasks) {
	std::string name;
	std::cout << "Welcome! Enter your name: " << std::endl;
	std::cin >> name;
	std::cout << "Hi, " << name << ", welcome to your to-do list!" << std::endl;
	DisplayTasks(tasks);
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "(Enter one of letters a-e)" << std::endl;
	PresentOptionsAndTakeInput(tasks);
}

static void DisplayTasks(const std::vector<Task>& tasks)
{
	std::cout << "Your tasks:" << std::endl;
	for (int i=0; i < tasks.size(); i ++)
	{
		std::string formattedTask = std::to_string(i + 1) + ". " + tasks[i].GetContent();
		std::cout << formattedTask << std::endl;
	}
}


static void PresentOptionsAndTakeInput(std::vector<Task>& tasks)
{
	std::cout << "a. Add a task" << std::endl;
	std::cout << "b. Remove a task" << std::endl;
	std::cout << "c. Edit a task" << std::endl;
	std::cout << "d. Mark a task as completed" << std::endl;
	std::cout << "e. Exit" << std::endl;
	char i;
	std::cin >> i;
	switch (i)
	{
		case 'a': 
		{
			Task newTask = AddTask();
			tasks.emplace_back(newTask);
			break;
		}
		case 'b':
			DeleteTask();
			break;
		case 'c':
			EditTask();
			break;
		case 'd':
			MarkAsCompleted();
			break;
		case 'e':
			QuitApplication();
			break;
		default:
			std::cout << "Input not recognized." << std::endl;
			break;

	}
}


int main()
{
	std::vector<Task> myTasks;
	LoadFromJson(myTasks, "tasks.json");
	InitApp(myTasks);
	std::cin.get();
	//SaveToJson(tasks, "tasks.json");
}