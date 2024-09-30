#include <string>
#include <cctype>
#include <unordered_map>
#include <iostream>
#include <cmath>
using namespace std;
// 자카드 유사도 - J(A,B) 는 두 집합의 교집합 크기를 두 집합의 합집합 크기로 나눈값
// 공집합은 1로 정의, double형도 필요
// 원소의 중복을 허용하는 다중집합에도 확장 가능.
// min -> 교집합 max -> 합집합
// 교집합을 구한 뒤 A에서 교집합과 빠진거 더하고 B에서도 같은 작업
// 문자열은 2글자씩 끊어서 다중집합 만들기
// 영문자로된 글자쌍만 유효 / 공백,숫자,특수문자는 버린다.
// 대소문자는 그냥 같은걸로 취급
// double이 아니라. 다루기쉽도록 유사도값에 65536을 곱하고 정수부만 출력한다.
// 아 그냥 특수문자같은게 껴있으면 무조건 버려야함.
// 오직 isalpha 2번이 연속으로 나와야함.

// 일단 str1과 str2를 읽을껀데 무조건 2개씩 읽는거야
// vector ? map ?
// vector에 넣고 size비교 및 작은거사이즈만큼 교집합 
// 비교하고 이제 
// 교집합뺀 사이즈들을 더해서 합집합 만들어주고
// 아 vector로 진행하겠음.
int solution(string str1, string str2) {
    double answer = 0.f;
    double min = 0.f;
    double max = 0.f;
    unordered_map<string, int> m;
    unordered_map<string, int> m2;
    int m_cnt= 0;
    int m2_cnt = 0;
    for(int i = 0; i < str1.size(); ++i)
    {
        if(isalpha(str1[i]))
        {
            if(isalpha(str1[i+1]) && i < str1.size())
            {
                string str;
                str += tolower(str1[i]);
                str += tolower(str1[i+1]);
               
                m[str]++;
                m_cnt++;
            }
        }
    }
    
    for(int i = 0; i < str2.size(); ++i)
    {
        if(isalpha(str2[i]))
        {
            if(isalpha(str2[i+1]) && i < str2.size())
            {
                string str;
                str += tolower(str2[i]);
                str += tolower(str2[i+1]);
                m2[str]++;
                m2_cnt++;
            }
        }
    }
    
    if(m_cnt > m2_cnt)
    {
        unordered_map<string,int> temp(m);
        m = m2;
        m2 = temp;
    }
    
    
    for(auto n : m)
    {
        while(m[n.first] > 0)
        {
            if(m2[n.first] > 0) // 존재
            {
                m2[n.first]--;
                m[n.first]--;
                min++;
            }
            else
                break;
        }
        
    }

    max = m_cnt + m2_cnt - min;
    
    if(min== 0 && max ==0){
        min = 1;
        max = 1;
    }
    
    answer = (min/max)*65536.f;
      
    
    return floor(answer);
}