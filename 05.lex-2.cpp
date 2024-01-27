#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;

    if (regex_match(str, regex("[a-hA-Ho-zO-Z][a-zA-Z0-9]*")))
    {
        cout << "Float Variable" << endl;
    }
    else if (regex_match(str, regex("(0|[1-9][0-9]*)\\.[0-9]{2}")))
    {
        cout << "Float Number" << endl;
    }
    else if (regex_match(str, regex("(0|[1-9][0-9]*)\\.[0-9]{2}[0-9]+")))
    {
        cout << "Double Number" << endl;
    }
    else
    {
        cout << "Invalid Input or Undefined" << endl;
    }

    return 0;
}
