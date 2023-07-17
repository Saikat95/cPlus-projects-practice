#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 9
#define empty 0

bool emptySpace(int[N][N],int&,int&);
bool isSafe(int[N][N],int,int, int);

bool solveSuduko(int grid[N][N]){
	int row, col;
	
	if(!emptySpace(grid,row,col)){
		return true;
	}
	
	for(int i=1; i<=9; ++i){
		if(isSafe(grid,row,col,i)){
			grid[row][col] = i;
			
			if(solveSuduko(grid)){
				return true;
			}
			
			grid[row][col] = empty;
	}
	
	}
	
	return false;	

}

bool emptySpace(int grid[N][N],int &row,int &col){
	for(row = 0; row<N; row++){
		for(col = 0; col<N; col++){
			if(grid[row][col] == empty){
				return true;
			}
		}
	}
	
	return false;
}

bool inRow(int grid[N][N],int row,int num){
	for(int col=0; col<N; ++col){
		if(grid[row][col] == num){
			return true;
		}
	}
	
	return false;
}

bool inCol(int grid[N][N], int col, int num){
	for(int row = 0; row < N; ++row){
		if(grid[row][col] == num){
			return true;
		}
	}
	return false;
}

bool inBox(int grid[N][N], int rowStart, int colStart,  int num){
	for(int row = 0; row < 3; ++row){
		for(int col = 0; col < 3; ++col){
			if(grid[row+rowStart][col+colStart] == num){
				return true;
			}
		}
	}
	
	return false;
}

bool isSafe(int grid[N][N], int row, int col, int num){
	return !inRow(grid,row,num) && !inCol(grid,col,num) && !inBox(grid,(row - row%3),(col-col%3),num) && emptySpace(grid,row,col);
}

void printGrid(int grid[N][N]){
	
	for(int i=0; i< N; i++){
		for(int j=0; j<N; j++){
			cout<<grid[i][j] << " ";
		}
		cout<<"\n";
	}
}

int main(int argc, char** argv) {
	/*int grid[9][9] = {
		
		{0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,}
		
	};*/
	
	  int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
	
	if(solveSuduko(grid) == true){
		printGrid(grid);
	}
	
	else{
		cout<<"No solutions found";
	}
	
	return 0;
}
