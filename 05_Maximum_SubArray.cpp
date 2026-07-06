#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int maxSum = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        int currentSum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            currentSum = currentSum + nums[j];
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
            }
        }
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int ans = maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << ans << endl;

    return 0;
}