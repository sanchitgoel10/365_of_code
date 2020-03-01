#include<bits/stdc++.h>
using namespace std;

int countsub(string input,string ouput[])
{
	if(input.empty())
	{ 
		ouput[0]="";
		return 1;
	}
	string s=input.substr(1);
	int smallouputsize=countsub(s,ouput);
	for(int i=0;i<smallouputsize;i++)
	{
		ouput[i+smallouputsize]=input[0] + ouput[i];
	}
	return 2*smallouputsize;
}



int main()
{
	string input;
	cin>>input;
	string* output=new string[1000];
	int count= countsub(input,output);
	for(int i=0;i<count;i++)
	{
		cout<<output[i]<<endl;
	}
}
