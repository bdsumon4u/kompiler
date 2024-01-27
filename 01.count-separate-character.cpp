#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string str, letters = "", digits = "", others = "";

    bool isWord = false;
    int words = 0;

    getline(cin, str);

    for (char c : str)
    {
        isWord = c != ' ';

        if (isalpha(c))
        {
            letters += c;
        }
        else if (isdigit(c))
        {
            digits += c;
        }
        else
        {
            others += c;

            if (isWord)
            {
                words++;
                isWord = false;
            }
        }
    }

    words += isWord;

    cout << "Number of words: " << words << endl;

    cout << "Number of letters: " << letters.size() << endl;
    cout << "Number of digits: " << digits.size() << endl;
    cout << "Number of others: " << others.size() << endl;

    cout << "Letters: " << letters << endl;
    cout << "Digits: " << digits << endl;
    cout << "Others: " << others << endl;

    return 0;
}
