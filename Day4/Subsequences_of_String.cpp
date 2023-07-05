/*
We are given a string "STR" containing lower case english letters. we need to find all non empty subsequences of "STR".
*/
#include <bits/stdc++.h>
using namespace std;

void helper(int n,string &s)
{
	if(n==0)
		return;
	else
	{
		s+=char(n%2+48);
		helper(n/2,s);
	}
} 
vector<string> subsequences(string str)
{
	int n=str.length();
	vector<string>result;
	for(int i=1;i<pow(2,n);i++)
	{
		string s="";
		helper(i,s);
		string r="";
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='1')
				r+=str[i];
		}
		result.push_back(r);
	}
	return result;
	
	
}
int main()
{
    int t;
    cin >> t;
    string str;
    for(int i=0;i<t;i++)
    {
        cin >> str;
        vector<string>res=subsequences(str);
        for(int i=0;i<res.size();i++)
        {
            cout << res[i] << endl;
        }
    }
    return 0;
}