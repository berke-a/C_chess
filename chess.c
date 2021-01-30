#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum { F, T } boolean; 

// Prints Board
void printBoard(char *board[9][9]){
	int i,j;
	boolean x=T;
	printf("----------------------------------- \n");
	printf("Chess Board: \n");
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			printf("%s  ",board[i][j]);
		}
		printf("\n");
	}
}


int charToInt(char tmp){
	if(tmp=='A'){
		return 1;
	}
	if(tmp=='B'){
		return 2;
	}
	if(tmp=='C'){
		return 3;
	}
	if(tmp=='D'){
		return 4;
	}
	if(tmp=='E'){
		return 5;
	}
	if(tmp=='F'){
		return 6;
	}
	if(tmp=='G'){
		return 7;
	}
	if(tmp=='H'){
		return 8;
	}
	return 0;
}

char intToChar(int tmp){
	if(tmp==1){
		return 'A';
	}
	if(tmp==2){
		return 'B';
	}
	if(tmp==3){
		return 'C';
	}
	if(tmp==4){
		return 'D';
	}
	if(tmp==5){
		return 'E';
	}
	if(tmp==6){
		return 'F';
	}
	if(tmp==7){
		return 'G';
	}
	if(tmp==8){
		return 'H';
	}
	return 'Z';
}

char intToInt(int tmp){
	if(tmp==1){
		return '1';
	}
	if(tmp==2){
		return '2';
	}
	if(tmp==3){
		return '3';
	}
	if(tmp==4){
		return '4';
	}
	if(tmp==5){
		return '5';
	}
	if(tmp==6){
		return '6';
	}
	if(tmp==7){
		return '7';
	}
	if(tmp==8){
		return '8';
	}
	return '9';
}

void charsToStr(char x1, char x2, char* dest) {
    sprintf(dest, "%c %c", x1, x2);
}

void pawn(char *board[9][9], char *moves[100], char type, int row, int column, char color){
	if(color=='W'){
		int i=0;
		char* tmp;
		if(row-1>=0 && *board[row-1][column]=='0'){
			char tmp2[2];
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(column),intToInt(8-row+1),tmp);
			moves[i]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			moves[i]=tmp2;
			free(tmp);
			i++;
		}
		if(row==6 && *board[row-1][column]=='0' && *board[row-2][column]=='0'){
			char tmp2[2];
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(column),intToInt(8-row+2),tmp);
			moves[i]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			moves[i]=tmp2;

			i++;
			free(tmp);
		}
		if(column-1>0 && row-1>=0 && *board[row-1][column-1]=='B'){
			char tmp2[2];
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(column-1),intToInt(8-row+1),tmp);
			moves[i]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			moves[i]=tmp2;

		}
		if(column+1<=8 && row-1>=0 && *board[row-1][column+1]=='B'){
			char tmp2[2];
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(column+1),intToInt(8-row+1),tmp);
			moves[i]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			moves[i]=tmp2;
		}
	}
	else{
		int i=0;
		char* tmp;
		if(row+1<=7 && *board[row+1][column]=='0'){
			char tmp2[2];
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(column),intToInt(8-row-1),tmp);
			moves[i]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			moves[i]=tmp2;
			free(tmp);
			i++;
		}
		if(row==1 && *board[row+1][column]=='0' && *board[row+2][column]=='0'){
			char tmp2[2];
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(column),intToInt(8-row-2),tmp);
			moves[i]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			moves[i]=tmp2;

			i++;
			free(tmp);
		}
		if(column-1>0 && row+1<=7 && *board[row+1][column-1]=='W'){
			char tmp2[2];
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(column-1),intToInt(8-row-1),tmp);
			moves[i]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			moves[i]=tmp2;

		}
		if(column+1<=8 && row+1<=7 && *board[row+1][column+1]=='W'){
			char tmp2[2];
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(column+1),intToInt(8-row-1),tmp);
			moves[i]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			moves[i]=tmp2;
		}
	}
}

