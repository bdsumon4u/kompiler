#include <bits/stdc++.h>

using namespace std;

class Tokenizer
{
    string lexeme;

    set<string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
        "if", "else", "float", "for", "goto", "int", "long", "while", "return", "switch",
        // ... (list of all C++ keywords)
    };

    set<string> arithmetics = {
        "+", "-", "*", "/", "%",
    };

    set<string> relationals = {
        "!=", "<", ">", "<=", ">=", "==",
    };

    set<string> logicals = {
        "&&", "||", "!",
    };

    set<string> assignments = {
        "=", "+=", "-=", "*=", "/=", "%=",
    };

public:
    Tokenizer(string lexeme)
    {
        this->lexeme = lexeme;
    }

    string recognize()
    {
        if (keywords.count(lexeme))
        {
            return "Keyword";
        }
        if (arithmetics.count(lexeme))
        {
            return "Arithmetic Operator";
        }
        if (relationals.count(lexeme))
        {
            return "Relational Operator";
        }
        if (logicals.count(lexeme))
        {
            return "Logical Operator";
        }
        if (assignments.count(lexeme))
        {
            return "Assignment Operator";
        }
        if (regex_match(lexeme, regex("[a-zA-Z_][a-zA-Z0-9_]*")))
        {
            return "Identifier";
        }
        if (regex_match(lexeme, regex("\\d+(\\.\\d+)?")))
        {
            if (lexeme.find('.') == string::npos)
            {
                return "Integer";
            }

            if (regex_match(lexeme, regex("\\d+\\.\\d{2}\\d+")))
            {
                return "Double";
            }

            return "Float";
        }

        return "Special";
    }
};

int main()
{
    string lexeme;
    cin >> lexeme;

    Tokenizer tokenizer(lexeme);
    cout << tokenizer.recognize() << endl;

    return 0;
}
