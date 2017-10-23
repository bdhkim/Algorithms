// Problem4b.cpp
// Dong Hyun Kim
// Partner: Eduardo Portet
// EC330 Homework 1

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void MergeFiles(string file1, string file2) {
	vector<string> allWords;
	ifstream fileOne(file1.c_str());
	ifstream fileTwo(file2.c_str());
	string word;

	while (fileOne >> word) {
		allWords.push_back(word);
	}
	fileOne.close();

	while (fileTwo >> word) {
		allWords.push_back(word);
	}
	fileTwo.close();


	sort(allWords.begin(),allWords.end());
	for (int i = 0; i < allWords.size(); ++i)
	{
		cout << allWords[i] << endl;
	}
}

int main(int argc, char *argv[]) {
	MergeFiles(argv[1],argv[2]);
	return 0;
}
