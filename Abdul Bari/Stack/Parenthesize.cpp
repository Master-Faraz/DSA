#include <iostream>
#include <stack>

using namespace std;

void check(string s);

int main()
{
    string s = "[]){";
    check(s);

    return 0;
}

void check(string s)
{
    stack<char> st;
    int top = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
            top++;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        else if (st.empty())
        {
            cout << "Parenthesis not balacned -_-" << endl;
            return;
        }
        /*  Ascii code ->

        "(" --> 40
        ")" --> 41

        "[" --> 91
        "]" --> 93

        "{" --> 123
        "}" --> 125

        */
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            char c = st.top();
            if ((s[i] ==']' && c != '[')||(s[i] =='}' && c != '{')||(s[i] ==')' && c != '('))
            {
                cout << "Parenthesis not balanced -_- " << endl;
                return;
            }
            else
            {
                st.pop();
                top--;
            }
        }
    }

    if (top == 0)
    {
        cout << "Parenthesis is balanced " << endl;
    }
    else
    {
        cout << "Parenthesis not balanced -_- " << endl;
    }
}