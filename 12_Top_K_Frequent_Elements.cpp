#include <iostream>
#include <vector>
using namespace std;
vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> result;
    vector<int> individuals = {};
    vector<int> indrepeat = {};
    for (int i = 0; i < nums.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < individuals.size(); j++)
        {
            if (nums[i] == individuals[j])
            {
                found = true;
            }
        }
        if (found == false)
        {
            individuals.push_back(nums[i]);
        }
    }
    for (int i = 0; i < individuals.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (individuals[i] == nums[j])
            {
                count++;
            }
        }
        indrepeat.push_back(count);
    }
    for (int i = 0; i < indrepeat.size() - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < indrepeat.size() - i - 1; j++)
        {
            if (indrepeat[j] > indrepeat[j + 1])
            {
                swap(indrepeat[j], indrepeat[j + 1]);
                swap(individuals[j], individuals[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    for (int i = individuals.size()-1; result.size()<k; i--)
    {
        result.push_back(individuals[i]);
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> ans = topKFrequent(nums, k);

    cout << "Top K Frequent Elements: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}