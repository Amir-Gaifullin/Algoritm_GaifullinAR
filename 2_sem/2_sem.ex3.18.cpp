#include <iostream>
#include <stack>
// сразу заимпортил готовый стек(очень удобно)
#include <stdlib.h>
using namespace std;

struct Grehem
{
    int x, y;
};

Grehem p0;
Grehem nextToTop(stack<Grehem> & Stack)

{
    Grehem p = Stack.top();
    Stack.pop();
    Grehem res = Stack.top();
    Stack.push(p);
    return res;
}

int swap(Grehem &p1, Grehem &p2)
{
    Grehem temp = p1;
    p1 = p2;
    p2 = temp;
}

int distSq(Grehem p1, Grehem p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
           (p1.y - p2.y)*(p1.y - p2.y);
}

int orientation(Grehem p, Grehem q, Grehem r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

int compare(const void *vp1, const void *vp2)
{
    Grehem *p1 = (Grehem *)vp1;
    Grehem *p2 = (Grehem *)vp2;

    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

    return (o == 2)? -1: 1;
}

void convex_hull(Grehem Grehems[], int n)
{
    int ymin = Grehems[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = Grehems[i].y;

        if ((y < ymin) || (ymin == y &&
                           Grehems[i].x < Grehems[min].x))
            ymin = Grehems[i].y, min = i;
    }

    swap(Grehems[0], Grehems[min]);
    p0 = Grehems[0];
    qsort(&Grehems[1], n-1, sizeof(Grehem), compare);
    int m = 1;
    for (int i=1; i<n; i++)
    {
        while (i < n-1 && orientation(p0, Grehems[i], Grehems[i+1]) == 0)
            i++;


        Grehems[m] = Grehems[i];
        m++;
    }

    if (m < 3) return;
    stack<Grehem> Stack;
    Stack.push(Grehems[0]);
    Stack.push(Grehems[1]);
    Stack.push(Grehems[2]);

    for (int i = 3; i < m; i++)
    {
        while (orientation(nextToTop(Stack), Stack.top(), Grehems[i]) != 2)
            Stack.pop();
        Stack.push(Grehems[i]);
    }

    while (!Stack.empty())
    {
        Grehem p = Stack.top();
        cout << "(" << p.x << ", " << p.y <<")" << endl;
        Stack.pop();
    }
}

int main()
{
//    n = 1000000;
//    Grehems = new int[n+1][n+1];
//    ifstream fin;
//    fin.open("test1.txt");
//    int count = 0
//    for (int i=1; i<=n; i++) {
//        int x,y;
//        count++
//        fin >> x,y;
//        value[count] = {x,y};
//    }
    Grehem Grehems[] = {{0, 4}, {10, 9}, {5, 5}, {5, 2},
                        {0, 0}, {8, 7}, {1, 1}, {20, 15}};
    int n = sizeof(Grehems)/sizeof(Grehems[0]);
//    double startTime = clock();
    convex_hull(Grehems, n);
//    double endTime = clock();
//    double totalTime = endTime - startTime;
//    cout << totalTime
    return 0;
}