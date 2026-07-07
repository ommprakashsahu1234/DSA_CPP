#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                for (int l = k + 1; l < nums.size(); l++)
                {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};

                        if (find(result.begin(), result.end(), temp) == result.end())
                        {
                            result.push_back(temp);
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = -1;

    vector<vector<int>> ans = fourSum(nums, target);

    cout << "Quadruplets:\n";

    for (auto quad : ans)
    {
        cout << "[ ";
        for (int x : quad)
        {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}