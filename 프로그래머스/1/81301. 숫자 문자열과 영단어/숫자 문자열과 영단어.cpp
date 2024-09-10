#include <string>
#include <vector>
#include <cctype>
#include <map>
using namespace std;

// 알파벳일때 

int solution(string s) {
    int answer = 0;
    string str = "";
    map<string, int> alphabet;
    
    alphabet.insert({"zero", 0});
     alphabet.insert({"one", 1});
     alphabet.insert({"two", 2});
     alphabet.insert({"three", 3});
     alphabet.insert({"four", 4});
     alphabet.insert({"five", 5});
     alphabet.insert({"six", 6});
     alphabet.insert({"seven", 7});
     alphabet.insert({"eight", 8});
     alphabet.insert({"nine", 9});
    
    string temp = "";
    for(int i = 0; i < s.length(); ++i)
    {
        if(isdigit(s[i])) // 숫자 일때 그냥 넣어주기
            str += s[i];
        else // 알파벳 일때
        {
            temp += s[i];
            if(alphabet.find(temp) != alphabet.end())
            {    
                str += to_string(alphabet[temp]);
                temp = "";
            }
        }
    }
    return stoi(str);
}