// Assignment 6
// Eduardo Portet
// Partners: Dong Hyun Kim and Erostin Lushka


#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

void fourA() {
	ifstream file("BigData.txt");
	string words;
	int count;

	while(file >> words) {
		if (string::npos == words.find_first_of("0123456789")) {
			count++;
		}
	}

	cout << "There are " << count << " words in this file!" << endl;
}

/////////////////
// Begin PartB //
/////////////////

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
    ifstream inFile("BigData.txt");
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
    cout << "\nThe shortest pangram is: " << fin << endl;

}
/* REALLY SLOW ALGORITHM IT TAKES AROUND 3H
bool isPangram(string word) {
	int occurence[26];
	int check = 0;
	int len = word.length();
	char * sentence = new char[word.length() + 1];
	strcpy(sentence,word.c_str());

	for (int i = 0; i < len; ++i)
	{
		if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
			int x = (int)sentence[i]%65;
			occurence[x] = 1;
		}
		else if (sentence[i] >= 'a' && sentence[i] <= 'z') {
			int x = (int)sentence[i]%97;
			occurence[x] = 1;
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		check += occurence[i];
	}

	if (check == 26)
	{
		return true;
	}

	return false;
}

void fourB() {
	ifstream file("BigData.txt");
	char letter;
	string sentence = "";
	string result = "";
	int size = 0;
	
	// Get the first 26 letters on the sentence because we arent going to find a panagram smaller than 26
	for (int i = 0; i < 26; ++i)
	{
		file >> noskipws >> letter;
		sentence += letter;
	}

	// Look through the file for the first panagram
	while(file >> noskipws >> letter) {
		sentence += letter;
		if (isPangram(sentence))
		{
			result = sentence; // Save the sentence to result
			size = sentence.length(); // Save the length of the result
			break;
		}
	}


	while(file >> noskipws >> letter) {
		// Erase the first letter of sentence
		while (isPangram(sentence)) {
			sentence.erase(0,1);
			// If it's still a pangram and it is smaller than the result, make this the result
			if (isPangram(sentence) && sentence.length() < size)
			{
				result = sentence; // Save the sentence to result
				size = sentence.length(); // Save the length of the result
			}
		}

		sentence += letter;
		
	}

	//cout << sentence << endl;

	if (result == "") { result = "No pangrams found"; }

	cout << result << endl;
}
*/

/////////////////
// Begin PartC //
/////////////////

struct node
{
    bool is_end;
    int prefix_count;
    struct node* child[26];//including lower and upper case
}*head;


void initialize()
{
    head=new node();
    head->prefix_count=0;
    head->is_end=false;

}

void triefy(string s)
{
	struct node *current = head;
	current->prefix_count++;

	for(int i = 0; i < s.size(); i++)
    {
		int ch = s[i]-'a';
		if(current->child[ch] == NULL) {
            current->child[ch] = new node();
		}
		current = current->child[ch];
	}
	current->is_end = true;
}


int words_with_prefix (string prefix)
{
    struct node *current = head;
    for(int i = 0; i < prefix.size(); i++) {
		int ch = prefix[i]-'a';
		if(current->child[ch] == NULL) {
            return 0;
		}
		else{
            current = current->child[ch];
		}
	}
	return current->prefix_count;
}

class Node {
public:
    Node() { mContent = ' '; mMarker = false; }
    ~Node() {}
    char content() { return mContent; }
    void setContent(char c) { mContent = c; }
    bool wordMarker() { return mMarker; }
    void setWordMarker() { mMarker = true; }
    Node* findChild(char c);
    void appendChild(Node* child) { mChildren.push_back(child); }
    vector<Node*> children() { return mChildren; }

private:
    char mContent;
    bool mMarker;
    vector<Node*> mChildren;
};

class Trie {
public:
    Trie();
    ~Trie();
    void addWord(string s);
    bool searchWord(string s);
    void deleteWord(string s);
    //int exclude_first_letter(string s);
private:
    Node* root;
};

Node* Node::findChild(char c)
{
    for ( int i = 0; i < mChildren.size(); i++ )
    {
        Node* tmp = mChildren.at(i);
        if ( tmp->content() == c )
        {
            return tmp;
        }
    }

    return NULL;
}

Trie::Trie()
{
    root = new Node();
}

Trie::~Trie()
{
    // Free memory
}

void Trie::addWord(string s)
{
    Node* current = root;

    if ( s.length() == 0 )
    {
        current->setWordMarker(); // an empty word
        return;
    }

    for ( int i = 0; i < s.length(); i++ )
    {
        Node* child = current->findChild(s[i]);
        if ( child != NULL )
        {
            current = child;
        }
        else
        {
            Node* tmp = new Node();
            tmp->setContent(s[i]);
            current->appendChild(tmp);
            current = tmp;
        }
        if ( i == s.length() - 1 )
            current->setWordMarker();
    }
}


bool Trie::searchWord(string s)
{
    Node* current = root;

    while ( current != NULL )
    {
        for ( int i = 0; i < s.length(); i++ )
        {
            Node* tmp = current->findChild(s[i]);
            if ( tmp == NULL )
                return false;
            current = tmp;
        }

        if ( current->wordMarker() )
            return true;
        else
            return false;
    }

    return false;
}

void fourC() {

    Trie* trie = new Trie();

    ifstream dict("dictionary.txt");
    ifstream data("BigDataTest.txt");
    string word;
	string wrds;
	string letter = "e";
	string capletter = "E";
	vector <string>  wordsWithoutLetter;

    int counter = 0;

	while (dict >> word){
		trie->addWord(word);

		if (strstr(word.c_str(),letter.c_str()) || strstr(word.c_str(),capletter.c_str())){
			//do nothing
		}
		else {
			if (trie->searchWord(word)==true){
				wordsWithoutLetter.push_back(word);
				//cout << word << endl; 
			}}}
	while ( data >> wrds){
		for (int i = 0; i < wordsWithoutLetter.size(); i++) {
			if (wrds.compare(wordsWithoutLetter[i]) == 0) {
				counter++;
			}
		}
	}

	cout << endl << "The number of words not containing 'E' is " << counter << endl;
}

int main()
{
	//fourA();
	//fourB();
	fourC();
	return 0;
}