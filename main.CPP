#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<new.h>
#include<dos.h>

//header file inclusion

typedef struct node
{
	struct node * next;
	int seat;
	char name[100];
	char adress[100];
	int age;
	char phone[100];
}node;

/*  the node consists of all information of
	 a particular traveller  */

typedef struct ll         //the linked list
{
	node *head;
	node *end;
	int count;
}ll;



ll* initialise()
{
	ll *l;
	l=(ll*)malloc(sizeof(ll));
	l->head=NULL;
	l->end=NULL;
	l->count=0;
	return l;
}


node* createnode(int seatx,char namex[100],char adressx[100],int agex,char phonex[100])
{
	node *newx;
	newx =(node *)malloc(sizeof(node));
	newx->seat=seatx;
	strcpy(newx->name,namex);
	newx->next=NULL;
	strcpy(newx->adress,adressx);
	newx->age=agex;
	strcpy(newx->phone,phonex);
	return newx;
}                  /*creating the linked list and assigning the information*/



void insertend(ll *l,int seatx,char namex[100],char adressx[100],int agex,char phonex[100])
{
	node *newx;
	newx=createnode(seatx,namex,adressx,agex,phonex);
	if(l->head==NULL)
	{
		l->end=newx;
		l->head=newx;
	}
	else
	{
		l->end->next=newx;
		l->end=newx;
		newx->next=NULL;
	}
	l->count++;
}
	/* to insert nodes at the end of linked list */


void clear()  //to clear the screen and put colors
{
	int i;
	for(i=0;i<81;i++)
	printf("\n");
}


void print(ll *l)
{
	node *temp;
	int i,j;
	char s;
	char t[10];
	t[1]='\0';
	t[2]='\0';
	clrscr();
	setbkcolor(YELLOW);
	clear();
	settextstyle(2,0,1);
	setusercharsize(1,1,1,1);

	for(i=120,j=1;i<430;i=i+20,j++)
	{

		setcolor(GREEN);  //setting colour to green for available seats
		for(temp=l->head;temp!=NULL;temp=temp->next)
		{
			if(temp->seat==j)
			setcolor(RED);    //if the seat is occupied print in red
		}
		t[0]=(char)((j/10)+48);
		t[1]=(char)((j%10)+48);  //extracting digits of the seat and storing it in char to be able to use in outtext

		rectangle(125,i,150,i+20);
		outtextxy(152,i+10,t);//seat no..
		j++;

		t[0]=(char)((j/10)+48);
		t[1]=(char)((j%10)+48);

		setcolor(GREEN);

		for(temp=l->head;temp!=NULL;temp=temp->next)
		{
			if(temp->seat==j)
			setcolor(RED);
		}

		rectangle(230,i,255,i+20);

		outtextxy(260,i+10,t);
	   }
	setcolor(GREEN);

	settextstyle(7,0,4);
	outtextxy(350,100,"Green::Available");
	setcolor(RED);
	outtextxy(350,140,"Red::Occupied");
	setcolor(WHITE);

}

int password()                   //setting the security password

{

	char pass[15]={0},check[15]={0},ch;

	//pass stores the input by user
	//check stores the correct password

	FILE *fpp;

	int i=0,j;

	printf("::FOR SECURITY PURPOSE::");

	for(j=0;j<1;j++)

	{

			i=0;

			printf("\n\n\tENTER THE PASSWORD:");

			pass[0]=getch();
			while(pass[i]!='\r')  //while the input is not enter

			{

			    if(pass[i]=='\b')

			    {

				i--;

				printf("\b");

				printf(" ");

				printf("\b");

				pass[i]=getch();
			    }
			    else
			    {
				printf("*");
				i++;
				pass[i]=getch();
			    }

			}
			i++;
			pass[i]='\0';
			FILE *q;
			q=fopen("SE.txt","w");
			fprintf(q,"password");
			fclose(q);
			fpp=fopen("SE.txt","r");

			if (fpp==NULL)
			{
			    printf("\nERROR WITH THE SYSTEM FILE...[FILE MISSING]\n");

			    getch();

			    return 1;

			}

			else

			i=0;

			while(1)

			{

			    ch=fgetc(fpp);

			    if(ch==EOF)

			    {

				check[i]='\0';

				break;

			    }

			    check[i]=ch-5;

			    i++;

			}

			if(strcmp(pass,check)==0)

			{

			    printf("\n\n\tACCESS GRANTED...\n");

			    return 0;

			}

			else

			{

			}

	}
	 getch();

	return 1;

}

void editpassword() //to change the password

