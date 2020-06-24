#include <bits/stdc++.h>
using namespace std;

char square[3][3];
string player1;
string player2;
bool win= false;
int arr[9][2]= {{0,0}, {0,1}, {0,2}, {1, 0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}};

void displayoriginalboard()
{
	cout<<"\t\t"<<""<<"   "<<"|"<<"   "<<"|"<<"   "<<endl;
    cout<<"\t\t"<<" "<<1<<" | "<<2<<" | "<<3<<endl;
    cout<<"\t\t"<<"___"<<"|"<<"___"<<"|"<<"___"<<endl;
    cout<<"\t\t"<<"   "<<"|"<<"   "<<"|"<<"   "<<endl;
    cout<<"\t\t"<<" "<<4<<" | "<<5<<" | "<<6<<endl;
    cout<<"\t\t"<<"___"<<"|"<<"___"<<"|"<<"___"<<endl;
    cout<<"\t\t"<<"   "<<"|"<<"   "<<"|"<<"   "<<endl;
    cout<<"\t\t"<<" "<<7<<" | "<<8<<" | "<<9<<endl;
    cout<<"\t\t"<<"   "<<"|"<<"   "<<"|"<<"   "<<endl<<endl<<endl;
}

void displayboard()
{	
	cout<<"\t\t"<<""<<"   "<<"|"<<"   "<<"|"<<"   "<<"\t\t\t"<<""<<"   "<<"|"<<"   "<<"|"<<"   "<<endl;
    cout<<"\t\t"<<" "<<square[0][0]<<" | "<<square[0][1]<<" | "<<square[0][2]<<"\t\t\t"<<" "<<1<<" | "<<2<<" | "<<3<<endl;
    cout<<"\t\t"<<"___"<<"|"<<"___"<<"|"<<"___"<<"\t\t\t"<<"___"<<"|"<<"___"<<"|"<<"___"<<endl;
    cout<<"\t\t"<<"   "<<"|"<<"   "<<"|"<<"   "<<"\t\t\t"<<"   "<<"|"<<"   "<<"|"<<"   "<<endl;
    cout<<"\t\t"<<" "<<square[1][0]<<" | "<<square[1][1]<<" | "<<square[1][2]<<"\t\t\t"<<" "<<4<<" | "<<5<<" | "<<6<<endl;
    cout<<"\t\t"<<"___"<<"|"<<"___"<<"|"<<"___"<<"\t\t\t"<<"___"<<"|"<<"___"<<"|"<<"___"<<endl;
    cout<<"\t\t"<<"   "<<"|"<<"   "<<"|"<<"   "<<"\t\t\t"<<"   "<<"|"<<"   "<<"|"<<"   "<<endl;
    cout<<"\t\t"<<" "<<square[2][0]<<" | "<<square[2][1]<<" | "<<square[2][2]<<"\t\t\t"<<" "<<7<<" | "<<8<<" | "<<9<<endl;
    cout<<"\t\t"<<"   "<<"|"<<"   "<<"|"<<"   "<<"\t\t\t"<<"   "<<"|"<<"   "<<"|"<<"   "<<endl<<endl<<endl;

}

bool checkwin(){
	//diagonal
	if(square[0][0] == square[1][1] && square[1][1] == square[2][2] && square[0][0] != ' ') return true;
	if(square[0][2] == square[1][1] && square[1][1] == square[2][0] && square[0][2] != ' ' ) return true;
    
    //horizontal
	if(square[0][0] == square[0][1] && square[0][1] == square[0][2] && square[0][0] != ' ') return true;
	if(square[1][0] == square[1][1] && square[1][1] == square[1][2] && square[1][0] != ' ') return true;
	if(square[2][0] == square[2][1] && square[2][1] == square[2][2] && square[2][0] != ' ' ) return true;

    //vertical
	if(square[0][0] == square[1][0] && square[1][0] == square[2][0] && square[0][0] != ' ') return true;
	if(square[0][1] == square[1][1] && square[1][1] == square[2][1] && square[0][1] != ' ') return true;
	if(square[0][2] == square[1][2] && square[1][2] == square[2][2] && square[0][2] != ' ') return true;

	return false;
}

bool checkvalid(int x, int y)
{
	if(x >= 3 || y >= 3)
	{
		return false;
	}
	return (square[x][y] != 'X' && square[x][y] != '0');
}

void mark_ur_place(int &count)
{
   char mark;
   string player;
   string competitor;
   if(count%2 == 0)
   {
   	 player= player1;
   	 competitor= player2;
     cout<<"Player "<<player1<<" its, your turn now!!"<<endl;
     mark= 'X';
   }
   else{
   	player= player2;
   	competitor= player1;
   	cout<<player2<<" its, your turn now!!"<<endl;
     mark= '0';
   }
    
    int num;
    cout<<"Enter the box number where you want to mark : ";
    cin>>num;
    cout<<endl;
    if(num <= 9) 
    {
    int x= arr[num-1][0];
    int y= arr[num-1][1];
    if(checkvalid(x,y))
    {
    	square[x][y] = mark;
    	displayboard();

    	if(checkwin())
    	{
            cout<<"Boom!! "<<player<<" , you cracked it!!! CONGRATULATIONS\n";

            cout<<"Shit!!! Sorry "<<competitor<<" you lost it! Better Luck next time\n";
            win= true;
    	}
    	else{
    		cout<<"Don't loose hope, story abhi baaki hai mere dost!!!\n";
    	}
    }
      else{
        cout<<"You NOOB, You entered the incorrect details\n TRY AGAIN \n";
        count--;
        }
    }
    else{
        cout<<"You NOOB, You entered the incorrect details\n TRY AGAIN \n";
        count--;
    }
}

int main()
{     
	cout<<"\t\tWelcome to the tic tac toe game!!!\n";
	cout<"--------------------------------------------\n--------------------------------------------\n";
	cout<<"Please enter your gaming names : \n Player 1 : ";
	cin>>player1;
	cout<<"\n Player 2 : ";
	cin>>player2;
	cout<<endl;

    for(int i=0; i<3; i++)
    {
    	for(int j=0; j< 3; j++)
    	{
    		square[i][j] = ' ';
    	}
    }

	displayoriginalboard();

	int count=0;

	while(count < 9)
	{
		mark_ur_place(count);
		count++;
		if(win) break;
	}

	if(count == 9 && !win) cout<<"Ohooo!!! the match is a draw between both of u\n Better Luck next time\n";

	return 0;
}