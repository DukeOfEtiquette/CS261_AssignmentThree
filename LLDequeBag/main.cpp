#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::string line;
	std::vector<std::string> memory, time;
	std::size_t found;
	int lineCount = 0;
	std::ifstream dataFile ("stuff.txt");
	std::ofstream refinedFile("refinedData.csv");

	while( std::getline(dataFile, line) )
	{
		lineCount++;
	}
	dataFile.close();
	dataFile.open("stuff.txt");

	for(int i = 0; i < lineCount; i++)
	{
		std::getline(dataFile, line);

		if(i%2 == 0)
		{
			found = line.find(':');
			memory.push_back(line.substr(found + 2, line.length() - found - 6));
		}else{
			found = line.find(':');
			time.push_back(line.substr(found + 2, line.length() - found - 5));
		}

	}
	dataFile.close();

	for(int i = 0; i < memory.size(); i++)
	{
		refinedFile << memory[i] << ",";
	}
		refinedFile << std::endl;
	for(int i = 0; i < time.size(); i++)
	{
		refinedFile << time[i] << ",";
	}
	refinedFile.close();

	return 0;
}
