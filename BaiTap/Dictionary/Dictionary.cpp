#include <iostream>
#include <string.h>
#include <map>

using namespace std;

struct WORD
{
    string Name;
    string Meaning;
};

void display(WORD dictionary[3]);
void Search(WORD dictionary[3], string word);

int main(int argc, char const *argv[])
{
    WORD dictionary[3] = {{"Binary", "Nhi phan"}, {"two", "hai"}, {"three", "ba"}};

    display(dictionary);

    string word;
    cout << "input word: ";
    cin >> word;

    Search(dictionary, word);

    return 0;
}

void Search(WORD dictionary[3], string word) {
    bool found = false;
    int flags = 0;
    for (int i = 0; i < 3; i++) {
        if (dictionary[i].Name == word) {
            found = true;
            flags = i;
            break;
        }
    }

    if (found) {
        cout << word << ": " << dictionary[flags].Meaning << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
}
