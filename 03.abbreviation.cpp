#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string code;
    getline(cin, code);

    map<string, string> abbreviations = {
        {"CSE-3141", "Computer Science & Engineering, 3rd year, 1st semester, Compiler Design, Theory."},
        {"CSE-3142", "Computer Science & Engineering, 3rd year, 1st semester, Compiler Design, Lab."},
    };

    if (abbreviations.count(code))
    {
        cout << abbreviations[code] << endl;
    }
    else
    {
        cout << "404 Not Found.";
    }

    return 0;
}
