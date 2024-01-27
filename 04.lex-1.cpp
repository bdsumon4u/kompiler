#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;

    if (regex_match(str, regex("[i-nI-N][a-zA-Z0-9]*")))
    {
        cout << "Integer Variable" << endl;
    }
    else if (regex_match(str, regex("[1-9][0-9]{0,3}")))
    {
        cout << "ShortInt Number" << endl;
    }
    else if (regex_match(str, regex("[1-9][0-9]{3}[0-9]+")))
    {
        cout << "LongInt Number" << endl;
    }
    else
    {
        cout << "Invalid Input or Undefined" << endl;
    }

    return 0;
}
