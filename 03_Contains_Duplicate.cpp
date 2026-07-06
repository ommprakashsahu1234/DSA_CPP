#include <iostream>
#include <vector>
using namespace std;
bool containsDuplicate(vector<int> &nums)
{
    bool Contains = false;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]==nums[j]){
                Contains = true;
                break;
            }
        }
    }
    return Contains;
}

int main()
{
    vector<int> Arr = {10,2,5,5,10,2,15,8,8,15,156456,451,};
    bool contains = containsDuplicate(Arr);
    if(contains){
        cout << "Array Contains Duplicate." << endl;
    }else{
        cout << "Array does not contain Duplicate." << endl;

    }
    return 0;
}