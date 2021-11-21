//Abdullah Irfan
//20I-2702
//CyberSecurity-T
//PF Project (King and Queen)


#include<iostream>
#include<iomanip>
using namespace std;

int k_r, k_c, q_r, q_c; //global variables for each piece's position

char movearr[8][8]; //globaly declared array that shows moves

void start(); //main function that calls other function
void initboard(char (&iarr)[8][8]); //initializes board with space characters
void dispboard(char (&darr)[8][8]); //shows fancy chess board
void game(char (&garr)[8][8], bool user); //function that repeats each time a user moves, till the user defeats the king or quits
void moves(char (&marr)[8][8]); //displays possible moves for the queen

int main()
{
	start();
	return 0;
}

void start()
{
	char boardarr[8][8]; //main array for chess board
	initboard(boardarr); //initializing array
	dispboard(boardarr); //displaying main board
	cout<<endl;
	int choice;
	
	choicerep:
	//giving menu to user
	cout<<"1. Queen\n2. Bishop\n3. Rock\n4. Knight\nPlease enter a choice (0~4): ";
	cin>>choice;
	
	//processing choice
	switch(choice)
	{
		case 1:
		{
			kr:
			cout<<"Enter king's row: ";
			cin>>k_r; //taking input for king's initial position
			if(k_r<0||k_r>7)
			{
				cout<<"Out of bounds. Please enter again.\n";
				goto kr;
			}
			
			kc:
			cout<<"Enter king's column: ";
			cin>>k_c; //taking input for king's initial position
			if(k_c<0||k_c>7)
			{
				cout<<"Out of bounds. Please enter again.\n";
				goto kc;
			}
			
			qr:
			cout<<"Enter queen's row: ";
			cin>>q_r; //taking input for queen's initial position
			if(q_r<0||q_r>7)
			{
				cout<<"Out of bounds. Please enter again.\n";
				goto qr;
			}
			
			qc:
			cout<<"Enter queen's column: ";
			cin>>q_c; //taking input for queen's initial position
			if(q_c<0||q_c>7)
			{
				cout<<"Out of bounds. Please enter again.\n";
				goto qc;
			}
			
			if((q_r==k_r)&&(q_c==k_c)) //checking if initial position of king is not equal to the queen's
			{
				cout<<"This position is already taken by the king\n";
				goto qr;
			}
			
			boardarr[k_r][k_c]='K';
			boardarr[q_r][q_c]='Q';
			break;
		}
		default:
		{
			cout<<"Invalid Choice. Please enter again.\n";
			goto choicerep;
		}
	}	
	game(boardarr, true);	//starting the repeating function for the game	
}

void initboard(char (&iarr)[8][8])
{
	char (*iptr)[8]=iarr; //assigning array to pointer
	
	//initializing array with space character
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			*(*(iptr+i)+j)=' ';
		}
	}
}

void dispboard(char (&darr)[8][8])
{
	char (*dptr)[8]=darr; //assigning array to pointer
	
	cout<<endl<<right<<setw(15)<<"CHESS BOARD"<<endl<<endl;
	cout<<"  ";
	
	//displaying column indexes
	for(int i=0; i<8; i++)
	{
		cout<<i<<' ';
	}
	cout<<endl;
	
	//displaying row indexes and array as board
	for(int i=0; i<8; i++)
	{
		cout<<i<<' ';
		for(int j=0; j<8; j++)
		{
			cout<<*(*(dptr+i)+j)<<' ';
		}
		cout<<endl;
	}
}

