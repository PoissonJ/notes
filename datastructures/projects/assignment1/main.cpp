#include <stdlib.h>
#include <string>
#include <vector>

#include "chain.cpp"

using namespace std;

int main() {
    chain<int>* nodeChain = new chain<int>();

    string line;
    while( getline( cin, line ) ) {

        vector<int> lineData;
        stringstream linestream;

        int value;
        int index;
        char c;

        int numberOfInsertions;
        int kthElementRemoved;
        int tempInt;
        vector<int> numbersToAddToHead;


        linestream.clear();
        linestream.str("");
        linestream << line;

        switch(line[0]) {

            case 'I':

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
                break;

            case 'J':

                linestream >> c >> numberOfInsertions >> kthElementRemoved;

                while (linestream >> tempInt) {
                    //cout << "Adding: " << tempInt << endl;
                    numbersToAddToHead.push_back(tempInt);
                }

                nodeChain->josephusSimulation(numbersToAddToHead, kthElementRemoved);

                break;

        }
    }

    return 0;
}
