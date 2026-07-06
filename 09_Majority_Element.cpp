#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int maxVisited = nums[0];
    int maxVisitCount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if(nums[i]==nums[j]){
                count++;
            }
        }
        if(count > maxVisitCount){
            maxVisitCount = count;
            maxVisited = nums[i];
        }
    }
    return maxVisited;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int ans = majorityElement(nums);

    cout << "Majority Element: " << ans << endl;

    return 0;
}