#include "Task.hpp"
#include <vector>
#include <iostream>





 void PresentOptionsAndTakeInput(std::vector<Task>& tasks, bool& appExited)
{
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "(Enter one of letters a-e)" << std::endl;
	std::cout << "a. Add a task" << std::endl;
	std::cout << "b. Remove a task" << std::endl;
	std::cout << "c. Edit a task" << std::endl;
	std::cout << "d. Show tasks" << std::endl;
	std::cout << "e. Exit" << std::endl;
	char i;
	GetSingleInput(i);
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
			DeleteTask(tasks);
			break;
		case 'c':
			EditTask(tasks);
			break;
		case 'd':
			DisplayTasks(tasks);
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