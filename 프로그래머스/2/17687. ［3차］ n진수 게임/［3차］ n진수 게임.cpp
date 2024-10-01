#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <iostream>
using namespace std;

// 2진법으로 4개를 미리 구하는데 2명이서 내가 첫번째
// 0 1 10 11 100
// 0 1  2  3   4
// 0111 -> 종료 
// 16진법으로 16개를 미리구하는데 2명이서 내가 첫번째
// 0 2 4 6 8 A C E 1 1 1 1 1 1 1 1 1

// 풀이과정
// 일단 구할숫자의 개수는 
// 0부터 시작해서 쭉 올라가는데
// 만약에 10이 나오고 3진법이다
// 10%3 == 1
// 10 /= 3 = 3
// 3%3 == 0
// 3 /= 3 = 1
// 101 이걸 string화 해서 answer에 넣어주고
// '하나씩'
// 100이면
// 100 % 16 == 4
// 100 /= 16 = 6
// 6 %16 == 6
// 6 /= 16 = 0
// 064
map<int,char> ten;

string Convert(int n, int num)
{
    string str;
    
    if(num == 0)
        str = "0";

    while(num > 0)
    {
        int remain = num%n;
        num /= n;
        if(remain >= 10)
            str = ten[remain] + str;
        else
            str = ten[remain] + str; 
    }
    
    return str;
}

string solution(int n, int t, int m, int p) {
    for(int i = 10; i < 16; ++i)
        ten[i] = i+55;
    for(int i = 0; i < 10; ++i)
        ten[i] = i + '0';
    
    string answer = "";
    int cnt = 0;
    int turn = 1;
    int valid = true;
    
    if(m==p)
        p = 0;
    
    while(valid)
    {
        string str = Convert(n, cnt);
        for(int i = 0; i < str.size(); ++i)
        {
            if(turn%m == p)
                answer += str[i];
            
            if(answer.size() == t)
            {
                valid = false;
                break;
            }
            
            turn++;
        }
        
        if(!valid) // 종료조건 그만해도된다.
            break;
        
        cnt++; // 그게 아니라면 다음것도 확인해야한다.
    }
    
    return answer;
}