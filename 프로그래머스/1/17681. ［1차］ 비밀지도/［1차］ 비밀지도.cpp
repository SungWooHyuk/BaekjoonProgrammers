#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    int firstGraph[n][n];
    int secondGraph[n][n];
    
    for(int i = 0; i < arr1.size(); ++i)
    {
        int k = arr1[i];
        int num = 0;
        string str;
        for(int z = 0; z < n; ++z)
        {
            int remainder = k%2;
            str = to_string(remainder) + str;
            k /= 2;
        }
        
        for(int j = 0; j < str.size(); ++j)
        {
            firstGraph[i][j] = str[j] - '0';
        }

    }
    
    for(int i = 0; i < arr2.size(); ++i)
    {
        int k = arr2[i];
        int num = 0;
        string str;
        for(int z = 0; z < n; ++z)
        {
            int remainder = k%2;
            str = to_string(remainder) + str;
            k /= 2;
        }
        
        for(int j = 0; j < str.size(); ++j)
        {
            secondGraph[i][j] = str[j] - '0';
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        string str;
        for(int j = 0; j < n; ++j)
        {
            if(firstGraph[i][j] != 0 || secondGraph[i][j] != 0)
            {
                str = str + '#'; 
            }
            else
            {
                str = str + ' ';
            }
        }
        answer.push_back(str);
    }
    
    return answer;
}