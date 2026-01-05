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

            if((num.size()%2)!=0){
                continue;
            }

            long long half=num.size()/2;
            long long count=0;

            for(long long j=0 ; j<half ; j++){
                if(num[j]!=num[j+half]){
                    break;
                }
                count++;
            }

            if(count==half){
                sum+=i;
            }

        }

        cout << start << " " << end << endl;
    }

    cout<<sum<<endl;

    return 0;
}
