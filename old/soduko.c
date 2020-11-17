#include <stdio.h>
#include <string.h>
#include <math.h>


int puzzle[9][9]={
	{8,7,6,1,9,0,4,3,0},
	{0,9,1,3,0,0,0,0,2},
	{4,0,0,7,8,5,0,9,1},
	{0,1,0,5,4,8,7,0,0},
	{0,4,3,0,0,0,9,0,8},
	{0,8,5,9,2,0,1,0,0},
	{0,0,4,8,0,1,0,0,0},
	{0,0,0,4,0,6,0,0,7},
	{0,6,0,2,5,0,0,8,4}
};
//small box is 3*3 box
void smallBox(int numList[9],int rowPosition, int columnPosition){
	int rowGridSelect = rowPosition /3;
	int columnGridSelect = columnPosition/3;
	int position[3][3] ={
		{0,1,2},
		{3,4,5},
		{6,7,8}};
	
	//get all the items within the grid and store in single dimensional array
	int i,j;
	int counter=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			numList[counter] = puzzle[position[rowGridSelect][i]][position[columnGridSelect][j]];
			counter++;
		}
	}
		
	
}


void main(){
	int array[9];
	smallBox(array,3,6);
	int i;
	for(i=0;i<9;i++){
	printf("%d \n",array[i]);
	}
}
