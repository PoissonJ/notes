#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main (void) {

    stringstream ss;
    char c;
    int foo;
    int foo2;
    string bar;
    string inp;

    while (getline (cin, inp)) {
        ss.clear ();
        ss.str (inp);

        ss >> c >> foo >> foo2;
        int number;
        while (ss >> number) {
            cout << number << endl;
        }
        //cout << foo << " " << foo2 << endl;
    }

    return 0;
}
