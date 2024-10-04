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
tuple<string, string, string> splitFile(const string& file) {
    string head, number, tail;
    int i = 0;

    // HEAD 추출
    while (i < file.size() && !isdigit(file[i])) {
        head += file[i++];
    }

    // NUMBER 추출 (최대 5자리)
    int count = 0;
    while (i < file.size() && isdigit(file[i]) && count < 5) {
        number += file[i++];
        count++;
    }

    // TAIL 추출 (나머지 부분)
    tail = file.substr(i);

    return make_tuple(head, number, tail);
}

vector<string> solution(vector<string> files) {
    // stable_sort를 사용해 정렬
    stable_sort(files.begin(), files.end(), [](const string& a, const string& b) {
        // 파일을 HEAD, NUMBER, TAIL로 분리
        auto [head1, number1, tail1] = splitFile(a);
        auto [head2, number2, tail2] = splitFile(b);

        // HEAD를 소문자로 변환해서 비교
        transform(head1.begin(), head1.end(), head1.begin(), ::tolower);
        transform(head2.begin(), head2.end(), head2.begin(), ::tolower);

        // HEAD 비교
        if (head1 != head2) return head1 < head2;

        // NUMBER 비교 (숫자로 변환)
        int num1 = stoi(number1);
        int num2 = stoi(number2);

        if (num1 != num2) return num1 < num2;

        // HEAD와 NUMBER가 같으면 원래 순서를 유지
        return false;
    });

    return files;
}