#include <iostream>
#include <array>
#include <string>
#include <stack>
#include <vector>
#include <chrono>

std::chrono::steady_clock::time_point gStartTime;

void StartAlgorithm()
{
	gStartTime = std::chrono::high_resolution_clock::now();
}

void PrintDuration()
{
	std::chrono::steady_clock::time_point endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - gStartTime).count();
	std::cout << "Duration: " << duration << " ms\n";
}

void GoToScreen(const std::string& screenName, std::array<std::string, 10>& screens)
{
	for(int i = 0; i < screens.size(); ++i)
	{
		if(screens[i].empty())
		{
			screens[i] = screenName;
			break;
		}
		std::cout << "(array) Go to Screen " << screens[i] << "\n";
	}
	
}
// Overloaded function for std::vector
void GoToScreen(const std::string& screenName, std::vector<std::string>& screens)
{
	screens.push_back(screenName);
}
// Overloaded function for std::stack
void GoToScreen(const std::string& screenName, std::stack<std::string>& screens)
{
	screens.push(screenName);
}

void GoBack(std::array<std::string, 10>& screens)
{
	// find the last added screen, remove it
	for(int i = screens.size() - 1; i >= 0; --i)
	{
		if(!screens[i].empty())
		{
			std::cout << "(array) Go Back From " << screens[i] << "\n";
			screens[i] = "";
			break;
		}
	}

	for(int i = screens.size() - 1; i >= 0; --i)
	{
		if(!screens[i].empty())
		{
			std::cout << "(array) Current Screen is " << screens[i] << "\n";
			break;
		}
	}
}

void GoBack(std::vector<std::string>& screens)
{
	std::cout << "(vector) Go Back From " << screens.back() << "\n";
	screens.pop_back();
	std::cout << "(vector) Current Screen is " << screens.back() << "\n";
}

void GoBack(std::stack<std::string>& screens)
{
	std::cout << "(stack) Go Back From " << screens.top() << "\n";
	screens.pop();
	std::cout << "(stack) Current Screen is " << screens.top() << "\n";	
}

int main()
{
    std::array<std::string, 10> screensArray;
	std::vector<std::string> screensVector;
	std::stack<std::string> screensStack;

	StartAlgorithm();
	std::cout << "Array:\n";
	GoToScreen("MainMenu", screensArray);
	GoToScreen("Settings", screensArray);
	GoToScreen("Audio", screensArray);	
	GoToScreen("GameOver", screensArray);	
	GoBack(screensArray);
	GoBack(screensArray);
	GoBack(screensArray);
	PrintDuration();

	// vector stack
	StartAlgorithm();
	std::cout << "\nVector:\n";	
	GoToScreen("MainMenu", screensVector);
	GoToScreen("Settings", screensVector);
	GoToScreen("Audio", screensVector);
	GoToScreen("GameOver", screensVector);
	GoBack(screensVector);
	GoBack(screensVector);
	GoBack(screensVector);
	PrintDuration();

	// Stack stack
	StartAlgorithm();
	std::cout << "\nStack:\n";
	GoToScreen("MainMenu", screensStack);
	GoToScreen("Settings", screensStack);
	GoToScreen("Audio", screensStack);
	GoToScreen("GameOver", screensStack);
	GoBack(screensStack);
	GoBack(screensStack);
	GoBack(screensStack);
	PrintDuration();

	return 0;
}
