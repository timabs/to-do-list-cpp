#include "Task.hpp"
#include <fstream>
#include <iostream>
#include <random>
using Json = nlohmann::json;

void GetSingleInput(std::string& s)
{
	std::cin >> s;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

void GetSingleInput(char& i)
{
	std::cin >> i;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Task::Task(const std::string& content, uint32_t _id) : m_Content(content) 
{

	id = _id;
}
Task::Task(const std::string& content) : m_Content(content)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<uint32_t> dist(0, 4294967295);
	id = dist(gen);
}
std::string Task::GetContent() const
{
	return m_Content;
}
uint32_t Task::GetId() const
{
	return id;
}

void Task::SetContent(const std::string& newContent)
{
	m_Content = newContent;
}

nlohmann::json Task::ToJson() const {
	nlohmann::json j;
	j["m_Content"] = m_Content;
	j["id"] = id;
	return j;
}

Task Task::FromJson(const nlohmann::json& j)
{
	std::string content = j.at("m_Content").get<std::string>();
	uint32_t id = j.at("id").get<uint32_t>();
	return Task(content, id);
}

void SaveToJson(const std::vector<Task>& tasks, const std::string& filename)
{
	Json j;
	for (const auto& task : tasks)
	{
		j.emplace_back(task.ToJson());
	}
	std::ofstream o(filename);
	o << j.dump(4); //Write to JSON with indentation of 4
}


void LoadFromJson(std::vector<Task>& tasks, const std::string& filename)
{
	std::ifstream i(filename);
	if (!i)
	{
		std::cerr << "Could not open file for reading: " << filename << '\n';
	}
	Json j;
	try
	{
		i >> j;
	}
	catch (Json::parse_error& e)
	{
		std::cerr << "JSON parse error: " << e.what() << '\n';
		return;
	}
	for (auto& entry : j)
	{
		tasks.emplace_back(Task::FromJson(entry));
	}
}

bool AreYouSure()
{
	char c;
	while (true)
	{
		std::cout << "Are you sure? Y/N" << std::endl;
		GetSingleInput(c);
		switch (c)
		{
		case 'Y':
			return true;
		case 'N':
			return false;
		default:
			std::cout << "Invalid input. Please enter Y or N." << std::endl;
			continue;
		}
	}
	
}


void DisplayTasks(const std::vector<Task>& tasks)
{
	std::cout << "Your tasks:" << std::endl;
	std::cout << "---------------------" << std::endl;
	for (int i = 0; i < tasks.size(); i++)
	{
		std::string formattedTask = std::to_string(i + 1) + ". " + tasks[i].GetContent();
		std::cout << formattedTask << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	std::cout << "" << std::endl;
}

Task AddTask()
{
	std::cout << "Enter your task: " << std::endl;
	std::string taskContent;
	std::getline(std::cin, taskContent);
	return Task(taskContent);
}

int PromptForNumAndReturn(std::string& s)
{
	int selectionNum;
	std::cout << "Which one?" << std::endl;
	GetSingleInput(s);
	try
	{
		selectionNum = std::stoi(s);
		selectionNum--;
		return selectionNum;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Invalid arg: " << e.what() << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Out of range: " << e.what() << std::endl;
	}
}
void DeleteTask(std::vector<Task>& tasks)
{
	std::string s;
	int selectionNum = PromptForNumAndReturn(s);
	std::cout << "To Delete: " << tasks[selectionNum].GetContent() << std::endl;
	bool sure = AreYouSure();
	if (sure)
	{
		tasks.erase(tasks.begin() + selectionNum);
	}
	
}
void EditTask(std::vector<Task>& tasks)
{
	std::string s;
	int selectionNum;
	std::string newTaskContent;
	selectionNum = PromptForNumAndReturn(s);
	std::cout << "To Edit: " << tasks[selectionNum].GetContent() << std::endl;
	std::cout << "Make your edit: ";
	std::getline(std::cin, newTaskContent);
	tasks[selectionNum].SetContent(newTaskContent);
	std::cout << "Edited task: " << tasks[selectionNum].GetContent() << std::endl;
	std::cout << "\n" << std::endl;
};
void MarkAsCompleted() {};
void QuitApplication(bool& appExited, std::vector<Task>& tasks) 
{
	SaveToJson(tasks, "tasks.json");
	appExited = true;
};