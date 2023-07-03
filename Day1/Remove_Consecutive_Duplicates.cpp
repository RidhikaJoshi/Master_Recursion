/*
We are given a string "str" of length 'N'. We need to remove Consecutive duplicates from the given string recursively.
*/

#include<bits/stdc++.h>
using namespace std;

void removeDuprec(string &s,string &res,int i)
{
    if(i==s.length())
        return ;
    removeDuprec(s, res,i+1);
    if(s[i]!=s[i-1])
        res+=s[i];
}
string removeDuplicate(string &s)
{
   string res="";
   int i=1;
   removeDuprec(s,res,i);
   res+=s[0];
   reverse(res.begin(),res.end());
   return res;
}
int main()
{
    int t,N;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> N;
        string s;
        cin >> s;
        string ans=removeDuplicate(s);
        cout << ans << endl;
    }
    return 0;
}