void bishop(char *board[9][9], char *moves[100], char type, int row, int column, char color, int index){
	if(color=='W'){
		int i,j;
		char *tmp;
		j=column+1;
		for(int i=row-1;i>=0;i--){
			char tmp2[2];
			if(*board[i][j]=='W'){
				break;	
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(j),intToInt(8-i),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[i][j]=='B'){
				break;
			}
			j++;
			if(j>8){
				break;
			}
		}
		j=column-1;
		for(int i=row-1;i>=0;i--){
			char tmp2[2];
			if(*board[i][j]=='W'){
				break;
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(j),intToInt(8-i),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[i][j]=='B'){
				break;
			}
			j--;
			if(j<1){
				break;
			}
		}
		j=column+1;
		for(int i=row+1;i<=7;i++){
			char tmp2[2];
			if(*board[i][j]=='W'){
				break;
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(j),intToInt(8-i),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[i][j]=='B'){
				break;
			}
			j++;
			if(j>8){
				break;
			}
		}
		j=column-1;
		for(int i=row+1;i<=7;i++){
			char tmp2[2];
			if(*board[i][j]=='W'){
				break;
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(j),intToInt(8-i),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[i][j]=='B'){
				break;
			}
			j--;
			if(j<1){
				break;
			}
		}
	}
	else{
		int i,j;
		int index=0;
		char *tmp;
		j=column+1;
		for(int i=row-1;i>=0;i--){
			char tmp2[2];
			if(*board[i][j]=='B'){
				break;	
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(j),intToInt(8-i),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[i][j]=='W'){
				break;
			}
			j++;
			if(j>8){
				break;
			}
		}
		j=column-1;
		for(int i=row-1;i>=0;i--){
			char tmp2[2];
			if(*board[i][j]=='B'){
				break;
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(j),intToInt(8-i),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[i][j]=='W'){
				break;
			}
			j--;
			if(j<1){
				break;
			}
		}
		j=column+1;
		for(int i=row+1;i<=7;i++){
			char tmp2[2];
			if(*board[i][j]=='B'){
				break;
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(j),intToInt(8-i),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[i][j]=='W'){
				break;
			}
			j++;
			if(j>8){
				break;
			}
		}
		j=column-1;
		for(int i=row+1;i<=7;i++){
			char tmp2[2];
			if(*board[i][j]=='B'){
				break;
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(j),intToInt(8-i),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[i][j]=='W'){
				break;
			}
			j--;
			if(j<1){
				break;
			}
		}
	}
}


int rook(char *board[9][9], char *moves[100], char type, int row, int column, char color){
	if(color=='W'){
		int i,j;
		int index=0;
		char *tmp;
		j=column;
		for(int i=row-1;i>=0;i--){
			char tmp2[2];
			if(*board[i][j]=='W'){
				break;	
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(j),intToInt(8-i),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[i][j]=='B'){
				break;
			}
		}
		j=column;
		for(int i=row+1;i<=7;i++){
			char tmp2[2];
			if(*board[i][j]=='W'){
				break;
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(j),intToInt(8-i),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[i][j]=='B'){
				break;
			}
		}
		j=row;
		for(int i=column+1;i<=8;i++){
			char tmp2[2];
			if(*board[j][i]=='W'){
				break;
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(i),intToInt(8-j),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[j][i]=='B'){
				break;
			}
		}
		j=row;
		for(int i=column-1;i>=1;i--){
			char tmp2[2];
			if(*board[j][i]=='W'){
				break;
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(i),intToInt(8-j),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[j][i]=='B'){
				break;
			}
		}
		return index;
	}
	if(color=='B'){
		int i,j;
		int index=0;
		char *tmp;
		j=column;
		for(int i=row-1;i>=0;i--){
			char tmp2[2];
			if(*board[i][j]=='B'){
				break;	
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(j),intToInt(8-i),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[i][j]=='W'){
				break;
			}
		}
		j=column;
		for(int i=row+1;i<=7;i++){
			char tmp2[2];
			if(*board[i][j]=='B'){
				break;
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(j),intToInt(8-i),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[i][j]=='W'){
				break;
			}
		}
		j=row;
		for(int i=column+1;i<=8;i++){
			char tmp2[2];
			if(*board[j][i]=='B'){
				break;
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(i),intToInt(8-j),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[j][i]=='W'){
				break;
			}
		}
		j=row;
		for(int i=column-1;i>=1;i--){
			char tmp2[2];
			if(*board[j][i]=='B'){
				break;
			}
			tmp=(char*) malloc(2*sizeof(char));
			charsToStr(intToChar(i),intToInt(8-j),tmp);
			moves[index]=(char*) malloc(sizeof(char*));
			tmp2[0]=*tmp;
			tmp2[1]=*(tmp+2);
			*moves[index]=tmp2[0];
			*(moves[index]+1)=tmp2[1];
			index++;
			if(*board[j][i]=='W'){
				break;
			}
		}
		return index;
	}
	return 0;
}

