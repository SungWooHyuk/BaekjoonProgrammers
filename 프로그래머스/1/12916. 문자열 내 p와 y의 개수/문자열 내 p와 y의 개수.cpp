#include <string>
#include <iostream>
using namespace std;

// s에 'p'의 개수와 'y'의 개수 비교
// 같으면 true 아니면 false
// 둘 다 없으면 true

bool solution(string ss)
{
    int s = 0;
    int y = 0;
    for(int i = 0; i < ss.length(); ++i)
    {
        if(ss[i] == 'P' || ss[i] == 'p')
            s++;
        else if(ss[i] == 'y' || ss[i] == 'Y')
            y++;
    }

    if(s == y || (s==0 && y ==0))
        return true;
    else 
        return false;
  
}