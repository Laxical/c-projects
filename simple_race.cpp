#include<iostream>
#include<math.h>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
	srand(time(0));
	const int size = 60;
	
	cout<<"Enter a alphabet to start: ";
	char x;
	cin>>x;
	
	int position;position = size/2;
	
	while(true){
		cout<<"|Start|";
		for(int i=0;i<size;i++){
			if(i==position)
				cout<<x;
			else
				cout<<" ";
		}
		cout<<"|Finish|"<<endl;
		position = position + (rand()%3-1);
		if(position<1){
			cout<<"You could not finish the race!"<<endl;
			break;
		}
		if(position>size-1){
			cout<<"Congrats!You finished the race!"<<endl;
			break;
		}
		for(int j=0;j<1000000;j++){
		}
	}

	return 0;
}
