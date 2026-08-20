#include <iostream>
#include <string>
#include <vector>

using namespace std;

string intToRoman(int num)
{
    vector<int> values = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    };

    vector<string> symbols = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    };

    string ans = "";

    for (int i = 0; i < values.size(); i++)
    {
        while (num >= values[i])
        {
            ans += symbols[i];
            num -= values[i];
        }
    }

    return ans;
}

int main()
{
    vector<int> tests = {
        1,
        3,
        4,
        9,
        40,
        58,
        90,
        400,
        944,
        1994,
        3749,
        3999
    };

    for (int num : tests)
    {
        cout << "Input: " << num << endl;
        cout << "Output: " << intToRoman(num) << endl;
        cout << "-------------------" << endl;
    }

    return 0;
}