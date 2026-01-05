#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main() {
    string filename = "test.txt"; 
    ifstream file(filename);
    int curr=50;
    long long count=0;
    int line_conunt=0;

    if (file.is_open()) {
        string line;

        while (getline(file, line)) {
            cout << "Read line: " << line << std::endl;

            char dir=line[0];

            int move=stoi(line.substr(1));

            if(dir=='L'){
                curr=(curr-move)%100;
                if(curr<0){
                    curr+=100;
                }
            }
            else{
                curr=(curr+move)%100;

            }
            cout<<curr<<endl;
            if(curr==0){
                count++;
            }
            line_conunt++;

        }

        file.close();

        cout<<line_conunt<<endl;

        cout<<count<<endl;
    } else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return 1; 
    }

    return 0;
}
