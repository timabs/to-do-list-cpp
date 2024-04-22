#include <iostream>
#include <string>
#include "json.hpp"
#include <fstream>
#include <iostream>

using Json = nlohmann::json;

class Task {
private:
	std::string m_Content;
public:
	Task(const std::string& content) :
		m_Content(content) {}
	std::string GetContent() const {
		return m_Content;
	}
	void SetContent(const std::string& newContent) {
		m_Content = newContent;
	}
	Json ToJson() const {
		Json j;
		j["m_Content"] = m_Content;
		return j;
	}
	static Task FromJson(const Json& j)
	{
		std::string content = j.at("m_Content").get<std::string>();
		return Task(content);
	}

};

void GreetUser() {
	std::string name;
	std::cout << "Welcome! Enter your name: " << std::endl;
	std::cin >> name;
	std::cout << "Hi, " << name << ", welcome to your to-do list!" << std::endl;
	std::cout << "What do you want to do?" << std::endl;
}

int main()
{
	GreetUser();
	return 0;
}