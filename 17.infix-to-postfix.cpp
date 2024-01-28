#include <bits/stdc++.h>

using namespace std;

map<char, int> prec = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'^', 3},
};

stack<char> op;
string postfix = "";

bool closingBracket(char c)
{
    return !op.empty() && c == ')' && op.top() != '(';
}

bool stHasHighPrec(char c)
{
    return !op.empty() && prec[op.top()] >= prec[c];
}

void shift()
{
    char top = op.top();
    if (top != '(')
    {
        postfix += top;
    }
    op.pop();
}

int main(int argc, char const *argv[])
{
    string infix;
    cin >> infix;

    for (char &c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
            continue;
        }

        if (c == '(')
        {
            op.push(c);
            continue;
        }

        while (closingBracket(c) || stHasHighPrec(c))
        {
            shift();
        }

        if (c != ')')
        {
            op.push(c);
        }
    }

    while (!op.empty())
    {
        shift();
    }

    cout << postfix << endl;

    return 0;
}
