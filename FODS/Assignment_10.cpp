#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
#define MAX 50
template<class T>
class Stack
{
    public:
        T data[MAX];
        int top;
    public:
        Stack()
        {
            top=-1;
        }
        int empty()
        {
            if(top==-1)
            {
                return 1;
            }
            return 0;
        }
        int full()
        {
            if(top==MAX-1)
            {
                return 1;
            }
            return 0;
        }
        void push(T x)
        {
            if(full()==1)
            {
                cout<<"\nStack is full";
            }
            else
            {
                top++;
                data[top]=x;
            }
        }
        T peek()
        {
            if(empty())
            {
                cout<<"\nStack is empty";
                return -1;
            }
            return data[top];
        }
        T pop()
        {
            T x;
            if(empty()==1)
            {
                cout<<"\nCan't Pop'";
                return -1;
            }
            else
            {
                x=data[top];
                top--;
                return x;
            }
        }
};

class Polish
{
    Stack<char> opStack; 
    Stack<int> evalStack;
    public: 
        int priority(char op)
        {
            if(op=='+'||op=='-')
            {
                return 1;
            }
            else if(op=='*'||op=='/')
            {
                return 2;
            }
            else if(op=='^')
            {
                return 3;
            }
            return 0;
        }
        bool isOperator(char c) 
        {
            return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
        }
        void reverse(char *exp) 
        {
            int len = strlen(exp);
            for (int i=0; i<len/2; i++) 
            {
                char temp = exp[i];
                exp[i] = exp[len-i-1];
                exp[len-i-1] = temp;
            }
        }

        void infixToPostfix(char *infix, char *postfix) 
        {
            int i = 0, k = 0;
            opStack.top = -1; 
                
            while(infix[i] != '\0') 
            {
                if(isdigit(infix[i])) 
                {
                    while(isdigit(infix[i]))
                    {
                        postfix[k++] = infix[i++];
                    }
                    postfix[k++] = ' '; 
                    i--; 
                }
                else if(infix[i] == '(') 
                {
                    opStack.push(infix[i]);
                }
                else if(infix[i] == ')') 
                {
                    while(!opStack.empty() && opStack.peek() != '(') 
                    {
                        postfix[k++] = opStack.pop();
                        postfix[k++] = ' '; 
                    }
                    if(opStack.empty()) 
                    {
                        cout<<"Invalid Expression: Unmatched Parentheses\n";
                        exit(1);
                    }
                    opStack.pop(); 
                }
                else if(isOperator(infix[i])) 
                {
                    postfix[k++] = ' '; 
                    while(!opStack.empty() && opStack.peek() != '(' && priority(opStack.peek()) >= priority(infix[i])) 
                    {
                        postfix[k++] = opStack.pop();
                        postfix[k++] = ' ';
                    }
                    opStack.push(infix[i]);
                }
                else if(isspace(infix[i])) 
                {
                    // Skip spaces
                }
                else 
                {
                    cout<<"Invalid Character: "<<infix[i]<<endl;
                    exit(1);
                }
                i++;
            }
                
            while(!opStack.empty()) 
            {
                if(opStack.peek() == '(') 
                {
                    cout<<"Invalid Expression: Unmatched Parentheses\n";
                    exit(1);
                }
                postfix[k++] = opStack.pop();
                postfix[k++] = ' '; 
            }
            postfix[k] = '\0';
        }
        void infixToPrefix(char infix[], char prefix[]) 
        {
            char infix_copy[MAX];
            strcpy(infix_copy, infix);
            reverse(infix_copy);
            for(int i = 0; infix_copy[i]!='\0'; i++) 
            {
                if(infix_copy[i] == '(') 
                {
                    infix_copy[i] = ')';
                }
                else if(infix_copy[i] == ')') 
                {
                    infix_copy[i] = '(';
                }
            }
                
            char temp_postfix[MAX];
            infixToPostfix(infix_copy, temp_postfix);
            reverse(temp_postfix);
                
            strcpy(prefix, temp_postfix);
        }

        int evalPostfix(char *postfix) 
        {
            evalStack.top = -1; 
            
            for(int i=0; postfix[i]; i++) 
            {
                if(isdigit(postfix[i])) 
                {
                    int num = 0;
                    while(isdigit(postfix[i])) 
                    {
                        num = num * 10 + (postfix[i] - '0');
                        i++;
                    }
                    evalStack.push(num);
                }
                else if(isOperator(postfix[i])) 
                {
                    if(evalStack.top < 1) 
                    {
                        cout<<"Invalid Expression: Not enough operands for operator\n";
                        exit(1);
                    }
                    int b = evalStack.pop(); // Operand 2 (RHS)
                    int a = evalStack.pop(); // Operand 1 (LHS)
                    
                    int result;
                    switch (postfix[i]) 
                    {
                        case '+': 
                            result = a + b; break;
                        case '-': 
                            result = a - b; break;
                        case '*': 
                            result = a * b; break;
                        case '/':
                            if (b == 0) 
                            {
                                cout<<"Division by zero error\n";
                                exit(1);
                            }
                            result = a / b; break;
                        case '^': 
                            result = (int)pow((double)a, (double)b); break;
                        default: 
                            result = 0; 
                    }
                    evalStack.push(result);
                }
            }
            
            if(evalStack.top != 0) 
            {
                cout<<"Invalid Expression: Too many operands left\n";
                exit(1);
            }
            return evalStack.pop();
        }
        int evalPrefix(char *prefix) 
        {
            evalStack.top = -1;
            int len = strlen(prefix);

            for(int i=len-1; i>=0; i--) 
            {
                if(isspace(prefix[i])) 
                {
                    continue;
                }

                if(isdigit(prefix[i])) 
                {
                    int num = 0, place = 1;
                    while(i>=0 && isdigit(prefix[i])) 
                    {
                        num += (prefix[i] - '0') * place;
                        place *= 10;
                        i--;
                    }
                    i++; 
                    evalStack.push(num);
                }
                else if(isOperator(prefix[i])) 
                {
                    int a = evalStack.pop();
                    int b = evalStack.pop();
                    int result;

                    switch(prefix[i]) 
                    {
                        case '+': 
                            result = a + b; 
                            break;
                        case '-': 
                            result = a - b; 
                            break;
                        case '*': 
                            result = a * b; 
                            break;
                        case '/':
                            if(b == 0) 
                            {
                                cout<<"Division by zero error\n";
                                exit(1);
                            }
                            result = a / b; 
                            break;
                        case '^': 
                            result = pow(a, b); 
                            break;
                    }
                    evalStack.push(result);
                }
            }

            return evalStack.pop();
        }

};
int main()
{   
    char infix[MAX], postfix[MAX], prefix[MAX];
    Polish p; 
    
    cout<<"Enter infix expression: ";
    cin.getline(infix, MAX);

    p.infixToPostfix(infix, postfix);
    p.infixToPrefix(infix, prefix); 

    cout<<"\nPostfix: "<<postfix<<endl;
    cout<<"Prefix: "<<prefix<<endl;

    int result = p.evalPostfix(postfix);
    cout<<"\nResult (Postfix Evaluation): "<<result<<endl;
    int pre_result = p.evalPrefix(prefix);
    cout<<"Result (Prefix Evaluation): "<<pre_result<<endl;
    
    
    return 0;
}