{

    //system("cls");

    //printf("\n");

    char pass[15]={0},confirm[15]={0},ch;

    int choice,i,check;

    FILE *fp;

    fp=fopen("SE.txt","rb");

    if(fp==NULL)

    {

	fp=fopen("SE.txt","wb");

	if(fp==NULL)

	{

	    printf("SYSTEM ERROR...");

	    getch();

	    return ;

	}

	fclose(fp);

	printf("\nSYSTEM RESTORED...\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");

	getch();

    }

	fclose(fp);

	check=password();

    if(check==1)

    {

	return ;

    }

    do

    {

	if(check==0)

		    {

			i=0;

			choice=0;

			printf("\n\n\tENTER THE NEW PASSWORD:");

			fflush(stdin);

			pass[0]=getch();

			while(pass[i]!='\r')

			{

			    if(pass[i]=='\b')

			    {

				i--;

				printf("\b");

				printf(" ");

				printf("\b");

				pass[i]=getch();

			    }

			    else

			    {

				printf("*");

				i++;

				pass[i]=getch();

			    }

			}

			pass[i]='\0';

			i=0;

			printf("\n\tCONFIRM PASSWORD:");

			confirm[0]=getch();

			while(confirm[i]!='\r')

			{

			    if(confirm[i]=='\b')

			    {

				i--;

				printf("\b");

				printf(" ");

				printf("\b");

				confirm[i]=getch();

			    }

			    else

			    {

				printf("*");

				i++;

				confirm[i]=getch();

			    }

			}

			confirm[i]='\0';

			if(strcmp(pass,confirm)==0)

			{

			    fp=fopen("SE.txt","wb");

			    if(fp==NULL)

			    {

				printf("\n\t\tSYSTEM ERROR");

				getch();

				return ;

			    }

			    i=0;

			    while(pass[i]!='\0')

			    {

				ch=pass[i];

				putc(ch+5,fp);

				i++;

			    }

			    putc(EOF,fp);

			    fclose(fp);

			}

			else

			{

			    printf("\n\tTHE NEW PASSWORD DOES NOT MATCH.");

			    choice=1;


			}


		    }

	}while(choice==1);


    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");

    getch();

}


int printticket(ll *l1,int seatx)
{
	node *temp;
	int   tage;
	int   flag=0;
	int   driver = DETECT,mode;
	int   i,j;
	char t[10];
	char *msg="DECA BUS";
	char *ticket="TICKET";
	initgraph(&driver,&mode,"c:\\turboc3\\bgi");

	t[0]=(char)(48+seatx/10);   //stores the seat number as characters
	t[1]=(char)(48+seatx%10);
	for(temp=l1->head;temp!=NULL;temp=temp->next)
	{

		if(temp->seat==seatx)
		{

			flag=1;
			printf("enter the age of the traveller\n");
			scanf("%d",&tage);
			if(tage==temp->age)
			{

				clrscr();
				setbkcolor(RED);
				clear();

				line(160,110,160,275);
				line(160,110,480,110);
				line(480,110,480,275);
				line(160,275,480,275);
				line(160,190,480,190);

				settextstyle(1,0,1);

				setusercharsize(2,1,2,1);

				outtextxy(210,-10,ticket);

				settextstyle(7,0,1);

				setusercharsize(1,1,1,1);

				outtextxy(251,111,msg);

				settextstyle(7,0,1);

				setusercharsize(1,1,1,1);

				outtextxy(281,145,"SERVICES");

				settextstyle(1,0,1);

				outtextxy(162,192,"Name:");

				outtextxy(222,192,temp->name);

				outtextxy(162,212,"Phone:");

				outtextxy(222,212,temp->phone);

				outtextxy(162,232,"Seat:");

				outtextxy(222,232,t);

				outtextxy(162,252,"Cost:");

				outtextxy(222,252,"Rs.300");

	   //executed untill any key is pressed
				getch();
			}

			else

			{

				printf("wrong age!!\n");

				return 0;

			}
			//the input age acts as a security check on the seat booking

		}
	}
	//if the swat asked for is not booked
	if(flag==0)

	{

		printf("seat still available..!!\n");

		return 0;
	}
}
void deletex(ll *l1,int seatx)
{
	//we also need to cancel a booking
	//for that we delete the ode correspomdig to the seat number

	node *temp;
	node *temp2;

	if(l1->head->seat==seatx)   //finding the seat in the linked list
	{

		temp=l1->head;
		l1->head=temp->next;
		printf("seat no deleted=%d\n",temp->seat);
		free(temp);

	}

	else

	for(temp=l1->head;temp!=NULL;temp=temp->next)
	{

		if(temp->next->seat==seatx)
		{

		    temp2=temp->next;
		    temp->next=temp->next->next;
		    printf("seat no deleted=%d\n",temp2->seat);
		    free(temp2);

		}
	}
}


