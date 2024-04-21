#include <iostream>
#include <string>

class Task {
private:
	std::string m_Content;
public:
	Task(const std::string& content) :
		m_Content(content) {}
	std::string GetContent() {
		return m_Content;
	}
	std::string SetContent(const std::string& newContent) {
		m_Content = newContent;
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