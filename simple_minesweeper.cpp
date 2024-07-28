#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;

int a[2][8];
char b[10][8],c[10][8];
int x,y;
bool gameOver;

void initialize(){
	srand(time(0));
 	for(int i=0;i<8;i++){
 		a[0][i]=rand()%10;
 		a[1][i]=rand()%8;
 	}
 	
 	for(int i=0;i<10;i++){
 		for(int j=0;j<8;j++){
			b[i][j]='*';
			c[i][j]='0';
		}
	}
	
 	for(int i=0;i<8;i++){
		c[a[0][i]][a[1][i]]='1';
	}
	
	gameOver=false;
}
 
void update(){
 	int count=0;
 	for(int i=0;i<10;i++){
 		for(int j=0;j<8;j++){
 			if((b[i+1][j]=='-'||b[i-1][j]=='-'||b[i][j+1]=='-'||b[i][j-1]=='-'||b[i-1][j-1]=='-'||b[i-1][j+1]=='-'||b[i+1][j+1]=='-'||b[i+1][j-1]=='-')
 			&&!(c[i+1][j]=='1'||c[i-1][j]=='1'||c[i][j+1]=='1'||c[i][j-1]=='1'||c[i-1][j-1]=='1'||c[i-1][j+1]=='1'||c[i+1][j+1]=='1'||c[i+1][j-1]=='1')&&c[i][j]!='1'){
				b[i][j]='-';
			}
			else if((b[i+1][j]=='-'||b[i-1][j]=='-'||b[i][j+1]=='-'||b[i][j-1]=='-'||b[i-1][j-1]=='-'||b[i-1][j+1]=='-'||b[i+1][j+1]=='-'||b[i+1][j-1]=='-')
			&&(c[i+1][j]=='1'||c[i-1][j]=='1'||c[i][j+1]=='1'||c[i][j-1]=='1'||c[i-1][j-1]=='1'||c[i-1][j+1]=='1'||c[i+1][j+1]=='1'||c[i+1][j-1]=='1')&&c[i][j]!='1'){
				if(c[i+1][j]=='1') count++;
				if(c[i-1][j]=='1') count++;
				if(c[i][j+1]=='1') count++;
				if(c[i][j-1]=='1') count++;
				if(c[i-1][j-1]=='1') count++;
				if(c[i-1][j+1]=='1') count++;
				if(c[i+1][j+1]=='1') count++;
				if(c[i+1][j-1]=='1') count++;
				b[i][j]=count+48;
				count=0;
			}
 		}
 	}
}

void print(){
	system("CLS");
	for(int i=0;i<10;i++){
		for(int j=0;j<8;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	for(int i=0;i<10;i++){
		for(int j=0;j<8;j++){
			cout<<c[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void input(){
	int a1,x1[2];
	cout<<"\nDo you want to mark or click:\n1) REVEAL\n2) MARK\n";
	cout<<"Option: ";
	cin>>a1;
	
	switch(a1){
		case 1:
			cout<<"enter coordinates: ";
			cin>>x>>y;
			if(c[x][y]!='1') b[x][y]='-';
			else gameOver=true;
			break;
		case 2:
			cout<<"Enter coordinates of cell you want to mark: ";
			cin>>x1[0]>>x1[1];
			b[x1[0]][x1[1]] = 'F';
			break;
		default:
			cout<<"Enter a valid option!";
	}
}

bool check(){
	int count1=0;
	for(int i=0;i<10;i++) for(int j=0;j<8;j++) if(b[i][j]=='*') count1++;
	if(count1 == 8) return true;
	else return false;
}
 
int main(){ 	
 	int flag=0;
 	initialize();
 	while(!gameOver){
 		update();
 		print();
 		flag++;
 		if(flag==11){
 			if(check()) break;
			input();
			flag=0;
		}
 	}
 	
 	if(gameOver==1) cout<<"!YOU STEPPED ON A MINE!\n";
 	else cout<<"!YOU FOUND ALL THE MINES!\n";
 	
 	return 0;
}
