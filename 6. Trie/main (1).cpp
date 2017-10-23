#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "Words.h"

using namespace std;

void fourA()
{
    ifstream inFile("BigDataSample.txt");
    ofstream output("Problem4.txt");
    string words;
    int count = 0;

    while (inFile >> words) {
        if(string::npos == words.find_first_of("0123456789")){
            count++;
        }
    }

    output << "There are " << count << " words containing only letters in the text file." << endl;

}

string CheckPangram(const string str)
{
    string s = str;
    string result = "";
    int hist[26] = {};
    for (int i = 0; i < str.length(); i++) {
      if (isalpha(s[i])) {
        s[i] = tolower(s[i]);
        hist[s[i]-'a']++;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (!hist[i])
        result += (char) (i+'a');
    }
    return result;
  }

  void fourB() {
    ifstream inFile("BigDataSample.txt");
    ofstream output;
    output.open("Problem4.txt", std::ios_base::app);

    string words;
    int count = 999999999;
    string fin = "";

    while (inFile >> words) {
        string result = CheckPangram(words);
        if ("" == result && words.length()< count)
        {
            fin = words;
            count = words.length();
        }
    }
    output << "\nThe shortest pangram is: " << fin << endl;

  }




int main()
{
    //fourA();
    //fourB();
    fourC();

    return 0;
}

