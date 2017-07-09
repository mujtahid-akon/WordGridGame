#include "iGraphics.h"
int level=  10 ,t=0,dflag=0,name = 0,pl1=0,pl2=0,snd=0;
int click_x=9000,click_y =900,row = 0,col=0,index_x=25,index_y=25,flag = 0,score = 0 ,score1 = 0 , score2 = 0 ,max = 0 ,count = 0,x,y;
char word[20][11] = { "mujtahid","rashed","buet","ant","and","the","tea","cat","rat","bat","mad","sad"};
char lettr3[52][20] = { "images\\level3\\a.bmp","images\\level3\\b.bmp","images\\level3\\c.bmp","images\\level3\\d.bmp","images\\level3\\e.bmp","images\\level3\\f.bmp","images\\level3\\g.bmp","images\\level3\\h.bmp","images\\level3\\i.bmp","images\\level3\\j.bmp","images\\level3\\k.bmp","images\\level3\\l.bmp","images\\level3\\m.bmp","images\\level3\\n.bmp","images\\level3\\o.bmp","images\\level3\\p.bmp","images\\level3\\q.bmp","images\\level3\\r.bmp","images\\level3\\s.bmp","images\\level3\\t.bmp","images\\level3\\u.bmp","images\\level3\\v.bmp","images\\level3\\w.bmp","images\\level3\\x.bmp","images\\level3\\y.bmp","images\\level3\\z.bmp" };
char lettr2[52][20] = { "images\\level2\\a.bmp","images\\level2\\b.bmp","images\\level2\\c.bmp","images\\level2\\d.bmp","images\\level2\\e.bmp","images\\level2\\f.bmp","images\\level2\\g.bmp","images\\level2\\h.bmp","images\\level2\\i.bmp","images\\level2\\j.bmp","images\\level2\\k.bmp","images\\level2\\l.bmp","images\\level2\\m.bmp","images\\level2\\n.bmp","images\\level2\\o.bmp","images\\level2\\p.bmp","images\\level2\\q.bmp","images\\level2\\r.bmp","images\\level2\\s.bmp","images\\level2\\t.bmp","images\\level2\\u.bmp","images\\level2\\v.bmp","images\\level2\\w.bmp","images\\level2\\x.bmp","images\\level2\\y.bmp","images\\level2\\z.bmp" };
char lettr1[52][20] = { "images\\level1\\a.bmp","images\\level1\\b.bmp","images\\level1\\c.bmp","images\\level1\\d.bmp","images\\level1\\e.bmp","images\\level1\\f.bmp","images\\level1\\g.bmp","images\\level1\\h.bmp","images\\level1\\i.bmp","images\\level1\\j.bmp","images\\level1\\k.bmp","images\\level1\\l.bmp","images\\level1\\m.bmp","images\\level1\\n.bmp","images\\level1\\o.bmp","images\\level1\\p.bmp","images\\level1\\q.bmp","images\\level1\\r.bmp","images\\level1\\s.bmp","images\\level1\\t.bmp","images\\level1\\u.bmp","images\\level1\\v.bmp","images\\level1\\w.bmp","images\\level1\\x.bmp","images\\level1\\y.bmp","images\\level1\\z.bmp" };
char digit[50][50] = { "images\\digit\\0.bmp","images\\digit\\1.bmp","images\\digit\\2.bmp","images\\digit\\3.bmp","images\\digit\\4.bmp","images\\digit\\5.bmp","images\\digit\\6.bmp","images\\digit\\7.bmp","images\\digit\\8.bmp","images\\digit\\9.bmp"};
char grid[11][11],letter,temp[15],sscore1[5],sscore2[5],sec[10],min[10],hour[10],player1[20],player2[20];


void time (void )
{
	if(flag==1)t++;
}

void sound ( void )
{
	if ( flag== 1 && (snd%118==0 || snd == 0) )
	{
		//PlaySound("music//back.wav",NULL,SND_FILENAME | SND_ASYNC);
	}
	snd++;
}


