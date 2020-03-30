/*
实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
*/

//解1：
int mySqrt(int x) {
    for(long int i=0;i<=x;i++){
        if(i*i==x) return i;
        if(i*i<x && (i+1)*(i+1)>x) return i;
    }
    return 0;
}
/*
此方法简单遍历，但没有体现二分
*/

//解2：
int mySqrt(int x) {
    if (x < 2) return x;

    long int testSqrt;
    int mid, left = 2, right = x / 2;
    while (right >= left) {
        mid = left + (right - left) / 2;
        testSqrt = (long int)mid * mid;
        if (testSqrt > x) {
            right = mid - 1;
        }
        else if (testSqrt < x) {
            left = mid + 1;
        }
        else return mid;
    }
    return right;
}
/*
体现了二分的思想，二分在一定意义上也涉及双指针的问题
*/
