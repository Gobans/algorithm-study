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
    else if(x < 0) return -1;
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<ll, ll> a,b,c,d;
    cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y >> d.X >> d.Y;

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
            cout << 1 << '\n';
            double tmp_point_x = (a.X * b.Y - a.Y * b.X) * (c.X - d.X) - (a.X - b.X) * (c.X * d.Y - c.Y * d.X);
	        double tmp_point_y = (a.X * b.Y - a.Y * b.X) * (c.Y - d.Y) - (a.Y - b.Y) * (c.X * d.Y - c.Y * d.X);
	        double tmp_dy = (a.X - b.X) * (c.Y - d.Y) - (a.Y - b.Y) * (c.X - d.X);

            if (tmp_dy == 0) //평행한 경우.  1,2번의 경우 좌표 출력하지 않음.
            {
                if (b == c && a <= c) //3번
                    cout << b.X << " " << b.Y << '\n';
                else if (a == d && c <= a)
                    cout << a.X << " " << a.Y << '\n';
            }
            else //4번
            {
                double x = tmp_point_x / tmp_dy;
                double y = tmp_point_y / tmp_dy;
                
                cout << fixed;
                cout.precision(15);
                cout << x << " " << y;
            }
        }
        else  //안겹치는 경우 2번.
            cout << 0 << '\n';
    }
    else  //일반적인 평행하지않으면서 겹치는 직선, 겹치지 않는 직선
    {
        if (tmp_ab <= 0 && tmp_cd <= 0) //둘이 한점에서 만나는 경우
        {
            double tmp_point_x = (a.X * b.Y - a.Y * b.X) * (c.X - d.X) - (a.X - b.X) * (c.X * d.Y - c.Y * d.X);
	        double tmp_point_y = (a.X * b.Y - a.Y * b.X) * (c.Y - d.Y) - (a.Y - b.Y) * (c.X * d.Y - c.Y * d.X);
	        double tmp_dy = (a.X - b.X) * (c.Y - d.Y) - (a.Y - b.Y) * (c.X - d.X);
                
            double x = tmp_point_x / tmp_dy;
            double y = tmp_point_y / tmp_dy;
            
            cout << 1 << '\n';
            cout << fixed;
            cout.precision(15);
            cout << x << " " << y;
        }
        else //만나지 않은 경우.1 1
            cout << 0 << '\n';
    }
}
