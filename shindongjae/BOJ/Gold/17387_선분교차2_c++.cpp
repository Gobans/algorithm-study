#include <iostream>
#include <algorithm>

#define ll long long int
using namespace std;


int e_p(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll,ll> p3)
{
    ll x = p1.first*p2.second + p2.first*p3.second+p3.first*p1.second
            -(p1.second*p2.first+p2.second*p3.first+p3.second*p1.first);
    if(x > 0) return 1;
    else if(x < 0) return -1;
    else return 0;
}

int main()
{
	pair<ll, ll> a,b,c,d;
	cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second>>d.first>>d.second;

	int abc = e_p(a,b,c);
    int abd = e_p(a,b,d);
    int cda = e_p(c,d,a);
    int cdb = e_p(c,d,b);


    if(abc*abd == 0 && cda*cdb == 0)
    {
        if(a>b) swap(a,b);
        if(c>d) swap(c,d);
        if(a<=d && c<=b)
            cout<<1;
        else
            cout<<0;

    }
	else if(abc*abd <= 0 && cda*cdb <= 0)
        cout << 1;
    else
        cout << 0;
}