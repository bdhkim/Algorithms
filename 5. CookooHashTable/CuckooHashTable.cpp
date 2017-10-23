// EC 330 HW 5
// Dong Hyun Kim
// Edwardo Portet

#include "CuckooHashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <stdlib.h>

using namespace std;

CuckooHashTable::CuckooHashTable() {

	currentSize = 0;
	vector<string> temp;
	for (int j = 0; j < LOGICAL_SIZE; j++)
	{
		temp.push_back("-"); //first fill in the vectors with dashes
	}
	contents.push_back(temp); 
	contents.push_back(temp);


}

void CuckooHashTable::add(string value){



	int position0 = hashCode(value,0); //determines where the input belongs in first Cuckoo table
	int position1 = hashCode(value,1); //determines where the input belongs in the second Cuckoo table
	string holdvalue = "";

	if(contents[0][position0] == "-"){
		contents[0][position0] = value;    //if the place is empty (fillied with dash), then insert
	}

	else if (contents[0][position0] != "-" && currentSize == 0){  //if the position is occupied, and check the insertion is not in infinite loop

		holdvalue = contents[0][position0]; //copy the data before overwriting

		contents[0][position0] = value; //insert the new input
		
		currentSize++; //increment this variable to denote that the variable has been moved

		add(holdvalue); //move to the next table

		currentSize = 0; //set the variable back to zero 
		
	}

	else if(currentSize>0) {   //currenSize being greater 1 means that the input has been copied and that it is now safe to insert the new input without overwriting

		contents[1][position1] = value; 
	}


}


void CuckooHashTable::print(){    

	for (int i = 0; i < 2; i++)
	{
		cout << "Table " << i << ": " << endl;
		for (int j = 0; j < LOGICAL_SIZE ; j++)
		{
			cout << contents[i][j] << endl;
		}

		cout << endl;

	}
}

int CuckooHashTable::hashCode(string value, int which){

	switch(which){
		case 0: return atoi(value.c_str()) % 13;  //determining where the input belongs in first table
		case 1: return 11 - (atoi(value.c_str()) % 11); //determining where the input belongs in second table
	}

	return 0;

}
