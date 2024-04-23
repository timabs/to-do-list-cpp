#include "Task.hpp"
#include <vector>
#include <iostream>



 void DisplayTasks(const std::vector<Task>& tasks)
{
	std::cout << "Your tasks:" << std::endl;
	std::cout << "---------------------" << std::endl;
	for (int i=0; i < tasks.size(); i ++)
	{
		std::string formattedTask = std::to_string(i + 1) + ". " + tasks[i].GetContent();
		std::cout << formattedTask << std::endl;
		std::cout << tasks[i].GetId() << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	std::cout << "" << std::endl;
}


 void PresentOptionsAndTakeInput(std::vector<Task>& tasks, bool& appExited)
{
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "(Enter one of letters a-e)" << std::endl;
	std::cout << "a. Add a task" << std::endl;
	std::cout << "b. Remove a task" << std::endl;
	std::cout << "c. Edit a task" << std::endl;
	std::cout << "d. Mark a task as completed" << std::endl;
	std::cout << "e. Exit" << std::endl;
	char i;
	std::cin >> i;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (i)
	{
		case 'a':
		{
			Task newTask = AddTask();
			tasks.emplace_back(newTask);
			DisplayTasks(tasks);
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
			QuitApplication(appExited, tasks);
			break;
		default:
			std::cout << "Input not recognized." << std::endl;
			break;

	}
}
static void InitApp(std::vector<Task>& tasks, bool& appExited) 
{
	 std::string name;
	 std::cout << "Welcome! Enter your name: " << std::endl;
	 std::getline(std::cin, name);
	 std::cout << "Hi, " << name << ", welcome to your to-do list!" << std::endl;
	 std::cout << "" << std::endl;
	 DisplayTasks(tasks);
	 while (!appExited)
	 {
		 PresentOptionsAndTakeInput(tasks, appExited);

	 }
 }

int main()
{
	bool appExited = false;
	std::vector<Task> myTasks;
	LoadFromJson(myTasks, "tasks.json");
	InitApp(myTasks, appExited);
}