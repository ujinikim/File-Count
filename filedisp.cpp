#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{   
    string input = argv[1];
    string directories;
    string files;
    string bytes;
    getline(cin,directories);
    getline(cin,files);
    getline(cin,bytes);
    if(input == "-d"){
        cout << directories << "\n";
    }
    else if(input == "-f"){
        cout << files << "\n";
    }
    else if(input == "-b"){
        cout << bytes << "\n";
    }
    else
    cout << "Invalid Input\n";
    return 0;
}
