#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
# define MAX 10
struct details
{
int amount[MAX];
int rear,front;
};
struct details l1_single,l1_multiple,l2_single,l2_multiple;
void create_queue();
int mov_car(void);
int mov_truck();
void enter_l1();
void enter_l2();
void check_status();
void four_wheeler();
void other_wheeler();
int rno();
int s_entry = 0;
int m_entry = 0;
int main()
{
 int veh;
 char ans;
 clrscr();
 create_queue();
 do
 {
 clrscr();
 printf("WELCOME TO THE TOLL PLAZA\n");
 printf("Which type of vehicle u have?\n1.Four Wheeler\n2.More Than Four Wheeler\n3.Check Status\n4.Exit\n");
 scanf("%d ",&veh);
 switch (veh)
 {
 case 1: enter_l1();
	 break;
 case 2: enter_l2();
	 break;
 case 3: check_status();
	 break;
 case 4: exit(0);
	 break;
 }
 printf("Do you would like to go to the main menu(Y/N)?\n");
 fflush(stdin);
 scanf("%c",&ans);
 }while (ans== 'y'|| ans== 'Y');
 getch();
 return 0;
}

void enter_l1()
 {
 int s_charge = 10;
 int m_charge =20;
 int choice;
 if (l1_single.front == 1 && l1_single.rear == MAX || l1_multiple.front == 1 && l1_multiple.rear == MAX)
 {
 printf("Lane1 is full");
 }
 else
 {
  mov_car();
  printf("What would you like to have?\n1.Single Trip\n 2.Multiple Trip\n");
  scanf("%d",&choice);
  switch (choice)
  {
  case 1:printf("YOUR SLIP IS READY\n");
	 printf("Welcome To The Toll Plaza\n");
	 printf("    TEL:085-656699         \n");
	 printf("----------------------------\n");
	 printf("LANE : 1                    \n");
	 printf("CLASS : 01 MOTORCAR         \n");
	 printf("FARE : RM 10.00             \n");
	 printf("AMOUNT PAID RM 10.00        \n");
	 printf("TRIP : SINGLE               \n");
	 printf("RCPT#    %d\n",rno());
	 printf("-----------------------------\n");
	 printf("        THANK YOU             \n");
	 printf(" VISIT AGAIN & HAPPY JOURNEY  \n");
	 s_entry++;
	 l1_single.amount[l1_single.rear] = s_charge;
	 s_charge =s_charge + 10;
	 l1_single.rear++;

	 break;

  case 2:printf("YOUR SLIP IS READY\n");
	 printf("Welcome To The Toll Plaza\n");
	 printf("    TEL:085-656699         \n");
	 printf("----------------------------\n");
	 printf("LANE : 1                    \n");
	 printf("CLASS : 01 MOTORCAR         \n");
	 printf("FARE : RM 10.00             \n");
	 printf("AMOUNT PAID RM 20.00        \n");
	 printf("TRIP : MULTIPLE             \n");
	 printf("RCPT#    %d\n",rno());
	 printf("-----------------------------\n");
	 printf("        THANK YOU            \n");
	 printf(" VISIT AGAIN & HAPPY JOURNEY \n");
	 m_entry++;
	 l1_multiple.amount[l1_multiple.rear] = m_charge;
	 m_charge = m_charge + 20;
	 l1_multiple.rear++;
	 break;


  }
 }
}

