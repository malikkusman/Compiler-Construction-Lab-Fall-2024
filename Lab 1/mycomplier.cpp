#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
    for (int i = 1; i < argc; i++){
        string a = argv[i];
        string line;
        ifstream file(a);

       
        while(getline(file, line)){
            cout << line << endl;
        }

        file.close();
    }
    return 0;
}
