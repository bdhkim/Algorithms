// MaxProduct.cpp
// Dong Hyun (Brian) Kim
// Eduardo Portet
// EC330 Homework 2

#include "MaxProduct.h"

using namespace std;

/////////////////
// Constructor //
/////////////////

MaxProductClass::MaxProductClass() {
}

//////////////////////
// Member Functions //
//////////////////////

long MaxProductClass::MaxProduct(string file) {
	
	// Long Vector that will store all the numbers from the given file
	// including the -999999
	vector<long> allNumbers;

	// Open the textfile
	ifstream inputfile(file.c_str());
	long num;

	// Break the file by " " to obtain all the numbers
	// Saving each number to the instance long num
	while (inputfile >> num) {
		allNumbers.push_back(num);
	}
	// Close the file
	inputfile.close();

	// Pointers to the begining and end of a sequence of numbers determined by the position of the -999999
	int countbegin = 0;
	int countend = 0;

	// long array that will hold the max values
	// products[0] will hold the max product at a given instance
	// products[1] will hold the max product overall
	long products[2];
	products[1] = 0; // initialize products[1] to 0

	for (int i = 0; i < allNumbers.size(); i++)
	{
		products[0] = 0; // initialize products[0] to 0 at the beggining of each new sequence
		if (allNumbers[i] == -999999)
		{
			countend = i; // once we find a -999999 we can set the ending pointer to it
			for (int j = countbegin; j < countend; j++) // iterate through the given sequence bounded by countbegin and countend
			{
				long first = allNumbers[j];
				long second = allNumbers[j+1];
				long third = allNumbers[j+2];
				
				if (products[0] < first || products[0] == 0 )
					products[0] = first;
				
				if (products[0] < first * second && (j+1 < countend))
					products[0] = first * second; 
				
				if (products[0] < first * second * third && (j+2 < countend))
					products[0] = first * second * third;
			}
			countbegin = countend+1; //set the countbegin variable to where the new sequence begins after -999999
			cout << products[0] << endl; //print out the products 
			if (products[1] < products[0]) //compares the value o the products
			{
				products[1] = products[0];
			}
		}
	}
	return products[1]; // returns the biggest product 
}
