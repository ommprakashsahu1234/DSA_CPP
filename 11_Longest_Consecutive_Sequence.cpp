#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    sort(nums.begin(), nums.end());

    int currentCount = 1;
    int maxCount = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            continue;
        }
        else if (nums[i] == nums[i - 1] + 1)
        {
            currentCount++;
        }
        else
        {
            currentCount = 1;
        }
        if (currentCount > maxCount)
        {
            maxCount = currentCount;
        }
    }
    return maxCount;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    int ans = longestConsecutive(nums);

    cout << "Longest Consecutive Sequence Length: " << ans << endl;

    return 0;
}