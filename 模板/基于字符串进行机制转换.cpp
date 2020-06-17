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

int main() {
	string str = "dC45";
	int total = 0;
	int c = 1;
	for (int i = str.length() - 1; i >= 0; i--) {
		int x = 0;
		if (str[i] >= '0' && str[i] <= '9') {
			x = str[i] - '0';
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			x = str[i] - 'a' + 10;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			x = str[i] - 'A' + 10;
		}
		total += x * c;
		//从十六进制转向十进制
		c *= 16;
	}
	cout << total << endl;
	int tmp = total;
	int ptr = 0;
	char ans[100];
	while (tmp) {
		//从十进制转向八进制
		int x = tmp % 8;
		ans[ptr++] = (x < 10) ? x + '0' : x - 10 + 'A';
		tmp /= 8;
	}
	for (int i = ptr - 1; i >= 0; i--) {
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
