#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

char food[2]={0,0};                   //����ʳ������� 
int i=0;                              //��ʾ�����±�ı��� 
int lenth=3;                          // ��ʾ�ߵĳ��� 
int x[20]={16,17,18};                 //ÿ������ĺ����� ,��СΪ1�����Ϊ38 
int y[20]={14,14,14};                 // ÿ������������꣬��СΪ1�����Ϊ31
char direction='d';                   // ���淽��ı��� 
	 
void Pos(int x,int y) {               //���ù��λ�õĺ��� 
    COORD pos;  
	HANDLE hOutput;
	pos.X=x;
	pos.Y=y;
	hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput,pos); 
 } 
 
void mkfood(){    //����ʳ�� 
    void Pos(); 
	srand((unsigned)time (NULL));
	food[0]=(char) (rand()%38+1);
	food[1]=(char) (rand()%31+1);
    Pos(food[0],food[1]);
    printf("*"); 
}

void map(){	    //��ӡ��ͼ 
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
 
void whether_eatfood(){   //�ж��Ƿ�Ե�ʳ�� 
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
 
void if_w(){   //������� 
   void Pos();   //����������� 
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

void if_s(){  //������� 
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
                 
void if_a(){  //������� 
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

void if_d(){  //������� 
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
	while(lenth<20){              //��ѭ���� 
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
	printf ("The snake is dead quq����"); 
	return 0;
    	}	
	   
	 }  
  	printf("���߳Ա����������ٳ���~"); 
    
//	Pos(50,50); 
	return 0;
}
//   �����Ӱ˵Ŀ���Ҫ�õĶ��� 
//	Sleep(500)�� 
//	system("cls");//��������
//	    printf("��");
//	    sleep(1);


