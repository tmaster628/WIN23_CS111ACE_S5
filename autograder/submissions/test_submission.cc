#include <iostream>
#include <string>

using namespace std;

string rev(const string &str) {
    if (str == "") return "";
    return rev(str.substr(1)) + str[0];
}

int main (int argc, char *argv[]) {

    if (argc != 2) {
        cout << "Error, # args provided is NOT 1" << endl;
        exit(0);
    }
    string str = string(argv[1]);
    str = rev(str);
    cout << str << endl;

    return 0;
}