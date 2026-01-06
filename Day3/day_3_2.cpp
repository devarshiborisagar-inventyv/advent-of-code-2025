#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;


// string extract_big_num(string number , int k , int curr_size , int n , int i , string curr_number){
//     if(curr_size>=k){
//         return curr_number;
//     }
//     if(i>=n){
//         return "";
//     }

//     curr_number.push_back(number[i]);
//     string num1=extract_big_num(number , k ,  curr_size+1, n, i+1 , curr_number);
//     curr_number.pop_back();
//     string num2=extract_big_num(number , k ,  curr_size , n , i+1 , curr_number);

//     if(num1>=num2){
//         return num1;
//     } 
//         return num2;


// }


int main()
{

    string filename = "input.txt";
    ifstream file(filename);
    int curr = 50;
    long long count = 0;
    int line_conunt = 0;

    if (file.is_open())
    {
        string line;

        long long ans=0;

        clock_t start, end;
        start = clock();

        while (getline(file, line))
        {
             if (!line.empty() && line.back() == '\r') {
                line.pop_back();
                
            }
            int n=line.size();
            vector<vector<string>>dp(n+1,vector<string>(13,""));
            for(int i=1 ; i<=n ; i++){
                for(int j=1 ; j<=12 ; j++){

                    string num2=dp[i-1][j-1];

                    num2.push_back(line[i-1]);

                    dp[i][j] = dp[i-1][j] > num2 ? dp[i-1][j] : num2;
                }

                // 170418192256861
                // 170418192256861

            }
            ans+=stoll(dp[n][12]);
        }
        end = clock();

        double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        std::cout << "CPU time used: " << cpu_time_used << " seconds" << std::endl;
        cout<<ans<<endl;
    }
}