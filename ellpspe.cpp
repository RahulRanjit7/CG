#include<iostream>
#include<math.h>
#include<conio.h>
#include<graphics.h>
using namespace std;


void midptellipse(int rx, int ry,
				int xc, int yc)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;

	// Initial decision parameter of region 1
	d1 = (ry * ry) - (rx * rx * ry) +
					(0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	// For region 1
	while (dx < dy)
	{

		// Print points based on 4-way symmetry
	putpixel(x + xc,y + yc,WHITE);
	putpixel(-x + xc,y + yc,WHITE);
	putpixel(x + xc,-y + yc,WHITE);
	putpixel(-x + xc,-y + yc,WHITE);
	

		// Checking and updating value of
		// decision parameter based on algorithm
		if (d1 < 0)
		{
			x++;
			dx = dx + (2 * ry * ry);
			d1 = d1 + dx + (ry * ry);
		}
		else
		{
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d1 = d1 + dx - dy + (ry * ry);
		}
	}

	// Decision parameter of region 2
	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
		((rx * rx) * ((y - 1) * (y - 1))) -
		(rx * rx * ry * ry);

	// Plotting points of region 2
	while (y >= 0)
	{

		// Print points based on 4-way symmetry
		putpixel(x + xc,y + yc,WHITE);
	putpixel(-x + xc,y + yc,WHITE);
	putpixel(x + xc,-y + yc,WHITE);
	putpixel(-x + xc,-y + yc,WHITE);

		// Checking and updating parameter
		// value based on algorithm
		if (d2 > 0)
		{
			y--;
			dy = dy - (2 * rx * rx);
			d2 = d2 + (rx * rx) - dy;
		}
		else
		{
			y--;
			x++;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d2 = d2 + dx - dy + (rx * rx);
		}
	}
	getch();
	closegraph();
}


int main()
{
	int mjr,mnr,x,y;
	cout<<"enter major radius: ";
	cin>>mjr;
	cout<<"enter minor radius: ";
	cin>>mnr;
	cout<<"enter center coordinates:(x,y) ";
	cin>>x>>y;
	midptellipse(mjr, mnr, x, y);

	return 0;
}



