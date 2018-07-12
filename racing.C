#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#define bwfb (7*16+1)
#define bwfr (7*16+4)
#define bwfw (7*16+7)
#define bbwfr (16*15+4)
void enemy_generator();
void levelgenerator();
char far *origin=(char*)0xB8000000;
char *message;
int h=-51,v=-70;
int s,stage=0;
int x[40],y[40];
void menu();

void enemy_generator()
{int n=12;
int enemyno=10+stage*3;
int limit;
int r;
char far *ptr;
 stage++;
 y[0]=0;
 y[1]=-7;


limit =RAND_MAX-(RAND_MAX % n);
for(s=0;s<enemyno;s++)
{
while((r=rand())>=limit);
r=(r%n)*4+16;
if(r==x[s-1])
s--;
else{
 x[s]= r;}}
}
void text (char *message,int a)
{ char far *ptr;
 ptr=origin;
 ptr=ptr+(2*12*80)+30*2;
 for( s=0;message[s]!='\0';s++)
{ if(message[s]=='\n')
{ptr=origin+(2*13*80)+28*2;
continue;}
*ptr=message[s];
ptr++;
if(a==0)
*ptr=bwfb;
else
*ptr=bbwfr;
ptr++; }
getch();}
void gameover()
{text("GAME OVER !!!          ",1);
exit(0);
}
void main()
{
char a=-37,b=32,blocks=-80,z,points=1,heart=3;
int k1=18,l1=15,k2=24,l2=18,l3=0,l4=1;
int life=0,p,point=0,counter=0;
int i,n,j,g,m;
int o=0;
int k=0;
int enemy=1;

char far *ptr;
stage=0;

menu();

for (n=0;n<1000;n++ )
{clrscr();
ptr=origin;

  if(o==0)
    {o=1;}
    else{
    o=0;}
for( j=0;j<25;j++)
{
for(i=0;i<80;i++)
{if(j==0)
{if(i==5)
{message="points=";
for( s=0;message[s]!='\0';s++)
{
*ptr=message[s];
ptr++;
*ptr=bwfb;
ptr++; }
for( p=0;p<point;p++)
{*ptr=points;
ptr++;
*ptr=bwfr;
ptr++;}
i=11+point;}
else
if(i==40)
{ message="life=";
  for( s=0;message[s]!='\0';s++)
{
*ptr=message[s];
ptr++;
*ptr=bwfb;
ptr++; }


for(g=0;g<life;g++)
{
*ptr=heart;
ptr++;
*ptr=bwfr;
ptr++;
}
i=44+life;}
else if(i==60)
{ message="steps=";
  for( s=0;message[s]!='\0';s++)
{
*ptr=message[s];
ptr++;
*ptr=bwfb;
ptr++;
i++; }
*ptr=(48)+((99-k)/10);
ptr++;
i++;
*ptr=bwfb;
ptr++;
*ptr=(48)+((99-k)%10);
ptr++;
*ptr=bwfb;
ptr++;
i++;
k++;
if(k>=1000)
exit(0);
   }


else
{*ptr=32;
ptr++;
*ptr=bwfw;
ptr++;
}}

else
if(j==1&&i==2)
{*ptr=-43;
ptr++;
*ptr=bwfb;
ptr++; }
else
if(j==24&&i==2)
{*ptr=-44;
ptr++;
*ptr=bwfb;
ptr++; }
else
if(j==1&&i==77)
{*ptr=-73;
ptr++;
*ptr=bwfb;
ptr++; }
else
if(j==24&&i==77)
{*ptr=-39;
ptr++;
*ptr=bwfb;
ptr++; }
else

if((j==1&&i>2&&i<77)||(j==24&&i>2&&i<=77))
{
*ptr=h;
ptr++;
*ptr=bwfb;
ptr++;
}
else if((i==2&&j>=1&&j<=24)||(i==77&&j>=1&&j<=24))
{
*ptr=v;
ptr++;
*ptr=bwfb;
ptr++;
}
 else

if((i>=x[l3]&&(i<=x[l3]+4)&&j>=y[l3]&&j<=(y[l3]+4)&&y[l3]>=0&&y[l3]<=24))
 {if(j==y[l3]||j==(y[l3]+4))
 {*ptr=32;
ptr++;
*ptr=4*16;
ptr++;}
else if((i==(x[l3]+2)&&j==y[l3]+1)||(i==(x[l3]+2)&&j==y[l3]+1))
 {*ptr=32;
ptr++;
*ptr=7*16;
ptr++;}
 else{
*ptr=32;
ptr++;
*ptr=1*16;
ptr++;}}else
 if((i>=x[l4]&&(i<=x[l4]+4)&&j>=y[l4]&&j<=(y[l4]+4)&&y[l4]>=0&&y[l4]<=24))
{if(j==y[l4]||j==(y[l4]+4))
 {*ptr=32;
ptr++;
*ptr=4*16;
ptr++;}
else if((i==(x[l4]+2)&&j==y[l4]+1)||(i==(x[l4]+2)&&j==y[l4]+1))
 {*ptr=32;
ptr++;
*ptr=7*16;
ptr++;}
 else{
*ptr=32;
ptr++;
*ptr=1*16;
ptr++;}
}

else if(i>=k1&&i<=k2&j>=l1&&j<=l2)
{if(j==l1||j==l2)
 {*ptr=32;
ptr++;
*ptr=4*16;
ptr++;}
else if((i==(k1+2)&&j==l1+1)||(i==(k2-2)&&j==l1+1))
 {*ptr=32;
ptr++;
*ptr=7*16;
ptr++;}
 else{
*ptr=32;
ptr++;
*ptr=1*16;
ptr++;}}
else
if ((i==15||i==65)||(i==40))
{
if(i==40&&(j%2==o))
{*ptr=32;
ptr++;
*ptr=bwfw;
ptr++;
}
else
{  *ptr=32;
ptr++;
*ptr=0;
ptr++;
    }
     }
else if((i>15&&i<65)||i<2||i>77)
{*ptr=32;
ptr++;
*ptr=bwfw;
ptr++;}
else
if(i>=68&&i<=74&&j>=9&&j<=17)
{if(i==68||i==74||j==9||j==17)
{*ptr=32;
ptr++;
*ptr=bwfw;
ptr++;}
else{ *ptr=32;
ptr++;

if(j>(9+(k/12)))
{
*ptr=4*16;}
else{*ptr=0;}
ptr++; }}
else{
*ptr=32;
ptr++;
*ptr=2*16;
ptr++;}

}
  }
if(kbhit())
{
z=getch();
if(z=='s')
{
if((l2+1)!=24)
{l2++;
l1++;}

}else
if(z=='p')
{menu();}
else
if(z=='d')
{
if((k2+1)%65!=0)
{
k1++;
k2++;}
}
else if(z=='a')
{
if((k1-1)!=15)
{
k1--;
k2--;}

}
else if(z=='w')
{
if((l1-1)!=2)
{ l1--;
l2--;}
}}
  y[l4]++;
if(y[l4]==24)
{l4+=2;
y[l4]=0;
enemy++;}
y[l3]++;
if(y[l3]==24)
{
l3+=2;
y[l3]=0;
enemy++;}
if(enemy==(10+stage*3+1))
{if(k1==y[l3])
{text("you won the game !!",1);
 return;}}
/*checking whether the car has collided*/
{int n,m;
for(n=k1;n<=k2;n++)
{for(m=l1;m<=l2;m++)
{if((m==y[l3]||m==(y[l3]+4))&&(n==x[l3]||n==(x[l3]+4)))
{text("you died",1);
exit(0);}
if((m==y[l4]||m==(y[l4]+4))&&(n==x[l4]||n==(x[l4]+4)))
{text("you died",1);
exit(0);}
}
 }
 }

 delay(150);
 }



getch();}
void menu()
{int u=1,i,j;
char ch;
char far *ptr;


while(1)
{ptr=origin;
for(j=0;j<25;j++)
{
 for( i=0;i<80;i++)
{
if(j==1&&i==2)
{*ptr=-43;
ptr++;
*ptr=bwfb;
ptr++; }
else
if(j==24&&i==2)
{*ptr=-44;
ptr++;
*ptr=bwfb;
ptr++; }
else
if(j==1&&i==77)
{*ptr=-73;
ptr++;
*ptr=bwfb;
ptr++; }
else
if(j==24&&i==77)
{*ptr=-39;
ptr++;
*ptr=bwfb;
ptr++; }
else

if((j==1&&i>2&&i<77)||(j==24&&i>2&&i<=77))
{
*ptr=h;
ptr++;
*ptr=bwfb;
ptr++;
}
else if((i==2&&j>=1&&j<=24)||(i==77&&j>=1&&j<=24))
{
*ptr=v;
ptr++;
*ptr=bwfb;
ptr++;
}
else
{*ptr=32;
ptr++;
*ptr=7*16;
ptr++;}
}}
ptr=origin+2*12*80+2*30;
message="=>restart" ;
for( s=0;message[s]!='\0';s++)
{
*ptr=message[s];
ptr++;
if(u==2)
{
*ptr=bbwfr;
ptr++;}
else
{*ptr=bwfb;
ptr++;}
 }
ptr=origin+2*13*80+2*30;
message="=>exit";
for( s=0;message[s]!='\0';s++)
{
*ptr=message[s];
ptr++;
if(u==3)
{
*ptr=bbwfr;
ptr++;}
else
{*ptr=bwfb;
ptr++;}}
if (stage!=0)
{ptr=origin+2*11*80+2*30;
message="=>resume";
for( s=0;message[s]!='\0';s++)
{
*ptr=message[s];
ptr++;
if(u==1)
{
*ptr=bbwfr;
ptr++;}
else
{*ptr=bwfb;
ptr++;} }
 }
 else
 {ptr=origin+2*11*80+2*35;
message="MENU";
for( s=0;message[s]!='\0';s++)
{
*ptr=message[s];
ptr++;
if(u==1)
{
*ptr=bbwfr;
ptr++;}
else
{*ptr=bwfb;
ptr++;} } }
ch=getch();
if(ch=='\r')
{if(u==1)
{ if(stage!=0)
break;}
else if(u==2)
{stage=0;
levelgenerator();
break;}
if(u==3)
{exit(0);}

}

else if(ch=='w')
{if(u==1)
u=3;
else
u--;}
else if(ch=='s')
{if(u==3)
u=1;
else
u++;}


}

}


void levelgenerator()
{stage++;
enemy_generator(stage);}
