#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int xmax,xmin,ymax,ymin;

int bit_convert(int x,int y)
{
    int cnt = 0;
    if((y-ymax) > 0)
    {
        cnt = cnt | (1<<3);
    }
    if((ymin-y) > 0)
    {
        cnt = cnt | (1<<2);
    }
    if((x-xmax) > 0)
    {
        cnt = cnt | (1<<1);
    }
    if((xmin-x) > 0)
    {
        cnt = cnt | (1<<0);
    }
    return cnt;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    cout << "Enter xmin: ";
    cin >> xmin;
    cout << "Enter xmax: ";
    cin >> xmax;
    cout << "Enter ymin: ";
    cin >> ymin;
    cout << "Enter ymax: ";
    cin >> ymax;
    line(xmin,ymin,xmax,ymin);
    line(xmin,ymax,xmax,ymax);
    line(xmin,ymax,xmin,ymin);
    line(xmax,ymax,xmax,ymin);
    cout << "Enter number of lines: ";
    int n,i,j,k,x1,x2,y1,y2,fcode,scode;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        line(x1,y1,x2,y2);
        fcode = bit_convert(x1,y1);
        scode = bit_convert(x2,y2);
        if((fcode == 0) && (scode == 0))
        {
            cout << "Visible\n";
        }
        else
        {
            k = fcode & scode;
            if(k == 0)
            {
                cout << "Visible candidate\n";
            }
            else
            {
                cout << "Invisible\n";
            }
        }
    }
    delay(10000);
    getch();
    closegraph();
}