void moves(char (&marr)[8][8])
{	
	//creating a copy of main board
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			movearr[i][j]=marr[i][j];
		}
	}
	
	//assigning possible moves to first diagonal
	for(int i=q_r+1, j=q_c+1; i<8&&j<8; i++, j++)
	{
		if(movearr[i][j]==' ')
		{
			movearr[i][j]='+';
		}
		else if(movearr[i][j]=='K')
		{
			movearr[i][j]='=';
			break;
		}
	}
	
	//assigning possible moves to second diagonal
	for(int i=q_r-1, j=q_c-1; i>=0&&j>=0; i--, j--)
	{
		if(movearr[i][j]==' ')
		{
			movearr[i][j]='+';
		}
		else if(movearr[i][j]=='K')
		{
			movearr[i][j]='=';
			break;
		}
	}
	
	//assigning ppossible moves to third diagonal
	for(int i=q_r+1, j=q_c-1; i<8&&j>=0; i++, j--)
	{
		if(movearr[i][j]==' ')
		{
			movearr[i][j]='+';
		}
		else if(movearr[i][j]=='K')
		{
			movearr[i][j]='=';
			break;
		}
	}
	
	//assigning possible moves to fourth diagonal
	for(int i=q_r-1, j=q_c+1; i>=0&&j<8; i--, j++)
	{
		if(movearr[i][j]==' ')
		{
			movearr[i][j]='+';
		}
		else if(movearr[i][j]=='K')
		{
			movearr[i][j]='=';
			break;
		}
	}
	
	//assigning possible moves downwards
	for(int i=q_r+1; i<8; i++)
	{
		if(movearr[i][q_c]==' ')
		{
			movearr[i][q_c]='+';
		}
		else if(movearr[i][q_c]=='K')
		{
			movearr[i][q_c]='=';
			break;
		}
	}
	
	//assigning possible moves upwards
	for(int i=q_r-1; i>=0;i--)
	{
		if(movearr[i][q_c]==' ')
		{
			movearr[i][q_c]='+';
		}
		else if(movearr[i][q_c]=='K')
		{
			movearr[i][q_c]='=';
			break;
		}
	}
	
	//assigning possible moves to the right
	for(int i=q_c+1; i<8; i++)
	{
		if(movearr[q_r][i]==' ')
		{
			movearr[q_r][i]='+';
		}
		else if(movearr[q_r][i]=='K')
		{
			movearr[q_r][i]='=';
			break;
		}
	}
	
	//assigning possible moves to the left
	for(int i=q_c-1; i>=0;i--)
	{
		if(movearr[q_r][i]==' ')
		{
			movearr[q_r][i]='+';
		}
		else if(movearr[q_r][i]=='K')
		{
			movearr[q_r][i]='=';
			break;
		}
	}
	
	dispboard(movearr); //displaying the array showing moves
	cout<<"+ represents available moves\n";
	cout<<"= represents available checkmate\n";
}

void game(char (&garr)[8][8], bool user)
{
	if(user!=true) //king will move accordingly
	{
		moves(garr); //displaying moves array
		garr[k_r][k_c]=' '; //emptying last position of king
		
		//various checks for the king to move accordingly
		if(movearr[k_r][k_c+1]==' '&&!(k_c+1<0||k_c+1>7))
		{
			k_c+=1;
		}
		else if(movearr[k_r][k_c-1]==' '&&!(k_c-1<0||k_c-1>7))
		{
			k_c-=1;
		}
		else if(movearr[k_r+1][k_c]==' '&&!(k_r+1<0||k_r+1>7))
		{
			k_r+=1;
		}
		else if(movearr[k_r-1][k_c]==' '&&!(k_r-1<0||k_r-1>7))
		{
			k_r-=1;
		}
		else if(movearr[k_r+1][k_c+1]==' '&&!(k_r+1<0||k_r+1>7)&&!(k_c+1<0||k_c+1>7))
		{
			k_c+=1;
			k_r+=1;
		}
		else if(movearr[k_r-1][k_c-1]==' '&&!(k_r-1<0||k_r-1>7)&&!(k_c-1<0||k_c-1>7))
		{
			k_c-=1;
			k_r-=1;
		}
		else if(movearr[k_r+1][k_c-1]==' '&&!(k_r+1<0||k_r+1>7)&&!(k_c-1<0||k_c-1>7))
		{
			k_c-=1;
			k_r+=1;
		}
		else if(movearr[k_r-1][k_c+1]==' '&&!(k_r-1<0||k_r-1>7)&&!(k_c+1<0||k_c+1>7))
		{
			k_c+=1;
			k_r-=1;
		}
		else //if king does not have any option to move without getting crushed user wins
		{
			cout<<"YOU WIN!!!"<<endl;
			return;
		}
		
		garr[k_r][k_c]='K'; //assigning new position to the king on the main array
		user=true; //switching players
		game(garr, user); //repeats game function with switched user
	}
	else //user will move queen
	{
		moves(garr); //displaying moves array
		char quit;
		quit:
		cout<<"Do you want to quit? (Y/n): ";
		cin>>quit; //giving user functionality to quit program
		if(quit=='Y') 
		{
			return; //quits game
		}
		else if(quit!='n')
		{
			goto quit; //wrong option then re enter option
		}
		garr[q_r][q_c]=' '; //emptying old position of queen
		ivmover:
		cout<<"Enter queen's row: "; //getting queen's position
		cin>>q_r;
		if(q_r<0||q_r>7)
		{
			cout<<"Invalid input\n";
			goto ivmover;
		}
		
		ivmovec:
		cout<<"Enter queen's column: "; //getting queen's position
		cin>>q_c;
		if(q_c<0||q_c>7)
		{
			cout<<"Invalid input\n";
			goto ivmovec;
		}
		
		if((movearr[q_r][q_c]=='+')||(movearr[q_r][q_c]=='=')) //checking if user entered valid posiition
		{
			if(garr[q_r][q_c]=='K') //checking if it is a checkmate
			{
				cout<<"YOU WIN!!!"<<endl; 
				return; //game ends
			}
			else
			{
				garr[q_r][q_c]='Q'; //new value assigned to queen
			}
		}
		else
		{
			cout<<"Queen can not move to this position\n";
			goto ivmover; //asks user for valid position again
		}
		
		user=false; //switching player
		game(garr, user); //repeating game array with switched user
	}
}
		
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
