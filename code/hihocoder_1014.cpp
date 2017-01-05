/*************************************************************************
    > File Name: hihocoder_1014.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: 2017年01月05日 星期四 18时34分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

//struct of the trie node
struct TrieNode{
	int Num;
	TrieNode* Next[26];
	TrieNode()
	{
		Num=0;
		for(int i=0;i<26;i++)
			Next[i]=NULL;
	}
}root;

//insert node into the tree
void Insert(string Str)
{
	TrieNode *p=&root;
	for(int i=0;i<Str.size();i++)
	{
		int position=Str[i]-'a';
		if(p->Next[position]==NULL)
			p->Next[position]=new TrieNode();
		p=p->Next[position];
		p->Num++;
	}
}

//find the number of letter
int find(string Str)
{
	TrieNode *p=&root;
	for(int i=0;i<Str.size();i++)
	{
		int position=Str[i]-'a';
		if(NULL==p->Next[position])
			return 0;
		p=p->Next[position];
	}
	return p->Num;
}

int main()
{
	int n=0,m=0;
	cin>>n;
	cin.ignore();
	while(n--)
	{
		string One;
		getline(cin,One);
		Insert(One);
	}
	cin>>m;
	cin.ignore();
	while(m--)
	{
		string Two;
		getline(cin,Two);
		cout<<find(Two)<<endl;
	}
	return 0;
}
