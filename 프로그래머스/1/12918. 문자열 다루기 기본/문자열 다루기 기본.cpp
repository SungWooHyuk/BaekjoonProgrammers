#include <string>
#include <vector>
#include <cctype>
using namespace std;

bool solution(string s) {
    
    if(s.size() == 4 || s.size() == 6)
    {
        for(auto c : s)
            if(isalpha(c))
                return false;
        
        return true;
    }
    else
        return false;
    
}