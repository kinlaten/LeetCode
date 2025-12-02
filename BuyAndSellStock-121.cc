class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty())
      return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 0; i < prices.size(); i++) {
      int currentPrice = prices[i];
      int profitToday = currentPrice - minPrice;

      maxProfit = max(profitToday, maxProfit);

      minPrice = min(currentPrice, minPrice);
    }

    return maxProfit;
  }
};
