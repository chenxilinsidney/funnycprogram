/**
 * @file id_465.c
 * @brief AOAPC I 465
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-25
 */

#include <iostream>

#include <string>
#include <limits>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1024;

struct bign {
    // data member
    int len, s[maxn];
    // constructor
    bign() {
        memset(s, 0, sizeof(s));
        len = 1;
    }
    bign(const char* num) {
        *this = num;
    }
    bign(const int num) {
        *this = num;
    }
    bign(const string num) {
        *this = num;
    }
    // operator =
    bign operator = (const char* num) {
        len = strlen(num);
        for (int i = 0; i < len; i++)
            s[i] = num[len - 1 - i] - '0';
        this->clean();
        return *this;
    }
    bign operator = (const int num) {
        char s[maxn];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    bign operator = (const string num) {
        *this = num.c_str();
        return *this;
    }
    // to string method
    string str() const {
        string res = "";
        for (int i = 0; i < len; i++)
            res = (char)(s[i] + '0') + res;
        if (res == "") res = "0";
        return res;
    }
    // clean method remove prefix zero
    void clean() {
        while (len > 1 && !s[len - 1])
            len--;
    }
    // operator +
    bign operator + (const bign& b) const {
        bign c;
        c.len = 0;
        for (int i = 0, g = 0; g || i < max(len, b.len); i++) {
            int x = g;
            if (i < len) x += s[i];
            if (i < b.len) x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
        c.clean();
    }
    // operator +=
    bign operator += (const bign& b) {
        *this = *this + b;
        return *this;
    }
    // operator -
    bign operator - (const bign& b) const {
        bign c;
        c.len = 0;
        for (int i = 0, g = 0; i < len; i++) {
            int x = s[i] - g;
            if (i < b.len) x -= b.s[i];
            if (x < 0) {
                g = 1;
                x += 10;
            } else {
                g = 0;
            }
            c.s[c.len++] = x;
        }
        c.clean();
        return c;
    }
    // operator -=
    bign operator -= (const bign& b) {
        *this = *this - b;
        return *this;
    }
    // operator *
    bign operator * (const bign& b) const {
        bign c;
        c.len = len + b.len;
        for (int i = 0; i < len; i++)
            for (int j = 0; j < b.len; j++)
                c.s[i + j] +=  s[i] * b.s[j];
        for (int i = 0; i < c.len - 1; i++) {
            c.s[i + 1] += c.s[i] / 10;
            c.s[i] %= 10;
        }
        c.clean();
        return c;
    }
    // operator *=
    bign operator *= (const bign& b) {
        *this = *this * b;
        return *this;
    }
    // operator <
    bool operator < (const bign& b) const {
        if (len != b.len)
            return len < b.len;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] != b.s[i])
                return s[i] < b.s[i];
        }
        return false;
    }
    // operator >=
    bool operator >= (const bign& b) const {
        return !(*this < b);
    }
    // operator >
    bool operator > (const bign& b) const {
        return b < *this;
    }
    // operator <=
    bool operator <= (const bign& b) const {
        return !(b < *this);
    }
    // operator ==
    bool operator == (const bign& b) const {
        if (len != b.len)
            return false;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] != b.s[i])
                return false;
        }
        return true;
    }
    // operator !=
    bool operator != (const bign& b) const {
        return !(b == *this);
    }
};


istream& operator >> (istream& in, bign& x) {
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

ostream& operator << (ostream& out, const bign& x) {
    out << x.str();
    return out;
}

int main()
{
    string line;
    bign max_int = numeric_limits<int>::max();
    bign first;
    bign second;
    bign result;
    char a[1025];
    char b[1025];
    char character;
    while (getline(cin, line)) {
        cout << line << endl;
        sscanf(line.c_str(), "%s%*c%c%*c%s", a, &character, b);
        first = a;
        second = b;
        if (character == '+')
            result = first + second;
        else
            result = first * second;
        if (first > max_int)
            cout << "first number too big" << endl;
        if (second > max_int)
            cout << "second number too big" << endl;
        if (result > max_int)
            cout << "result too big" << endl;
    }
    return 0;
}
