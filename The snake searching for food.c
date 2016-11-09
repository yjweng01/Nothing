#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

char food[2]={0,0};                   //储存食物的坐标 
int i=0;                              //表示数组下标的变量 
int lenth=3;                          // 表示蛇的长度 
int x[20]={16,17,18};                 //每节蛇身的横坐标 ,最小为1，最大为38 
int y[20]={14,14,14};                 // 每节蛇身的纵坐标，最小为1，最大为31
char direction='d';                   // 储存方向的变量 
	 
void Pos(int x,int y) {               //设置光标位置的函数 
    COORD pos;  
	HANDLE hOutput;
	pos.X=x;
	pos.Y=y;
	hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput,pos); 
 } 
 
void mkfood(){    //制作食物 
    void Pos(); 
	srand((unsigned)time (NULL));
	food[0]=(char) (rand()%38+1);
	food[1]=(char) (rand()%31+1);
    Pos(food[0],food[1]);
    printf("*"); 
}

void map(){	    //打印地图 
    int i,j,k; 
	void Pos();
	Pos(0,0);       
	for(i=0;i<=40;i++) {
	   if (i<40) printf("+");
	   else printf("\n");}
	for(j=0;j<=30;j++) {
	  printf("+                                      +\n");
	}   
	for(i=0;i<=40;i++) {
	   if (i<40) printf("+");
	   else printf("\n");}
	
} 
 
void whether_eatfood(){   //判断是否吃到食物 
   void mkfood();
   void Pos();
   void if_w();
   void if_s();
   void if_a();
   void if_d(); 
   if(x[0]==food[0]&&y[0]==food[1]){
   	lenth=lenth+1;
   	mkfood();
 	for(i=1;i<=lenth;i++){
  		x[i]=x[i-1];
  		y[i]=y[i-1];
 	
	  }
	switch (direction){
		case'w':x[0]=x[1];y[0]=y[1]+1;break;
		    
		case's':x[0]=x[1];y[0]=y[1]-1;break;
		    
		case'a':x[0]=x[1]-1;y[0]=y[1];break;
	
		case'd':x[0]=x[1]+1;y[0]=y[1];break;
		  
	}
   	   
   }
   else ;
}
 
void if_w(){   //如果向上 
   void Pos();   //如果方向向上 
  // for(i=0;i<lenth;i++){
  // 	 y[i]=y[i]-1;
//	 Pos(x[i],y[i]);
//	 printf(".") ;
  // }
  	for(i=1;i<=lenth;i++){
  		x[i]=x[i-1];
  		y[i]=y[i-1];
	  }
	y[0]=y[0]-1;
    for(i=0;i<lenth;i++){
    	Pos(x[i],y[i]);
    	printf(".");
   } 
}

void if_s(){  //如果向下 
   void Pos();
   for(i=1;i<=lenth;i++){
  		x[i]=x[i-1];
  		y[i]=y[i-1];
	  }
   y[0]=y[0]+1;
   for(i=0;i<lenth;i++){
    	Pos(x[i],y[i]);
    	printf(".");
   } 
}
                 
void if_a(){  //如果向左 
   void Pos();
    for(i=1;i<=lenth;i++){
  		x[i]=x[i-1];
  		y[i]=y[i-1];
	  }
   x[0]=x[0]-1;
   for(i=0;i<lenth;i++){
   	 Pos(x[i],y[i]);
   	 printf(".");
   }
}

void if_d(){  //如果向右 
   void Pos();
  for(i=1;i<=lenth;i++){
  		x[i]=x[i-1];
  		y[i]=y[i-1];
	  }
   x[0]=x[0]+1;
   for(i=0;i<lenth;i++){
   	 Pos(x[i],y[i]);
   	 printf(".");
   }
}


int main(){ 
	void mkfood();
	void map();
	void Pos(int x,int y);
	void whether_eatfood();
	void if_w();
	void if_a();
	void if_s();
	void if_d();

	char tem=' ';
    mkfood();
	while(lenth<20){              //主循环体 
   	map();
    whether_eatfood();
    tem=getchar(); 
    if (tem=='w'||tem=='s'||tem=='a'||tem=='d'){
    	direction=tem;
	}   else;
		Sleep(1500);
  system("cls");
	switch (direction){
	    	case 'w':if_w();break;
	    	case 's':if_s();break;
	    	case 'a':if_a();break;
	    	case 'd':if_d();break;
		}

	if(x[0]==0||x[0]==39||y[0]==0||y[0]==32){
	printf ("The snake is dead quq……"); 
	return 0;
    	}	
	   
	 }  
  	printf("蛇蛇吃饱啦，不能再长啦~"); 
    
//	Pos(50,50); 
	return 0;
}
//   杂七杂八的可能要用的东西 
//	Sleep(500)； 
//	system("cls");//清屏函数
//	    printf("■");
//	    sleep(1);


