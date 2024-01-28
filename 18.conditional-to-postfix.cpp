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

string inToPost(string infix)
{
    postfix.clear();
    for (char c : infix)
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

    return postfix;
}

string parse(string str, string ter = "")
{
    int thenIndex, elseIndex;

    if (str.substr(0, 3) == "if ")
    {
        thenIndex = str.find(" then ");
        return inToPost(str.substr(3, thenIndex - 3)) + parse(str.substr(thenIndex + 6)) + ter;
    }

    if ((elseIndex = str.find(" else ")) != -1)
    {
        return inToPost(str.substr(0, elseIndex)) + ter + parse(str.substr(elseIndex + 6), "?");
    }

    return inToPost(str) + ter;
}

int main(int argc, char const *argv[])
{
    // string str = "if a then if c-d then a+c else a*c else a+b"; // acd-ac+ac*?ab+?
    string str = "if a then if c-d then a+c else if b then q else a+b"; // acd-ac+bqab+??
    // string str = "if a-b+c then d"; // ab-c+d
    // string str = "if a then b else c"; // abc?
    // string str = "d^c"; // dc^

    cout << parse(str) << endl;

    return 0;
}
