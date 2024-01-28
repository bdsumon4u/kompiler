#include <bits/stdc++.h>

using namespace std;

class Grammar {
    char start, ep;
    map<char, set<char>> first;
    map<char, set<char>> follow;
    map<char, set<string>> prods;

    void computeFirst(char head) {
        for (auto &body : prods[head]) {
            for (int i = 0; i < body.size(); i++) {
                if (!isupper(body[i])) {
                    first[head].insert(body[i]);
                    break;
                }
                
                if (body[i] != head) {
                    computeFirst(body[i]);
                }
                for (auto &ch : first[body[i]]) {
                    if (ch != ep || i == body.size() - 1) {
                        first[head].insert(ch);
                    }
                }
                if (!first[body[i]].count(ep)) {
                    break;
                }
            }
        }
    }

    void mergeFirst(char head, char from) {
        for (auto &ch : first[from]) {
            if (ch != ep) {
                follow[head].insert(ch);
            }
        }
    }

    void mergeFollow(char head, char from) {
        if (head != from) {
            computeFollow(from);
        }
        for (auto &ch : follow[from]) {
            follow[head].insert(ch);
        }
    }

    void computeFollow(char head) {
        for (auto &prod : prods) {
            for (auto &body : prod.second) {
                for (int i = 0; i < body.size(); i++) {
                    if (body[i] != head) {
                        continue;
                    }

                    if (i == body.size() - 1){
                        mergeFollow(head, prod.first);
                    }

                    for (int j = i + 1; j < body.size(); j++) {
                        if (!isupper(body[j])) {
                            follow[head].insert(body[j]);
                            break;
                        }

                        mergeFirst(head, body[j]);
                        if (!first[body[j]].count(ep)) {
                            break;
                        }
                        if (j == body.size() - 1) {
                            mergeFollow(head, prod.first);
                        }
                    }
                }
            }
        }
    }

public:
    Grammar(char start, char ep) {
        char head;
        string body;
        this->ep = ep;
        this->start = start;
        follow[start].insert('$');
        cout << "Enter Productions: Head Body" << endl;
        while (cin >> head >> body) {
            prods[head].insert(body);
        }

        for (auto &prod : prods) {
            computeFirst(prod.first);
        }

        for (auto &prod : prods) {
            computeFollow(prod.first);
        }
    }

    void printFirst() {
        for (auto &head : prods) {
            cout << "First(" << head.first << ") = { ";
            for (auto &ch : first[head.first]) {
                cout << ch << " ";
            }
            cout << "}" << endl;
        }
    }

    void printFollow() {
        for (auto &head : prods) {
            cout << "Follow(" << head.first << ") = { ";
            for (auto &ch : follow[head.first]) {
                cout << ch << " ";
            }
            cout << "}" << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    char start, ep;
    cout << "Enter Start Symbol: ";
    cin >> start;
    cout << "Enter Epsilon Symbol: ";
    cin >> ep;

    Grammar grammar(start, ep);
    grammar.printFirst();
    grammar.printFollow();

    return 0;
}
