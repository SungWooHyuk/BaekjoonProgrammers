#include <string>
#include <vector>

using namespace std;
int answer = 0;
int cnt = -1;
string AEIOU = "AEIOU";
string target = "";
void dfs(string word) 
{
    if(answer == cnt)
        return;
    
    for(int i = 0; i < 5; ++i)
    {
        word = word + AEIOU[i];
        answer++;
        
        if(target == word)
            cnt = answer;
        
        if(word.length() < 5)
            dfs(word);
        
        word.pop_back();
    }   
}
int solution(string word) {   
    target = word;
    dfs("");
    return cnt;
}