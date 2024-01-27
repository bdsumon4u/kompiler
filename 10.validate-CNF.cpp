#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);

    vector<string> PN = {"Sagor", "Selim", "Salma", "Nipu"};
    vector<string> P = {"he", "she", "I", "we", "you", "they"};
    vector<string> N = {"book", "cow", "dog", "home", "grass", "rice", "mango"};
    vector<string> V = {"read", "eat", "take", "run", "write"};

    // RegEx: (PN|P) ((V) (N))?

    string pattern = "(";
    for (auto word : PN)
    {
        pattern += word + "|";
    }
    for (auto word : P)
    {
        pattern += word + "|";
    }
    pattern.pop_back();

    pattern += ")\\s(";
    for (auto word : V)
    {
        pattern += word + "|";
    }
    pattern.pop_back();

    pattern += ")(\\s(";
    for (auto word : N)
    {
        pattern += word + "|";
    }
    pattern.pop_back();

    pattern += "))?";

    cout << pattern << endl;

    if (regex_match(str, regex(pattern)))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }

    return 0;
}
