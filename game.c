//CSE PROJECT FOR GROUP-1

//Game: Dots & Boxes

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

void scan(	);

int f,i,j,player_no=2,temp_row,temp_coloumn,player_point[4],point_1_row,point_2_row,point_1_coloumn,point_2_coloumn,row,coloumn,total_point,temp,q,f_com=0,player_number,count_continue,x,point_limit=0,n1,n2,l1,l2;
char input_string[10] , arr[30][55] , player_name[3][50] , c ,  row_number , ch , str[2];

struct move
{
	int r,c;
}p1[5000],p2[5000];

int max( int t1 , int t2 )
{
	if(t1>=t2)	return t1;
	else	return t2;
}

void p_array(   )
{
	for(j=1,n1=0,n2=0 ; j<=2*coloumn-1 ; j+=2)
	{
		for(i=2 ; i<=2*row-1 ; i+=2)
		{
			if(arr[i][j]!=' ')
			continue;
			
		 	if(j>=3&&	(arr[i][j-2]=='|'&&arr[i-1][j-1]=='-')	||	(arr[i][j-2]=='|'&&arr[i+1][j-1]=='-')	||	(arr[i+1][j-1]=='-'&&arr[i-1][j-1]=='-')	)
			{
				//    +  +
				//       |
				//    +  +
				   
			   p2[n2].r=i;
			   p2[n2].c=j;
			   n2++;
				   
				continue;
			}
			
			if(j<=2*coloumn-3&&	(arr[i][j+2]=='|'&&arr[i-1][j+1]=='-')	||	(arr[i][j+2]=='|'&&arr[i+1][j+1]=='-')	||	(arr[i+1][j+1]=='-'&&arr[i-1][j+1]=='-')	)
			{
			   //    +  +
  				//	   |
				//    +  +
				
  	         p2[n2].r=i;
			   p2[n2].c=j;
			   n2++;
				
				continue;
			}
			
			p1[n1].r=i;
			p1[n1].c=j;
			n1++;
		}
	}
	
	l1=n1;
	l2=n2;
	
	for(i=1; i<=2*row-1 ; i+=2)
	{
		for(j=2 ; j<=2*coloumn-1 ; j+=2)
		{
			if(arr[i][j]!=' ')
			continue;
			
			if(i>=3&&	(arr[i-1][j-1]=='|'&&arr[i-2][j]=='-')	||	(arr[i-1][j+1]=='|'&&arr[i-2][j]=='-')	||	(arr[i-1][j-1]=='|'&&arr[i-1][j+1]=='|')	)
			{
				//    +  +
				//
				//    +--+
				
				p2[n2].r=i;
			   p2[n2].c=j;
			   n2++;
				
				continue;
			}
			
			if(temp_row<=2*row-3&&	(arr[i+1][j-1]=='|'&&arr[i+2][j]=='-')	||	(arr[i+1][j+1]=='|'&&arr[i+2][j]=='-')	||	(arr[i+1][j-1]=='|'&&arr[i+1][j+1]=='|')	)
			{
				//    +--+
				//
				//    +  +
				
				p2[n2].r=i;
			   p2[n2].c=j;
			   n2++;
				
				continue;
			}
			
			p1[n1].r=i;
		   p1[n1].c=j;
   	   n1++;
		}
	}
}

