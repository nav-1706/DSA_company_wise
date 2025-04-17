#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    std::string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    std::stringstream ss(input);
    std::string line;

    while (getline(ss, line, '\n')) {
        cout<<line<<" "<<line.length()<<endl;
    }

    return 0;
}
