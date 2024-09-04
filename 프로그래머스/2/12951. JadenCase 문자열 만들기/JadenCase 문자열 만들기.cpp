#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string solution(string s) {
    bool first = true;
    
    for(auto& c : s)
    {
        if(first && c != ' ')
        {
            c = toupper(c);
            first = false;
        }
        else if (c == ' ' && !first)
            first = true;
        else
            c = tolower(c);
    }

    return s;
}