void thanku()
{

    int   driver = DETECT,mode;
    int   x[10],y[10];
     int   i,j;

    initgraph(&driver,&mode,"c:\\turboc3\\bgi");

	  setcolor(15);
	  for(i=0;i<5;i++)
	  {

	  setcolor(1+i++);
	  delay(150);

	  line(0+i,210+i,80+i,210+i);
	  line(40+i,210+i,40+i,290+i);  /*t*/
	  line(85+i,210+i,85+i,290+i);
	  line(85+i,250+i,125+i,250+i);
	  line(125+i,210+i,125+i,290+i);  /*h*/
	  line(130+i,290+i,160+i,210+i);
	  line(160+i,210+i,190+i,290+i);
	  line(145+i,250+i,175+i,250+i);  /*a*/
	  line(195+i,210+i,195+i,290+i);
	  line(195+i,210+i,245+i,290+i);
	  line(245+i,210+i,245+i,290+i);  /*n*/
	  line(250+i,210+i,250+i,290+i);
	  line(250+i,250+i,290+i,210+i);
	  line(250+i,250+i,290+i,290+i); /*k*/
	  line(420+i,210+i,445+i,250+i);
	  line(445+i,250+i,445+i,290+i);
	  line(445+i,250+i,470+i,210+i); /*y*/
	  circle(515+i,250+i,40);        /*o*/
	  line(560+i,210+i,560+i,260+i);
	  line(610+i,210+i,610+i,260+i);
	  arc(585+i,260+i,181+i,360+i,25); /*u*/

	  }
	 setcolor(RED);
	 settextstyle(4,0,5);
	 outtextxy(80,400,"For using DECA Bus Services..");

}


void welcome()
{
	int i=0;
	int count=0;

	clrscr();

	setbkcolor(BLACK);
	clear();
	setcolor(YELLOW);
	setlinestyle(1,0,5);
	settextstyle(7,0,3);
	setcolor(RED);
	for(count=0;count<100;count++)
       {
	sound(count*10);
	delay(50);
	nosound();
       }



	outtextxy(40,40,"WELCOME\n to DECA Bus Services..");
	outtextxy(70,70,"LOADING....");

	for(i=0;i<30;i++)
	{
		outtextxy(90+(i*5),100,"[]");
		sound(i*100);
		delay(300);
		nosound();
	}
}

void main()
{
	int total=32,check=1;

	 //total 32 seats in the bus

	int s,ch,flag=0;

	char ch2,adressx[100];
	char phonex[100];
	int agex;
	int seatx;
	int gdriver = DETECT, gmode, errorcode;
	char namex[100];
	int i;

	ll *l1=initialise();

	node *temp;
	initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
	check=password();
		      //calling the security password function

	if(check==0)
	{
		exit(0);
	}
	errorcode = graphresult();

	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();

		exit(1); /* terminate with an error code */
	}

	welcome();//the loading page

	clrscr();

	clear();

	do
	{

	clrscr();
	setbkcolor(9);
	clear();

	setcolor(RED);

	setfillpattern("01010101",2);
	settextstyle(7,2,3);
	 printf("enter your choice\n");
	settextstyle(5,0,2);

	for(i=0;i<6;i++)
	{

		bar3d(40,20+(i*70),500,80+(i*70),6,1);

	}

	setcolor(4);

	outtextxy(45,22,"1.To Input data");

	outtextxy(45,92,"2. To Print a Ticket");

	outtextxy(45,162,"3. To Display the bus Availabilities");

	outtextxy(45,232,"4. To Change the Password of the Program");

	outtextxy(45,302,"5. To cancel a Booking");

	outtextxy(45,372,"6 To EXIT");



	scanf("%d",&ch);

		switch(ch)
		{

			case 1: do

				{

					flag=0;

					printf("enter seat number\n");

					scanf("%d",&s);

					//if(s>32)
					printf("enter the name of the traveller\n");
					scanf("%s",namex);

					printf("enter the adress\n");
					scanf("%s",adressx);

					printf("enter the age of the traveller\n");
					scanf("%d",&agex);

					printf("enter the phone number");
					scanf("%s",phonex);

					for(temp=l1->head;temp!=NULL;temp=temp->next)
					{
						if(temp->seat==s)
						{

							flag=1;

						}
					}

					if(flag!=1)

					{

						insertend(l1,s,namex,adressx,agex,phonex);
						printf("enter another??y/n\n");
						flushall();
						scanf("%c",&ch2);

						if(l1->count>=total)
						{
							printf("cannot enter any more..\n");

							ch2='n';
						}
					}

					else

					{
						printf("seat already occupied..apply for another..\n");

						ch2='y';
					}

				}while(ch2!='n');

				clrscr();
				setbkcolor(GREEN);
				clrscr();
				break;

			case 2: do

				{
					printf("enter the seat number\n");

					scanf("%d",&agex);

					ch=printticket(l1,agex);

					if(ch==1)
					{
						ch2='N';
					}

					if(ch==0)
					{
						printf("Input again? Y/N\n");

						ch2=getch();

						flushall();

					}

				}while(ch2=='y'||ch2=='Y');

				getch();

				clrscr();

				break;

			case 3: print(l1);

				getch();

				clrscr();

				break;

			case 4: editpassword();

				delay(5000);

				clrscr();

				break;

			case 5: printf("enter the seat number u want to cancel\n");

				scanf("%d",&seatx);

				deletex(l1,seatx);

				getch();

				clrscr();

				break;

			case 6: thanku();

				break;
		}

	}while(ch!=6);

	getch();

	closegraph();
}
