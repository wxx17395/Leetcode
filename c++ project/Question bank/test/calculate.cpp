#include <bits/stdc++.h>
using namespace std;

float calculate(string s){
    stack<float> st;
    char op = '+';
    int size = s.size();
    float res = 0, num = 0;
    for (int i = 0; i < size; ++i){
        char ch = s[i];
        if (isdigit(ch)){
            num = num * 10 + (ch - '0');
        } else if (ch == '('){
            int j = i, cnt = 0;
            for (; i < size; ++i){
                if (s[i] == '('){
                    ++cnt;
                } else if (s[i] == ')'){
                    --cnt;
                }
                if (cnt == 0){
                    num = calculate(s.substr(j + 1, i - j - 1));
                    break;
                }
            }
        }
        if (ch < '0' && ch != ' ' || i == size - 1){
            if (op == '+'){
                st.push(num);
            } else if (op == '-'){
                st.push(-num);
            } else if (op == '*' || op == '/'){
                float tmp = st.top();
                if (op == '*'){
                    tmp *= num;
                } else {
                    tmp /= num;
                }
                st.pop();
                st.push(tmp);
            }
            op = ch;
            num = 0;
        }
    }
    while (!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

int main()
{
    string s{"6+5/3"};
    cout << calculate(s) << endl;
    return 0;
}
