#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main() {
    string filename = "input.txt"; 
    ifstream file(filename);
    int curr=50;
    long long count=0;
    int line_conunt=0;

    if (file.is_open()) {
        string line;

        while (getline(file, line)) {
        
            char dir=line[0];

            int move=stoi(line.substr(1));

            if(dir=='L'){
                int flag=0;
                if(curr==0){
                    flag=1;
                }
                curr=(curr-move);
                int n=abs(curr/100);


                if(n>0){    
                    cout<<line<<endl;
                    count+=n;
                }    
                
                curr=curr%100;


                if(curr<0){
                    curr+=100;
                    if(!flag){
                        cout<<line<<endl;
                        count++;
                    }
                }
            }
            else{
                curr=(curr+move);
                
                
                cout<<line<<endl;
                count+=curr/100;

                curr=curr%100;

                if(curr==0){
                    count--;
                }

            }
            if(curr==0){
                cout<<line<<endl;
                count++;
            }
            line_conunt++;

        }

        file.close();

        cout<<line_conunt<<endl<<endl<<endl;

        cout<<count<<endl;
    } else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return 1; 
    }

    return 0;
}