void com_point_check(	)
{
   if(total_point<=0)
	return	;
	
	for(j=1,f_com=0 ; j<=2*coloumn-1 ; j+=2)
	{
		for(i=2 ; i<=2*row-1 ; i+=2)
		{
			if(j>=3&&arr[i][j-2]=='|'&&arr[i-1][j-1]=='-'&&arr[i+1][j-1]=='-'&&arr[i][j]!='|')//checked if created a box on the left side of '|'
			{
				//    +  +
				//       |
				//    +  +
				
				arr[i][j]='|';
				arr[i][j-1]='C';//player_number is int , so added 48 to convert to char
				
				player_point[player_no]++;//point added for making a box
				
		   	total_point--;//total step remained for the game to end calculating
		   	f_com=1;
			}
			
			if(j<=2*coloumn-3&&arr[i][j+2]=='|'&&arr[i-1][j+1]=='-'&&arr[i+1][j+1]=='-'&&(arr[i][j]!='|'||f_com==1))//checked if created a box on the right side of '|'
			{
			   //    +  +
	         //    |
				//    +  +
				
				arr[i][j]='|';
				arr[i][j+1]='C';//player's number is added inside the created box
				
				player_point[player_no]++;
				
		   	total_point--;
		   	f_com=1;
			}
			
			if(f_com==1)
			{
				f_com=0;
				
				system("cls");
				
				pattern();
				
				com_point_check();
				
				return ;
			}
		}
	}
	
	for(i=1,f_com=0 ; i<=2*row-1&&f_com==0 ; i+=2)
	{
		for(j=2 ; j<=2*coloumn-1&&f_com==0 ; j+=2)
		{
			if(i>1&&arr[i-2][j]=='-'&&arr[i-1][j-1]=='|'&&arr[i-1][j+1]=='|'&&arr[i][j]!='-')//checked if created a box above '-'
			{
				//    +  +
				//
				//    +--+
				
				arr[i-1][j]='C';
				arr[i][j]='-';
				
				player_point[player_no]++;
		   	
		   	total_point--;
		   	f_com=1;
			}
			
			if(i<=2*row-3&&arr[i+2][j]=='-'&&arr[i+1][j-1]=='|'&&arr[i+1][j+1]=='|'&&(arr[i][j]!='-'||f_com==1))//checked if created a box below '-'
			{
		 	   //    +--+
			 	//
			 	//    +  +
				
				arr[i+1][j]='C';
				arr[i][j]='-';
				
				player_point[player_no]++;
		   	
		   	total_point--;
		   	f_com=1;
			}
			
			if(f_com==1)
			{
				f_com=0;
				count_continue=0;
				
				system("cls");
				
				pattern();
				
				com_point_check();
								
				return ;
			}
		}
	}
}

void complay(	)
{
	if(total_point<=0)
	return	;
	
	com_point_check();
	
	p_array();
	
	if(total_point<=0)
	return	;
	
	f_com=1;
	
	if(n1>0)
	{
		srand(time(0));
		
		temp=rand()%n1;
	   
		if(temp<l1)
		arr[p1[temp].r][p1[temp].c]='|';
		else
		arr[p1[temp].r][p1[temp].c]='-';
	}
	else if(n2>0)
	{
		srand(time(0));
		
		temp=rand()%n2;
		
		if(temp<l2)
		arr[p2[temp].r][p2[temp].c]='|';
		else
		arr[p2[temp].r][p2[temp].c]='-';
	}
}

void play(	)
{
	f=0;
	
	if(total_point<=0)
	return	;
	
	if((abs(point_1_row-point_2_row)==1&&point_1_coloumn==point_2_coloumn))
	{
		//    +  +
		//    |  |
		//    +  +
		
		temp_row=2*max(point_1_row,point_2_row)-2;
		temp_coloumn=2*point_1_coloumn-1;
		
		
		if(arr[temp_row][temp_coloumn]=='|')
		scan();
		
		arr[temp_row][temp_coloumn]='|';//this is move for given input
		
		if(temp_coloumn>=3&&arr[temp_row][temp_coloumn-2]=='|'&&temp_row>=1&&temp_row<=2*row-1&&arr[temp_row-1][temp_coloumn-1]=='-'&&arr[temp_row+1][temp_coloumn-1]=='-')//checked if created a box on the left side of '|'
		{
			//    +  +
			//       |
			//    +  +
			
			arr[temp_row][temp_coloumn-1]=player_no+48;//player_number is int , so added 48 to convert to char
			
			player_point[player_no]++;//point added for making a box
			f=1;
		   total_point--;//total step remained for the game to end calculating
		}
		if(temp_coloumn<=2*coloumn-1&&arr[temp_row][temp_coloumn+2]=='|'&&temp_row>=1&temp_row<=2*row-1&&arr[temp_row-1][temp_coloumn+1]=='-'&&arr[temp_row+1][temp_coloumn+1]=='-')//checked if created a box on the right side of '|'
		{
			//    +  +
			//    |
			//    +  +
			
			arr[temp_row][temp_coloumn+1]=player_no+48;//player's number is added inside the created box
			
			player_point[player_no]++;
			f=1;
		   total_point--;
		}
	}
	else if(abs(point_1_coloumn-point_2_coloumn)==1&&point_1_row==point_2_row)
	{
		//    +--+
		//
		//    +--+
		
		temp_row=2*point_1_row-1;
		temp_coloumn=2*max(point_1_coloumn,point_2_coloumn)-2;
		
		
		if(arr[temp_row][temp_coloumn]=='-')
		scan();
		
		arr[temp_row][temp_coloumn]='-';
		
		if(temp_row>=1&&arr[temp_row-2][temp_coloumn]=='-'&&temp_coloumn>=1&&temp_coloumn<=2*coloumn-1&&arr[temp_row-1][temp_coloumn-1]=='|'&&arr[temp_row-1][temp_coloumn+1]=='|')//checked if created a box above '-'
		{
			//    +  +
			//
			//    +--+
			
			arr[temp_row-1][temp_coloumn]=player_no+48;
			
			player_point[player_no]++;
		   f=1;
		   total_point--;
		}
		
		if(temp_row<=2*row-1&&arr[temp_row+2][temp_coloumn]=='-'&&temp_coloumn>=1&&temp_coloumn<=2*coloumn-1&&arr[temp_row+1][temp_coloumn-1]=='|'&&arr[temp_row+1][temp_coloumn+1]=='|')//checked if created a box below '-'
		{
			//    +--+
			//
			//    +  +
			
			arr[temp_row+1][temp_coloumn]=player_no+48;
			
			player_point[player_no]++;
		   f=1;
		   total_point--;
		}
	}
}

