#include <iostream>
#include <string>
#include "base64.h"
using namespace std;

string deciToBin_8bit(int deci)
{
	if (deci == 0)
		return "00000000";
	string str = "";
	while (deci != 0)
	{
		if (deci % 2 == 0)
			str = "0" + str;
		else
			str = "1" + str;
		deci /= 2;
	}
	while(str.size()<8)
		str = "0" + str;
	return str;
}

string deciToBin_6bit(int deci)
{
	if (deci == 0)
		return "000000";
	string str = "";
	while (deci != 0)
	{
		if (deci % 2 == 0)
			str = "0" + str;
		else
			str = "1" + str;
		deci /= 2;
	}
	while (str.size()<6)
		str = "0" + str;
	return str;
}

int binToDeci(string bin)
{
	int val = 0;
	for (int i = 0; i < bin.size(); i++)
		val = val * 2 + bin[i] - '0';
	return val;
}

string base64_encryption(string in)
{
	string value("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123476789+/");
	string out = "";
	int n = in.size();
	int i;
	string str;
	for (i = 0; i < n / 3; i++)
	{
		str = "";
		str = str + deciToBin_8bit(in[3 * i + 0]) + deciToBin_8bit(in[3 * i + 1]) + deciToBin_8bit(in[3 * i + 2]);
		for (int k = 0; k < 4; k++)
			out += value[binToDeci(str.substr(6 * k, 6))];
	}
	str = "";
	for (int j = 3 * i; j < n; j++)
		str += deciToBin_8bit(in[j]);
	while (str.size() % 6 != 0)
		str += "0";
	for(int k=0;k<str.size()/6;k++)
		out += value[binToDeci(str.substr(6 * k, 6))];
	return out;
}

string base64_decryption(const string in)
{
	string value("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123476789+/");
	string out = "";
	int n = in.size();
	int i;
	string str;
	for (i = 0; i < n / 4; i++)
	{
		str = "";
		str = str + deciToBin_6bit(value.find(in[4 * i + 0])) + deciToBin_6bit(value.find(in[4 * i + 1])) + deciToBin_6bit(value.find(in[4 * i + 2])) + deciToBin_6bit(value.find(in[4 * i + 3]));
		for (int k = 0; k < 3; k++)
			out.push_back((char)binToDeci(str.substr(8 * k, 8)));
	}
	str = "";
	for (int j = 4 * i; j < n; j++)
		str += deciToBin_6bit(value.find(in[j]));
	int m = str.size();
	while (m % 8 != 0 && str[m - 1] == '0')
		m--;
	for (int k = 0; k < m / 8 ; k++)
		out.push_back((char)binToDeci(str.substr(8 * k, 8)));
	return out;
}
