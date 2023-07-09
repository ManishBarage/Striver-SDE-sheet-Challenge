#include <bits/stdc++.h> 
int atoi(string str) {
    int ans = 0;
    int i=0;
    int sign =1;

    if(str[i]=='-')
    {
        sign =-1;
        i++;
    }

    while(i<str.length())
    {
        if(str[i]-'0' >=0 && str[i]-'0'<=9)
        {
            ans = ans*10 + str[i]-'0';
        }
        i++;
    }

    return ans*sign;
}