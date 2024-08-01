#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void toLowerCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

int main() {
    string paragraph;
    map<string, int> wordCount;
    cout << "Enter a paragraph: ";
    getline(cin, paragraph);

    stringstream ss(paragraph);
    string word;

    while (ss >> word) {
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        toLowerCase(word);
        if (!word.empty()) {
            wordCount[word]++;
        }
    }
    cout<<endl<<"Word Frequencies:"<<endl;
    for (const auto &entry : wordCount) {
        cout << entry.first << ": " << entry.second << endl;
    }
    return 0;
}
