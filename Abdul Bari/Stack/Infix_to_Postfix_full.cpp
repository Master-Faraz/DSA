#include <iostream>
#include <stack>
using namespace std;

int isOperand(char x);
int out_precedance(char x);
int in_precedance(char x);

char *convert(string s);

int main()
{
    string s;
    cout << "enter the expression" << endl;
    cin >> s;

    char *postfix = convert(s);

    cout << "\nPostfix Expression :-> " << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << postfix[i] << " ";
    }
    cout << endl;
    return 0;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int out_precedance(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
}
int in_precedance(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
}

char *convert(string s)
{
    stack<char> st;
    int l = s.length() + 1; //.    +1 for /0

    char *postfix = new char[l]; // .  char array

    int i = 0, j = 0;
    while (i < s.length())
    {
        char c = s[i];
        // char top  = st.top();

        if (isOperand(s[i])) // .    not operator
        {
            postfix[j++] = c;
            i++;
        }
        else
        {
            if (st.empty())
            {
                st.push(c);
                i++;
            }
            else if (out_precedance(c) > in_precedance(st.top()))
            {
                st.push(c);
                i++;
            }
            else
            {
                if (out_precedance(c) == in_precedance(st.top()))
                {
                    st.pop();
                    i++;
                }
                else
                {
                    char del = st.top();
                    st.pop();
                    postfix[j++] = del;
                    i++;
                }
            }
        }
    }

    // Remaining operators in stack
    while (!st.empty())
    {
        char op = st.top();
        st.pop();
        postfix[j++] = op;
    }
    postfix[j] = '/0';

    return postfix;
}