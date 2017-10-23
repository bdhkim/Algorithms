// EC 330 Assignment 6
// Dong Hyun Kim
// Edwardo Portet

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void fourA()
{
    ifstream inFile("BigData.txt");
    ofstream output("Problem4.txt");
    string words;
    int count = 0;

    while (inFile >> words) {
        if(string::npos == words.find_first_of("0123456789")){
            count++;
        }
    }

    output << "There are " << count << " words containing only letters in the BigData.txt file." << endl;

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

/*



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

    ofstream output;
    output.open("Problem4.txt", std::ios_base::app);

    Trie* trie = new Trie();

    ifstream dict("dictionary.txt");
	string word;

    int counter = 0;

	while (dict >> word){
		trie->addWord(word);

        if ( trie->searchWord("E")==false ){
        counter++;}

	}

    output << "\nThe number of words containing E is " << counter << "!" << endl;

}
*/
int main()
{
    fourA();
    fourB();
	//fourC();

	return 0;


}
