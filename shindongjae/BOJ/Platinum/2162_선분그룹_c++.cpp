#include <iostream>
#include <algorithm>

#define X first
#define Y second
#define ll long long
using namespace std;


ll e_p(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c)
{
    ll x = a.X * b.Y + b.X * c.Y + c.X * a.Y - (a.Y * b.X + b.Y * c.X + c.Y * a.X);

    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

ll is_meet(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d)
{
    ll abc, abd, cda, cdb;
    abc = e_p(a, b, c);
    abd = e_p(a, b, d);
    cda = e_p(c, d, a);
    cdb = e_p(c, d, b);

    ll tmp_ab, tmp_cd;
    tmp_ab = abc * abd;
    tmp_cd = cda * cdb;

    if (tmp_ab == 0 && tmp_cd == 0)
    {
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        if (a <= d && c <= b) // 겹치는 경우.  1 3 4번
        {
            return 1;
        }
        else  //안겹치는 경우 2번.
            return 0;
    }
    else  //일반적인 평행하지않으면서 겹치는 직선, 겹치지 않는 직선
    {
        if (tmp_ab <= 0 && tmp_cd <= 0) //둘이 한점에서 만나는 경우
            return 1;
        else //만나지 않은 경우.1 1
            return 0;
    }
}

ll group[3000];
ll num[3000] = {0};

ll Find(ll a) {
    if (group[a] == a) return a;
    return group[a] = Find(group[a]);
}

void Union(ll a, ll b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
    {
        if (a < b)
            group[b] = a;
        else
            group[a] = b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    ll n;
    cin >> n;
    pair<ll, ll> vec[3000][2];
    for (ll i = 0; i < n; i++)
    {
        group[i] = i;
        cin >> vec[i][0].X >> vec[i][0].Y;
        cin >> vec[i][1].X >> vec[i][1].Y;
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (is_meet(vec[i][0], vec[i][1], vec[j][0], vec[j][1]))
            {
                Union(i, j);
            }
        }
    }


    ll num_group=0;
    ll max_group=0;

    for(ll i = 0; i < n; i++)
    {
        if(group[i] == i) num_group++;
        num[Find(i)]++;
        if(num[Find(i)] > max_group)
            max_group = num[Find(i)];
    }

    cout << num_group << '\n' << max_group;
}