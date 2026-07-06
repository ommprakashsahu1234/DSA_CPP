#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;

    for (int buy = 0; buy < prices.size(); buy++)
    {
        for (int sell = buy + 1; sell < prices.size(); sell++)
        {
            int profit = prices[sell] - prices[buy];

            if (profit > maxProfit)
            {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}

int main()
{
    vector<int> stocks = {7, 1, 5, 3, 6, 4};

    int maxprofit = maxProfit(stocks);

    cout << "Maximum Profit : " << maxprofit << endl;

    return 0;
}