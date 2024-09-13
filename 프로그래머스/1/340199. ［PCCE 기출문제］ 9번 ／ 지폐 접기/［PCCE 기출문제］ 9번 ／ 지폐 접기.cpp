// 항상 긴쪽을 반으로 접음
// 정수로만 계산하고 그냥 회전해서 넣을 수 있으면 그만
// 최소를 구하기 지갑과 지폐는 1장식만있음
// 지갑의 큰값이 bill의 큰 값보다 작으면 무조건 접어야
// 
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    sort(wallet.begin(), wallet.end()); // 오름차순 정렬
    sort(bill.begin(), bill.end());
    while(1)
    {
        if(wallet[0] < bill[0] || wallet[1] < bill[1])
        {
            bill[1] /= 2;
            if(bill[0] > bill[1])
            {
                int temp = bill[0];
                bill[0] = bill[1];
                bill[1] = temp;
                
            }
            answer+=1;
        }
        else
            break;
    }
    
    return answer;
}