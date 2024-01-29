#include <bits/stdc++.h>

using namespace std;

// Parse Tree
class ParseTree
{
    map<string, string> prods = {
        {"E+E", "E"},
        {"E-E", "E"},
        {"E*E", "E"},
        {"E/E", "E"},
        {"(E)", "E"},
        {"a", "E"},
        {"b", "E"},
        {"c", "E"},
    };

    map<string, string> edges = {
        {"E+E", "/|\\"},
        {"E-E", "/|\\"},
        {"E*E", "/|\\"},
        {"E/E", "/|\\"},
        {"(E)", "/|\\"},
        {"a", "|"},
        {"b", "|"},
        {"c", "|"},
    };

    string input;
    string stack;

    string ispace = "";
    vector<string> tree;

    bool reduce()
    {
        string espace = "";
        for (int i = 0; i < input.size(); i++)
        {
            if (i)
            {
                espace += " ";
            }

            for (auto prod : prods)
            {
                if (input.substr(i, prod.first.size()) == prod.first)
                {
                    input.erase(i, prod.first.size());
                    input.insert(i, prod.second);

                    tree.push_back(espace + ispace + edges[prod.first]);

                    if (prod.first.size() == 3)
                    {
                        ispace += " ";
                    }

                    tree.push_back(ispace + input);

                    return true;
                }
            }
        }

        return false;
    }

public:
    ParseTree(string &input)
    {
        this->tree = {input};
        this->input = input;
        this->stack = "";
    }

    void generate()
    {
        while (input.size() > 1)
        {
            if (!reduce())
            {
                cout << "Parse Error" << endl;
                return;
            }
        }

        while (!tree.empty())
        {
            cout << tree.back() << endl;
            tree.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    string exp;
    cin >> exp;

    ParseTree tree(exp);
    tree.generate();

    return 0;
}
