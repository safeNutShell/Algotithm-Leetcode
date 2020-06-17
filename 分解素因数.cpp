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

//判断是否为素数
bool judge(int a) {
	//0,1不是素数
	if (a <= 1) return false;
	int bound = (int)sqrt(a) + 1;
	//判断2到根a（向上取整）是否整除a
	for (int i = 2; i < bound; i++) {
		if (a % i == 0) return false;
	}
	return true;
}

int main() {
	int a = 7;
	if (judge(a)) cout << "YES" << endl;
	bool prime[1000] = { false };
	for (int i = 2; i < 1000; i++) {
		prime[i] = judge(i);
	}
	int p[1000];
	int pSize = 0;
	for (int i = 2; i < 1000; i++) {
		if (prime[i] == true) {
			p[pSize++] = i;
		}
	}
	cout << "1000以内共有" << pSize << "个素数:" << endl;
	for (int i = 0; i < pSize; i++)
		cout << p[i] << ' ';
	//分解素因数
  //需要一个单纯的素数数组
	cout << "\n\n";
	int test = 764;
	int ansPrime[1000];
	int ansNum[1000];
	int ansSize = 0;
	for (int i = 0; i < pSize; i++) {
		if (test % p[i] == 0) {
			ansPrime[ansSize] = p[i];
			ansNum[ansSize] = 0;
			while (test % p[i] == 0) {
				ansNum[ansSize]++;
				test /= ansPrime[ansSize];
			}
			ansSize++;
			if (test == 1)
				break;
		}
	}
	if (test != 1) {
		cout << "???" << endl;
		ansPrime[ansSize] = test;
		ansNum[ansSize++] = 1;
	}
	for (int i = 0; i < ansSize; i++) {
		for (int j = 0; j < ansNum[i]; j++) {
			cout << ansPrime[i] << ' ';
		}
	}
	return 0;
}
