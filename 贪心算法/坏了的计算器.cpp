/*
在显示着数字的坏计算器上，我们可以执行以下两种操作：
双倍（Double）：将显示屏上的数字乘 2；
递减（Decrement）：将显示屏上的数字减 1 。
最初，计算器显示数字 X。
返回显示数字 Y 所需的最小操作数。
*/

int brokenCalc(int X, int Y) {
    if(X>=Y) return X-Y;
    if(Y%2==0) return brokenCalc(X,Y/2)+1;
    else return brokenCalc(X,Y+1)+1;
}