void knight(char *board[9][9], char *moves[100], char type, int row, int column, char color){
	if(color=='W'){
		char *tmp;
		int index=0;
		if(row-2>=0){
			if(column-1>=1){
				if(*board[row-2][column-1]=='0' || *board[row-2][column-1]=='B'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column-1),intToInt(8-row-2),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
			if(column+1<=8){
				if(*board[row-2][column+1]=='0' || *board[row-2][column+1]=='B'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column+1),intToInt(8-row-2),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
		}
		if(row+2<=7){
			if(column-1>=1){
				if(*board[row+2][column-1]=='0' || *board[row+2][column-1]=='B'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column-1),intToInt(8-row+2),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
			if(column+1<=8){
				if(*board[row+2][column+1]=='0' || *board[row+2][column+1]=='B'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column+1),intToInt(8-row+2),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
		}
		if(column+2<=8){
			if(row+1<=7){
				if(*board[row+1][column+2]=='0' || *board[row+1][column+2]=='B'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column+2),intToInt(8-row+1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
			if(row-1>=0){
				if(*board[row-1][column+2]=='0' || *board[row-1][column+2]=='B'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column+2),intToInt(8-row-1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
		}
		if(column-2>=1){
			if(row+1<=7){
				if(*board[row+1][column-2]=='0' || *board[row+1][column-2]=='B'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column-2),intToInt(8-row+1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
			if(row-1>=0){
				if(*board[row-1][column-2]=='0' || *board[row-1][column-2]=='B'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column-2),intToInt(8-row-1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
		}
	}
	if(color=='B'){
		int index=0;
		char *tmp;
		if(row-2>=0){
			if(column-1>=1){
				if(*board[row-2][column-1]=='0' || *board[row-2][column-1]=='W'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column-1),intToInt(8-row-2),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
			if(column+1<=8){
				if(*board[row-2][column+1]=='0' || *board[row-2][column+1]=='W'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column+1),intToInt(8-row-2),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
		}
		if(row+2<=7){
			if(column-1>=1){
				if(*board[row+2][column-1]=='0' || *board[row+2][column-1]=='W'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column-1),intToInt(8-row+2),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
			if(column+1<=8){
				if(*board[row+2][column+1]=='0' || *board[row+2][column+1]=='W'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column+1),intToInt(8-row+2),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
		}
		if(column+2<=8){
			if(row+1<=7){
				if(*board[row+1][column+2]=='0' || *board[row+1][column+2]=='W'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column+2),intToInt(8-row+1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
			if(row-1>=0){
				if(*board[row-1][column+2]=='0' || *board[row-1][column+2]=='W'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column+2),intToInt(8-row-1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
		}
		if(column-2>=1){
			if(row+1<=7){
				if(*board[row+1][column-2]=='0' || *board[row+1][column-2]=='W'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column-2),intToInt(8-row+1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
			if(row-1>=0){
				if(*board[row-1][column-2]=='0' || *board[row-1][column-2]=='W'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column-2),intToInt(8-row-1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
		}
	}

}

void king(char *board[9][9], char *moves[100], char type, int row, int column, char color){
	if(color=='W'){
		char *tmp;
		int index=0;
		if(row-1>=0){
			if(column-1>=1){
				if(*board[row-1][column-1]=='0' || *board[row-1][column-1]=='B'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column-1),intToInt(8-row-1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
			if(column+1<=8){
				if(*board[row-1][column+1]=='0' || *board[row-1][column+1]=='B'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column+1),intToInt(8-row-1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
		}
		if(row+1<=7){
			if(column-1>=1){
				if(*board[row+1][column-1]=='0' || *board[row+1][column-1]=='B'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column-1),intToInt(8-row+1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
			if(column+1<=8){
				if(*board[row+1][column+1]=='0' || *board[row+1][column+1]=='B'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column+1),intToInt(8-row+1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
		}
		if(row+1<=7){
			if(*board[row+1][column]=='0' || *board[row+1][column]=='B'){
				char tmp2[2];
				tmp=(char*) malloc(2*sizeof(char));
				charsToStr(intToChar(column),intToInt(8-row+1),tmp);
				moves[index]=(char*) malloc(sizeof(char*));
				tmp2[0]=*tmp;
				tmp2[1]=*(tmp+2);
				*moves[index]=tmp2[0];
				*(moves[index]+1)=tmp2[1];
				index++;
			}
		}
		if(row-1>=0){
			if(*board[row-1][column]=='0' || *board[row-1][column]=='B'){
				char tmp2[2];
				tmp=(char*) malloc(2*sizeof(char));
				charsToStr(intToChar(column),intToInt(8-row-1),tmp);
				moves[index]=(char*) malloc(sizeof(char*));
				tmp2[0]=*tmp;
				tmp2[1]=*(tmp+2);
				*moves[index]=tmp2[0];
				*(moves[index]+1)=tmp2[1];
				index++;
			}
		}
		if(column+1<=8){
			if(*board[row][column+1]=='0' || *board[row][column+1]=='B'){
				char tmp2[2];
				tmp=(char*) malloc(2*sizeof(char));
				charsToStr(intToChar(column+1),intToInt(8-row),tmp);
				moves[index]=(char*) malloc(sizeof(char*));
				tmp2[0]=*tmp;
				tmp2[1]=*(tmp+2);
				*moves[index]=tmp2[0];
				*(moves[index]+1)=tmp2[1];
				index++;
			}
		}
		if(column-1>=1){
			if(*board[row][column-1]=='0' || *board[row][column-1]=='B'){
				char tmp2[2];
				tmp=(char*) malloc(2*sizeof(char));
				charsToStr(intToChar(column-1),intToInt(8-row),tmp);
				moves[index]=(char*) malloc(sizeof(char*));
				tmp2[0]=*tmp;
				tmp2[1]=*(tmp+2);
				*moves[index]=tmp2[0];
				*(moves[index]+1)=tmp2[1];
				index++;
			}
		}
	}
	if(color=='B'){
		char *tmp;
		int index=0;
		if(row-1>=0){
			if(column-1>=1){
				if(*board[row-1][column-1]=='0' || *board[row-1][column-1]=='W'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column-1),intToInt(8-row-1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
			if(column+1<=8){
				if(*board[row-1][column+1]=='0' || *board[row-1][column+1]=='W'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column+1),intToInt(8-row-1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
		}
		if(row+1<=7){
			if(column-1>=1){
				if(*board[row+1][column-1]=='0' || *board[row+1][column-1]=='W'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column-1),intToInt(8-row+1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
			if(column+1<=8){
				if(*board[row+1][column+1]=='0' || *board[row+1][column+1]=='W'){
					char tmp2[2];
					tmp=(char*) malloc(2*sizeof(char));
					charsToStr(intToChar(column+1),intToInt(8-row+1),tmp);
					moves[index]=(char*) malloc(sizeof(char*));
					tmp2[0]=*tmp;
					tmp2[1]=*(tmp+2);
					*moves[index]=tmp2[0];
					*(moves[index]+1)=tmp2[1];
					index++;
				}
			}
		}
		if(row+1<=7){
			if(*board[row+1][column]=='0' || *board[row+1][column]=='W'){
				char tmp2[2];
				tmp=(char*) malloc(2*sizeof(char));
				charsToStr(intToChar(column),intToInt(8-row+1),tmp);
				moves[index]=(char*) malloc(sizeof(char*));
				tmp2[0]=*tmp;
				tmp2[1]=*(tmp+2);
				*moves[index]=tmp2[0];
				*(moves[index]+1)=tmp2[1];
				index++;
			}
		}
		if(row-1>=0){
			if(*board[row-1][column]=='0' || *board[row-1][column]=='W'){
				char tmp2[2];
				tmp=(char*) malloc(2*sizeof(char));
				charsToStr(intToChar(column),intToInt(8-row-1),tmp);
				moves[index]=(char*) malloc(sizeof(char*));
				tmp2[0]=*tmp;
				tmp2[1]=*(tmp+2);
				*moves[index]=tmp2[0];
				*(moves[index]+1)=tmp2[1];
				index++;
			}
		}
		if(column+1<=8){
			if(*board[row][column+1]=='0' || *board[row][column+1]=='W'){
				char tmp2[2];
				tmp=(char*) malloc(2*sizeof(char));
				charsToStr(intToChar(column+1),intToInt(8-row),tmp);
				moves[index]=(char*) malloc(sizeof(char*));
				tmp2[0]=*tmp;
				tmp2[1]=*(tmp+2);
				*moves[index]=tmp2[0];
				*(moves[index]+1)=tmp2[1];
				index++;
			}
		}
		if(column-1>=1){
			if(*board[row][column-1]=='0' || *board[row][column-1]=='W'){
				char tmp2[2];
				tmp=(char*) malloc(2*sizeof(char));
				charsToStr(intToChar(column-1),intToInt(8-row),tmp);
				moves[index]=(char*) malloc(sizeof(char*));
				tmp2[0]=*tmp;
				tmp2[1]=*(tmp+2);
				*moves[index]=tmp2[0];
				*(moves[index]+1)=tmp2[1];
				index++;
			}
		}
	}
}

void findMoves(char *board[9][9], char *moves[100], char type, int row, int column, char color){
	
	if(type=='P'){
		pawn(board,moves,type,row,column,color);
	}
	else if(type=='B'){
		bishop(board,moves,type,row,column,color,0);
	}
	else if(type=='R'){
		rook(board,moves,type,row,column,color);
	}
	else if(type=='K'){
		knight(board,moves,type,row,column,color);
	}
	else if(type=='Q'){
		//Reuse of rook and bishop functions for queen moves.
		int index;
		index=rook(board,moves,type,row,column,color);
		bishop(board,moves,type,row,column,color,index);
	}
	else if(type=='G'){
		king(board,moves,type,row,column,color);
	}
}


int main(){
	int i,j,k,row,column,x,y,z,move;
	char *piece,*tmp,**moves,*placeToMove;
	char *board[9][9]={
		{"8 ","BR","BK","BB","BQ","BG","BB","BK","BR"},
		{"7 ","BP","BP","BP","BP","BP","BP","BP","BP"},
		{"6 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 "},
		{"5 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 "},
		{"4 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 "},
		{"3 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 "},
		{"2 ","WP","WP","WP","WP","WP","WP","WP","WP"},
		{"1 ","WR","WK","WB","WQ","WG","WB","WK","WR"},
		{"  ","A ","B ","C ","D ","E ","F ","G ","H "}
	};
	x=y=1;
	printBoard(board);
	while(x==1){
		for(i=1;i<3;i++){
			if(i==1){
				y=1;
				moves=(char**) malloc(100*sizeof(char*));
				while(y==1){
					printf("Player 1(W): \n");
					printf("Select a piece : \n");
					scanf("%s",piece);
					row=56-(int)*(piece+1);
					column=charToInt(*piece);
					tmp=board[row][column];
					if(*tmp=='W'){
						y=-1;
					}
				}
				findMoves(board,moves,*(tmp+1),row,column,'W');
				j=0;
				printf("Press  ");
				while(moves[j]!=NULL){
					printf(" %d:%.*s   ",j+1,2,moves[j]);
					j++;
				}
				printf("\n");
				if(moves[0]==NULL){
					printf("There aren't any moves. \n");
					continue;
				}
				scanf("%d",&move);
				placeToMove=moves[move-1];
				board[row][column]="0 ";
				row=56-(int)*(placeToMove+1);
				column=charToInt(*placeToMove);
				if(*board[row][column]=='B' && *(board[row][column]+1)=='G'){
					printf("----------------------------------- \n");
					printf("             GAME OVER              \n");
					printf("          WINNER : WHITE            \n");
					return 0;
				}
				if(*(tmp+1)=='P'){
					board[row][column]="WP";
				}
				if(*(tmp+1)=='R'){
					board[row][column]="WR";
				}
				if(*(tmp+1)=='K'){
					board[row][column]="WK";
				}
				if(*(tmp+1)=='B'){
					board[row][column]="WB";
				}
				if(*(tmp+1)=='Q'){
					board[row][column]="WQ";
				}
				if(*(tmp+1)=='G'){
					board[row][column]="WG";
				}
				printBoard(board);
			}
			if(i==2){
				y=1;
				moves=(char**) malloc(100*sizeof(char*));
				while(y==1){
					printf("Player 2(B): \n");
					printf("Select a piece : \n");
					scanf("%s",piece);
					row=56-(int)*(piece+1);
					column=charToInt(*piece);
					tmp=board[row][column];
					// This if check's purpose is to check if the user chose a valid piece
					if(*tmp=='B'){
						y=-1;
					}
				}
				findMoves(board,moves,*(tmp+1),row,column,'B');
				j=0;
				printf("Press  ");
				while(moves[j]!=NULL){
					printf(" %d:%.*s   ",j+1,2,moves[j]);
					j++;
				}
				printf("\n");
				if(moves[0]==NULL){
					printf("There aren't any moves. \n");
					continue;
				}
				scanf("%d",&move);
				placeToMove=moves[move-1];
				board[row][column]="0 ";
				row=56-(int)*(placeToMove+1);
				column=charToInt(*placeToMove);
				if(*board[row][column]=='W' && *(board[row][column]+1)=='G'){
					printf("----------------------------------- \n");
					printf("             GAME OVER              \n");
					printf("          WINNER : BLACK            \n");
					return 0;
				}
				if(*(tmp+1)=='P'){
					board[row][column]="BP";
				}
				if(*(tmp+1)=='R'){
					board[row][column]="BR";
				}
				if(*(tmp+1)=='K'){
					board[row][column]="BK";
				}
				if(*(tmp+1)=='B'){
					board[row][column]="BB";
				}
				if(*(tmp+1)=='Q'){
					board[row][column]="BQ";
				}
				if(*(tmp+1)=='G'){
					board[row][column]="BG";
				}
				printBoard(board);
			}
		}
	}
	return 0;
}