void pattern(	)
{
	for(i=0 ; i<=2*row ; i++)
		{
			row_number='a';//row numbering initialization
			
			for(j=0 ; j<5 ; j++)//pattern printing in the middle of the command prompt
			printf("	");
			
			if(i==2*row||i==0)//numbering coloumn in the 1st & last row only
			{
				printf("  ");
				
				for(j=1 ; j<=coloumn ; j++,row_number++)
				printf(" %c",row_number);//naming coloumn a,b,c,d.......
				
				printf("\n");
				
				continue;
			}
			
			for(j=0 ; j<=2*coloumn ; j++)
			{
           if((j==0||j==2*coloumn)&&i%2==1)//numbering row in the 1st & last coloumn only
				{
            	if(i/2+1<=9)
            	printf(" ");
					
					printf("%d ",i/2+1);//naming row 1,2,3,4........
				}
				else if(j==0&&i%2==0)
				printf("   ");
	         
				if(j>0&&j<2*coloumn)
	         printf("%c",arr[i][j]);
		   }
		   
			if(i<2*row)
         printf("\n");
	   }
	   
		printf("\n\n");
}

void scan(	)
{
	   printf("enter 'quit' to quit the game or 'reset' to reset the game\n");
		
		l1://starting line for wrong input
		
		printf("%s , please enter your 2 points to be conected : ",player_name[player_no]);
		
		strcpy(input_string,"\0");
		
		scanf("%s",&input_string);//input for move i.e. a1a2,a1b1 etc.
		
		if(strcmp(input_string,"quit")==0)
		{
			q=1;//flag for quiting
			
			return ;
		}
		else if(strcmp(input_string,"reset")==0)
		{
			//just reset(re-initialize every thing
			
			for(i=1;i<=2*row;i++)
				for(j=1;j<=2*coloumn;j++)
	   		   if(i%2==0||j%2==0)
					arr[i][j]=' ';
			
			player_point[1]=0;
			player_point[2]=0;
			player_point[3]=0;
			
			player_no=player_number+1;
			total_point=(row-1)*(coloumn-1);
			
			return ;
		}
		else if(strlen(input_string)>6||strlen(input_string)<4)
		goto l1;//if legnth>6 , then wrong input
		
		x=0;//index counting for input_string
		
		if(input_string[x+1]>='0'&&input_string[x+1]<='9')//if row of point 1>=10 ( 2 digit input )
		{
			//coping row value into str string
			
			str[0]=input_string[x];
			str[1]=input_string[x+1];
			str[2]='\0';
			
			point_1_row=atoi(str);
			
			x++;
		}
		else if(input_string[x]>='1'&&input_string[x]<='9')//if row  of point 1<=9 ( 1 digit input )
		point_1_row=input_string[x]-'0';
		else
		goto l1;//if point is not in limit , then wrong input
		
		if(point_1_row>row)
		goto l1;
		
		x++;
		
	   if(input_string[x]>='a'&&input_string[x]<='a'+coloumn-1)
		point_1_coloumn=input_string[x]-'a'+1;
		else
		goto l1;//if point is not in limit , then wrong input
		
		x++;
		
		if(input_string[x+1]>='0'&&input_string[x+1]<='9')//if row of point 2>=10 ( 2 digit input )
		{
			str[0]=input_string[x];
			str[1]=input_string[x+1];
			str[2]='\0';
			
			point_2_row=atoi(str);
			
			x++;
		}
		else if(input_string[x]>='1'&&input_string[x]<='9')//if row of point 2<=9 ( 1 digit input )
		point_2_row=input_string[x]-'0';
		else
		goto l1;//if point is not in limit , then wrong input
		
		if(point_2_row>row)
		goto l1;
		
		x++;
		
		if(input_string[x]>='a'&&input_string[x]<='a'+coloumn-1)
		point_2_coloumn=input_string[x]-'a'+1;
		else
		goto l1;//if point is not in limit , then wrong input
		
		if(!((abs(point_1_row-point_2_row)==1&&point_1_coloumn==point_2_coloumn)||(abs(point_1_coloumn-point_2_coloumn)==1&&point_1_row==point_2_row)))
		goto l1;//if both point are not beside each other, then wrong input.	i.e.  a1b2,a1c1,b1b3
}

