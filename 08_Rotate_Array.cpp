#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    k = k % nums.size();
    for (int i = 1; i <= k; i++)
    {
        int lastElement = nums[nums.size() - 1];
        for (int j = nums.size() - 1; j > 0; j--)
        {
            nums[j] = nums[j - 1];
        }
        nums[0] = lastElement;
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);

    cout << "Rotated Array: ";

    for (int x : nums)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}