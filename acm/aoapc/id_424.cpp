/**
 * @file id_424.c
 * @brief AOAPC I 424
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-25
 */

#include <iostream>
#include <cstdio>
#include <cstring>

#include <string>
using namespace std;


const int maxn = 102;

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
            c.s[i + 1] += s[i] / 10;
            c.s[i] %= 10;
        }
        c.clean();
        return c;
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

bign value[100];

int main()
{
    string line;
    int value_length = 0;
    while (getline(cin, line) &&
            !(line.length() == 1 && line[0] == '0')) {
        value[value_length++] = line;
    }
    int value_index = 0;
    for (value_index = 1; value_index < value_length; value_index++) {
        value[0] += value[value_index];
    }
    cout << value[0] << endl;
    return 0;
}

