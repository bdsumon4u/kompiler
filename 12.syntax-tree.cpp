#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    char data;
    Node *left, *right;

    Node(char data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// Syntax Tree
class SyntaxTree
{
    vector<pair<char, vector<string>>> prods = {
        {'E', {"E+E", "E-E", "E*E", "E/E", "(E)", "a", "b", "c"}}
        // {'E', {"E+T", "E-T", "T"}},
        // {'T', {"T*F", "T/F", "F"}},
        // {'F', {"(E)", "a", "b", "c"}},
    };

    map<char, int> prec = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'^', 3},
    };

    string input;

    stack<char> op;
    string postfix = "";

    void precedence()
    {
        if (prods.size() == 1)
        {
            return;
        }

        int p = 1;
        for (auto &prod : prods)
        {
            for (string &body : prod.second)
            {
                if (body.size() == 3)
                {
                    if (!isalpha(body[1]))
                    {
                        prec[body[1]] = p;
                    }
                }
            }
            p++;
        }
    }

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

public:
    SyntaxTree(string &input)
    {
        this->input = input;

        precedence();

        inToPost(input);

        generate();
    }

    void generate()
    {
        Node *root = new Node(postfix.back());
        postfix.pop_back();
        stack<Node *> st;
        st.push(root);

        while (!st.empty())
        {
            auto top = st.top();

            char back = postfix.back();
            postfix.pop_back();

            if (!top->right)
            {
                top->right = new Node(back);
                if (!isalnum(back))
                {
                    st.push(top->right);
                }
                continue;
            }
            if (!top->left)
            {
                top->left = new Node(back);
                st.pop();
                if (!isalnum(back))
                {
                    st.push(top->left);
                }
            }
        }

        printTree(root);
    }

    void printTree(Node *root)
    {
        queue<Node *> q1, q2;
        q1.push(root);

        while (!q1.empty())
        {
            auto front = q1.front();
            q1.pop();

            cout << front->data << " ";

            if (front->left)
            {
                q2.push(front->left);
            }
            if (front->right)
            {
                q2.push(front->right);
            }
            if (q1.empty())
            {
                cout << endl;
                swap(q1, q2);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    string exp;
    cin >> exp;

    SyntaxTree tree(exp);

    return 0;
}
