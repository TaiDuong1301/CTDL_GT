#include <iostream>
#include <fstream>  //A combination of ofstream and ifstream: creates, reads, and writes to files

using namespace std;

void writeFile(string filename, int num);
void readFile(string filename, int &num);

int main()
{
    int numIN = 1301, numOUT;
    string filename = "data.txt";

    writeFile(filename, numIN);

    readFile(filename, numOUT);

    cout << numOUT;

    return 0;
}

void writeFile(string filename, int num) {
    //open a text file
    ofstream f(filename);
    // write to the file
    f << num;
    //close the file
    f.close();
}

void readFile(string filename, int &num) {
    ifstream f(filename);

    f >> num;

    f.close();
}