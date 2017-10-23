#include <iostream>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void MergeFiles(string file1, string file2)
{
    ifstream fileone(file1);
    ifstream filetwo(file2);

    vector<string> results;
    string contents;

    while(fileone >> contents)
        results.push_back(contents);

    while(filetwo >> contents)
        results.push_back(contents);

    sort(results.begin(), results.end());

    for (int i=0; i < results.size();i++)
        cout << results[i] << endl;



}
int main (int argc, char* argv[])
{
    MergeFiles(argv[1],argv[2]);

    return 0;
}
