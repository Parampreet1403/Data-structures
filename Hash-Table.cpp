// 09/06/20 - Parampreet Singh 
// Creating a Hash Table (Int, String)

#include <iostream>
#include <list>
#include <string>

class hashTable
{
private:
	static const int hashGroup{ 10 };
	std::list<std::pair<int, std::string>> table[hashGroup]; // Index 0-9

public:
	bool isEmpty();
	int hashFunction(int key);
	void insertItem(int key, std::string value);
	void removeItem(int key);
	void searchItem(int key);
	void printTable();
};

bool hashTable::isEmpty()
{
	for (int i{}; i < hashGroup; i++)
		if (!table[i].empty()) return false; // Not empty

	return true; // Empty
}

int hashTable::hashFunction(int key)
{ 
	int index{ key % 10 }; // key = 905, index = 5
	return index;
}

void hashTable::insertItem(int key, std::string value)
{
	int hashIndex{ hashFunction(key) };
	auto& cell{ table[hashIndex] };
	auto bItr{ cell.begin() };
	bool keyExist{};

	for (; bItr != cell.end(); bItr++)
	{
		if (bItr->first == key)
		{
			keyExist = true;
			bItr->second = value;
			break;
		}
	}

	if (keyExist)
		std::cout << "[WARNING]: Key value updated." << std::endl;
	else
	{
		std::cout << "Key inserted" << std::endl;
		cell.emplace_back(key, value);
	}

	return;
}

void hashTable::removeItem(int key)
{
	int hashIndex{ hashFunction(key) };
	auto& cell{ table[hashIndex] };
	auto bItr{ cell.begin() };
	bool keyExist{};

	for (; bItr != cell.end(); bItr++)
	{
		if (bItr->first == key)
		{
			keyExist = true;
			bItr = cell.erase(bItr);
			std::cout << "[INFO]: Pair removed." << std::endl;
			break;
		}
	}

	if (!keyExist)
		std::cout << "[ERROR]: Key was not found." << std::endl;

	return;
}

void hashTable::searchItem(int key)
{
	int hashIndex{ hashFunction(key) }; 
	auto& cell{ table[hashIndex] };
	auto bItr{ cell.begin() };
	bool keyExist{};

	for (; bItr != cell.end(); bItr++)
	{
		if (bItr->first == key)
		{
			keyExist = true;
			std::cout << "[INFO]: Value: " << bItr->second << std::endl;
		}
	}

	if (!keyExist)
		std::cout << "[ERROR]: Key does not exist." << std::endl;

	return;
}

void hashTable::printTable()
{
	for (int i{}; i < hashGroup; i++)
	{
		if (!table[i].empty())
		{
			auto bItr{ table[i].begin() };
			for (; bItr != table[i].end(); bItr++)
				std::cout << "[INFO]: Key: " << bItr->first << ", Value: " << bItr->second << std::endl;
		}
	}

	return;
}

int main()
{
	hashTable Company;

	if (Company.isEmpty())
		std::cout << "Correct answer" << std::endl;
	else std::cout << "Wrong answer" << std::endl;

	Company.insertItem(96, "John");
	Company.insertItem(99, "Jerry");
	Company.insertItem(98, "Simon");

	Company.searchItem(98);

	Company.removeItem(98);

	Company.insertItem(99, "Smith");

	Company.printTable();

	if (!Company.isEmpty())
		std::cout << "Correct answer" << std::endl;
	else std::cout << "Wrong answer" << std::endl;

	Company.searchItem(98);

	return 0;
}