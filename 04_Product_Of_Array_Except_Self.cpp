#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int product = 1;
    vector<int> result(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j<nums.size(); j++)
        {
            if(i!=j){
                product = product * nums[j];
            }
        }
        result[i]=product;
        product =1;
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};

    vector<int> ans = productExceptSelf(nums);

    cout << "Output: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}