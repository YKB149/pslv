#include<iostream.h>
#include<process.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

int i, j, k;     //Decleration of Variables
class Transfn    //Definition of class
{
	private:   //Access Specifiers
		int n, Before[10][3], After[10][3];
		float T[3][3];
	public:    //Access specifiers
		void GetData();    //Member functions
		void Menu();
		void Multi();
		void Drawpoly();
};
//We access the get data member function by using scope resolution operator

void Transfn::GetData()
{
	cout<<"\n\n\tEnter the number of vertices==>";
	cin>>n;
	cout<<"\n\tEnter the coordinates of vertices==>";
	for(i=0;i<n;i++)
	{
		cin>>Before[i][0];
		cin>>Before[i][1];
		Before[i][2]=1;
	}

	Before[n][0]=Before[0][0];
	Before[n][1]=Before[0][1];
	Before[i][2]=1;

	cout<<"\n\n\tMatrix Representation is==>\n\n";

//By using Matrix Representation
for(i=0;i<n;i++)
	{
		cout<<"\n\n\t";
		for(j=0;j<3;j++)
		{
			cout<<"\t";
			cout<<Before[i][j];
		}
	}
}

//Menu function for performing different types of transformations

void Transfn::Menu()
{
	int nCh, Tx, Ty, nC, nChoice, Sx, Sy, nChoice1;
	double X;
	float Shx, Shy, Xp, Yp;
	cout<<"\n\n\t1.Translation.\n\n\t2.Rotation.\n\n\t3.Scaling.";
	cout<<"\n\n\t4.Exit.";
	cin>>nCh;
	switch(nCh)
	{
		case 1:
			cout<<"\n\tEnter the translation coordinates Tx==>";
			cin>>Tx;
			cout<<"\n\tEnter the translation coordinates Ty==>";
			cin>>Ty;
			T[0][0]=1;
			T[0][1]=0;
			T[0][2]=0;
			T[1][0]=0;
			T[1][1]=1;
			T[1][2]=0;
			T[2][0]=Tx;
			T[2][1]=Ty;
			T[2][2]=1;
			break;
		case 2:
			cout<<"\n\n1.Counter Clockwise.";
			cout<<"\n\n2.Clockwise";
			cout<<"\n\nEnter TYour choice==>";

			cin>>nC;
			cout<<"\n\n\tEnter the angle==>";
			cin>>X;
			X=X*(3.1432/180);
			if(nC==1)
			{
				T[0][0]=cos(X);
				T[0][1]=sin(X);
				T[0][2]=0;
				T[1][0]=(-1)*sin(X);
				T[1][1]=cos(X);
				T[1][2]=0;
				T[2][0]=0;
				T[2][1]=0;
				T[2][2]=1;
			}
			else
			{
				T[0][0]=cos(X);
				T[0][1]=(-1)*sin(X);
				T[0][2]=0;
				T[1][0]=sin(X);
				T[1][1]=cos(X);
				T[1][2]=0;
				T[2][0]=0;
				T[2][1]=0;
				T[2][2]=1;
			}
			break;
		case 3:
			cout<<"\n\n\tEnter the values of X-Scaling==>";
			cin>>Sx;
			cout<<"\n\n\tEnter the values of Y-Scaling==>";
			cin>>Sy;

				T[0][0]=Sx;
				T[0][1]=0;
				T[0][2]=0;
				T[1][0]=0;
				T[1][1]=Sy;
				T[1][2]=0;
				T[2][0]=0;
				T[2][1]=0;
				T[2][2]=1;
				break;
		case 4:
			exit(0);
			break;
		default:
			cout<<"\n\nInvalid Choice !!!!";
	}
}   //End of Menu function

void Transfn::Multi()
{
	for(i=0;i<=n;i++)
	{
		for(j=0;j<3;j++)
		{
			After[i][j]=0;
			for(k=0;k<3;k++)
			{
After[i][j]=After[i][j]+(Before[i][j]*T[k][j]);
			}
		}
	}
}

//Draw poly function

void Transfn::Drawpoly()
{
	int i;
	int Xc, Yc, Xmax, Ymax;
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "c:\TTURBOC3\BIN");
	Xmax=640;
	Ymax=480;
	Xc=Xmax/2;
	Yc=Ymax/2;

	line(0, Yc, Xmax, Yc);
	line(Xc, 0, Xc, Ymax);
	outtextxy(Xc, 0, "Y-axis");
	outtextxy(Xc, Yc, "(0, 0)");

	cout<<"\n\n\tbefore Transformation==>";
	for(i=0;i<n;i++)
	{
line(Xc+Before[i][0], Yc-Before[i][1], Xc+Before[i+1][0], Yc-Before[i+1][1]);
	}
	getch();
	//cleardevice();
	cout<<"\n\n\tAfter Transformation==>";
	Xmax=640;
	Ymax=480;
	Xc=Xmax/2;
	Yc=Ymax/2;

	line(0, Yc, Xmax, Yc);
	line(Xc, 0, Xc, Ymax);
	for(i=0;i<n;i++)
	{
line(Xc+After[i][0], Yc-After[i][1], Xc+After[i+1][0], Yc-After[i+1][1]);
	}
}

//main function
int main()
{
	Transfn obj;   //creating object of class Transformation
	clrscr();
	char nAns;
	obj.GetData();
	do
	{
		obj.Menu();  //creating object of menu function
		obj.Multi();  //creatin object if multi function
		obj.Drawpoly();  //creating object of drawpoly function

		cout<<"\n\n\tDo you want to continue(y||Y)";
		cin>>nAns;
		cleardevice();
	}
	while(nAns=='y' || nAns=='y');
	getch();
	closegraph();
return 0;
}
  //main function ends