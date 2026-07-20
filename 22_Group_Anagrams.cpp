#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<string> sortedStrs;
    for (string s : strs)
    {
        sort(s.begin(), s.end());
        sortedStrs.push_back(s);
    }

    vector<bool> visited(strs.size(), false);
    vector<vector<string>> ans;

    for (int i = 0; i < strs.size(); i++)
    {
        if (visited[i])
            continue;

        vector<string> current;

        current.push_back(strs[i]);
        visited[i] = true;

        for (int j = i + 1; j < strs.size(); j++)
        {
            if (!visited[j] && sortedStrs[i] == sortedStrs[j])
            {
                current.push_back(strs[j]);
                visited[j] = true;
            }
        }

        ans.push_back(current);
    }

    return ans;
}
int main()
{
    vector<vector<string>> testCases =
        {
            {"eat", "tea", "tan", "ate", "nat", "bat"},
            {""},
            {"a"},
            {"abc", "cab", "bac"},
            {"abc", "def", "ghi"},
            {"aa", "aa", "aa"},
            {"ab", "ba", "cd", "dc"},
            {},
            {"abc"},
            {"abc", "abc", "abc"},
            {"listen", "silent", "enlist"},
            {"rat", "tar", "art", "car"},
            {"zzz", "zzz", "zz"},
            {"abcd", "bcda", "dacb", "xyz"},
            {"a", "b", "c", "d"}};

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "========== Test Case " << i + 1 << " ==========\n";

        cout << "Input : [";
        for (int j = 0; j < testCases[i].size(); j++)
        {
            cout << "\"" << testCases[i][j] << "\"";
            if (j != testCases[i].size() - 1)
                cout << ", ";
        }
        cout << "]\n\n";

        vector<vector<string>> ans = groupAnagrams(testCases[i]);

        cout << "Output:\n";

        cout << "[\n";
        for (int j = 0; j < ans.size(); j++)
        {
            cout << "  [";

            for (int k = 0; k < ans[j].size(); k++)
            {
                cout << "\"" << ans[j][k] << "\"";

                if (k != ans[j].size() - 1)
                    cout << ", ";
            }

            cout << "]";

            if (j != ans.size() - 1)
                cout << ",";

            cout << "\n";
        }
        cout << "]\n\n";
    }

    return 0;
}