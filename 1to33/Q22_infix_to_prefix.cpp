// 22) Write a program to convert Infix Expression into Prefix Expression. Ensure your implementation handles parentheses, multi-digit operands, and input errors gracefully.
// Concept used: Reverse-modify-reverse technique using infix-to-postfix on reversed expression and then reversing the token sequence.

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

string manualReverse(const string &s) {
    string rev = "";
    for (int i = s.length() - 1; i >= 0; i--)
        rev += s[i];
    return rev;
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

string infixToPostfix(string s) {
    stack<char> st;
    string post = "";

    for (int i = 0; i < (int)s.length(); i++) {

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
            while (!st.empty() && precedence(st.top()) >= precedence(s[i])) {
                post += st.top();
                post += ' ';
                st.pop();
            }
            st.push(s[i]);
        }
        else {
            return "ERROR: Invalid character!";
        }
    }

    while (!st.empty()) {
        post += st.top();
        post += " ";
        st.pop();
    }

    return post;
}

string infixToPrefix(string infix) {
 
    string rev = manualReverse(infix);

    for (int i = 0; i < (int)rev.length(); i++) {
        if (rev[i] == '(') rev[i] = ')';
        else if (rev[i] == ')') rev[i] = '(';
    }

    string postfix = infixToPostfix(rev);

    string prefix = manualReverse(postfix);

    return prefix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