void compare (void)
{
	//*************************** It will compare the word by row   *********************
	int max=0,p,t,q,Q,l;

	max = 0 ; 
	for ( p = col,t,q ; p<level+1;p++)
	{

		for (q = col; q>= 1 ;q--)
		{
			if ( grid[row][q] == '\0') break;

			for ( l = q,t=0 ; l <= p ; l++ ,t++)
			{
				if ( grid[row][l] == '\0') break;
				temp[t] = grid[row][l];
			}
			temp[t] ='\0';

			//printf(" temp = %s \n",temp);

			for (Q = 0 ; Q<13;Q++)  
			{
				if ( strcmp(temp,word[Q]) == 0 )
				{
					if ( strlen(temp) > max )
					{
						//printf("temp =  %s \n",temp);
						max = strlen(temp);
					}
				}
			}
		}
	} 

	for ( p = row,t,q ; p<level+1;p++)
	{
		for (q = row; q>= 1 ;q--)
		{
			if ( grid[q][col] == '\0') break;

			for ( l = q,t=0 ; l <= p ; l++ ,t++)
			{
				if ( grid[l][col] == '\0') break;
				temp[t] = grid[l][col];
			}
			temp[t] ='\0';


			for (Q = 0 ; Q<13;Q++)  
			{
				if ( strcmp(temp,word[Q]) == 0 )
				{
					if ( strlen(temp) > max )
					{
						//printf("temp =  %s \n",temp);
						max = strlen(temp);
					}
				}
			}
		}
	} 

	if ( max > 2 ) score += max;
	if ( count%2 != 0 ) score1 += max;
	else score2 += max;
	//printf("score = %d score1 = %d score2 = %d  and max = %d \n",score,score1,score2,max);
	max = 0 ;
	temp[0]= '\0';

}
void a1 (void )         //  at first it assign null value in all the position in the grid 2d array
{
	int i,j;

	for ( i = 1;i<level+1 ; i++ )
	{
		for ( j = 1;j<level+1 ; j++ )
		{
			grid[i][j]  = '\0';
		}
	}
}

