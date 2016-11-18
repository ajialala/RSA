#include<iostream>
#include<ctime>
#include"BigInt.h"
#include"Rsa.h"
using std::cout;
using std::endl;
using std::cin;

bool islegal(const string& str)
{//判断输入是否合法
	for(string::const_iterator it=str.begin();it!=str.end();++it)
		if(!isalnum(*it))//不是字母数字
			return false;
	return true;
}

BigInt decode(Rsa& rsa, string str)
{//解密
	if (islegal(str) == false)
		return false;
	BigInt c(str);

	BigInt m = rsa.decodeByPr(c);

	return m;
}

BigInt encry(Rsa& rsa, string str)
{//加密
	if (islegal(str) == false)
		return false;
	BigInt m(str);
	BigInt c;
	c = rsa.encryptByPu(m);

	return c;
}

int go(int a,string b)
{//控制函数
	Rsa rsa;
	BigInt bb,cc;
	int n=512;

		if(a!=1&&a!=2)
			cout<<"重新输入,加密请输入1；解密请输入2"<<endl;
		else
		{
			switch(a)
			{
			case 1:
				bb = encry(rsa, b);//加密
				cout << bb << endl;
				break;
			case 2:
				cc = decode(rsa, b);//解密
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