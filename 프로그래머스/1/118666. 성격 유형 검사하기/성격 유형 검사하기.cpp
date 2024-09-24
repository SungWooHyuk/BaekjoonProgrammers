#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> m;
    m['R'] = 0;
    m['T'] = 0;
    m['C'] = 0;
    m['F'] = 0;
    m['J'] = 0;
    m['M'] = 0;
    m['A'] = 0;
    m['N'] = 0;
    
    for(int i = 0; i < survey.size(); ++i)
    {
        int k = choices[i];
        if(k == 4)
            continue;
        
        if(survey[i] == "AN")
        {
            if(k < 4)
                m['A'] += (4 - k);
            else
                m['N'] += k % 4;
        }
        else if(survey[i] == "NA")
        {
            if(k < 4)
                m['N'] += (4 - k);
            else
                m['A'] += k % 4;
        }
        else if(survey[i] == "CF")
        {
            if(k < 4)
                m['C'] += (4 - k);
            else
                m['F'] += k % 4;
        }
        else if(survey[i] == "FC")
        {
            if(k < 4)
                m['F'] += (4 - k);
            else
                m['C'] += k % 4;
        }
        else if(survey[i] == "MJ")
        {
            if(k < 4)
                m['M'] += (4 - k);
            else
                m['J'] += k % 4;
        }
        else if(survey[i] == "JM")
        {
            if(k < 4)
                m['J'] += (4 - k);
            else
                m['M'] += k % 4;
        }
        else if(survey[i] == "RT")
        {
            if(k < 4)
                m['R'] += (4 - k);
            else
                m['T'] += k % 4;
        }
        else if(survey[i] == "TR")
        {
            if(k < 4)
                m['T'] += (4 - k);
            else
                m['R'] += k % 4;
        }
    }
    
    if(m['R'] > m['T'])
        answer += 'R';
    else if(m['R'] < m['T'])
        answer += 'T';
    else
        answer += 'R';
    
    if(m['C'] > m['F'])
        answer += 'C';
    else if(m['C'] < m['F'])
        answer += 'F';
    else
        answer += 'C';
    
    if(m['M'] > m['J'])
        answer += 'M';
    else if(m['M'] < m['J'])
        answer += 'J';
    else
        answer += 'J';
    
    if(m['A'] > m['N'])
        answer += 'A';
    else if(m['A'] < m['N'])
        answer += 'N';
    else
        answer += 'A';
    
    return answer;
}