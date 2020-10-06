#include "Header.h"

std::string hashfunction(std::string word = "")
{
	unsigned int sum = 0;
	if (word == "")
	{
		word += std::to_string(sum);
	}
	for (int i : word)
	{
		unsigned int val = i;
		sum += val * val;
		sum += (~val % ~sum);
		sum += sum << 1;
	}
	sum = sum >> 1;
	std::stringstream ss;
	ss << std::hex << sum;
	std::string result = (ss.str());
	while (result.length() != 20)
	{
		for (unsigned int ch : result)
		{
			ch = (ch + ~result.length()) * sum >> 2;
			ch += sum | ch;
			ch += ch >> 2;
			ss.str("");
			ss << std::hex << ch;
			result += ss.str();
		}
		if (result.length() > 20)
		{
			result = result.substr(0, 20);
		}
	}
	std::cout << result << std::endl;
	return result;
}

void reading(std::string& word)
{
	std::string filename;
	std::cout << "Enter the full file name:" << std::endl;
	std::cin >> filename;
	std::ifstream file(filename);
	if (!file)
	{
		std::cout << "File was not found" << std::endl;
		exit(0);
	}
	else {
		while (std::getline(file, word)){}
		
		hashfunction(word);
	}

}
int main() {
	std::string word, choice;
	char filename;
	std::cout << "Use a hand written text or read from a file?" << std::endl;
	std::cin >> choice;
	if (choice == "text")
	{
		std::cout << "Enter your text:" << std::endl;
		std::cin >> word;
		hashfunction(word);
	}
	else {
		reading(word);
	}



	return 0;
}