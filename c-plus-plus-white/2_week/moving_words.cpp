#include <iostream>
#include <string>
#include <vector>
using namespace std;

void    MoveStrings(vector<string>& source, vector<string>& destination)
{
    for (auto word : source)
        destination.push_back(word);
    source.clear();
}

int     main(void)
{
    vector<string> words = {"hi", "hello"};
    vector<string> pro = {"hey", "hola"};
    cout << "words size - " << words.size() << endl;
    cout << "pro size - " << pro.size() << endl;
    MoveStrings(words, pro);
    cout << "after" << endl;
    cout << "words size - " << words.size() << endl;
    for (auto word : pro)
        cout << word << ", ";
    return (0);
}