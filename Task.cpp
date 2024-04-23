#include "Task.hpp"
#include <fstream>
#include <iostream>
#include <random>
using Json = nlohmann::json;

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
Task AddTask()
{
	std::cout << "Enter your task: " << std::endl;
	std::string taskContent;
	std::getline(std::cin, taskContent);
	return Task(taskContent);
}
void DeleteTask()
{

}
void EditTask()
{
	
};
void MarkAsCompleted() {};
void QuitApplication(bool& appExited, std::vector<Task>& tasks) 
{
	SaveToJson(tasks, "tasks.json");
	appExited = true;
};