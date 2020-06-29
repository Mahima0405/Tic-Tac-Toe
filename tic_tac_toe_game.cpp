#include <bits/stdc++.h>
using namespace std;

char square[3][3];
string player1;
string player2;
bool win= false;
int arr[9][2]= {{0,0}, {0,1}, {0,2}, {1, 0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}};

string to_upper(string str)
{
    string ans;
    for(int i=0; i<str.length(); i++)
    {
        char ch= str[i];
        if(ch >= 'a' && ch <= 'z')
            {
                ch= ch - 32;
                ans= ans + ch;
            }
    }
    return ans;
}

int displayinstructions()
{
    system("cls");
    cout<<endl<<endl; 
    cout<<"\t\t0X0X   WELCOME TO THE WORLD OF GAMING !!!   X0X0\n \t\t   0X0X   TIC TAC TOE GAME   X0X0\n";

    cout<<"\t----------------------------------------------------------------"<<endl;
    cout<<"\t----------------------------------------------------------------"<<endl<<endl;
    cout<<"\n\t\t\t0X0X   HOW TO PLAY THE GAME?   X0X0\n";
    cout<<"\t----------------------------------------------------------------"<<endl<<endl;
    cout<<"\t 1. The game is played on a grid that's 3 squares by 3 squares.\n\t 2. You are 'X', your friend is 'O'. Players take turns putting their marks in empty squares.\n\t 3. The first player to get 3 of its marks in a row (up, down, across, or diagonally) is the winner.\n\t 4. If a winner is not choosen and it is a draw, then, when all 9 squares are full, the game is over.";
    cout<<"\n\n\t Ready to play the game?\n\t 1. Yes\n\t 2. No\n\t ";
    int i;
    cout<<"Choice num: ";
    cin>>i;
    cout<<endl<<endl;
    if(i == 1) return 1;
    return 0;
}

void displayboard()
{	
    system("cls");
    cout<<endl<<endl; 
    cout<<"\t\t0X0X   WELCOME TO THE WORLD OF GAMING !!!   X0X0\n \t\t   0X0X   TIC TAC TOE GAME   X0X0\n";

    cout<<"\t----------------------------------------------------------------"<<endl;
    cout<<"\t----------------------------------------------------------------"<<endl<<endl;
    cout<<endl<<endl;
    cout<<"\t     PLAYER 1 < "<<player1<<" > <X> -----  PLAYER 2 < "<<player2<<" > <0>"<<endl<<endl;
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
     cout<<"\t Player "<<player1<<" its, your turn now!!"<<endl;
     mark= 'X';
   }
   else{
   	player= player2;
   	competitor= player1;
   	cout<<"\t Player "<<player2<<" its, your turn now!!"<<endl;
     mark= '0';
   }
    
    int num;
    cout<<"\t Enter the box number where you want to mark : ";
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
            cout<<"\t\t Boom!! "<<player<<" , you cracked it!!!\n\t\t\t CONGRATULATIONS\n";
            win= true;
    	}
    }
      else{
        cout<<"\t\t MARK CAREFULLY....\n\t This coordinate has already been marked...\n\t\t PLEASE TRY AGAIN \n\n";
        count--;
        }
    }
    else{
        cout<<"\t SORRY!! But, you entered the wrong coordinates of the board...\n\t\t PLEASE TRY AGAIN \n\n";
        count--;
    }
}

int main()
{    
    cout<<endl<<endl; 
	cout<<"\t\t0X0X   WELCOME TO THE WORLD OF GAMING !!!   X0X0\n \t\t   0X0X   TIC TAC TOE GAME   X0X0\n";

	cout<<"\t----------------------------------------------------------------"<<endl;
    cout<<"\t----------------------------------------------------------------"<<endl<<endl;
    cout<<"\t\t\t0X0X   MENU   X0X0\n";
    cout<<"\t----------------------------------------------------------------"<<endl<<endl;

    cout<<"\t 1. Play Game :)\n\t 2. How To play? :?\n\t 3. Exit  \n\n\t ";
    int i;
    cout<<"Choice num: ";
    cin>>i;
    cout<<endl<<endl;
    
    while(i == 2)
    {
        i= displayinstructions();
        if(i == 1) break;
        else{
            cout<<"\t\t\t    MENU\n";
            cout<<"\t**************************************************"<<endl<<endl;
            cout<<"\t 1. Play Game :)\n\t 2. How To play? :?\n\t 3. Exit  \n\n\t ";
            cout<<"Choice num: ";
            cin>>i;
            cout<<endl<<endl;
        }
    }

    if(i == 3) {
        system("cls");
        return 0;
    }

    cout<<"\t\t\t X0X0   LET'S PLAY THE GAME!!!   X0X0\n";

	cout<<"\t Please enter your gaming names : \n\t Player 1 : ";
	cin>>player1;
    player1= to_upper(player1);
	cout<<"\t Player 2 : ";
	cin>>player2;
    player2= to_upper(player2);
	cout<<endl;

    for(int i=0; i<3; i++)
    {
    	for(int j=0; j< 3; j++)
    	{
    		square[i][j] = ' ';
    	}
    }

	displayboard();

	int count=0;

	while(count < 9)
	{
		mark_ur_place(count);
		count++;
		if(win) break;
	}

	if(count == 9 && !win) cout<<"\t Ohooo!!! The match is a DRAW between both of you...\n\t\t BETTER LUCK NEXT TIME \n\n\n";
    
    cout<<"   0X0X THANKYOU FOR PLAYING THE GAME !!! HOPE TO SEE YOU SOON X0X0"<<endl<<endl<<endl<<endl;
    
	return 0;
}
