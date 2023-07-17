#include<iostream>

using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int slot;
char current_marker;
int current_player;

void boardLayout(){
	cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
	cout<<"---+---+---\n";
	cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
	cout<<"---+---+---\n";
	cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}

bool markPosition(int slot){
	
	int row = slot/3;
	int col = slot%3 - 1;
	
	if(slot%3 == 0){
		row = slot/3 - 1;
		col = 2;
	}
	
	if(board[row][col] != 'x' && board[row][col] != 'o'){
		board[row][col] = current_marker;
		return true;
	}
	
	else{
		return false;
	}
}

int winner(){
	for(int i=0; i<3; ++i){
		//row
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
		//column
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
	}
	
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;
	
	return 0;
}

void swap(){
	if(current_player == 1) current_player = 2;
	else if(current_player == 2) current_player = 1;
	
	if(current_marker == 'x') current_marker = 'o';
	else if(current_marker == 'o') current_marker = 'x';
}

void game(){
	current_player = 1;
	cout<<"Player 1 enter marker: ";
	cin>>current_marker;
	boardLayout();
	
	int won = 0;
	
	for(int i=0; i<9; ++i){
		cout<<endl;
		cout<<"Player "<<current_player<<" Enter slot: ";
		cin>>slot;
		
		if(slot < 1 || slot > 9){
			cout<<"Invalid Slot number."<<endl;
			--i;
			continue;
		}
		
		if(!markPosition(slot)){
			cout<<"Already Occupied."<<endl;
			--i;
			continue;
		}
		
		boardLayout();
		
		won = winner();
		
		if(won == 1){
			cout<<"\n\nPlayer 1 is winner. Congratulation!!"<<endl;
			break;
		}
		
		if(won == 2){
			cout<<"\n\nPlayer 2 is winner. COngratulation!!"<<endl;
		}
		
		swap();
	}
	
	if(won == 0){
		cout<<"\n\nIt's a TIE."<<endl;
	}
	
	//board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
}

int main(){
	
	char choice;
	
	do{
		
		game();
		
		cout<<"Do you want to play again(y/n)?: ";
		cin>>choice;
		
		
	} while(choice == 'y');
	
	return 0;
}
