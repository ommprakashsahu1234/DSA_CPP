#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int> &height)
{
    int total = 0;
    for (int i = 1; i < height.size() - 1; i++)
    {
        int leftMax = 0, rightMax = 0;
        for (int j = i; j < height.size(); j++) // rightmax
        {
            rightMax = max(rightMax, height[j]);
        }
        for (int j = i; j >= 0; j--) // leftmax
        {
            leftMax = max(leftMax, height[j]);
        }
        total += max(0, min(leftMax, rightMax) - height[i]);
    }
    return total;
}

int main()
{
    vector<int> height = {5, 2, 4, 1, 0, 4};

    int ans = trap(height);

    cout << "Trapped Water: " << ans << endl;

    return 0;
}