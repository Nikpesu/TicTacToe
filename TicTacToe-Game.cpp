#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <windows.h>


using namespace std;

	string savestring;
	char board[3][3]={{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}}, last_move, player='X';
	bool game=true, wrong_input=false, saveCheck=true, win=false;
	int numerator=0, saveNumber=0;


void save_check()
{
	//creating a folder if its missing
	CreateDirectory(".//saves", NULL);	
	
	//finding next sutible file name
	ifstream checksave("");
	do
	{
		saveNumber++;
		checksave.close();
		savestring=".//saves//save" + to_string(saveNumber) + ".txt";
		ifstream checksave(savestring);
		saveCheck=checksave.is_open();
	} while(saveCheck);
	
	cout<<savestring;
	
}

void game_and_save()
{
	ofstream save(savestring);
	
	while(game==true)
	{
		//Board input
		{
			if(1==0)
			{
				A:
				wrong_input=true;
			}
				
			system ("CLS");
			
			
			cout<<endl;
			cout<<"   "<<board[0][0]<<"|"<<board[0][1]<<"|"<<board[0][2]<<endl;
			cout<<"   "<<"-+-+-\n";
			cout<<"   "<<board[1][0]<<"|"<<board[1][1]<<"|"<<board[1][2]<<endl;
			cout<<"   "<<"-+-+-\n";
			cout<<"   "<<board[2][0]<<"|"<<board[2][1]<<"|"<<board[2][2];
			
			if(wrong_input==true)
			{
				wrong_input=false;
				cout<<"\n\nWrong input! (Chose on number that is on the board)\n";
			} 
			else cout<<"\n\n";
		
			cout<<"Input your next move \""<<player<<"\":";
			last_move=getch();
			
					if(last_move=='1' and board[0][0]=='1') board[0][0]=player;
			else 	if(last_move=='2' and board[0][1]=='2') board[0][1]=player;
			else 	if(last_move=='3' and board[0][2]=='3') board[0][2]=player;
			else 	if(last_move=='4' and board[1][0]=='4') board[1][0]=player;
			else 	if(last_move=='5' and board[1][1]=='5') board[1][1]=player;
			else 	if(last_move=='6' and board[1][2]=='6') board[1][2]=player;
			else 	if(last_move=='7' and board[2][0]=='7') board[2][0]=player;
			else 	if(last_move=='8' and board[2][1]=='8') board[2][1]=player;
			else 	if(last_move=='9' and board[2][2]=='9') board[2][2]=player;
			else 	goto A;
			
		}
		
		//win condition check
		{
			if(last_move=='1' and ((board[0][1]==player and board[0][2]==player) or (board[1][0]==player and board[2][0]==player) or (board[1][1]==player and board[2][2]==player))) game=false;
			if(last_move=='2' and ((board[0][0]==player and board[0][2]==player) or (board[1][1]==player and board[2][1]==player))) game=false;
			if(last_move=='3' and ((board[0][1]==player and board[0][0]==player) or (board[1][2]==player and board[2][2]==player) or (board[2][0]==player and board[1][1]==player))) game=false;
			if(last_move=='4' and ((board[0][0]==player and board[2][0]==player) or (board[1][1]==player and board[1][2]==player))) game=false;
			
			if(last_move=='5' and ((board[1][0]==player and board[1][2]==player) or (board[0][1]==player and board[2][1]==player))) game=false;
			if(last_move=='5' and ((board[0][0]==player and board[2][2]==player) or (board[0][2]==player and board[2][0]==player))) game=false;
			
			if(last_move=='6' and ((board[0][2]==player and board[2][2]==player) or (board[1][1]==player and board[1][0]==player))) game=false;
			if(last_move=='7' and ((board[0][0]==player and board[1][0]==player) or (board[2][1]==player and board[2][2]==player) or (board[1][1]==player and board[0][2]==player))) game=false;
			if(last_move=='8' and ((board[2][0]==player and board[2][2]==player) or (board[0][1]==player and board[1][1]==player))) game=false;
			if(last_move=='9' and ((board[2][0]==player and board[2][1]==player) or (board[1][2]==player and board[0][2]==player) or (board[1][1]==player and board[0][0]==player))) game=false;
				
		}
		
		//winner?
		{
			if(game==false)
			{
				system ("CLS");
				cout<<endl;
				cout<<"   "<<board[0][0]<<"|"<<board[0][1]<<"|"<<board[0][2]<<endl;
				cout<<"   "<<"-+-+-\n";
				cout<<"   "<<board[1][0]<<"|"<<board[1][1]<<"|"<<board[1][2]<<endl;
				cout<<"   "<<"-+-+-\n";
				cout<<"   "<<board[2][0]<<"|"<<board[2][1]<<"|"<<board[2][2]<<endl<<endl;
				cout<<player<<" won!";
				win=true;
			} 	
			
		}
		
		//draw?
		{
			numerator++;
			if(numerator==9 and win==false)
			{
				system ("CLS");
				cout<<endl;
				cout<<"   "<<board[0][0]<<"|"<<board[0][1]<<"|"<<board[0][2]<<endl;
				cout<<"   "<<"-+-+-\n";
				cout<<"   "<<board[1][0]<<"|"<<board[1][1]<<"|"<<board[1][2]<<endl;
				cout<<"   "<<"-+-+-\n";
				cout<<"   "<<board[2][0]<<"|"<<board[2][1]<<"|"<<board[2][2]<<endl<<endl;
				cout<<"Draw!";
				game=false;
			}
			
		}
	
		//save board state
		{
			save<<"{"<<board[0][0]<<","<<board[0][1]<<","<<board[0][2]<<","<<board[1][0]<<","<<board[1][1]<<","<<board[1][2]<<","<<board[2][0]<<","<<board[2][1]<<","<<board[2][2]<<"}, ";
			if(game==false)
			{
				save<<"[";
				if(numerator==9 and win==false) save<<"=";
				else save<<player; 
				save<<"]";
			}
		}
		
		//Player changer after each move
		{
			if(player=='X') player='O'; else player='X'; 	
		}
	}
	cout<<endl<<"This is game number "<<saveNumber<<endl;
	
	save.close();
}

int main() {
	
	save_check();
	
	game_and_save();
	
	
	
	system("pause");
	return 0;
}
