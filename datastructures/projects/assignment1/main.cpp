#include <stdlib.h>
#include <string>
#include <vector>

#include "chain.cpp"

using namespace std;

int main() {

    // Instantiate new chain object
    chain<int>* nodeChain = new chain<int>();

    string line;

    // Read in text file line by line
    while( getline( cin, line ) ) {

        stringstream linestream;

        int value;
        int index;
        char c;

        int numberOfInsertions;
        int kthElementRemoved;
        int tempInt;
        vector<int> numbersToAddToHead;

        // Clear the linestream
        linestream.clear();
        // Fill linestream with a blank string
        linestream.str("");
        // Populate linestring with the current line from file
        linestream << line;

        switch(line[0]) {

            case 'I':

                // Move the 'I' to the temp character, and the numbers to value
                // and index
                linestream >> c >> value >> index;
                nodeChain->insert(index, value);

                break;

            case 'D':

                linestream >> c >> index;

                nodeChain->erase(index);
                break;

            case 'S':

                nodeChain->printAll();
                break;

            case 'P':

                linestream >> c >> index;

                nodeChain->printOne(index);
                cout << endl;
                break;

            case 'J':

                linestream >> c >> numberOfInsertions >> kthElementRemoved;

                while (linestream >> tempInt) {
                    numbersToAddToHead.push_back(tempInt);
                }

                nodeChain->josephusSimulation(numbersToAddToHead, kthElementRemoved);
                cout << endl;



                break;

        }
    }

    return 0;
}
