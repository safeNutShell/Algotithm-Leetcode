/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。
如输入2.10000，3，输出9.26100
*/

//解1：
double myPow(double x, int n) {
    if(x==1 || x==0) return x;
    if (n == 0) return 1;
    else if (n > 0) {
        double result = x;
        for (int i = 0; i < n-1; i++) {
            result *= x;
        }
        return result;
    }
    else {
        double result = x;
        for (int i = 0; i > n + 1; i--) {
            result *= x;
        }
        return 1 / result;
    }
}
/*
暴力算法，很容易超时；优化的目标应该是n，幂次本身的特殊性可以提供优化路径
*/

//解2：
