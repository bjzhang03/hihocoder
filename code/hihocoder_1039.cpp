/*************************************************************************
    > File Name: hihocoder_1039.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: 2017年01月05日 星期四 15时41分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

//decide whether the string is the last one
bool HasSameLetter(const string & Str)
{
	bool result=false;
	for(int i=0;i<(int)Str.size()-1;i++)
	{
		if(Str[i]==Str[i+1])
		{
			result=true;
			break;
		}
	}
	return result;
}
int main()
{
	int T=0;
	cin>>T;
	//ignore an character of '\n'
	cin.ignore();

	//start the processor
	string INSERTION="ABC";
	while(T--)
	{
		//get the string
		string Str;
		getline(cin,Str);
	
		int result=-1;
		//insert a character in the str
		for(int i=0;i<=Str.size();i++)
		{
			//devide the string into two parts
			string Left=Str.substr(0,i);
			string Right=Str.substr(i,Str.size()-i);

			string Temp;
			for(int k=0;k<INSERTION.size();k++)
			{
				Temp=Left+INSERTION[k]+Right;

				//start processing the string
				while(HasSameLetter(Temp))
				{
					string Reduce;
					int start=0;
					while(start<Temp.size())
					{
						int tag=start+1;
						while(tag<Temp.size()&&Temp[tag]==Temp[start])
							tag++;
						if(tag==start+1)
						{
							Reduce.push_back(Temp[start]);
							start++;
						}
						else
						{
							start=tag;
						}

					}
					Temp=Reduce;

					if(result<(int)Str.size()-(int)Temp.size()+1)
						result=(int)Str.size()-(int)Temp.size()+1;
				}
			}
		}
		cout<<result<<endl;
		
	}
	return 0;
}
