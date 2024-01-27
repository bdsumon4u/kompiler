#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c)
{
    switch (tolower(c))
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    string word, vstr = "", cstr = "";
    vector<string> vowels, consonants;

    while (cin >> word)
    {
        if (isVowel(word[0])) {
            vowels.push_back(word);
        }
        else if (isalpha(word[0]))
        {
            consonants.push_back(word);
        }
    }

    cout << "Number of vowels: " << vowels.size() << endl;
    cout << "Number of consonants: " << consonants.size() << endl;

    cout << endl << "Vowels: " << endl;
    for (auto &word : vowels) {
        cout << word << endl;
        if (vstr.size())
        {
            vstr += " ";
        }
        vstr += word;
    }
    cout << endl;

    cout << endl << "Consonants: " << endl;
    for (auto &word : consonants)
    {
        cout << word << endl;
        if (cstr.size())
        {
            cstr += " ";
        }
        cstr += word;
    }
    cout << endl;

    cout << "Vowel string: " << vstr << endl;
    cout << "Consonant string: " << cstr << endl;

    return 0;
}
