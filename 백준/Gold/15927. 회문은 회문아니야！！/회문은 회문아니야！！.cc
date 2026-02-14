#include <bits/stdc++.h>
using namespace std;

int main() {

    string text;
    cin >> text;
    //  no palindrome
    for (int i = 0; i < text.size()/2; i++) {
        if (text[i] != text[text.size()-i-1]) {
            cout << text.size();
            return 0;
        }
    }
    //  palindrome
    for (auto i : text) {
        if (i != text[0]) {
            cout << text.size()-1;
            return 0;
        }
    }
    //  no same palindrome
    cout << -1;

    return 0;
}