#include<iostream>
//#include<conio.h>
using namespace std;
#define VEX 4
#define INT64_MAX 999999
int b[VEX][VEX];

void printPath(int path[][VEX], int i, int j){
	if(path[i][j] == i) return;
	printPath(path, i, path[i][j]);
	cout<<path[i][j]<< " ";
}

void floyd() {
	int i, j, k;
	int path[VEX][VEX];
	//init path[][]
	for(i=0; i<VEX; i++)
		for(j=0; j<VEX; j++){
			if(i==j) path[i][j] = 0;
			else if(b[i][j] != INT64_MAX) path[i][j] = i;
			else path[i][j] = -1;
		}
	//running fWarshalll
	for(k=0; k<VEX; k++)
		for(i=0; i<VEX; i++)
			for(j=0; j<VEX; j++)
				if((b[i][k]*b[k][j]) !=0 && (i!=j))
					if((b[i][k]+b[k][j] < b[i][j]) || (b[i][j]==0)) {
						b[i][j] = b[i][k] + b[k][j];
						path[i][j] = path[k][j];
					}
	for(i=0; i<VEX; i++)
		for(j=0; j<VEX; j++)
			cout<<b[i][j]<<" ";
	cout<<"Paths\n";
	for(i=0; i<VEX; i++)
		for(j=0; j<VEX; j++){
			if(i!=j && path[i][j]!=-1){
				cout<<"Shortest path from "<<i<<"to "<<j<<" is "<<i<<" " ;
				printPath(path, i, j);
				cout<<j<<"\n";
			}
		}

}

int main() {
	//cout<<"enter number of nodes: ";
	int i, j;
	//cin>>n;
	cout<<"Enter adj matrix:\n";
	for(i=0; i<VEX; i++) {
		cout<<"Enter values of "<<i+1<<"th row\n";
		for(j=0; j<VEX; j++)
			cin>>b[i][j];
	}
	floyd();
	return 0;
}
