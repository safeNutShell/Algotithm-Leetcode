//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
//注意你不能在买入股票前卖出股票。

//解：
int maxProfit(vector<int>& prices) {
    int minPrice=INT_MAX;
    int maxPro=0;
    for(int i=0;i<prices.size();i++){
        if(prices[i]<minPrice)
            minPrice=prices[i];
        if(prices[i]-minPrice>maxPro)
            maxPro=prices[i]-minPrice;
    }
    return maxPro;
}
/*
累了3.6号写
*/
