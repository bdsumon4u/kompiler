#include <bits/stdc++.h>

using namespace std;

// Syntax Tree
class SyntaxTree
{
    map<string, string> prods = {
        {"EAE", "E"},
        {"(E)", "E"},
        {"ID", "E"},
        {"+", "A"},
        {"-", "A"},
        {"*", "A"},
        {"/", "A"},
    };

    map<string, string> edges = {
        {"EAE", "/|\\"},
        {"(E)", "/|\\"},
        {"ID", "|"},
        {"+", "|"},
        {"-", "|"},
        {"*", "|"},
        {"/", "|"},
    };

    set<string> notID = {"A", "E", "ID"};

    int index = 0;
    bool idOrKey;
    string input;
    string stack;

    string ispace = "";
    vector<string> tree;

    string getIdOrInt(string str)
    {
        for (auto &key: notID)
        {
            if (str.substr(0, key.size()) == key)
            {
                return "";
            }
        }

        string token = "";
        idOrKey = isalnum(str[index]);
        while (index < str.size() && isalnum(str[index]))
        {
            token += str[index];
            index++;
        }

        index = 0;

        if (token.size())
        {
            return token;
        }

        while (input[index] >= '0' && input[index] <= '9')
        {
            token += input[index];
            index++;
        }

        return token;
    }

    bool reduce()
    {
        string espace = "";
        for (int i = 0; i < input.size(); i++)
        {
            if (i)
            {
                espace += " ";
            }

            string replace = "ID", token = getIdOrInt(input.substr(i));

            if (token.empty())
            {
                for (auto prod : prods)
                {
                    if (input.substr(i, prod.first.size()) == prod.first)
                    {
                        token = prod.first;
                        replace = prod.second;
                        break;
                    }
                }
            }

            if (token.size())
            {
                input.erase(i, token.size());
                input.insert(i, replace);

                string edge = edges.count(token) ? edges[token] : "|";

                tree.push_back(espace + ispace + edge);

                if (token.size() == 3)
                {
                    ispace += " ";
                }

                tree.push_back(ispace + input);

                return true;
            }
        }

        return false;
    }

public:
    SyntaxTree(string &input)
    {
        this->tree = {input};
        this->input = input;
        this->stack = "";
    }

    void validate()
    {
        while (input.size() > 1)
        {
            if (!reduce())
            {
                cout << "Syntax Error" << endl;
                return;
            }
        }

        while (!tree.empty())
        {
            cout << tree.back() << endl;
            tree.pop_back();
        }

        cout << "VALID" << endl;
    }
};

int main(int argc, char const *argv[])
{
    string exp;
    cin >> exp;

    SyntaxTree tree(exp);
    tree.validate();

    return 0;
}
