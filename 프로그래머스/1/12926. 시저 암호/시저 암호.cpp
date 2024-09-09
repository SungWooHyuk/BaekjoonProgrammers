#include <string>
#include <vector>
#include <iostream>

using namespace std;


string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ' ')
        {   
            answer += s[i];
            continue;
        }
        int num = static_cast<int>(s[i]);
        if(num < 91) // 소문자
        {
            if(num + n > 90)
            {
                int k = num+n-91;
                s[i] = 'A';
                for(int j = 0; j < k; ++j)
                    s[i]++;
            }
            else
            {
                for(int j = 0; j < n; ++j)
                    s[i]++;
            }
        }
        else{
            if(num + n > 122)
            {
                int k = num+n-123;
                s[i] = 'a';
                
                for(int j = 0; j < k; ++j)
                    s[i]++;
                
            }
            else
            {
                for(int j = 0; j < n; ++j)
                    s[i]++;
            }
        }
        
        answer += s[i];
    }
    
    return answer;
}