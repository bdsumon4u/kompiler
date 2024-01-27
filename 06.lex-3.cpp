#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;

    if (regex_match(str, regex("ch_[a-zA-Z0-9][a-zA-Z0-9]*")))
    {
        cout << "Character Variable" << endl;
    }
    else if (regex_match(str, regex("bn_[a-zA-Z0-9][a-zA-Z0-9]*")))
    {
        cout << "Binary Variable" << endl;
    }
    else if (regex_match(str, regex("0(0|1)(0|1)*")))
    {
        cout << "Binary Number" << endl;
    }
    else
    {
        cout << "Invalid Input or Undefined" << endl;
    }

    return 0;
}
