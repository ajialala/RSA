#include "Rsa.h"
#include<iostream>
#include<sstream>
#include<ctime>
#include<cstdlib>

using std::cout;
using std::endl;
using std::ostringstream;

Rsa::Rsa()
{
}

Rsa::~Rsa()
{
}

BigInt Rsa::encryptByPu(const BigInt& m)
{//公钥加密
	const BigInt e = 65537;
	string temstr;
	temstr = "1D32AC2085722534E49CD537D05D1A18DF33F51C7CD4E53B9DE8467DA267242AB85181FA10EB46ACBB78DDFB255D4A5E44102A98CB6957E86A666A0200E9166B";
	BigInt N;
	N = BigInt(temstr);
	return m.moden(e,N);
}

BigInt Rsa::decodeByPr(const BigInt& c)
{//私钥解密
	string temstr;
	temstr = "1D32AC2085722534E49CD537D05D1A18DF33F51C7CD4E53B9DE8467DA267242AB85181FA10EB46ACBB78DDFB255D4A5E44102A98CB6957E86A666A0200E9166B";
	BigInt N;
	N = BigInt(temstr);
	string temstr1;
	temstr1 = "165AEFD34E9920C7A8AA33CE3228B68C8888FD88BC433CE83274DF53DDFE5E801A83202687A9DB3DBF2CD7C377E3AB7BE35EA5BE087B4B06BF1FC7C6C3CDA1F1";
	BigInt _d;
	_d = BigInt(temstr1);
	return c.moden(_d,N);
}

BigInt Rsa::encryptByPr(const BigInt& m)
{//私钥加密
	return decodeByPr(m);
}

BigInt Rsa::decodeByPu(const BigInt& c)
{//公钥解密
	return encryptByPu(c);
}