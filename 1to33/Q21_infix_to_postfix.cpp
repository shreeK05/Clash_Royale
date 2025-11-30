// 21) Write a program to convert Infix Expression into Postfix Expression. Ensure your implementation handles parentheses, multi-digit operands, and input errors gracefully.
// Concept used: Stack-based expression conversion using operator precedence and scanning characters to build tokens.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

string infixToPostfix(string s) {
    stack<char> st;
    string post = "";

    for (int i = 0; i < (int)s.length(); i++) {

        // Skip spaces
        if (s[i] == ' ') continue;

     
        if (isdigit(s[i])) {
            while (i < (int)s.length() && isdigit(s[i])) {
                post += s[i];
                i++;
            }
            post += ' ';
            i--;
        }

        else if (s[i] == '(') {
            st.push(s[i]);
        }
  
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                post += st.top();
                post += ' ';
                st.pop();
            }
            st.pop(); 
        }
  
        else if (isOperator(s[i])) {
            while (!st.empty() && prec(st.top()) >= prec(s[i])) {
                post += st.top();
                post += ' ';
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        post += st.top();
        post += ' ';
        st.pop();
    }

    return post;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
