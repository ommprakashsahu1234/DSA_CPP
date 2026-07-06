#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;

    if (intervals.empty())
        return result;

    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> &last = result.back();
        if (last[1] >= intervals[i][0])
        {
            last[1] = max(last[1], intervals[i][1]);
        }
        else
        {
            result.push_back(intervals[i]);
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> intervals =
    {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    vector<vector<int>> ans = merge(intervals);

    cout << "Merged Intervals:\n";

    for (auto interval : ans)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    return 0;
}