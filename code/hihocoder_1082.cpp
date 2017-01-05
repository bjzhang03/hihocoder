/*************************************************************************
    > File Name: hihocoder_1082.cpp
    > Author: bjzhang03
    > Mail: bjzhang1991@gmail.com
    > Created Time: 2017年01月05日 星期四 21时01分00秒
 ************************************************************************/

#include<iostream>
using namespace std;
const string candidate="marshtomp";
const string replace="fjxmlhx";

bool IsWord(int position,const string &Str)
{
	for(int j=0;j<candidate.size();j++)
	{
		if(!(position+j<Str.size()&&tolower(Str[position+j])==candidate[j]))
			return false;
	}
	return true;
}

string ReplaceStr(int position,string Str)
{
	string result;
	for(int i=0;i<position;i++)
		result.push_back(Str[i]);
	for(int i=0;i<replace.size();i++)
		result.push_back(replace[i]);
	for(int i=position+candidate.size();i<Str.size();i++)
		result.push_back(Str[i]);
	return result;
}
int main()
{
	string Str;
	while(getline(cin,Str))
	{
		while(true)
		{
			bool tag=false;
			int index=0;
			for(int i=0;i<Str.size();i++)
			{
				if(IsWord(i,Str))
				{
					tag=true;
					index=i;
					break;
				}
			}
			if(tag)
			{
				Str=ReplaceStr(index,Str);
			}
			else
				break;
		}
		cout<<Str<<endl;
	}
	return 0;
}
