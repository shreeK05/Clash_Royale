// 23) Write a program to Evaluate Postfix Expression.
// Concept used: Stack-based evaluation of postfix expressions with multi-digit operands and arithmetic operators.

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;
    
    for (int i = 0; i < (int)exp.length(); i++) {

        if (exp[i] == ' ')
            continue;

        if (isdigit(exp[i])) {
            int num = 0;
            while (i < (int)exp.length() && isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            st.push(num);
            i--;  
        }
        else {
            
            if (st.size() < 2) {
                cout << "Invalid postfix expression!\n";
                return -1;
            }

            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int result = 0;

            switch (exp[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '%': result = a % b; break;
                default:
                    cout << "Invalid operator!\n";
                    return -1;
            }

            st.push(result);
        }
    }

    return st.top();
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    getline(cin, exp);

    int ans = evaluatePostfix(exp);
    cout << "Result = " << ans << endl;

    return 0;
}
