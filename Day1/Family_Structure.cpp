#include<bits/stdc++.h>
using namespace std;

string parent(long long int n)
{
	if(n==2 || n==1)
		return "Male";
	else if(n==3)
		return "Female";
	else
	{	
		long long int node=n,p=floor(n/2);
	 	string r=parent(p);
        if (r == "Male")
		{
        	if (node == (p * 2))
                return "Male";
            else
            	return "Female";
        } 
		else 
		{
          if (node == (p * 2))
            return "Female";
          else
            return "Male";
        }
    }
}

string kthChildNthGeneration(int n, long long int k)
{
	long long int StartNodeOfGen=pow(2,n-1);
	long long int Node=StartNodeOfGen + (k-1);
	if(k==1)
		return "Male";
	string res=parent(Node);
	return res;

}

int main()
{
    int t;
    cin >>t;
    for(int i=0;i<t;i++)
    {

        int n;
        long long int k;
        cin >> n >> k;
        string res=kthChildNthGeneration(n,k);
        cout << res << endl;
    }
    return 0;
}