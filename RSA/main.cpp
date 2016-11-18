#include<iostream>
#include<ctime>
#include"BigInt.h"
#include"Rsa.h"
using std::cout;
using std::endl;
using std::cin;

bool islegal(const string& str)
{//�ж������Ƿ�Ϸ�
	for(string::const_iterator it=str.begin();it!=str.end();++it)
		if(!isalnum(*it))//������ĸ����
			return false;
	return true;
}

BigInt decode(Rsa& rsa, string str)
{//����
	if (islegal(str) == false)
		return false;
	BigInt c(str);

	BigInt m = rsa.decodeByPr(c);

	return m;
}

BigInt encry(Rsa& rsa, string str)
{//����
	if (islegal(str) == false)
		return false;
	BigInt m(str);
	BigInt c;
	c = rsa.encryptByPu(m);

	return c;
}

int go(int a,string b)
{//���ƺ���
	Rsa rsa;
	BigInt bb,cc;
	int n=512;

		if(a!=1&&a!=2)
			cout<<"��������,����������1������������2"<<endl;
		else
		{
			switch(a)
			{
			case 1:
				bb = encry(rsa, b);//����
				cout << bb << endl;
				break;
			case 2:
				cc = decode(rsa, b);//����
				cout << cc << endl;
				break;
				return 0;
			}
		}
}


int main(int argc, char* argv[])
{
	int a = atol(argv[1]);
	string b = argv[2];
	go(a,b);
}