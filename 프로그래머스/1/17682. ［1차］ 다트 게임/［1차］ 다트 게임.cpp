#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string dartResult) {
    vector<int> ret;  // To store the result of each throw
    int num = 0;      // To store the current score
    int answer = 0;   // Final answer
    
    for (int i = 0; i < dartResult.size(); ++i) {
        // Check if it's a digit (score)
        if (isdigit(dartResult[i])) {
            // If the digit is '1' and the next one is '0', it's 10
            if (dartResult[i] == '1' && dartResult[i+1] == '0') {
                num = 10;
                ++i;  // Skip the '0' in "10"
            } else {
                num = dartResult[i] - '0';  // Convert char digit to integer
            }
        }
        // Check for bonus (S, D, T)
        else if (isalpha(dartResult[i])) {
            if (dartResult[i] == 'D') {
                num = num * num;
            } else if (dartResult[i] == 'T') {
                num = num * num * num;
            }
            // Push the current score to the vector
            ret.push_back(num);
        }
        // Check for options (* or #)
        else {
            if (dartResult[i] == '*') {
                // Double the current and the previous score
                if (!ret.empty()) {
                    ret[ret.size() - 1] *= 2;
                }
                if (ret.size() > 1) {
                    ret[ret.size() - 2] *= 2;
                }
            } else if (dartResult[i] == '#') {
                // Make the current score negative
                ret[ret.size() - 1] *= -1;
            }
        }
    }
    
    // Sum up the scores
    for (int n : ret) {
        answer += n;
    }
    
    return answer;
}
