#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

#define Number 0
#define Alpha 1
#define AlphaNumber 2
#define ALL 3
#define error 10

char pw[6];

int make_pw(int flag)
{
	int a, b;
	srand((unsigned int)time(0));

	a = rand() % 2 + 4;

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

int main()
{
	char type;
	int flag=error;
	int ret, i;

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

	return 0;

err: 
	cout << "error" << endl;
	return -1;
}
