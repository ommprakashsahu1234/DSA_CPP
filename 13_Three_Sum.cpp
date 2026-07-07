#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    if (find(ans.begin(), ans.end(), temp) == ans.end()) // In two lines: `find()` returns `ans.end()` when it searches the entire vector and does not find the required element.Therefore, `find(...) == ans.end()` means **"this triplet is not already present, so it is safe to insert it."
                    {
                        ans.push_back(temp);
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = threeSum(nums);

    cout << "Triplets:\n";

    for (auto triplet : ans)
    {
        cout << "[ ";
        for (int x : triplet)
        {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}