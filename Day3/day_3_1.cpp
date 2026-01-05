#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

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

        

        while (getline(file, line))
        {
            cout << "Read line: " << line << std::endl;
            int n = line.size();

            char maxi = -1;
            int max_index = -1;

            for (int i = 0; i < n; i++)
            {

                if (line[i] > maxi)
                {
                    maxi = line[i];
                    max_index = i;
                }
            }

            if (max_index == n - 1)
            {

                char maxi_two = -1;
                int max_index_two = -1;

                for (int i = 0; i < n - 1; i++)
                {

                    if (line[i] > maxi)
                    {
                        maxi_two = line[i];
                        max_index_two = i;
                    }
                }


            }
            else
            {

                char maxi_two = -1;
                int max_index_two = -1;

                for (int i = max_index + 1; i < n - 1; i++)
                {

                    if (line[i] > maxi)
                    {
                        maxi_two = line[i];
                        max_index_two = i;
                    }
                }

                
            }

            cout << maxi << endl;
        }
    }
}