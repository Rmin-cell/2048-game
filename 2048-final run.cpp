#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include<conio.h>
#include<windows.h>

int counter=0;
int score=0;
int counter2=0;
using namespace std;

int board[4][4];
int dirline[]={1,0,-1,0};
int dircolumn[]={0,1,0,-1};

pair <int ,int >generateunoccupiedposition(){
    int occupied=1,line,column;
    while(occupied){
        line=rand()%4;
        column=rand()%4;
        if(board[line][column]==0)
            occupied=0;
    }
    return make_pair(line,column);
}
void addpiece(){
    pair<int,int >pos=generateunoccupiedposition();
    board[pos.first][pos.second]=2;
}
void newgame(){
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
            board[i][j]=0;
    if(counter==1){
    	addpiece();
    	addpiece();
	}
	else	        
    	addpiece();
}
void Menu(){
	system("cls");
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j)
            if(board[i][j]==0)
                cout<<setw(4)<<"-";
            else
                cout<<setw(4)<<board[i][j];
        cout<<"\n";
    }
	cout<<"Menu:"<<endl<<"N:New Game"<<endl<<"Q=quit"<<endl<<"P=overall score"<<endl;
}
bool candomove(int line,int column,int nextline,int nextcolumn){
    if(nextline<0 || nextcolumn<0 || nextline>=4 || nextcolumn>=4
        || (board[line][column])!=board[nextline][nextcolumn] && board[nextline][nextcolumn] !=0)
            return false;
    return true;
}
void applymove(int direction){
    int startline=0,startcolumn=0,linestep=1,columnstep=1;
    if(direction==0){
        startline=3;
        linestep=-1;
    }
    if(direction==1){
        startcolumn=3;
        columnstep=-1;
    }
    int movepossible=0;
    for(int i=startline;i>=0 && i<4; i+=linestep)
        for(int j=startcolumn;j>=0 && j<4 ;j+=columnstep){
            int nextI=i+dirline[direction],nextJ=j+dircolumn[direction];
            if(candomove(i,j,nextI,nextJ)){	
               board[nextI][nextJ]+=board[i][j];
               score=score+board[nextI][nextJ];
               board[i][j]=0;
               movepossible=1;

            }
        }
    if(movepossible)
        addpiece();
	else{
		cout<<"You Lose! better Luck next time ;)";
		Sleep(3000);	
	}
	 

}


int main(int argc, char** argv) {
	char start,comment;
	char commandtodir[128];
    commandtodir['s']=0;
    commandtodir['d']=1;
    commandtodir['w']=2;
    commandtodir['a']=3;
	cout<<"Welcome to 2048 Game.Press N to start a New Game: "<<endl;
	cin>>start;
	if(start=='n' || start=='N'){
		++counter;
		newgame();
		++counter2;
		while(true){
    Menu();
    char command;
    command=getch();
	if(command=='n' || command=='N'){
		newgame();    
		score=0;
	}
		
    else if(command=='q'|| command=='Q') {
		cout<<"Are you sure? Y=yes,N=no";
		cin>>comment;
		if(comment=='y' || comment=='Y')
			break;		
	}
	else if(command=='p' || command=='P'){
		cout<<"your overall score is:"<<score;	
		Sleep(3000);	
}
    else{
        int currentdirection=commandtodir[command];
        applymove(currentdirection);
    }

  }
	
}
	counter=0;
	
		
/*char commandtodir[128];
    commandtodir['s']=0;
    commandtodir['d']=1;
    commandtodir['w']=2;
    commandtodir['a']=3;
    
  while(true){
    Menu();
    char command;
    command=getch();
    
    if(command!='n' || command!='q' || command!='p' && counter2<1)
        break;
	if(command=='n' || command=='N')
		newgame();    
    else if(command=='q'|| command=='Q') {
		cout<<"Are you sure? Y=yes,N=no";
		cin>>comment;
		if(comment=='y' || comment=='Y')
			break;		
	}
	else if(command=='p' || command=='P'){
		cout<<"your overall score is:"<<score;	
		Sleep(3000);	
}
    else{
        int currentdirection=commandtodir[command];
        applymove(currentdirection);
    }

  }
*/	
	return 0;
}