void enter_l2()
 {
 int s_charge = 10;
 int m_charge =20;
 int choice;
 if (l2_single.front == 1 && l2_single.rear == MAX || l2_multiple.front == 1 && l2_single.rear == MAX)
 {
 printf("Lane2 is full");
 }
 else
 {
  mov_truck();
  printf("What would you like to have?\n1.Single Trip\n 2.Multiple Trip\n");
  scanf("%d",&choice);
  switch (choice)
  {
  case 1:printf("YOUR SLIP IS READY\n");
	 printf("Welcome To The Toll Plaza\n");
	 printf("    TEL:085-656699         \n");
	 printf("----------------------------\n");
	 printf("LANE : 1                    \n");
	 printf("CLASS : 02 TRUCK        \n");
	 printf("FARE : RM 10.00             \n");
	 printf("AMOUNT PAID RM 10.00        \n");
	 printf("TRIP : SINGLE               \n");
	 printf("RCPT#   %d\n",rno());
	 printf("-----------------------------\n");
	 printf("        THANK YOU            \n");
	 printf(" VISIT AGAIN & HAPPY JOURNEY \n");
	 s_entry++;
	 l2_single.amount[l1_single.rear] = s_charge;
	 s_charge =s_charge + 10;
	 l2_single.rear++;
	 break;

  case 2:printf("YOUR SLIP IS READY\n");
	 printf("Welcome To The Toll Plaza\n");
	 printf("    TEL:085-656699         \n");
	 printf("----------------------------\n");
	 printf("LANE : 1                    \n");
	 printf("CLASS : 02 TRUCK         \n");
	 printf("FARE : RM 10.00             \n");
	 printf("AMOUNT PAID RM 20.00        \n");
	 printf("TRIP : SINGLE               \n");
	 printf("RCPT#     %d\n",rno());
	 printf("-----------------------------\n");
	 printf("        THANK YOU            \n");
	 printf(" VISIT AGAIN & HAPPY JOURNEY \n");
	 m_entry++;
	 l2_multiple.amount[l2_multiple.rear] = m_charge;
	 m_charge =m_charge + 20;
	 l2_multiple.rear++;
	 break;
  }
 }
}
void check_status()
{
 int option;
 clrscr();
 printf("Select any of the option below to check the status\n1.For Four Wheeler\n2.For More Than Four Wheeler\n");
 scanf("%d",&option);
 switch(option)
 {
  case 1: four_wheeler();
	  break;
  case 2: other_wheeler();
	  break;
 }
}

void four_wheeler()
{
 int sum1=0,i,sum2=0,total;
 printf(">> Status Updates <<\n");
 printf("For Single Trip :\n");
 printf("Number Of Entries : %d\n",s_entry);
 for ( i=l1_single.front;i<MAX;i++);
 {
  sum1 = sum1 + l1_single.amount[i];
 }
 printf("Total Amount : %d\n",sum1);
 printf("For Multiple Trip :\n");
 printf("Number Of Entries : %d\n ",m_entry);
 for ( i=l1_multiple.front;i<MAX;i++);
 {
  sum2 = sum2 + l1_multiple.amount[i];
 }
 printf("Total Amount : %d\n",sum2);
 total = sum1 + sum2;
 printf("Total Collection: %d\n",total);
}

void other_wheeler()
{
 int sum1=0,i,sum2=0,total;
 printf(">> Status Updates <<\n");
 printf("For Single Trip :\n");
 printf("Number Of Entries : %d\n",s_entry);
 for ( i=l2_single.front;i<=MAX;i++);
 {
  sum1 = sum1 + l2_single.amount[i];
 }
 printf("Total Amount : %d\n",sum1);
 printf("For Multiple Trip :\n");
 printf("Number Of Entries : %d\n ",m_entry);
 for ( i=l2_multiple.front;i<=MAX;i++);
 {
  sum2 = sum2 + l2_multiple.amount[i];
 }
 printf("Total Amount : %d\n",sum2);
 total = sum1 + sum2;
 printf("Total Collection: %d\n",total);
}

void create_queue()
{
 l1_single.front = 1;
 l1_single.rear = 0;
 l1_multiple.front = 1;
 l1_multiple.rear = 0;
 l2_single.front = 1;
 l2_single.rear = 0;
 l2_multiple.front = 1;
 l2_multiple.rear = 0;
}
int rno(int n)
{
 n = rand(5);
 return n;
 }
