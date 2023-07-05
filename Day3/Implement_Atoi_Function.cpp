/*
Given a string str of length n.Implement the atoi function.If thers is no numbers in the string return 0;
In other words,convert the string into integer.
*/

#include <bits/stdc++.h>
using namespace std;

int helper(string str,int res,int i)
{
    if(i==str.length())
        return res ;
    else
    {
        if((str[i]>='0' && str[i]<='9'))
            res=res*10+(int(str[i])-48);
        return helper(str,res,i+1);
    }
}
int atoi(string str)
{
    int res=0;
    int ans=helper(str,res,0);
    if(str[0]=='-')
        return ans*-1;
    return ans;

}
int main()
{
    string str;
    cin >> str;
    int ans=atoi(str);
    cout << ans << endl;
}
