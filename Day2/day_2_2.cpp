#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream file("input.txt");

    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }

    string line;
    getline(file, line);  
    file.close();

    stringstream ss(line);
    string range;

    long long sum=0;

    while (getline(ss, range, ',')) {   
        size_t dashPos = range.find('-');

        if (dashPos == string::npos) continue;

        long long start = stoll(range.substr(0, dashPos));
        long long end   = stoll(range.substr(dashPos + 1));


        for(long long i=start ; i<=end ; i++){

            string num=to_string(i);

            long long half=num.size()/2;

            for(int stried=1 ; stried<=half ; stried++){

            if(num.size()%stried!=0){
                continue;
            }

            long long count=0;

            
            long long no_of_comparison=(num.size()/stried)-1;
           

            for(long long j=0 ; j<stried ; j++){
                
                long long inner_count=0;

                for(long long k=j+stried ; k<num.size() ; k+=stried){

                    if(num[k]==num[k-stried]){
                        inner_count++;
                    }

                }

                if(inner_count==no_of_comparison){
                    count++;
                }
                

            }

            if(count==stried){
                cout<<i<<endl;
                sum+=i;
                break;
            }

        }

        }
    }

    cout<<sum<<endl;

    return 0;
}
