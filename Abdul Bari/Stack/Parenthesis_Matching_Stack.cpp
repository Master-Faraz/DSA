
#include <iostream>
#include <cstring>

using namespace std;

struct Stack
{
    int top;
    int size;
    char *s;
};

void display(struct Stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        cout << st.s[i] << endl;
    }
}

void push(struct Stack &st, int key)
{
    if (st.top == st.size - 1)
        cout << "Stack overflow" << endl;
    else
    {
        st.top++;
        st.s[st.top] = key; //        *******   Improtant    *******
    }
}

int pop(struct Stack &st)
{
    int key;
    if (st.top < 0)
        cout << "Stack underflow" << endl;
    else
    {
        key = st.s[st.top];
        st.s[st.top] = 0;
        st.top--;
    }
    return key;
}

int peek(struct Stack &st, int index)
{
    int x = -1;

    if (st.top - index + 1 < 0)
        cout << "Ïnvalid Index " << endl;
    else
        x = st.s[st.top - index + 1];

    return x;
}

int stack_top(struct Stack st)
{
    if (st.top >= 0)
        return st.s[st.top];
    else
        return -1;
}

int is_balance(Stack st, char c[]);

int main()
{
    char c[1000];
    cin >> c;

    Stack st;
    st.top = -1;
    st.size = strlen(c);
    st.s = new char[strlen(c)];

    cout << is_balance(st, st.s) << endl;

    return 0;
}

int is_balance(Stack st, char c[])
{
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] == '(')
        {
            push(st, '(');
            st.top++;
        }
        else if (c[i] == ')')
        {
            if (st.top <= 0) // .              Stack is empty
                return false;

            pop(st);
        }
    }

    return st.top == 0 ? true : false;
}