#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool IsValid(const string& str)
{
    int i = 0;
    for(auto& s : str)
    {
        if(i<0)
            break;
        if(s=='(')
            ++i;
        else
            --i;
    }
    if(i==0)
        return true;
    else
        return false;
}
string Revert(const string& str)
{
    if(str == "")
        return str;
    
    string u,v;
    int k = 0;
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == '(')
            k++;
        else
            k--;
        
        if(k==0){
            u+=str[i];
            v = str.substr(i+1);
            break;
        }
        else
            u += str[i];
    }
    
    if(IsValid(u)) 
        return u + Revert(v);
    else // 올바르지 않다면 
    {
        string sol = "(";
        sol = sol + Revert(v) + ')';
        u = u.substr(1, u.size()-2);
        for (char &c : u) {
            c = (c == '(') ? ')' : '(';
        }
        return sol + u;
    }
    
}

string solution(string p) {
    string answer = "";
    if(IsValid(p))
        return p;
    
    return Revert(p);
    
    //step 1 -> u랑 v로 분리 하는데 u를 균형잡힌 문자열로 더 이상 분리안되게끔 u,v나눠주기
    //step 2 -> 나눈 뒤 u가 올바른지 아닌지 체크해서 2가지 버전으로 나누기
    //step 3 -> 만약 올바르면 u를 기록하고 , v에 대해 다시 처음부터 진행해주고
    //step 4 -> 올바르지않으면 v에대해 재귀적으로 처리해준다.
    //step 5 -> 재귀적으로 나온 값을 ( ) 사이에 넣고 앞뒤를 삭제한 u를 + 해준다.
    //step 6 -> 이제 처음에 기록했던값부터 쭉 더해서 return을 해서 올바른 값을 만들어준다.
}