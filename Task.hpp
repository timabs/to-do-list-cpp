#ifndef TASK_HPP
#define TASK_HPP

#include "json.hpp"

class Task {
private:
	std::string m_Content;
	uint32_t id;
public:
	Task(const std::string& content, uint32_t _id);
	Task(const std::string& content);
	std::string GetContent() const;
	uint32_t GetId() const;
	void SetContent(const std::string& newContent);
	nlohmann::json ToJson() const;
	static Task FromJson(const nlohmann::json& j);
};

void GetSingleInput(std::string& s);
void GetSingleInput(char& i);
void SaveToJson(const std::vector<Task>& tasks, const std::string& filename);
void LoadFromJson(std::vector<Task>& tasks, const std::string& filename);
bool AreYouSure();
Task AddTask();
void DeleteTask(std::vector<Task>& tasks);
void EditTask(std::vector<Task>& tasks);
void MarkAsCompleted();
void QuitApplication(bool& appExited, std::vector<Task>& tasks);
#endif // TASK_HPP
