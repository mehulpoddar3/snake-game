#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
bool print;

int x, y, fx, fy;
const int width = 50;
const int height = 20;
int score;
int tx[100], ty[100];
int nt;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;
void setup()
{
	gameover =false;
	x = width / 2;
	y = height / 2;
	fx = rand() % width;
	fy = rand() % height;
	dir =STOP;
	score = 0;


}
void draw()
{
	system("cls");
    for(int i=0;i<width+1;i++)
		cout<<"#";
	cout << endl;
	for (int i = 0; i <height; i++)
	{
		for (int j = 0; j <width; j++)
		{
			if (j == 0)
				cout << "#";
			else if (i == y && j == x)
				cout << "O";
			else if (i == fy && j == fx)
				cout << "@";

			else
			{	 print = false;
			
				for (int k = 1; k <=nt; k++)
				{
					if (ty[k]==i && tx[k]==j)
					{
						cout << "o";
						print = true;

					}
				}
				
				if(!print)
				cout <<" ";
			}


            if(j == width-1)
            cout << "#";
		
		}
		cout << endl;
	}

	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;
	cout << "score:" << score;

}
void input()
{

	
	if (_kbhit())
	{
		
		switch (_getch())
		{
		
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameover = true;
			break;
			     
		}
	}
}
void logic()
{
	tx[0] = x;
	ty[0] = y;
	int px = tx[0];
	int py = ty[0];
	int px2; int py2;
	for (int i = 1; i <= nt; i++)
	{
		px2=tx[i];
		py2=ty[i];
		tx[i] = px;
		ty[i] = py;
		px = px2;
		py = py2;
	}
	

	switch (dir)
	{
	  case UP:
		   y--;
		   break;
	  case DOWN:
		  y++;
		  break;
	  case LEFT:
		  x--;
		  break;
	  case RIGHT:
		   x++;
		  break;
	  default:
		  break;


	}
	//if (x <=0 || x >= width||y<0 || y > height)
		//gameover = true;

	if (x <= 0)
		x = width - 1;
	else if (x >= width)
		x = 1;
	if (y< 0)
		y = height - 1;
	else if (y >= height)
		y= 0;
	for (int i = 1; i <= nt; i++)
	{
		if (tx[i] == x && ty[i] == y)
			gameover = true;
	}

	if (x == fx && y == fy)
	{
		score += 10;
		fx = rand() % width;
		fy = rand() % height;
		nt++;
	}
	

}

int main()
{ 
	setup();
	while (!gameover)
	{
		draw();
		input();
		logic();
	}
	return 0;
}
