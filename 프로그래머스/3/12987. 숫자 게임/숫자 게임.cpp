#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int answer = 0;
    int a_p = 0;
    int b_p = 0;
    while(a_p != A.size() && b_p != B.size())
    {
        if(A[a_p] < B[b_p]) // B팀 승리
        {
            a_p++;
            b_p++;
            answer++;
        }
        else
            b_p++;
    }
    
    return answer;
}