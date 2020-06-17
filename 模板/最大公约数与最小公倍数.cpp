#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
//#define INT_MAX 2147483647

using namespace std;

//求最大公约数，使用辗转相除法
int gcd(int a, int b) {
	//注意，b一定是较小数
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main() {
	int a = 81, b = 45;
	int GCD = gcd(a, b);
	cout << GCD << endl;
  //利用最大公约数的结果求最小公倍数
	int LCM = a * b / gcd(a, b);
	cout << LCM << endl;
	return 0;
}
