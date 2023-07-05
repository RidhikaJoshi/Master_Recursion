/*
We are given a interger 'N'.we need to generate all Binary strings of Length 'N' such that there are no consecutives 1's in the resultant string.
*/

#include<bits/stdc++.h>
using namespace std;

int helper(int n,string &str)
{
    if(n==0)
        return 1;
    if(str.length()==0)
        str+=char((n%2)+48);
    else if(str[str.length()-1]=='0')
        str+=char((n%2)+48);
    else if(str[str.length()-1]=='1')
    {
        if(n%2==1)
            return 0;
        else
            str+='0';
    }
    return helper(n/2,str);
}

vector<string> generateString(int N)
{
    vector<string>result;
    for(int i=0;i<pow(2,N);i++)
    {
        string str="";
        if (helper(i, str))
        {
            str.append(N-str.length(), '0');
            reverse(str.begin(), str.end());
            result.push_back(str);
        }
    }
   return result;
   
}

int main()
{
    int N;
    cin >> N;
    vector<string>res=generateString(N);
    for(int i=0;i<res.size();i++)
    {
        cout << res[i]<< endl;
    }
    return 0;
}