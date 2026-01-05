#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


string extract_big_num(string number , int k , int curr_size , int n , int i , string curr_number){
    if(curr_size>=k){
        return curr_number;
    }
    if(i>=n){
        return "";
    }

    curr_number.push_back(number[i]);
    string num1=extract_big_num(number , k ,  curr_size+1, n, i+1 , curr_number);
    curr_number.pop_back();
    string num2=extract_big_num(number , k ,  curr_size , n , i+1 , curr_number);

    if(num1>=num2){
        return num1;
    } 
        return num2;


}


int main()
{

    string filename = "test.txt";
    ifstream file(filename);
    int curr = 50;
    long long count = 0;
    int line_conunt = 0;

    if (file.is_open())
    {
        string line;

        long long ans=0;


        while (getline(file, line))
        {
             if (!line.empty() && line.back() == '\r') {
                line.pop_back();
                
            }
            
            
            cout << "Read line: " << line << std::endl;
            int n=line.size();
            string number=extract_big_num(line , 12 ,  0 , n , 0  , "");
            cout<<number<<endl;


            //vector<vector<string>>dp(n+1,vector<string>(13,""));



            long long num_to_add=stoll(number);
           ans+=num_to_add;  


        }

        cout<<ans<<endl;
    }
}