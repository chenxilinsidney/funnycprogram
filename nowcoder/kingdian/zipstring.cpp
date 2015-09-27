#include <iostream>
#include <string>
using namespace std;
class Zipper {
public:
    string zipString(string iniString) {
        string result;
        // zip
        for (size_t index = 0; index < iniString.size(); ) {
            size_t temp = index;
            while (iniString[temp + 1] == iniString[index]) temp++;
            // push character
            result.push_back(iniString[index]);
            // count to string
            result += to_string(temp - index + 1);
            // check size
            if (result.size() >= iniString.size()) return iniString;
            // new index
            index = temp + 1;
        }
        return result;
    }
};

int main()
{
    Zipper zip;
    string iniString;
    cin >> iniString;
    cout << zip.zipString(iniString) << endl;
    return 0;
}
