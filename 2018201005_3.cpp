#include<bits/stdc++.h>
#include<fstream>
#include<sys/stat.h>
#define ll long long
using namespace std;

int main(void) 
{
	struct stat buf;
	ofstream fptr1;
  	ifstream fptr;
	ll num,i,j;
	string input,output;
	int x=0;
	cin>>input;
	cin>>output;
	if(stat(input.c_str(),&buf)==-1)
	{
		cout<<"File does not exist"<<endl;
		return 0;
	}
	vector<ll> v;
	fptr.open(input);
	i=0;
	while(fptr>>num)
	{
		if(i%1000000==0 && i!=0)
		{
		  i=0;
		  string x1=to_string(x);
		  fptr1.open(x1,fstream::out);
		  fptr1.close();
		  fptr1.open(x1);
		  sort(v.begin(),v.end());
		  for(j=0;j<v.size();j++)
		    fptr1<<v[j]<<endl;
		  x++;
		  fptr1.close();
		  v.clear();
		}
		v.push_back(num);
		i++;
	}
	string x1=to_string(x);
	fptr1.open(x1,fstream::out);
	fptr1.close();
	fptr1.open(x1);
	sort(v.begin(),v.end());
	for(j=0;j<v.size();j++)
	{
	 	fptr1<<v[j]<<endl;
	}
	fptr.close();
	fptr1.close();
	fptr1.open(output,fstream::out);
	fptr1.close();
	fptr1.open(output);
	for(i=x;i>=0;i--)
	{
		fptr.open(to_string(i));
		while(fptr>>num)
			fptr1<<num<<endl;
		fptr.close();
		char *a;
		a=new char[to_string(i).length()+1];
		strcpy(a,to_string(i).c_str());
		remove(a);
	}
	fptr1.close();
	return 0;
}