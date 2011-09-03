#include <iostream>

using namespace std;

int pasos(int a,int b)
{
	int c=b-a;
	int count=0;
	for(int w=1;w>0;w++)
	{
		if(c>=(w*2))
		{
			c-=w*2;
			count+=2;
		}
		else if(c>=(w))
		{
			c-=w;
			count++;;
		}
		else if(c==0)
		 return count;
		else
		{
			count++;
			return count;		
		}
		
	}
}

int main(int argc, char **argv)
{
	int w=0;
	cin>>w;
	for(int p=0;w>p;p++)
	{
		int min,max;
		cin>>min;
		cin>>max;
		cout<<pasos(min,max)<<endl;
	}
	return 0;
}

