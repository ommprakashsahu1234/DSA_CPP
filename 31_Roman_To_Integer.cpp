#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int number = mp[s[0]];
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (mp[s[i]] < mp[s[i + 1]])
        {
            number -= 2 * mp[s[i]];
        }
        number += mp[s[i + 1]];
    }

    return number;
}

int main()
{
    vector<string> tests = {
        "III",
        "IIII",
        "IV",
        "IX",
        "LVIII",
        "MCMXCIV",
        "I",
        "MMMCMXCIX"};

    for (string s : tests)
    {
        cout << "Input: " << s << endl;
        cout << "Output: " << romanToInt(s) << endl;
        cout << "-------------------" << endl;
    }

    return 0;
}