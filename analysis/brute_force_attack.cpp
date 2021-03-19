#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

#define Number 0
#define Alpha 1
#define AlphaNumber 2
#define ALL 3
#define error 10

char pw[8];
char attack[8];

int make_pw(int flag)
{
	int a, b;
	srand((unsigned int)time(0));

	a = rand() % 4 + 4;

	for (int i = 0; i < a; i++)
	{
		b = rand();
		switch (flag) {
		case(ALL):
			b = b % 93 + '!';
			break;
		case(AlphaNumber):
			b = b % 62;
			if (b < 10) b += '0' ;
			else if (b < 36) b += 'A'-10;
			else b += 'a' -36;
			break;
		case(Alpha):
			b = b % 52;
			if (b < 26) b += 'A';
			else b += 'a' - 26;
			break;
		case(Number):
			b = b % 10 +'0';
			break;
		}
		pw[i] = b;
	}

	return a;

}

int find_pw(int cnt)
{
	int ret,i;
	while (1) {
		ret = strcmp(pw, attack);
		if (ret == 0) {
			return 1;
		}
		attack[cnt]++;
		for (i = 0; i <= cnt; i++) {
			if (attack[0] > 126) {
				return 0;
			}

			if (attack[cnt - i] > 126) {
				attack[cnt - i] = 0;
				attack[cnt - i - 1]++;
			}
		}
		

	}
	return 0;
}

int main()
{
	char type;
	int flag=error;
	int ret, i, cnt;

	cout << "Input type of key('n->only number', 'a->only alphabet', 't->alpha+num', 'A->alpha+num+특수문자' ) : ";
	cin >> type;

	switch (type) {
	case('n'):
		flag = Number;
		break;
	case('a'):
		flag = Alpha;
		break;
	case('t'):
		flag = AlphaNumber;
		break;
	case('A'):
		flag = ALL;
		break;
	if(flag == error)
		goto err;
	}

	ret = make_pw(flag);
	cout << ret << endl;

	for (i = 0; i < ret; i++)
		cout << pw[i] << "\t";
	cout << endl;

	memset(attack, '!', 4);
	memset(attack+4, 0, 4);
	cnt = 3;
	while (1) {
		ret = find_pw(cnt);
		if (ret) {
			cout << "find" << endl;
			break;
		}
		cnt++;
		if (cnt > 8) {
			cout << "over" << endl;
			goto err;
		}
		memset(attack, '!', 8);
		memset(attack + cnt + 1, 0, 7 - cnt);
	}
	
	for (int w = 0; w <= cnt; w++) {
		cout << attack[w] << "\t";
	}

	return 0;

err: 
	cout << "error" << endl;
	return -1;
}
