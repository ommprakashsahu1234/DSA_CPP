#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

int main()
{
    vector<int> Arr = {5, 6, 7, 8, 9};
    int target = 15;
    vector<int> Ans = twoSum(Arr, target);
    if (!Ans.empty())
    {
        cout << Ans[0] << " " << Ans[1];
    }
    else
    {
        cout << "No valid pair found.";
    }
    return 0;
}