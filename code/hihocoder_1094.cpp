/*************************************************************************
    > File Name: hihocoder_1094.cpp
    > Author: bjzhang03
    > Mail: bjzhang1991@gmail.com
    > Created Time: 2017年01月05日 星期四 21时35分16秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Judge the position is right
bool JudgePosition(const vector<string> & map,const vector<string> &environments,int  prow,int pcol)
{
	bool result=true;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			result=(result&&(environments[i][j]==map[prow-1+i][pcol-1+j]));
			if(!result)
				return result;
		}
	}
	return result;
}

//Rotate the environment
void RotateEnvironments(vector<string> &environments)
{
	char** P=new char*[3];
	for(int i=0;i<3;i++)
		P[i]=new char[3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			P[j][2-i]=environments[i][j];
		}
	}

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			environments[i][j]=P[i][j];
		}
	}

	//free the space
	for(int i=0;i<3;i++)
		delete [] P[i];
	delete [] P;
}

int main()
{

	int N=0,M=0,T=3;
	cin>>N>>M;
	cin.ignore();

	vector<string> map;
	while(N--)
	{
		string Temp;
		getline(cin,Temp);
		map.push_back(Temp);
	}
	vector<string> environments;
	while(T--)
	{
		string Temp;
		getline(cin,Temp);
		environments.push_back(Temp);
	}

	if(map.empty())
	{
		cout<<endl;
		return 0;
	}
	for(int i=1;i<map.size()-1;i++)
	{
		for(int j=1;j<map[i].size()-1;j++)
		{
			bool result=false;
			vector<string> NewEnv=environments;
			for(int loop=0;loop<4;loop++)
			{
				RotateEnvironments(NewEnv);
				result=(result||JudgePosition(map,NewEnv,i,j));
			}
			if(result)
			{
				cout<<(i+1)<<" "<<(j+1)<<endl;
			}
		}
	}

	return 0;
}
