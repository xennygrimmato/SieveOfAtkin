#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void printull(vector<unsigned long long> vec)
{
	vector<unsigned long long>::iterator it;
	for(it=vec.begin();it!=vec.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<"\n";
}
/*
void printbool(vector<bool> vec)
{
	vector<bool>::iterator it;
	for(it=vec.begin();it!=vec.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<"\n";
}
*/
int main()
{
	unsigned long long start,end;
	cin>>start>>end;
	unsigned long long RANGE=end-start+1;
	vector<unsigned long long> v(RANGE+4);
	vector<unsigned long long> res;
	vector<bool> is_prime(RANGE);
	v.clear();
	res.clear();
	for(int i=start;i<=end;i++)
	{
		v.push_back(i);
	}
	vector<unsigned long long>::iterator it;
	res.push_back(2);
	res.push_back(3);
	for(unsigned long long x=1;x<=sqrt(end);x+=1)
	{
		for(unsigned long long y=1;y<=sqrt(end);y+=1)
		{
		    unsigned long long n;
		    n=4*x*x + y*y;
    		if((n<=end) && ((n%12==1) || (n%12==5)))
    		{
        		if(is_prime[n]==1)
        			is_prime[n]=0;
        		else
        			is_prime[n]=1;
        	}
    		n=3*x*x + y*y;
    		
    		if((n<=end) && (n%12==7))
    		{
        		if(is_prime[n]==1)
        			is_prime[n]=0;
        		else
        			is_prime[n]=1;
        	}
    		n=3*x*x - y*y;
    		if((x>y) && (n<=end) && (n%12==11))
        	{
        		if(is_prime[n]==1)
        			is_prime[n]=0;
        		else
        			is_prime[n]=1;
        	}
		}
	}
	
	for(unsigned long long n=5;n<=sqrt(end);n++)
	{
		if(is_prime[n]==1)
		{
			for(unsigned long long k = n*n;k<=end;k+=(n*n))
			{
				is_prime[k]=0;
			}
		}
	}
	
	for(unsigned long long n=5;n<=end;n++)
	{
		if(is_prime[n]==1)
			res.push_back(n);
	}
	
	printull(res);
	return 0;
}
