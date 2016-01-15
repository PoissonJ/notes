#include <iostream>
#include <stdexcept>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;
using std::string;

class illegalIndex : public logic_error
{
public:
   illegalIndex(string message): logic_error(message) {}
};
