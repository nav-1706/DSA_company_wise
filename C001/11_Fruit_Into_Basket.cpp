#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "\t\tfile.ext";

    size_t lastTab = str.rfind('\t');

    if (lastTab != string::npos) {
        cout << "Last tab found at index: " << lastTab << "\n";
    } else {
        cout << "No tab found.\n";
    }

    cout<<"printing 1st char"<<str[1]<<endl;
    cout<<"Hello"<<endl;

    cout<<str.size()<<endl;

    return 0;
}