int mov_car()
{
      int gd = DETECT, gm;
    int i, maxx, midy;

    /* initialize graphic mode */
    initgraph(&gd, &gm, "C:\\turboc3\\BGI");
    /* maximum pixel in horizontal axis */
    maxx = getmaxx();
    /* mid pixel in vertical axis */
    midy = getmaxy()/2;

    for (i=0; i < maxx-150; i=i+5) {
	/* clears screen */
	cleardevice();

	/* draw a white road */
	setcolor(WHITE);
	line(0,midy - 190,maxx , midy - 190);
	line(0, midy-170, 100, midy-170);
	line(150,midy -170,250 ,midy -170);
	line(300, midy-170,400, midy-170);
	line(450, midy-170, 550, midy-170);
	line(600,midy-170,650,midy-170);
	line(0,midy -150, maxx , midy - 150);
	line(0,midy -110, maxx , midy - 110);
	line(0,midy - 70, maxx , midy - 70);
	line(0,midy-90,100,midy-90);
	line(150,midy -90,250 ,midy -90);
	line(300, midy-90,400, midy-90);
	line(450, midy-90, 550, midy-90);
	line(600,midy-90,650,midy-90);
	line(0,midy - 37, maxx , midy - 37);
	line(0,midy -21, maxx , midy - 21);
	line(0, midy+10, maxx, midy+10);
	line(0, midy+28, 100, midy+28);
	line(150,midy +28,250 ,midy +28);
	line(300, midy+28,400, midy+28);
	line(450, midy+28, 550, midy+28);
	line(600,midy+28,650,midy+28);
	line(0, midy + 47, maxx, midy + 47);
	line(0,midy+80,maxx,midy+80);
	line(0,midy+100,100,midy+100);
	line(150,midy +100,250 ,midy +100);
	line(300, midy+100,400, midy+100);
	line(450, midy+100, 550, midy+100);
	line(600,midy+100,650,midy+100);
	line(0,midy+120,maxx,midy+120);

	/* Draw Car */
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, RED);

	line(i, midy + 23, i, midy);
	line(i, midy, 40 + i, midy - 20);
	line(40 + i, midy - 20, 80 + i, midy - 20);
	line(80 + i, midy - 20, 100 + i, midy);
	line(100 + i, midy, 120 + i, midy);
	line(120 + i, midy, 120 + i, midy + 23);
	line(0 + i, midy + 23, 18 + i, midy + 23);
	arc(30 + i, midy + 23, 0, 180, 12);
	line(42 + i, midy + 23, 78 + i, midy + 23);
	arc(90 + i, midy + 23, 0, 180, 12);
	line(102 + i, midy + 23, 120 + i, midy + 23);
	line(28 + i, midy, 43 + i, midy - 15);
	line(43 + i, midy - 15, 57 + i, midy - 15);
	line(57 + i, midy - 15, 57 + i, midy);
	line(57 + i, midy, 28 + i, midy);
	line(62 + i, midy - 15, 77 + i, midy - 15);
	line(77 + i, midy - 15, 92 + i, midy);
	line(92 + i, midy, 62 + i, midy);
	line(62 + i, midy, 62 + i, midy - 15);
	floodfill(5 + i, midy + 22, YELLOW);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, DARKGRAY);
	/*  Draw Wheels */
	circle(30 + i, midy + 25, 9);
	circle(90 + i, midy + 25, 9);
	floodfill(30 + i, midy + 25, BLUE);
	floodfill(90 + i, midy + 25, BLUE);
	/* Add delay of 0.1 milli seconds */
	delay(100);
    }

    getch();
    closegraph();
    return 0;

    }
int mov_truck()
{
int gd = DETECT, gm;
    int i, maxx, midy;

    /* initialize graphic mode */
    initgraph(&gd, &gm, "C:\\turboc3\\BGI");
    /* maximum pixel in horizontal axis */
    maxx = getmaxx();
    /* mid pixel in vertical axis */
    midy = getmaxy()/2;
  for (i=0; i < maxx-150; i=i+5) {
	/* clears screen */
	cleardevice();

	/* draw a white road */
	setcolor(WHITE);
	line(0,midy - 190,maxx , midy - 190);
	line(0, midy-170, 100, midy-170);
	line(150,midy -170,250 ,midy -170);
	line(300, midy-170,400, midy-170);
	line(450, midy-170, 550, midy-170);
	line(600,midy-170,650,midy-170);
	line(0,midy -150, maxx , midy - 150);
	line(0,midy -110, maxx , midy - 110);
	line(0,midy - 70, maxx , midy - 70);
	line(0,midy-90,100,midy-90);
	line(150,midy -90,250 ,midy -90);
	line(300, midy-90,400, midy-90);
	line(450, midy-90, 550, midy-90);
	line(600,midy-90,650,midy-90);
	line(0,midy - 37, maxx , midy - 37);
	line(0,midy -21, maxx , midy - 21);
	line(0, midy+10, maxx, midy+10);
	line(0, midy+28, 100, midy+28);
	line(150,midy +28,250 ,midy +28);
	line(300, midy+28,400, midy+28);
	line(450, midy+28, 550, midy+28);
	line(600,midy+28,650,midy+28);
	line(0, midy + 47, maxx, midy + 47);
	line(0,midy+80,maxx,midy+80);
	line(0,midy+100,100,midy+100);
	line(150,midy +100,250 ,midy +100);
	line(300, midy+100,400, midy+100);
	line(450, midy+100, 550, midy+100);
	line(600,midy+100,650,midy+100);
	line(0,midy+120,maxx,midy+120);

   /*Draw the truck*/
   setcolor(RED);
   setfillstyle(SOLID_FILL, RED);
   rectangle(50+i,260,150+i,320);//for bigger rectangle
   rectangle(150+i,320,200+i,290);//for small recangle
   circle(75+i,midy+93,10);
   circle(132+i,midy +93,10);
   circle(185+i,midy+93,10);
   delay(100);

  }
  getch();
 closegraph();
 return 0;
 }





