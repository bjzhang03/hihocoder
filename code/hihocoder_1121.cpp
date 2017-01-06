/*************************************************************************
    > File Name: hihocoder_1121.cpp
    > Author: bjzhang03
    > Mail: bjzhang1991@gmail.com
    > Created Time: 2017年01月06日 星期五 19时10分02秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int main()
{
	int T=0;
	cin>>T;
	while(T--)
	{
		int N=0,M=0;
		cin>>N>>M;

		vector<int> *P=new vector<int>[N+1]();

		while(M--)
		{
			int Node1=0,Node2=0;
			cin>>Node1>>Node2;

			P[Node1].push_back(Node2);
			P[Node2].push_back(Node1);
		}

		//find a size>0 node
		set<int> One,Two;
		int start=0;
		for(int i=0;i<=N;i++)
			if(0==P[i].size())
				One.insert(i);
			else
				start=i;

		string result="Correct";
		while(N>=(One.size()+Two.size()))
		{
			int start=0;
			//find a node which size is greater than 0

			queue<int> TempNode;
			Two.insert(start);
			TempNode.push(start);
			while(!TempNode.empty())
			{
				if("Wrong"==result)
					break;

				int CurrentNode=TempNode.front();
				TempNode.pop();

				int tag=1;
				if(One.find(CurrentNode)!=One.end())
					tag=-1;

				if(1==tag)
				{
					//insert node into One
					for(int i=0;i<P[CurrentNode].size();i++)
					{
						if(One.find(P[CurrentNode][i])==One.end()&&Two.find(P[CurrentNode][i])==Two.end())
						{
							TempNode.push(P[CurrentNode][i]);
						}
						else if(Two.find(P[CurrentNode][i])!=Two.end())
						{
							result="Wrong";
							break;
						}
						One.insert(P[CurrentNode][i]);
					}
				}
				else
				{
					//insert node into Two
					for(int i=0;i<P[CurrentNode].size();i++)
					{
						if(One.find(P[CurrentNode][i])==One.end()&&Two.find(P[CurrentNode][i])==Two.end())
						{
							TempNode.push(P[CurrentNode][i]);
						}
						else if(One.find(P[CurrentNode][i])!=One.end())
						{
							result="Wrong";
							break;
						}
						Two.insert(P[CurrentNode][i]);
					}
				}				
			}
		}
		cout<<result<<endl;
		result="Correct";
	}
	return 0;
}
