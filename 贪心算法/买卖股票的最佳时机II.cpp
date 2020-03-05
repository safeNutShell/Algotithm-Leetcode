给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

//解
//贪心算法
int maxProfit(vector<int>& prices) {
    bool have=false;
    int profit=0;
    int buy=0;
    for(int i=0;i<prices.size();i++){
        if(i==prices.size()-1){
            if(have){
                have=false;
                profit+=prices[i]-buy;
            }
            break;
        }
        if(!have&&prices[i+1]>prices[i]){
            have=true;
            buy=prices[i];
        }
        if(have&&prices[i+1]<prices[i]){
            have=false;
            profit+=prices[i]-buy;
        }
    }
    return profit;
}
/*
贪心算法，为了获得全局的最优解，求每一步的最优解。
对于买入和卖出，买入的时机应该是即将涨价前夕，卖出的时机应该是即将降价的前夕，这样一次遍历，同时防止多次买卖交叉，即可得最大利润。
这样做的原理是，首先在最低点买入，如果我错过之后的第一个最（注意是“最”）大点而期望之后有更高的波峰，这期间必将损失一次买卖，而两次买卖的总
利润会比一次买卖的更高。
*/
