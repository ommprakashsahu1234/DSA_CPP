#include <iostream>
#include <vector>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int subArrayCount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                subArrayCount++;
            }
        }
    }
    return subArrayCount;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    int k = 3;

    int ans = subarraySum(nums, k);

    cout << "Number of Subarrays: " << ans << endl;

    return 0;
}