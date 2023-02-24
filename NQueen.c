#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8 // Ν basilises


void print_array(int a[N]){
	for (int j = 0; j < N; j++){
		printf("%d \t",a[j]+1);
	}
	printf("\n");
}

bool isValid (int Board[N][N], int k, int l){ // function for constrain check
	for (int i = k, j = l; i >= 0 && j >= 0; i--, j--){ //same first diag
		if (Board[i][j]){
			return false;
		}
	}

	for (int i = k, j = l; i >= 0 && j < N; i--, j++){// same second diag
		if (Board[i][j]){
			return false;
		}
	}
	
	for (int i = k; i >= 0; i--){ //same column
		if (Board[i][l]){
			return false;
		}
	}
	
	return true;
}


void solve(int board[N][N], int row, int column, int vector[N], int *sol_Num){
	if (row == N-1){// last row---end of recursion
		if (isValid(board, row, column)){ // check constrains
			vector[row] = column;// update solution vector
			printf("\n Soluntion Number : %d\n \n\t \t", *(sol_Num)+1); 
			print_array(vector); //solution print
			(*sol_Num)++; 
		}
		return; 
	}

	if (isValid(board, row, column)){// check new partial solution
		board[row][column] = 1;// update checkboard
		vector[row] = column;// update solution vector
		row++;
		solve(board, row, 0, vector, sol_Num); // recursion----in depth of solution space tree
		// when the call returns it with look in breadth
		for (column = 1; column < N; column++){
			solve(board, row, column, vector, sol_Num);
		}
		// if all combinations are not valid
		row--;
		board[row][vector[row]] = 0;// update checkboard
		// backtrack
	}
}


int main(){
	int Board[N][N] = { 0 };
	int sol_Num= 0;
	int vector[N] = { 0 };// solution vector
	for (int i = 0; i < N; i++){
		solve(Board, 0, i, vector, &sol_Num);
	}// call recursion function for each column of the first row
	return 0;
}