int main(	)
{
	player_no=2;//initializing player no to play first
	
	player_point[1]=0;//initializing point of all player1
	player_point[2]=0;//initializing point of all player2
	player_point[3]=0;//initializing point of all computer
	
	printf("Do you want to play with another player(input 1) or with computer(input 2)\n");
	
	scanf("%d",&player_number);
	
	if(player_number==1)
	{
		getchar();//for scaning the extra ascii value of "enter" button
		printf("please input name of player 1 : ");
		scanf("%[^\n]s",&player_name[1]);//for scaning with space
		
		getchar();//for scaning the extra ascii value of "enter" button
		printf("\nplease input name of player 2 : ");
		scanf("%[^\n]s",&player_name[2]);//scaning with space
	}
	else
	{
		getchar();
		printf("please input your name (player 1) : ");
		scanf("%[^\n]s",&player_name[1]);//for scaning with space
		
		player_no=3;//player no.for computer
	}
	
	printf("\nplease enter row(<=15) & column(<=26) : ");
	scanf("%d%d",&row,&coloumn);
	
	row++;coloumn++;//for scanned row*coloumn boxes ( not row*coloumn points )
	
	total_point=(row-1)*(coloumn-1);//total point calculated for certain row & coloumn
	
	//total_point will be deducted 1 point for every point any player or computer earn
	
	if(row>15)//limiting row number
	row=15;
	if(coloumn>26)//limiting coloumn number
	coloumn=26;
	//char arr[2*row][2*coloumn];
	
	for(i=1;i<=2*row;i++)
		for(j=1;j<=2*coloumn;j++)
			if(i%2==1&&j%2==1)
			arr[i][j]='+';//odd i&j position will contain *
			else
			arr[i][j]=' ';//even i or j position will contain space, which will be replaced by (-,|&payer name/number)

	do //scanning right value & inserting in array
	{
		system("cls");//clears screen
		
		q=0;//flag for quiting
		
		if(total_point<=0)
		break;//no step left to play
		
		if(player_number==1)
		printf("point of %s : %d \n point of %s : %d \n",player_name[1],player_point[1],player_name[2],player_point[2]);
		else
		printf("point of %s : %d \n point of computer : %d \n",player_name[1],player_point[1],player_point[3]);
		
		if(player_no==3)//player no 3 for computer
		player_no=1;
		else if(player_no==2&&f==0)//if f==0 , because the point hasn't changed , so no 2nd move
		player_no=1;
		else if(player_no==1&&f==0)//if f==0 , because the point hasn't changed , so no 2nd move
		{
			if(player_number==1)
			player_no=2;
			else
			player_no=3;
		}
		//if f==1 , then no change of player_number because player has earn a point
		
		pattern();
	   
		if(player_no==3)//for move of computer
	   {
	   	f_com=0;
	   	count_continue=0;
	   	
	   	complay();
	   	
			if(total_point>0)
	   	continue;
	   	else
			break;
		}
	   
		scan();
		
		play();
		
	}	while(total_point>0 && q==0);
	
	//game finished
	
	system("cls");
	
	pattern();
	
	if(player_number==1)
	printf("point of %s : %d\npoint of %s : %d\n",player_name[1],player_point[1],player_name[2],player_point[2]);
	else
	printf("point of %s : %d\npoint of computer : %d\n",player_name[1],player_point[1],player_point[3]);
	
	printf("\n");
	
	if(q==0)
	{
		if(player_number==2)
		{
			if(player_point[1]==player_point[3])
			printf("sorry, but it's a draw. Hope you will try again\n");
			else if(player_point[1]>player_point[3])
			printf(" Congratulation %s . You have won the game . \n",player_name[1]);
			else if(player_point[1]<player_point[3])
			printf("sorry, %s . You have lost the game . Hope you will try again\n",player_name[1]);
		}
		else if(player_point[1]==player_point[2])
		printf("sorry, but it's a draw. hope you will try again\n");
		else if(player_point[1]>player_point[2])
		printf(" Congratulation %s . You have won the game . \n",player_name[1]);
		else
		printf(" Congratulation %s . You have won the game . \n",player_name[2]);
	}
	
	printf("Thank you for playing this game. Hope you will play it again soon.\n");
}