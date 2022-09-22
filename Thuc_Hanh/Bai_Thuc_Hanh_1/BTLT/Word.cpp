#include <iostream>
#include <string.h>

using namespace std;

struct WORD
{
    string Name;
    string Meaning;
};

void Search(WORD dictionary[3], string word);

int main(int argc, char const *argv[])
{
    WORD dictionary[3] = {{"Binary", "Nhi phan"}, {"two", "hai"}, {"three", "ba"}};

    string word;
    cout << "Search : ";
    cin >> word;

    Search(dictionary, word);

    return 0;
}

void Search(WORD dictionary[3], string word) {
    int flags = -1;
    for (int i = 0; i < 3; i++) {
        if (dictionary[i].Name == word) {
            flags = i;
            break;
        }
    }

    if (flags != -1) {
        cout << "Meaning : " << dictionary[flags].Meaning << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
}