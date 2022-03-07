#include<iostream>
using namespace std;
char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
bool draw=false;

void display_board()
{
	system("cls");
	cout<<"\t\t ---------------------------------"<<endl;
	cout<<"\t\t| T I C   T A C   T O E   G A M E |"<<endl;
	cout<<"\t\t ---------------------------------"<<endl;
	cout<<"\n";
	
	cout<<"PLAYER 1: [X]"<<endl;
	cout<<"PLAYER 2: [O]"<<endl;
	cout<<"\n";
	
	cout<<"\t\t             |      |      "<<endl;
	cout<<"\t\t         "<<a[0][0]<<"   |  "<<a[0][1]<<"   |  "<<a[0][2]<<endl;
	cout<<"\t\t       ______|______|______"<<endl;
	cout<<"\t\t             |      |      "<<endl;
	cout<<"\t\t         "<<a[1][0]<<"   |  "<<a[1][1]<<"   |  "<<a[1][2]<<endl;
	cout<<"\t\t       ______|______|______"<<endl;
	cout<<"\t\t             |      |     "<<endl;
	cout<<"\t\t         "<<a[2][0]<<"   |  "<<a[2][1]<<"   |  "<<a[2][2]<<endl;
	cout<<"\t\t             |      |     "<<endl;
	
	cout<<endl;
	cout<<endl;
}
void turnfunc()
{
	int choice;
	int row, col;
	if(turn=='X')
	{
		cout<<"PLAYER 1: [X] TURN: ";
	}
	else if(turn=='O')
	{
		cout<<"PLAYER 2: [O] TURN: ";
	}
	cin>>choice;
	switch (choice)
	{
		case 1: row=0; col=0; break;
		case 2: row=0; col=1; break;
		case 3: row=0; col=2; break;
		case 4: row=1; col=0; break;
		case 5: row=1; col=1; break;
		case 6: row=1; col=2; break;
		case 7: row=2; col=0; break;
		case 8: row=2; col=1; break;
		case 9: row=2; col=2; break;
		default: cout<<"Wrong Choice!!!\n"; break;
	}
	if(turn=='X' && a[row][col]!='X' && a[row][col]!='O')
	{
		a[row][col]='X';
		turn='O';
	}
	else if(turn=='O' && a[row][col]!='X' && a[row][col]!='O')
	{
		a[row][col]='O';
		turn='X';
	}
	else
	{
		cout<<"The block is already filled. Please try again."<<endl;
		turnfunc();
	}
display_board();
}
bool result()
{
	//for win (row or column or diagonally)
	for(int i=0;i<3;i++)
	{
		if(a[i][0]==a[i][1] && a[i][0]==a[i][2] || a[0][i]==a[1][i] && a[0][i]==a[2][i])
		{
			return false;
		}
	}
	for(int i=1;i<3;i++)
	{
		if(a[0][0]==a[1][1] && a[0][0]==a[2][2] || a[0][2]==a[1][1] && a[0][2]==a[2][0])
		{
			return false;
		}
	}
	//for continuation
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]!= 'X' && a[i][j]!= 'O')
			{
				return true;
			}
		}
	}
	//draw
	draw =true;
	return false;
}
int main()
{
	while(result())
	{
		display_board();
		turnfunc();
	}
	if(turn=='X' && draw==false)
	{
		cout<<"PLAYER 2: [O] WINS."<<endl;
	}
	else if (turn=='O' && draw==false)
	{
		cout<<"PLAYER 1: [X] WINS."<<endl;
	}
	else
	{
		cout<<"DRAW"<<endl;
	}
	return 0;
}

