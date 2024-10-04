#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>
using namespace std;
// 영문 대소문자, 숫자, 공백(" "), 마침표("."), 빼기 부호("-")
// 숫자가 오기전까지는 HEAD , 그 뒤에 NUMBER , 그 뒤에 TAIL
// HEAD의 대소문자 구분 X , NUMBER는 stoi를 이용해야함.
// 일단 HEAD를 먼저 떼고 분석해야한다. 일단 숫자가 없으니 isdigit이 아닐때까지
// 체크하면될것이고, isdigit이 나오는 순간부터 안나올때까지의 부분도 체크해서
// HEAD, NUMBER부분을 분리해준다. 나머지 부분들을 합해서 TAIL로 냅두고.
// 1단계는 HEAD끼리비교 -> 이게 같다? 그러면 2단계 NUMBER비교 -> 어? 냅두기.
// 1000개니까 그냥 
vector<string> solution(vector<string> files) {
   stable_sort(files.begin(), files.end(), [](const string& a, const string& b) {
        string head1, head2;
        string num1, num2;

        // HEAD 추출
        int i = 0;
        while (i < a.size() && !isdigit(a[i])) head1 += a[i++];
        int j = 0;
        while (j < b.size() && !isdigit(b[j])) head2 += b[j++];

        // HEAD를 소문자로 변환해서 비교
        transform(head1.begin(), head1.end(), head1.begin(), ::tolower);
        transform(head2.begin(), head2.end(), head2.begin(), ::tolower);

        // HEAD가 다르면 사전순으로 정렬
        if (head1 != head2) return head1 < head2;

        // NUMBER 추출
        while (i < a.size() && isdigit(a[i])) num1 += a[i++];
        while (j < b.size() && isdigit(b[j])) num2 += b[j++];

        // stoi를 사용하여 숫자 비교
        int n1 = stoi(num1);
        int n2 = stoi(num2);
        if (n1 != n2) return n1 < n2;

        // HEAD, NUMBER가 같다면 원래 순서 유지 (tail 비교는 하지 않음)
        return false;
    });
    return files;
}