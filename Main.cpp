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
};


int main()
{
	Task task1 = Task("bing bong");
	std::cout << "Hello World" << std::endl;
	std::cout << task1.GetContent() << std::endl;
	return 0;
}