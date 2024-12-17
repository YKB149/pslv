#include<graphics.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
class algo
{
	public:
	void dda_line(float x1,float y1,float x2, float y2);
	void bresenham_cir(int r);
	
};
void algo::dda_line(float x1,float y1,float x2, float y2) //DDA LINE
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
		putpixel(x,y,15);
		x=x+Dx;
		y=y+Dy;
		i=i+1;
delay(50);
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
putpixel(320+x,240+y,15);
putpixel(320-x,240+y,15);
putpixel(320+x,240-y,15);
putpixel(320-x,240-y,15);
putpixel(320+y,240+x,15);
putpixel(320-y,240+x,15);
putpixel(320+y,240-x,15);
putpixel(320-y,240-x,15);

if(d<=0)
{
d=d+4*x+6;
}
else
{
d=d+4*(x-y)+6;
y=y-1;
}
x=x+1;
}while(x<y);
}
int main()
{
	algo al;
	int gm,gd=DETECT,r;
	float x1,y1,x2,y2;
	
	cout<<"\n Enter the coordinate of first point (x1,y1)=";
	cin>>x1>>y1;
	cout<<"\n Enter the coordinate of first point (x2,y2)=";
	cin>>x2>>y2;
	cout<<"\n Enter the radiud of the circle(r)=";
	cin>>r;
     initgraph(&gd,&gm,NULL);
	al.dda_line(x1,y1,x2,y2);
	al.bresenham_cir(r);
	delay(5000);
	return 0;
}































