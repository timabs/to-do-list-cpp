#ifndef TASK_HPP
#define TASK_HPP

#include "json.hpp"

class Task {
private:
	std::string m_Content;
public:
	Task(const std::string& content);
	std::string GetContent() const;
	void SetContent(const std::string& newContent);
	nlohmann::json ToJson() const;
	static Task FromJson(const nlohmann::json& j);
};

void SaveToJson(const std::vector<Task>& tasks, const std::string& filename);
void LoadFromJson(std::vector<Task>& tasks, const std::string& filename);

#endif // TASK_HPP
