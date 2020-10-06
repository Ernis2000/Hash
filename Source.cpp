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
		while (std::getline(file, word)) {}

		hashfunction(word);
	}

}

std::string randomword(const int length) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	std::string result("", length);

	for (int i = 0; i < length; ++i) {
		result[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	return result;
}
void randomwordtests()
{
	unsigned int collisions = 0;
	for (int i = 0; i < RANDOM_COUNT; i++)
	{
		std::string word1 = randomword(RANDOM_LENGTH);
		std::string word2 = randomword(RANDOM_LENGTH);
		if (hashfunction(word1) == hashfunction(word2))
		{
			collisions++;
		}

	}
	std::cout << "Number of collisions:" << collisions << std::endl;
}
std::string wordtobinary(std::string word)
{
	std::string binaryword = "";
	for (char& _char : word)
	{
		binaryword += std::bitset<8>(_char).to_string();
	}
	return binaryword;
}

double compare(std::string hashbinary1, std::string hashbinary2) {
	const size_t length = std::min(hashbinary1.length(), hashbinary2.length());
	unsigned int identical = 0;

	for (int i = 0; i < length; i++) {
		if (hashbinary1[i] == hashbinary2[i]) {
			identical++;
		}
	}
	return 1.0 - (double)identical / length;
}
void similiartest()
{
	unsigned int collisions = 0;
	double min_difference = 1.0;
	double max_difference = 0;
	double totaldifference = 0;
	for (int i = 0; i < SIMILAR_COUNT; i++)
	{
		const std::string word1 = randomword(SIMILAR_LENGHT);
		std::string word2;

		do {
			const unsigned int lettertochange = rand() % SIMILAR_LENGHT;
			const std::string newletter = randomword(1);
			word2 = word1;
			word2[lettertochange] = newletter[0];
		} while (word1 == word2);
			const std::string hash1 = hashfunction(word1);
			const std::string hash2 = hashfunction(word2);
			if (hash1 == hash2)
			{
				collisions++;
			}
			const std::string binary1 = wordtobinary(hash1);
			const std::string binary2 = wordtobinary(hash2);
			const double difference = compare(binary1, binary2);
			totaldifference += difference;
			if (difference < min_difference)
			{
				min_difference = difference;
			}
			else if (difference > max_difference)
			{
				max_difference = difference;
			}
	}
	std::cout << "Collisions: " << collisions << "\n";
	std::cout << "Minimum difference: " << min_difference * 100 << "\n";
	std::cout << "Maximum difference: " << max_difference * 100 << "\n";
	std::cout << "Average difference: " << (totaldifference / SIMILAR_COUNT) * 100 << "\n";

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
	//	hashfunction(word);
	}
	else {
		reading(word);
	}

	similiartest();
	



	return 0;
}