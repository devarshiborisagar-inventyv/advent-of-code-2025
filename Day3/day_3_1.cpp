#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

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


        while (getline(file, line))
        {
             if (!line.empty() && line.back() == '\r') {
                line.pop_back();
                
            }
            
            
            cout << "Read line: " << line << std::endl;
            
            
            int n = line.size();

            char maxi = -1;
            int max_index = -1;
            char maxi_two = -1;
            int max_index_two = -1;
            string number="";

            for (int i = 0; i < n; i++)
            {

                if (line[i] > maxi)
                {
                    maxi = line[i];
                    max_index = i;
                }
            }

            cout<<n<<endl;

            if (max_index == n - 1)
            {

                for (int i = 0; i < n - 1; i++)
                {

                    if (line[i] > maxi_two)
                    {
                        maxi_two = line[i];
                        max_index_two = i;
                    }
                }

                 number.push_back(maxi_two);
                number.push_back(maxi);
               


            }
            else
            {

                for (int i = max_index + 1; i < n ; i++)
                {
                    if (line[i] > maxi_two)
                    {
                        maxi_two = line[i];
                        max_index_two = i;
                    }
                }

                number.push_back(maxi);
                number.push_back(maxi_two);

                
            }


            cout<<number<<endl;
           long long num_to_add=stoll(number);
           ans+=num_to_add;  
        
        }

        cout<<ans<<endl;
    }
}