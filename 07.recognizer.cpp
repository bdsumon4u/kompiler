#include <bits/stdc++.h>

using namespace std;

class Lexer
{
    bool idOrKey;
    string code;
    int index;

    vector<string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
        "if", "else", "float", "for", "goto", "int", "long", "while", "return", "switch",
        // ... (list of all C++ keywords)
    };

    vector<string> operators = {
        "+", "-", "*", "/", "%", "=", "!=", "<", ">", "<=", ">=", "==", "&&", "||",
        "++", "--", "+=", "-=", "*=", "/=", "%=", "<<", ">>", "&", "|", "^", "~", "!",
        // ... (list of all C++ operators)
    };

    bool isKeyword(string &token)
    {
        return find(keywords.begin(), keywords.end(), token) != keywords.end();
    }

    bool isIdentifier(string &token)
    {
        return regex_match(token, regex("[a-zA-Z_][a-zA-Z0-9_]*"));
    }

    bool isOperator(string &token)
    {
        return find(operators.begin(), operators.end(), token) != operators.end();
    }

    bool isConstant(string &token)
    {
        return regex_match(token, regex("\\d+"));
    }

    bool isNotEnd(char c)
    {
        if (idOrKey)
        {
            return isalnum(c);
        }

        return !isalnum(c) && c != ' ';
    }

public:
    Lexer(string &code)
    {
        this->code = code;
        this->index = 0;
    }

    string nextToken()
    {
        string token = "";
        idOrKey = isalnum(code[index]);
        while (index < code.size() && isNotEnd(code[index]))
        {
            token += code[index];
            index++;
        }

        if (index < code.size() && token.empty())
        {
            index++;
            return nextToken();
        }

        return token;
    }

    string getType(string &token)
    {
        if (isKeyword(token))
        {
            return "Keyword";
        }
        if (isIdentifier(token))
        {
            return "Identifier";
        }
        if (isOperator(token))
        {
            return "Operator";
        }
        if (isConstant(token))
        {
            return "Constant";
        }

        return "Special";
    }
};

int main()
{
    string code;
    getline(cin, code);

    Lexer lexer(code);

    string token;
    while ((token = lexer.nextToken()) != "")
    {
        cout << token << " : " << lexer.getType(token) << endl;
    }

    return 0;
}
