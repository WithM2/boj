#include <iostream>

using namespace std;

int a, b, c, d;

int main() {

    cin >> a >> b >> c >> d;
    c += d;
    if (c >= 60) {
        b += c/60;
        c %= 60;
    }
    if (b >= 60) {
        a += b/60;
        b %= 60;
    }
    if (a >= 24) {
        a %= 24;
    }

    cout << a << ' ' << b << ' ' << c;
    return 0;
}   