
/*

   求多边形与圆相交的面积

*/

#include <iostream>

#include <cstdio>

#include <cmath>

#define max(x, y) ((x) > (y) ? (x) : (y))

#define min(x, y) ((x) < (y) ? (x) : (y))

#define PI acos(-1.0)

#define EPS 1e-8

using namespace std;

inline int DB(double x)
{

    if (x < -EPS)
        return -1;

    if (x > EPS)
        return 1;

    return 0;
}

struct point
{

    double x, y;

    point() {}

    point(double _x, double _y) : x(_x), y(_y) {}

    point operator-(point a)
    {

        return point(x - a.x, y - a.y);
    }

    point operator+(point a)
    {

        return point(x + a.x, y + a.y);
    }

    double operator*(point a)
    {

        return x * a.y - y * a.x;
    }

    point oppose()
    {

        return point(-x, -y);
    }

    double length()
    {

        return sqrt(x * x + y * y);
    }

    point adjust(double L)
    {

        L /= length();

        return point(x * L, y * L);
    }

    point vertical()
    {

        return point(-y, x);
    }

    double operator^(point a)
    {

        return x * a.x + y * a.y;
    }
};

struct segment
{

    point a, b;

    segment() {}

    segment(point _a, point _b) : a(_a), b(_b) {}

    point intersect(segment s)
    {

        double s1 = (s.a - a) * (s.b - a);

        double s2 = (s.b - b) * (s.a - b);

        double t = s1 + s2;

        s1 /= t;

        s2 /= t;

        return point(a.x * s2 + b.x * s1, a.y * s2 + b.y * s1);
    }

    point vertical(point p)
    {

        point t = (b - a).vertical();

        return intersect(segment(p, p + t));
    }

    int isonsegment(point p)
    {

        return DB(min(a.x, b.x) - p.x) <= 0 &&

               DB(max(a.x, b.x) - p.x) >= 0 &&

               DB(min(a.y, b.y) - p.y) <= 0 &&

               DB(max(a.y, b.y) - p.y) >= 0;
    }
};

struct circle
{

    point p;

    double R;
};

circle C;

point p[5005];

int n;

double cross_area(point a, point b, circle C)
{

    point p = C.p;

    double R = C.R;

    int sgn = DB((b - p) * (a - p));

    double La = (a - p).length(), Lb = (b - p).length();

    int ra = DB(La - R), rb = DB(Lb - R);

    double ang = acos(((b - p) ^ (a - p)) / (La * Lb));

    segment t(a, b);

    point s;

    point h, u, temp;

    double ans, L, d, ang1;

    if (!DB(La) || !DB(Lb) || !sgn)
        ans = 0;

    else if (ra <= 0 && rb <= 0)
        ans = fabs((b - p) * (a - p)) / 2;

    else if (ra >= 0 && rb >= 0)
    {

        h = t.vertical(p);

        L = (h - p).length();

        if (!t.isonsegment(h) || DB(L - R) >= 0)
            ans = R * R * (ang / 2);

        else
        {

            ans = R * R * (ang / 2);

            ang1 = acos(L / R);

            ans -= R * R * ang1;

            ans += R * sin(ang1) * L;
        }
    }
    else
    {

        h = t.vertical(p);

        L = (h - p).length();

        s = b - a;

        d = sqrt(R * R - L * L);

        s = s.adjust(d);

        if (t.isonsegment(h + s))
            u = h + s;

        else
            u = h + s.oppose();

        if (ra == 1)
            temp = a, a = b, b = temp;

        ans = fabs((a - p) * (u - p)) / 2;

        ang1 = acos(((u - p) ^ (b - p)) / ((u - p).length() * (b - p).length()));

        ans += R * R * (ang1 / 2);
    }

    return ans * sgn;
}

double cal_cross(circle C, point p[], int n)
{

    double ans = 0;

    int i;

    p[n] = p[0];

    for (i = 0; i < n; i++)
        ans += cross_area(p[i], p[i + 1], C);

    return fabs(ans);
}
double polygonarea(int N)
{
    int i, j;
    double area = 0;
    for (i = 0; i < N; i++)
    {
        j = (i + 1) % N;
        area += p[i].x * p[j].y;
        area -= p[i].y * p[j].x;
    }
    area /= 2;
    return (area < 0 ? -area : area);
}
double x, y, v, det, t, g, R;
int main()
{
    int n, m;
    //freopen("test.in","r",stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf %lf", &p[i].x, &p[i].y);
    double sum;
    sum = polygonarea(n);
    sum = fabs(sum);
    det = det / 180 * PI;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        double ans;
        double w, q;
        scanf("%lf %lf %lf %lf", &C.p.x, &C.p.y, &w, &q);
        ans = sum - sum * w * 1.0 / q;
        double l = 0.0, r = 1000000;
        while (r - l > 1e-10)
        {
            C.R = (l + r) * 0.5;
            double area = cal_cross(C, p, n);
            /* if(abs(area-ans)<=1e-7)
                {
                    printf("%.12lf\n", C.R);
                    break;
                } */
            if (area > ans)
            {
                r = C.R;
            }
            else
                l = C.R;
        }
        printf("%.10lf\n", l);
    }

    //double area = cal_cross(C, p, n);
    return 0;
}
