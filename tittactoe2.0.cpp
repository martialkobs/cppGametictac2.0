#include<iostream>
#include<ctime>
#include<random>
using namespace std;

//empty board
char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
void display_board();
void load_x_player_choice();
void load_o_player_choice();
void load_computer_choice();
int count_board(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();

int main()
{
 //bool quit_game = false;
 int mode;

cout<<"-----------------------"<<endl;
cout<<"1. Computer Vs Player"<<endl;
cout<<"2. Player Vs Player"<<endl;
cout<<"3. QUIT"<<endl;
cout<<"-----------------------"<<endl;
cout<<"PLEASE CHOOSE A GAME MODE:"<<endl;
cin>>mode;

switch(mode){

case 1:
    computer_vs_player();
break;
case 2:
    player_vs_player();
break;
case 3:
//quit_game = true;
cout<<"GOOD BYE !"<<endl;
    break;
default:
    cout<<"PLEASE MAKE A VALID SELECTION !"<<endl;
}

return 0;
}


void computer_vs_player(){
    string player_name;
    cout <<"PLEASE ENTER YOUR NAME ?: ";
    cin>>player_name;
    while(true){
        system("cls");
        display_board();
        if (count_board('X') == count_board('O')){  /* X turn */
            cout<<player_name<<" 's TURN"<<endl;
            load_x_player_choice();
        }
            else
            {
               load_computer_choice();
               
            }
            char winner = check_winner(); /*store check winner in 'var winner'*/
            if (winner == 'X'){
                system("cls");
                display_board();
                cout<< player_name <<"IS THE WINNER !!!"<<endl;
                break;
            }
            else if (winner == 'O'){
                system("cls");
                display_board();
                cout<< "THE A1 IS THE WINNER ! "<<endl;
                break;
            }
            else if  (winner == 'D'){
            cout<<"DRAW !!"<<endl;
                break;
            }
        }
            
        }


void load_computer_choice(){
srand(time(0));//random
int choice;
do{
    choice = rand()%10; //rnt 0-9
}while (board[choice] != ' ');
board[choice] = 'O';
}

void load_x_player_choice(){
    while (true){
        cout<<"PLEASE TYPE 1-9 FOR THE SPACE OPTIONS:";
        int choice;
        cin>>choice;
        choice--; //array eg [0-8]
        if(choice < 0 || choice > 8){
            cout<<"AN INVALID CHOICE, PLEASE ENTER NUM# 1-9!"<<endl;
        }
    else if (board[choice] != ' '){
        cout<<"***PLEASE CHOOSE AN EMPTY SPACE ***!"<<endl;
    }
    else{
        board[choice] = 'X';
        break;
    
    }
    }
}

void load_o_player_choice(){
    while (true){
         cout<<"PLEASE TYPE 1-9 FOR THE SPACE OPTIONS:";
        int choice;
        cin>>choice;
        choice--; //array eg [0-8]
        if(choice <0 || choice > 8){
              cout<<"AN INVALID CHOICE, PLEASE ENTER NUM# 1-9!"<<endl;
        }
    else if (board[choice] != ' '){
           cout<<"***PLEASE CHOOSE AN EMPTY SPACE ***!"<<endl;
    }
    else{
        board[choice] = 'O';
        break;
        }
    }
}

void player_vs_player(){

string x_player_name, o_player_name;
cout<<"PLEASE ENTER X PLAYER NAME?:"<<endl;
cin>>x_player_name;
cout<<"PLEASE ENTER O PLAYER NAME?:"<<endl;
cin>>o_player_name;
while (true)
{
    system("cls");
    display_board();
    if (count_board ('X') == count_board ('O')){
cout<<x_player_name<<"'s Turn"<<endl;
load_x_player_choice();
}
else
{
    cout<<o_player_name<<"'s Turn"<<endl;
    load_o_player_choice();

}
char winner = check_winner();
if (winner == 'X') {
    system("cls");
    display_board();
    cout<<x_player_name<<"  Won"<<endl;
    break;
}
else if 
    (winner == 'O'){
        system("cls");
        display_board();
        cout<<o_player_name<<"  Is The Winner !!!"<<endl;
    break;
   
    }
    else if (winner == 'D') {
        cout<<"DRAW!!!"<<endl;
        break;
    }
}
    }


int count_board(char symbol){
int total = 0;
for(int i=0; i < 9; i++){
if (board[i] == symbol)
    total += 1;

}
return total;
}

char check_winner(){
//check winner row
if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
return board[0];
if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
return board[3];
if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
return board[6];
//check winner column
if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
return board[0];
if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
return board[1];
if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
return board[2];
//check diagonally
if (board[0] == board[4] && board[4] == board[8] && board [0] != ' ')
return board[0];
if (board[2] == board[4] && board [4] == board [6] && board[2] != ' ')
return board[2];
if (count_board ('X') + count_board ('O') < 9)
    return 'C'; //continue
else
   return 'D'; //drop game

}

void display_board()
{
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"   "<<board[0]<<"  |   "<<board[1]<<"  |   "<<board[2]<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"--------------------"<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"   "<<board[3]<<"  |   "<<board[4]<<"  |   "<<board[5]<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"--------------------"<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"   "<<board[6]<<"  |   "<<board[7]<<"  |   "<<board[8]<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
}