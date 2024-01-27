#include <bits/stdc++.h>

using namespace std;

// Shift-Reduce Parser
class Parser
{
    map<string, string> prods = {
        {"E+E", "E"},
        {"E-E", "E"},
        {"E*E", "E"},
        {"E/E", "E"},
        {"(E)", "E"},
        {"id", "E"},
    };

    string input;
    string stack;

    void print(string data)
    {
        cout << setw(24) << left << data;
    }

public:
    Parser(string &input)
    {
        this->input = input + "$";
        this->stack = "$";
    }

    void parse()
    {
        cout << "STACK\t\t\tINPUT\t\t\tACTION" << endl;
        cout << "*********************** *********************** ***********************" << endl;

        while (true)
        {
            print(stack);
            print(input);
            if (input == "$" && stack == "$E")
            {
                cout << "ACCEPTED" << endl;
                break;
            }

            if (input.empty())
            {
                cout << "FAILED" << endl;
                break;
            }

            // Try to reduce
            string handle = "";
            int j = stack.size() - 1;
            while (j)
            {
                handle = stack[j] + handle;
                if (prods.count(handle))
                {
                    stack.erase(j, handle.size());
                    stack += prods[handle];
                    cout << "Reduce: " << handle << "->" << prods[handle] << endl;
                    break;
                }
                j--;
            }

            // Try to shift
            if (j == 0)
            {
                stack += input[0];
                cout << "Shift: " << input[0] << endl;
                input.erase(0, 1);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    string exp;
    cin >> exp;

    Parser parser(exp);
    parser.parse();

    return 0;
}
