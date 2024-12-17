#include<iostream>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

using namespace std;
class algo
{
public:void dda_line(float x1,float y1,float x2,float y2);
       void bresenham_cir(int r); 
};

void algo::dda_line(float x1,float y1,float x2,float y2)  //DDA line

{
float x,y,dx,dy,Dx,Dy,length;
int i,c;

dx=abs(x2-x1);
dy=abs(y2-y1);
if(dx>=dy)
{
length=dx;
}
else
{
length=dy;
}
Dx=(x2-x1)/length;
Dy=(y2-y1)/length;
x=x1+0.5;
y=y1+0.5;
i=0;
while(i<=length)
{
putpixel(320+x,240-y,3);
x=x+Dx;
y=y+Dy;
i=i+1;
}
}
void algo::bresenham_cir(int r)
{
int x,y,d,c;
x=0;
y=r;
d=3-(2*r);
do
{
putpixel(320+x,240+y,3);
putpixel(320-x,240+y,3);
putpixel(320+x,240-y,3);
putpixel(320-x,240-y,3);
putpixel(320+y,240+x,3);
putpixel(320-y,240+x,3);
putpixel(320+y,240-x,3);
putpixel(320-y,240-x,3);

if(d<=0)
{
d=d+(4*x)+6;
y=y;
}
else
{
d=d+(4*(x-y))+6;
y=y-1;
}
x=x+1;
}
while(x<y);
}
int main()
{
    algo a1;
    int gm,gd=DETECT;
    int i;
    float r,ang,r1;

    cout<<"\n Enter the radius of large circle=";
    cin>>r;

    initgraph(&gd,&gm,NULL);
    a1.bresenham_cir((int)r);
    ang=3.14/180;
    float c=r*cos(30*ang);
    float s=r*sin(30*ang);
    a1.dda_line(0,r,0-c,0-s);
    a1.dda_line(0-c,0-s,0+c,0-s);
    a1.dda_line(0+c,0-s,0,r);
            r1=s;
    a1.bresenham_cir((int)r1);
    delay(5000);
    return 0;

}









