/*************************************************************************
    > File Name: hihocoder_1051.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: 2017年01月05日 星期四 19时43分58秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

//get the length of the longest interval
int LongestInterval(const vector<int> &AllDays)
{
	int result=0;
	int spos=1,epos=1;
	while(epos<AllDays.size())
	{
		while(epos<AllDays.size()&&0==AllDays[epos])
			epos++;
		if(epos==AllDays.size()-1&&AllDays[epos]==0)
			epos++;
		if(epos-spos>=result)
			result=epos-spos;
		while(spos<AllDays.size()&&0==AllDays[spos])
			spos++;
		spos++;
		epos++;
	}
	return result;
}

int main()
{
	int T=0;
	cin>>T;
	while(T--)
	{
		vector<int> AllDays(101,0);
		int N=0,M=0;
		cin>>N>>M;

		if(M>=N)
		{
			while(N--)
			{
				int Node=0;
				cin>>Node;
			}
			cout<<100<<endl;
		}
		else
		{
			vector<int> candidate;
			while(N--)
			{
				int Node=0;
				cin>>Node;
				AllDays[Node]=1;
				candidate.push_back(Node);
			}

			int Length=0;
			
			for(int i=0;i<=candidate.size()-M;i++)
			{
				vector<int> NewAllDays=AllDays;
				for(int j=i;j<i+M;j++)
				{
					NewAllDays[candidate[j]]=0;
				}
				
				if(Length<LongestInterval(NewAllDays))
					Length=LongestInterval(NewAllDays);
			}
			cout<<Length<<endl;
		}
	}
	return 0;
}
