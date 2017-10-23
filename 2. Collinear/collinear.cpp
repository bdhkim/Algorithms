// MaxProduct.cpp
// Dong Hyun (Brian) Kim
// Eduardo Portet
// EC330 Homework 4

#include <iostream>
#include <vector>
#include <fstream>
#include <cstrng>
#include <string>

using namespace std;


int main()
{
	
	vector<float> coordinates;

	// Open the textfile
	ifstream inputfile("points.txt".c_str());
	float num;

	// Break the file by " " to obtain all the numbers
	// Saving each number to the instance long num
	while (inputfile >> num) {
		coordinates.push_back(num);
	}
	// Close the file
	inputfile.close();

	for (int i=0; i < coordinates.size(); i++)
	{
		cout << coordinates[i] << endl;
	}

	return 0;
}
