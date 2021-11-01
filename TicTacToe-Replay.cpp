#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <windows.h>


using namespace std;


int main(int argc, char** argv) {
	char game_move;
	bool game_input=false, exit_save=false, replay=true;
	int game_number, current_position=1, number_of_moves=1;
	string savestring, game, bracket_check, winner_check;
	//game input
	{
		while(game_input==false)
		{
			system("CLS");
			if(1==0)
			{
				A:
				system("CLS");
				cout<<"Game doesn't exitst in game folder. Try again.'\n";
			}
			cout<<"Input game number: ";
			cin>> game_number;		
			savestring=".//saves//save" + to_string(game_number) + ".txt";
			ifstream ulaz(savestring);
			exit_save=ulaz.is_open();
			exit_save=(exit_save and exit_save==ulaz.good());
			if(exit_save==true)
			{
				system("CLS");
				cout<<"Good input!\nYou move trough game with left and right arrow on keyboard.\nFor game replay press ENTER.";
				while(getch()!=13){}
				system("CLS");
				game_input=true;
			} else goto A;
				
		}
		
		ifstream ulaz(savestring);
		getline(ulaz, game);
		ulaz.close();
	}


	//Game control
	{
		while(replay==true)
		{
			
			//print
			{
				system("CLS");
				cout<<endl<<"	"<<game[current_position+0]<<"|"<<game[current_position+2]<<"|"<<game[current_position+4]<<endl;
				cout<<"	"<<"-+-+-\n";
				cout<<"	"<<game[current_position+6]<<"|"<<game[current_position+8]<<"|"<<game[current_position+10]<<endl;
				cout<<"	"<<"-+-+-\n";
				cout<<"	"<<game[current_position+12]<<"|"<<game[current_position+14]<<"|"<<game[current_position+16]<<endl;
				bracket_check=game[current_position+20];
				if(bracket_check!="[")
				{
					cout<<"\nMove "<<number_of_moves;
				}
				else
				{
					cout<<"\nLast move and ";
					winner_check=game[current_position+21];
					if(winner_check=="=") cout<<"game ended with a draw.";
					if(winner_check=="O" or winner_check=="X") cout<<"\""<<game[current_position+21]<<"\" won!";
					cout<<"\nPress left arrow to go back or press ENTER for program ending.";
				}
			}
		
			//moving
			{
				while(1==1)
				{
					getch();	
					game_move=getch();	
					bracket_check=game[current_position+20];
					if(bracket_check!="["){
						if(game_move==75)
						{
							if((current_position-21)>=0){
								current_position-=21;
								number_of_moves--;
								break;
							}
						}
						else if (game_move==77)
						{
							current_position+=21;
							number_of_moves++;
							break;
						}
					} 
					else if(game_move==75)
					{
						current_position-=21;
							number_of_moves--;
							break;
					}
					else if(game_move==13)
					{
						goto E;
					}
					
				}
			}
		}
	}
	
	E:

	return 0;
}