void print(void)  // print the whole arrary if there is null then print 0
{
	int i,j;
	for ( i = 1;i<level+1;i++ )
	{
		for ( j = 1;j<level+1;j++ )
		{
			if(grid[i][j]=='\0') printf("0 ");
			else printf("%c ",grid[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	return;
}

void index_check( void ) 
{
	int i,j;
	//printf("click_x = %d click_y = %d \n",click_x, click_y);
	for ( i = 25,col = 1  ; i <= 25+(level-1)*600/level ; i += 600/level,col++ )
	{
		for ( j = 25+(level-1)*600/level,row = 1 ; j >= 25 ; j -= 600/level,row++ )
		{
			if ( click_x >= i && click_x <i+600/level && click_y >= j && click_y <j+600/level)
			{
				index_x = i;
				index_y = j;
				//printf(" row = %d col = %d \n",row,col);
				return;
			}
			//printf("row = %d col = %d index_x = %d index_y = %d \n",row,col,index_x,index_y);
		}
	}
	
	
}

void iDraw()
{
	int i , j;
	if ( flag == 0 )
	{
		a1();
		flag =3;
		t=0;
		snd=0;
	}
	if ( flag == 1 )
	{
		//printf("time = %d\n",snd);
		iSetColor ( 55,42,30);
		//iSetColor(45,62,80);
		iFilledRectangle ( 0,0,1000,650);

		iSetColor(35,31,29);
		//iSetColor(77,77,77);
		//iSetColor(52,73,94);
		iFilledRectangle(17,17,616,616);

		iSetColor(110,104,81);
		//iSetColor(28,39,44);
		iFilledRectangle(25,25,600,600);

		for ( i = 1  ; i < level+1 ; i++)
		{
			for ( j = 1 ; j< level+1;j++)
			{
				if ( grid[i][j] != '\0')
				{
					int pos = (int)grid[i][j] - 97; 
					if ( pos < 26 && pos >=0 )
					{
						if ( level == 5 ) iShowBMP( (25+(j-1)*600/level) , 25+((level-i)*600/level) , lettr1[pos]);
						if ( level == 6 ) iShowBMP( (25+(j-1)*600/level) , 25+((level-i)*600/level) , lettr2[pos]);
						if ( level == 10 ) iShowBMP( (25+(j-1)*600/level) , 25+((level-i)*600/level) , lettr3[pos]);
					}
				}

			}
		}

		for ( i = 25 ; i <= 25+(level-1)*600/level ; i += 600/level )
		{
			for ( j = 25 ; j<= 25+(level-1)*600/level ; j += 600/level )
			{
				iSetColor ( 55,42,30);
				//iSetColor(52,73,94);
				iRectangle(i,j,600/level,600/level);
			}
		}

		//iShowBMP(658,24,"images//scorboard.bmp");

		iSetColor(35,31,29);
		iFilledRectangle(650,16,330,618);
		iShowBMP(658,24,"images//scorboard1.bmp");


		//First Scoreboard 

		sprintf(sscore1,"%d",score1);
		if ( score1 == 0 )
		{
			iShowBMP(810,428,"images//digit//0.bmp");
			iShowBMP(890,428,"images//digit//0.bmp");
		}
		else if ( score1<=9)
		{
			iShowBMP(810,428,"images//digit//0.bmp");
			iShowBMP(890,428,digit[sscore1[0]-48]);
		}
		else
		{
			iShowBMP(810,428,digit[sscore1[0]-48]);
			iShowBMP(890,428,digit[sscore1[1]-48]);
		}

		//Second Scoreboard
		sprintf(sscore2,"%d",score2);
		if ( score2 == 0 )
		{
			iShowBMP(810,76,"images//digit//0.bmp");
			iShowBMP(890,76,"images//digit//0.bmp");
		}
		else if ( score2<=9)
		{
			iShowBMP(810,76,"images//digit//0.bmp");
			iShowBMP(890,76,digit[sscore2[0]-48]);
		}
		else
		{
			iShowBMP(810,76,digit[sscore2[0]-48]);
			iShowBMP(890,76,digit[sscore2[1]-48]);
		}

		iSetColor(172,172,172);
		iRectangle(index_x,index_y,600/level,600/level);
		iSetColor(250,250,250);
		iText(840,385,player1,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(840,40,player2,GLUT_BITMAP_TIMES_ROMAN_24);


		sprintf(hour,"%d",t/3600);

		if((t%3600)/60>9)sprintf(min,"%d",(t%3600)/60);
		else sprintf(min,"0%d",(t%3600)/60);
		
		if((t%3600)%60>9)sprintf(sec,"%d",(t%3600)%60);
		else sprintf(sec,"0%d",(t%3600)%60);


		iText(849,300,hour,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(861,300,":",GLUT_BITMAP_TIMES_ROMAN_24);

		iText(871,300,min,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(896,300,":",GLUT_BITMAP_TIMES_ROMAN_24);

		iText(904,300,sec,GLUT_BITMAP_TIMES_ROMAN_24);



		iSetColor(35,31,29);
		iFilledCircle(791,556,12,800);


		iSetColor(69,69,69);
		iFilledCircle(791,556,10,800);

		iSetColor(35,31,29);
		iFilledCircle(774,206,12,800);

		
		iSetColor(69,69,69);
		iFilledCircle(774,206,10,800);




		if ( count%2 == 0 )
		{
			iSetColor(69,182,45);
			iFilledCircle(791,556,12,800);
			iSetColor(250,0,0);
			iFilledCircle(791,556,10,800);
		}
		else
		{
			iSetColor(69,182,45);
			iFilledCircle(774,206,12,800);

			iSetColor(250,0,0);
			iFilledCircle(774,206,10,800);
		}

	}



	if ( flag == 3 )

	{
		if ( t==2 || snd%120==0)
		{
			PlaySound("music//back.wav",NULL,SND_FILENAME | SND_ASYNC);
		}
		
		iShowBMP(0,0,"images//pic3.bmp");
		iShowBMP(860,550,"images//button//start_game.bmp");
		iShowBMP(860,495,"images//button//level.bmp");
		iShowBMP(860,440,"images//button//help.bmp");
		iShowBMP(860,385,"images//button//credit.bmp");
		iShowBMP(860,330,"images//button//quit.bmp");


		if ( x > 860 )
		{
			if ( y < 385) iShowBMP(790,330,"images//button//lquit.bmp");
			else if ( y < 440)iShowBMP(790,385,"images//button//lcredit.bmp");
			else if ( y < 495)iShowBMP(790,440,"images//button//lhelp.bmp");
			else if ( y < 550)iShowBMP(790,495,"images//button//llevel.bmp");
			else if ( y < 605)iShowBMP(790,550,"images//button//lstart_game.bmp");
		}
		if ( click_x >860  && click_y>=350 && click_y <=600 ){
			flag = 4;
			dflag = 0;
		}

	}
	if ( flag == 4 )
	{
		//dflag=0;
		if ( click_x >860)
		{
			
			if ( click_y >550 && click_y <600)
			{
				PlaySound("music//click.wav",NULL,SND_FILENAME | SND_ASYNC);
				snd = 0;
				flag = 1;
				t = 0 ;
				a1();
				score1 = 0;
				score2 = 0;
				if ( level < 5 ) level = 10;
				//printf("Rashedul islam\n");
			}
			else if ( click_y >495 && click_y <545)
			{
				//dflag = 0;
				flag = 5 ;
				level = 1;
				if ( dflag == 0)PlaySound("music//click.wav",NULL,SND_FILENAME | SND_ASYNC);
				dflag = 1;

			}
			else if ( click_y >440 && click_y <490)
			{
				//dflag = 0;
				
				iShowBMP(0,0,"images//help.bmp");
				if ( dflag == 0)PlaySound("music//click.wav",NULL,SND_FILENAME | SND_ASYNC);
				dflag = 1;
			}
			else if ( click_y >385 && click_y <435)
			{
				
				iShowBMP(0,0,"images//credit.bmp");
				if ( dflag == 0)PlaySound("music//click.wav",NULL,SND_FILENAME | SND_ASYNC);
				dflag = 1;
			}
			else if ( click_y >330 && click_y <380 )
			{
				//dflag = 0;
				if ( dflag == 0)PlaySound("music//click.wav",NULL,SND_FILENAME | SND_ASYNC);
				dflag = 1;
				exit(0);
			}
		}
	}
	if ( flag == 5 )
	{
		iShowBMP(0,0,"images//level.bmp");
		if ( click_x >=373 && click_x <= 628)
		{
			if ( click_y >=650-221 && click_y <= 650-163)
			{
				level = 5;
				PlaySound("music//click.wav",NULL,SND_FILENAME | SND_ASYNC);
			}
			if ( click_y >=650-293 && click_y <=650- 233)
			{
				level = 6;
				PlaySound("music//click.wav",NULL,SND_FILENAME | SND_ASYNC);
			}
			if ( click_y >=650- 367 && click_y <= 650-310)
			{
				level = 10;
				PlaySound("music//click.wav",NULL,SND_FILENAME | SND_ASYNC);
			}
		}
		if (click_y >= 72 && click_y <=119)
		{
			iSetColor(241,225,163);
			if ( click_x >=234 && click_x <=580)
			{
				name = 1;
				iRectangle(234,70,236,49);
			}
			if ( click_x >=700 && click_y <=935)
			{
				name = 2;
				iRectangle(701,70,236,49);
			}
		}
		iSetColor(241,225,163);
		iText(247,86,player1,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(712,86,player2,GLUT_BITMAP_TIMES_ROMAN_24);
		if ( click_x >= 505 && click_x <= 579)
		{
			if (click_y >= 0 && click_y <=41)
			{
				if (level < 5 ) level = 10;
				flag = 1;
				a1();
				score1 = 0;
				score2 = 0;
				t = 0;
				index_x = 25 ;
				index_y = 25 ;
				PlaySound("music//click.wav",NULL,SND_FILENAME | SND_ASYNC);
			}
		}
	}



}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{


	//place your codes here
	return;
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		click_x = mx;
		click_y = my;
		index_check();
	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}
/*iPassiveMouseMove is called to detect and use 
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	x = mx;
	y = my;
  /*Something to do with my*/
 
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	//printf("row = %d col = %d \n",row,col);
	letter = key;
	if ( key == '\b' && flag != 5) {
		//printf("backslash  rashed\n");
		click_x = 999999999;
		click_y = 999999999;
		flag = 3;
		PlaySound("music//back.wav",NULL,SND_FILENAME | SND_ASYNC);
	}
	if ( grid[row][col] == '\0'  && key>='a' && key <='z')
	{
		grid[row][col] = key;
		PlaySound("music//enter.wav",NULL,SND_FILENAME | SND_ASYNC);
		count++;
		//print();
		compare();
		
	}
	if (flag == 5 && name == 1 && pl1<=10)
	{
		if ( key == '\b')
		{
			pl1--;
			player1[pl1] = '\0';
		}
		else
		{
			player1[pl1] = key;
			pl1++;
		}
	}
	if ( flag == 5 && name == 2 && pl2 <=10 )
	{
		if ( key == '\b')
		{
			pl2--;
			player2[pl2] = '\0';
		}
		else
		{
			player2[pl2] = key;
			pl2++;
		}
	}
	

}

void iSpecialKeyboard(unsigned char key)
{
	if ( key == GLUT_KEY_RIGHT ) 
	{

		if ( index_x < 25+(level-1)*600/level)
		{
			index_x += 600/level;
			col++;
			PlaySound("music//move.wav",NULL,SND_FILENAME | SND_ASYNC);
		}
	}
	else if ( key == GLUT_KEY_LEFT ) 
	{
		if ( index_x > 25)
		{
			PlaySound("music//move.wav",NULL,SND_FILENAME | SND_ASYNC);
			index_x -= 600/level;
			col--;
		}
	}


	else if ( key == GLUT_KEY_UP ) 
	{
		if ( index_y < 25+(level-1)*600/level)
		{
			PlaySound("music//move.wav",NULL,SND_FILENAME | SND_ASYNC);
			index_y += 600/level;
			row--;
		}
	}
	else if ( key == GLUT_KEY_DOWN ) 
	{
		if ( index_y > 25)
		{
			PlaySound("music//move.wav",NULL,SND_FILENAME | SND_ASYNC);
			index_y -= 600/level;
			row++;
		}
	}

}

int main()
{
	iClear();
	iSetTimer(1000,time);
	iSetTimer(100,sound);
	iInitialize(1000,650,"Word Grid");
	return 0;
}	