#include <string>
#include <vector>
#include <cctype>
#include <iostream>
// 3 <= length <= 15
// 소문자, 숫자, - _ . 가능
// .로 시작,끝은 안되고 연속도 불가능 예외체크

// 싹 다 소문자로
// 소문자 숫자 - _ . 빼고 제거.
// .이 2개이상이면 하나로 줄이고
// 처음이나 끝에 있으면 제거
// 빈 문자열이면 a를 대입
// 16자 이상이면 15개 이후는 싹 다 제거
// 여기서도 .이 마지막이면 요놈 제거
// 2자 이하면 마지막 문자 반복해서 3이 될 떄까지.

using namespace std;

string solution(string new_id) {
    string answer = "";
    int cnt = 0;
    while(1)
    {
        string newa = "";
        if(cnt == 7)
            break;
        
        if(cnt == 0)
        {
            for(auto n : new_id)
            {
                if(isalpha(n))
                    newa += tolower(n);
                else 
                    newa += n;
            }
        }
        else if(cnt == 1)
        {
            for(auto n : answer)
            {
                if(isdigit(n) || isalpha(n) || n == '-' || n =='.' || n =='_')
                    newa += n;
            }
        }
        else if(cnt == 2)
        {
            bool point = false;
            for(auto n : answer)
            {
                if(n == '.' && point)
                {
                    
                }
                else if(n == '.' && !point){
                    newa+=n;
                    point = true;
                }
                else
                {
                    point = false;
                    newa +=n;
                }
            }
        }
        else if(cnt == 3)
        {
            while(1)
            {
                int k = answer.size();
                if(answer[0] == '.')
                {
                    answer.erase(0,1);
                }
                else if(answer[k-1] == '.')
                {
                    answer.erase(k-1,1);
                }
                else
                    break;
            }
            cnt++;
            continue;
        }
        else if(cnt == 4)
        {
            if(answer == "")
                newa = 'a';
            else
            {
                cnt++;
                continue;
            }
        }
        else if(cnt == 5)
        {
            if(answer.size() > 15)
            {
                for(int i = 0; i < 15; ++i)
                    newa += answer[i];
                
                while(1)
                {
                    if(newa[newa.size()-1] == '.')
                        newa.erase(newa.size()-1,1);
                    else
                        break;
                }
            }
            else
            {
                cnt++;
                continue;
            }
        }
        else if(cnt == 6)
        {
            while(1)
            {
                if(answer.size() < 3)
                    answer += answer[answer.size()-1];
                else
                    break;
            }
            cnt++;
            continue;
        }
        
        cnt++;
        answer = newa;
    }
    
    return answer;
}