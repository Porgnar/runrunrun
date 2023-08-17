#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>


void red () {
  printf("\033[1;31m");
}

void green () {
  printf("\033[1;32m");
}

void yellow () {
  printf("\033[1;33m");
}

void blue () {
  printf("\033[1;34m");
}

void magenta () {
  printf("\033[1;35m");
}

void cyan () {
  printf("\033[1;36m");
}

void reset () {
  printf("\033[0m");
}



typedef struct entity{
	int posx;
	int posy;
	int status;
	int radius;
}entity;

int main(){
	
	srand(time(NULL));
	
	int mapwidth=30;
	int mapheight=30;
	int numorc=5;
	int score=0;
	
	entity player;
	player.posx= rand() % mapheight;
	player.posy= rand() % mapwidth;
	if(player.posx==0){player.posx=1;}
	if(player.posx==mapheight){player.posx=1;}
	if(player.posy==0){player.posy=1;}
	if(player.posy==mapwidth){player.posy=mapwidth-1;}
	
	entity treasure;
	treasure.posx= rand() % mapheight;
	treasure.posy= rand() % mapwidth;
	if(treasure.posx==0){treasure.posx=1;}
	if(treasure.posx==mapheight){treasure.posx=1;}
	if(treasure.posy==0){treasure.posy=1;}
	if(treasure.posy==mapwidth){treasure.posy=mapwidth-1;}
	
	
	entity orc[numorc];
	
	for(int i=0;i<numorc;i++){
		orc[i].radius=6;
		orc[i].posx= rand() % mapheight;
		orc[i].posy= rand() % mapwidth;
		if(orc[i].posy==0){orc[i].posy=1;}
		if(orc[i].posy==mapwidth){orc[i].posy=mapwidth-1;}
		if(orc[i].posx==0){orc[i].posy=1;}
		if(orc[i].posx==mapheight){orc[i].posy=mapheight-1;}
	}
	

	
	char map[mapheight][mapwidth];
	
	for (int i=0;i<mapheight;i++){
		for (int j=0;j<mapwidth;j++){
			
			if((i==0)||(j==0)||(i==mapheight-1)||(j==mapwidth-1)){map[i][j]='#';}
			else{map[i][j]='.';};
			
			
		}
	}
	/*
	for(int i=2;i<4;i++){
		for (int j=i+1;j<i+4;j++){
			
			map[i][j]='#';
		}
		
	}*/
	
//	map[18][19]='#';
//	map[19][18]='#';
	
	map[player.posx][player.posy]='X';
	map[treasure.posx][treasure.posy]='@';
	
	for (int i=0;i<numorc;i++){ 
		map[orc[i].posx][orc[i].posy]='O';
	}
	
	
	
	system("clear");
		/*
		for (int i=(player.posx-5);i<(player.posx+6);i++){
			for(int j=(player.posy-5);j<(player.posy+6);j++){
				
				if((i>=0)&&(i<=20)&&(j>=0)&&(j<=20)){
					if(map[i][j]=='X'){cyan();}
					if(map[i][j]=='O'){red();}
					printf("%c ",map[i][j]);
					reset();
				}
				
			}
			printf("\n");
		}*/
		
		for (int i=0;i<mapheight;i++){
			for(int j=0;j<mapwidth;j++){
				
				if((i>=0)&&(i<=mapheight-1)&&(j>=0)&&(j<=mapwidth-1)){
					if(map[i][j]=='X'){cyan();}
					if(map[i][j]=='O'){red();}
					if(map[i][j]=='@'){yellow();}
					if(map[i][j]=='#'){magenta();}
					if(map[i][j]=='.'){green();}
					printf("%c ",map[i][j]);
					reset();
				}
				
			}
			printf("\n");
		}	//print map and position loop
	


	for(;;){			//main loop
	
		printf("\n");
		
		
		//input deciding the next step of the player character, will proably export it to a custom header and a void function if enough of these things come up
		
		
		int input;
		
		for(;;){
			scanf("%d",&input);
			if((input>=0)&&(input<=9)){break;break;}
		}
		
		
		map[player.posx][player.posy]='.';
		
		
		
		if(input==4){
			if((map[player.posx][player.posy-1]!='#')&&(map[player.posx][player.posy-1]!='O')){player.posy-=1;}
		}
		
		if(input==6){
			if((map[player.posx][player.posy+1]!='#')&&(map[player.posx][player.posy+1]!='O')){player.posy+=1;}
		}
		
		if(input==8){
			if((map[player.posx-1][player.posy]!='#')&&(map[player.posx-1][player.posy]!='O')){player.posx-=1;}
		}
		
		if(input==2){
			if((map[player.posx+1][player.posy]!='#')&&(map[player.posx+1][player.posy]!='O')){player.posx+=1;}
		}
		
		if(input==1){
			if((map[player.posx+1][player.posy-1]!='#')&&(map[player.posx+1][player.posy-1]!='O')){player.posy-=1;player.posx+=1;}
		}
		
		if(input==7){
			if((map[player.posx-1][player.posy-1]!='#')&&(map[player.posx-1][player.posy-1]!='O')){player.posy-=1;player.posx-=1;}
		}
		
		if(input==9){
			if((map[player.posx-1][player.posy+1]!='#')&&(map[player.posx-1][player.posy+1]!='O')){player.posy+=1;player.posx-=1;}
		}
		
		if(input==3){
			if((map[player.posx+1][player.posy+1]!='#')&&(map[player.posx+1][player.posy+1]!='O')){player.posy+=1;player.posx+=1;}
		}
		


		map[treasure.posx][treasure.posy]='@';
		map[player.posx][player.posy]='X'; //player moves


		if((player.posx==treasure.posx)&&(player.posy==treasure.posy)){
			score++;
			treasure.posx= rand() % mapheight;
			treasure.posy= rand() % mapwidth;
			if(treasure.posx==0){treasure.posx=1;}
			if(treasure.posx==mapheight){treasure.posx=1;}
			if(treasure.posy==0){treasure.posy=1;}
			if(treasure.posy==mapwidth){treasure.posy=mapwidth-1;}
		}

		for(int i=0;i<numorc;i++){

			int orng=rand() % 5;
		
			if((orng==0)||(orng==2)||(orng==4)||(orng==3)){
	
				if((abs(orc[i].posx-player.posx)<=orc[i].radius)&&(orc[i].posx<player.posx)&&(map[orc[i].posx+1][orc[i].posy]!='#')&&(map[orc[i].posx+1][orc[i].posy]!='O')&&(map[orc[i].posx+1][orc[i].posy]!='X')){
					map[orc[i].posx][orc[i].posy]='.';
					orc[i].posx+=1;			
					
				}
				
				else if((abs(orc[i].posx-player.posx)<orc[i].radius)&&(orc[i].posx>player.posx)&&(map[orc[i].posx-1][orc[i].posy]!='#')&&(map[orc[i].posx-1][orc[i].posy]!='O')&&(map[orc[i].posx-1][orc[i].posy]!='X')){
					map[orc[i].posx][orc[i].posy]='.';
					orc[i].posx-=1;			
					
				}
				
				else if((abs(orc[i].posy-player.posy)<orc[i].radius)&&(orc[i].posy<player.posy)&&(map[orc[i].posx][orc[i].posy+1]!='#')&&(map[orc[i].posx][orc[i].posy+1]!='O')&&(map[orc[i].posx][orc[i].posy+1]!='X')){
					map[orc[i].posx][orc[i].posy]='.';
					orc[i].posy+=1;			
				
				}
			
				else if((abs(orc[i].posy-player.posy)<orc[i].radius)&&(orc[i].posy>player.posy)&&(map[orc[i].posx][orc[i].posy-1]!='#')&&(map[orc[i].posx][orc[i].posy-1]!='O')&&(map[orc[i].posx][orc[i].posy-1]!='X')){
					map[orc[i].posx][orc[i].posy]='.';
					orc[i].posy-=1;			
				
				}else{orng=1;}
	
			}
			
			
			
			if((orng==1)){
				int rdir=rand() % 10;
				
				if((rdir==5)||(rdir==0)||(rdir==10)){rdir=7;}
				
				if(rdir==4){
					if((map[orc[i].posx][orc[i].posy-1]!='#')&&(map[orc[i].posx][orc[i].posy-1]!='X')&&(map[orc[i].posx][orc[i].posy-1]!='O')){map[orc[i].posx][orc[i].posy]='.';orc[i].posy-=1;}
				}
			
				if(rdir==6){
					if((map[orc[i].posx][orc[i].posy+1]!='#')&&(map[orc[i].posx][orc[i].posy+1]!='X')&&(map[orc[i].posx][orc[i].posy+1]!='O')){map[orc[i].posx][orc[i].posy]='.';orc[i].posy+=1;}
					}
			
				if(rdir==8){
					if((map[orc[i].posx-1][orc[i].posy]!='#')&&(map[orc[i].posx-1][orc[i].posy]!='X')&&(map[orc[i].posx-1][orc[i].posy]!='O')){map[orc[i].posx][orc[i].posy]='.';orc[i].posx-=1;}
				}
			
				if(rdir==2){
					if((map[orc[i].posx+1][orc[i].posy]!='#')&&(map[orc[i].posx+1][orc[i].posy]!='X')&&(map[orc[i].posx+1][orc[i].posy]!='O')){map[orc[i].posx][orc[i].posy]='.';orc[i].posx+=1;}
				}
			
				if(rdir==1){
					if((map[orc[i].posx+1][orc[i].posy-1]!='#')&&(map[orc[i].posx+1][orc[i].posy-1]!='X')&&(map[orc[i].posx+1][orc[i].posy-1]!='O')){map[orc[i].posx][orc[i].posy]='.';orc[i].posy-=1;orc[i].posx+=1;}
				}
			
				if(rdir==7){
					if((map[orc[i].posx-1][orc[i].posy-1]!='#')&&(map[orc[i].posx-1][orc[i].posy-1]!='X')&&(map[orc[i].posx-1][orc[i].posy-1]!='O')){map[orc[i].posx][orc[i].posy]='.';orc[i].posy-=1;orc[i].posx-=1;}
				}
			
				if(rdir==9){
					if((map[orc[i].posx-1][orc[i].posy+1]!='#')&&(map[orc[i].posx-1][orc[i].posy+1]!='X')&&(map[orc[i].posx-1][orc[i].posy+1]!='O')){map[orc[i].posx][orc[i].posy]='.';orc[i].posy+=1;orc[i].posx-=1;}
				}
			
				if(rdir==3){
					if((map[orc[i].posx+1][orc[i].posy+1]!='#')&&(map[orc[i].posx+1][orc[i].posy+1]!='X')&&(map[orc[i].posx+1][orc[i].posy+1]!='O')){map[orc[i].posx][orc[i].posy]='.';orc[i].posy+=1;orc[i].posx+=1;}
				}
				
				
				
			}
		
		map[orc[i].posx][orc[i].posy]='O';	//orc i moves
		
		}//for orcs
		
	
		
		
		
		
		
		system("clear");
	
	
	/*
		for (int i=(player.posx-5);i<(player.posx+6);i++){
			for(int j=(player.posy-5);j<(player.posy+6);j++){
				
				if((i>=0)&&(i<=20)&&(j>=0)&&(j<=20)){
					if(map[i][j]=='X'){cyan();}
					if(map[i][j]=='O'){red();}
					printf("%c ",map[i][j]);
					reset();
				}
				
			}
			printf("\n");
		}	//print map and position loop
		
*/	
		
		sleep(0.5);
		
		for (int i=0;i<mapheight;i++){
			for(int j=0;j<mapwidth;j++){
				
				if((i>=0)&&(i<=mapheight-1)&&(j>=0)&&(j<=mapwidth-1)){
					if(map[i][j]=='X'){cyan();}
					if(map[i][j]=='O'){red();}
					if(map[i][j]=='@'){yellow();}
					if(map[i][j]=='#'){magenta();}
					if(map[i][j]=='.'){green();}
					printf("%c ",map[i][j]);
					reset();
				}
				
			}
			printf("\n");
		}	//print map and position loop
		
		yellow();
		printf("\nYour score is: %d\n",score);
		reset();
		
		int caught=0;
		
		for (int i=player.posx-1;i<player.posx+2;i++){
			for (int j=player.posy-1;j<player.posy+2;j++){
				if(map[i][j]=='O'){caught++;}
			}
			
		}
		
		if(caught!=0){red();printf("\nYou got caught, game over!\n\n");reset();break;break;}


		
	}	//main game loop

	
		
	
	
	
	
	
	
	return 0;
}