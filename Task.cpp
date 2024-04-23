#include "Task.hpp"
#include <fstream>
#include <iostream>

using Json = nlohmann::json;

Task::Task(const std::string& content) : m_Content(content) {}

std::string Task::GetContent() const
{
	return m_Content;
}

void Task::SetContent(const std::string& newContent)
{
	m_Content = newContent;
}

nlohmann::json Task::ToJson() const {
	nlohmann::json j;
	j["m_Content"] = m_Content;
	return j;
}

Task Task::FromJson(const nlohmann::json& j)
{
	std::string content = j.at("m_Content").get<std::string>();
	return Task(content);
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
	std::cin >> taskContent;
	return Task(taskContent);
}

void EditTask()
{
	
};
void MarkAsCompleted() {};
void QuitApplication() {};