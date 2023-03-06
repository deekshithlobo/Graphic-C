#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<GL/glut.h>
#include<unistd.h>
int submenu;
void *currentfont;
int pole=1;
int flag=0;
void aliceside();
void bobside();
float points[]={75,160,75,170,	75,180,	75,190,	75,200,75,210,75,220,	75,230,	75,240,	75,250,	75,260,	75,270,	75,280,	75,290,	75,300,	75,310,	75,320,	75,330,	75,340,75,350,75,360,85,360,95,360,105,360,115,360,120,360};

float alice_coordinates[]={
	380,310,
	385,310,
	395,310,
	405,310,
	415,310,
	425,310,
	425,300,
	425,290,
	425,280,
	425,270,
	425,260,
	425,250,
	425,240,
	425,230,
	425,220,
	425,210,
	425,200,
	425,190,
	425,180,
	425,170,
	425,160,	
};
void erase_tcpconn(){
	glColor4f(0,0,0,0);
	glBegin(GL_QUAD_STRIP);
	glVertex2f(175.0,400.0);
	glVertex2f(175.0,390.0);
	glVertex2f(325.0,400.0);
	glVertex2f(325.0,390.0);
	glEnd();
	glBegin(GL_QUAD_STRIP);
	glColor4f(0,0,0,0);
	glVertex2f(175.0,350.0);
	glVertex2f(175.0,330.0);
	glVertex2f(325.0,350.0);
	glVertex2f(325.0,330.0);
	glEnd();

}

void tcpconn_message(){
	//function that creates message link after control segment

	glColor4f(0.6,0.7,0.8,0.6);
	glBegin(GL_QUAD_STRIP);
	glVertex2f(175.0,350.0);
	glVertex2f(175.0,330.0);
	glVertex2f(325.0,350.0);
	glVertex2f(325.0,330.0);
	glEnd();
	glFlush();

}

void tcpconn_bob(){
	glColor4f(0.6,0.7,0.8,0.6);
	glBegin(GL_QUAD_STRIP);
	glVertex2f(175.0,400.0);
	glVertex2f(175.0,390.0);
	glVertex2f(325.0,400.0);
	glVertex2f(325.0,390.0);
	glEnd();
}

void erase(int v){

	glPointSize(7.0);
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	glVertex2f(points[v-6],points[v-5]);
	glVertex2f(75,160);
	glEnd();
	glFlush();

}

void erase_alice(int v){

	glPointSize(7.0);
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	glVertex2f(alice_coordinates[v-6],alice_coordinates[v-5]);
	glVertex2f(380,310);
	glEnd();
	glFlush();

}

void drawpoints(float x,float y){
	glPointSize(7.0);
	glBegin(GL_POINTS);
	glColor3f(0,1,0);
	glVertex2f(x,y);
	glEnd();
	glFlush();

}

void delack(float x,float y){
	glLineWidth(1.5);
	glColor4f(0.6,0.7,0.8,0.5);
	glBegin(GL_LINES);
	glVertex2f(x,y);
	glVertex2f(x+5,y);
	glEnd();
	glFlush();

}

void delline(float x,float y){
	//glEnable(GL_BLEND);
	glLineWidth(1.5);
	glColor4f(0.6,0.7,0.8,0.6);
	glBegin(GL_LINES);
	glVertex2f(x,y);
	glVertex2f(x-5,y);
	glEnd();
	glFlush();
	//glDisable(GL_BLEND);	
}

void ctrline(float x,float y){
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(x,y);
	glVertex2f(x+5,y);
	glEnd();
	glFlush();
}

void ack(float x,float y){
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(x,y);
	glVertex2f(x-5,y);
	glEnd();
	glFlush();
}

void message(){
	glLineWidth(8);
	glBegin(GL_LINES);
	glColor3f(0,1,1);
	glVertex2f(180.0,340.0);
	glVertex2f(175.0,340.0);
	glEnd();
	glFlush();
}

void messageflow(float x,float y){
	glLineWidth(8);
	glBegin(GL_LINES);
	glColor3f(0,1,1);
	glVertex2f(x,y);
	glVertex2f(x+5,y);
	glEnd();
	glFlush();

}

void erasemessage(float x,float y){

	glLineWidth(8);
	glColor4f(0.6,0.7,0.8,0.6);
	glBegin(GL_LINES);
	glVertex2f(x,y);
	glVertex2f(x-5,y);
	glEnd();
	glFlush();

}

void alice_online(int message_count_alice){
	int j=0,x1=375,y1=310,x2=425,y2=160;
	while(j<41){

		drawpoints(alice_coordinates[j],alice_coordinates[j+1]);
		j+=2;
		double late=9999999;
		while(late>0){
			while(late>0){
				while(late>0){
					while(late>0){
						while(late>0){
							while(late>0){
								while(late>0){
									while(late>0){
										while(late>0){
											late--;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(j>6)
			erase_alice(j);

	}
	while(j<50){
		erase_alice(j);
		j+=2;	
	}
	//410 to 440
	//alice recieved message
	glLineWidth(3);
	glColor3f(0.5,1,0.3);
	glBegin(GL_LINES);
	glVertex2f(410,135);
	glVertex2f(440,135);
	glVertex2f(410,130);
	glVertex2f(440,130);
	glVertex2f(410,125);
	glVertex2f(440,125);
	glVertex2f(410,120);
	glVertex2f(440,120);
	glVertex2f(410,115);
	glVertex2f(440,115);
	glEnd();
	glFlush();
	sleep(1);
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex2f(405.0,145.0);
	glVertex2f(405.0,105.0);
	glVertex2f(445.0,105.0);
	glVertex2f(445.0,145.0);
	glEnd();
	glFlush();
}

void bobflow(int message_count_alice){
	int j=0;
	float x=175.0,y=395.0;
	float x1=325.0,y1=395.0;
	float m1=175,m2=340;
	float i=points[j];
	while(j<51){

		drawpoints(points[j],points[j+1]);
		j+=2;
		double late=9999999;
		while(late>0){
			while(late>0){
				while(late>0){
					while(late>0){
						while(late>0){
							while(late>0){
								while(late>0){
									while(late>0){
										while(late>0){
											late--;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(j>6)
			erase(j);

	}
	while(j<51){
		erase(j);
		j-=2;
	}
	tcpconn_bob();
	glPointSize(7.0);
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	glVertex2f(115,360);
	glVertex2f(120,360);
	glEnd();
	glFlush();
	ctrline(175,395);
	while(x<325){
		ctrline(x,y);
		x+=0.09;
		if(x>180){
			delline(x,y);
		}
	}
	aliceside();
	ack(x1,y1);
	while(x1>175){
		ack(x1,y1);
		x1-=0.09;
		if(x1<320){
			delack(x1,y1);
		}
	}
	bobside();
	//here goes segment after control connection
	tcpconn_message();
	message();
	messageflow(m1,m2);
	while(m1<325){

		messageflow(m1,m2);
		m1+=0.09;
		if(m1>180){
			erasemessage(m1,m2);
		}
	}
	aliceside();

	//alice has message
	glPointSize(10);
	glColor3f(0,0,1);
	glBegin(GL_POINTS);
	glVertex2f(350,470);
	glEnd();

	erase_tcpconn();
	glFlush();

	erase_tcpconn();
	glFlush();

}

float points_utod[]={
	115,360,105,360,95,360,	85,360,	75,360,	75,350,	75,340,	75,330,	75,320,	75,310,	75,300,	75,290,	75,280,	75,270,	75,260,	75,250,	75,240,	75,230,	75,220,	75,210,	75,200,	75,190,	75,180,	75,170,	75,160
};

float alice_coordinates_dtou[]={

	425,160,//21
	425,170,
	425,180,
	425,190,
	425,200,
	425,210,
	425,220,
	425,230,
	425,240,
	425,250,
	425,260,
	425,270,
	425,280,
	425,290,
	425,300,
	425,310,
	415,310,
	405,310,
	395,310,
	385,310,
	380,310,
};

void tcpconn_alice(){

	//glEnable(GL_BLEND);
	glColor4f(0.6,0.7,0.8,0.6);
	glBegin(GL_QUAD_STRIP);
	glVertex2f(175.0,400.0);
	glVertex2f(175.0,390.0);
	glVertex2f(325.0,400.0);
	glVertex2f(325.0,390.0);
	glEnd();

}

void alice_erase_alice(int v){

	glPointSize(7.0);
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	glVertex2f(points_utod[v-6],points_utod[v-5]);
	glVertex2f(115,360);
	glEnd();
	glFlush();

}

void alice_erase(int v){//erases alice to her server

	glPointSize(7.0);
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	glVertex2f(alice_coordinates_dtou[v-6],alice_coordinates_dtou[v-5]);
	glVertex2f(425,160);
	glEnd();
	glFlush();

}

void alice_drawpoints(float x,float y){//draws alice to her server
	glPointSize(7.0);
	glBegin(GL_POINTS);
	glColor3f(0,1,0);
	glVertex2f(x,y);
	glEnd();
	glFlush();

}

void alice_ctrline(float x,float y){
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(x,y);
	glVertex2f(x-5,y);
	glEnd();
	glFlush();
}

void alice_delline(float x,float y){
	//glEnable(GL_BLEND);
	glLineWidth(1.5);
	glColor4f(0.6,0.7,0.8,0.6);
	glBegin(GL_LINES);
	glVertex2f(x,y);
	glVertex2f(x+5,y);
	glEnd();
	glFlush();
	//glDisable(GL_BLEND);	
}

void alice_ack(float x,float y){
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(x,y);
	glVertex2f(x+5,y);
	glEnd();
	glFlush();
}

void alice_delack(float x,float y){
	//glEnable(GL_BLEND);
	glLineWidth(1.5);
	glColor4f(0.6,0.7,0.8,0.5);
	glBegin(GL_LINES);
	glVertex2f(x,y);
	glVertex2f(x-5,y);
	glEnd();
	glFlush();
	//glDisable(GL_BLEND);

}

void alice_messageflow(float x,float y){
	glLineWidth(8);
	glBegin(GL_LINES);
	glColor3f(0,1,1);
	glVertex2f(x,y);
	glVertex2f(x-5,y);
	glEnd();
	glFlush();

}

void alice_erasemessage(float x,float y){

	glLineWidth(8);
	glColor4f(0.6,0.7,0.8,0.6);
	glBegin(GL_LINES);
	glVertex2f(x,y);
	glVertex2f(x+5,y);
	glEnd();
	glFlush();

}

void alice_message(){
	glLineWidth(8);
	glBegin(GL_LINES);
	glColor3f(0,1,1);
	glVertex2f(320.0,340.0);
	glVertex2f(325.0,340.0);
	glEnd();
	glFlush();
}

void bob_online(int message_count_bob){
	int j=0,x1=375,y1=310,x2=425,y2=160;

	while(j<50){

		alice_drawpoints(points_utod[j],points_utod[j+1]);
		j+=2;
		double late=9999999;
		while(late>0){
			while(late>0){
				while(late>0){
					while(late>0){
						while(late>0){
							while(late>0){
								while(late>0){
									while(late>0){
										while(late>0){
											late--;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(j>6)
			alice_erase_alice(j);

	}
	while(j<60){
		alice_erase_alice(j);
		j+=2;	
	}
	glLineWidth(3);
	glColor3f(0.5,1,0.3);
	glBegin(GL_LINES);
	glVertex2f(60,135);
	glVertex2f(90,135);
	glVertex2f(60,130);
	glVertex2f(90,130);
	glVertex2f(60,125);
	glVertex2f(90,125);
	glVertex2f(60,120);
	glVertex2f(90,120);
	glVertex2f(60,115);
	glVertex2f(90,115);
	glEnd();
	glFlush();
	sleep(1);
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex2f(55.0,145.0);
	glVertex2f(55.0,105.0);
	glVertex2f(95.0,105.0);
	glVertex2f(95.0,145.0);
	glEnd();
	glFlush();


}

void aliceflow(int message_count_bob){
	int j=0;
	float x=325.0,y=395.0;
	float x1=175.0,y1=395.0,m2=340,m1=325;

	while(j<42){

		alice_drawpoints(alice_coordinates_dtou[j],alice_coordinates_dtou[j+1]);
		j+=2;
		//sleep(0.9);
		double late=9999999;
		while(late>0){
			while(late>0){
				while(late>0){
					while(late>0){
						while(late>0){
							while(late>0){
								while(late>0){
									while(late>0){
										while(late>0){
											late--;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(j>6)
			alice_erase(j);

	}
	while(j<50){
		alice_erase(j);
		j+=2;
	}
	tcpconn_bob();
	alice_ctrline(325,395);
	while(x>175){
		alice_ctrline(x,y);
		x-=0.09;
		if(x<320){
			alice_delline(x,y);
		}
	}

	bobside();
	ack(x1,y1);
	bobside();
	while(x1<325){
		alice_ack(x1,y1);
		x1+=0.09;
		if(x1>180){
			alice_delack(x1,y1);
		}
	}
	aliceside();
	tcpconn_message();
	alice_message();
	alice_messageflow(m1,m2);
	while(m1>175){

		alice_messageflow(m1,m2);
		m1-=0.09;
		if(m1<320){
			alice_erasemessage(m1,m2);
		}
	}
	bobside();

	//bob has message
	glPointSize(10);
	glColor3f(0,0,1);
	glBegin(GL_POINTS);
	glVertex2f(150,470);
	glEnd();

	erase_tcpconn();
	glFlush();


}

int message_count_alice = 0,message_count_bob=0;

void setFont(void *font){
	currentfont=font;
}

void controls(){
	glClearColor(0.5,0.9,0.1,0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	char *ptrS="A/a: System2 to System1.";
	int lenS=strlen(ptrS);
	glColor3f(0,0, 0);
	glRasterPos2f(185,370);
	for(int i=0;i<lenS;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ptrS[i]);
	glFlush();

	ptrS="L/l: System1 to System2.";
	lenS=strlen(ptrS);
	glColor3f(0, 0,0);
	glRasterPos2f(185,340);
	for(int i=0;i<lenS;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ptrS[i]);
	glFlush();

	ptrS="P/p: System2 is online";
	lenS=strlen(ptrS);
	glColor3f(0,0,0);
	glRasterPos2f(185,290);
	for(int i=0;i<lenS;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ptrS[i]);
	glFlush();

	ptrS="q/Q: System1 is online";
	lenS=strlen(ptrS);
	glColor3f(0,0,0);
	glRasterPos2f(185,260);
	for(int i=0;i<lenS;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ptrS[i]);
	glFlush();

}

void drawstring(float x,float y,float z,char *str){
	char *c;
	glRasterPos3f(x,y,z);
	for(c=str;*c!='\0';c++)
	{       glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

void bobside(){
	//bob's computer
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glColor3f(0.5,0.5,0.5);
	glVertex2f(50.0,150.0);
	glVertex2f(50.0,100.0);
	glVertex2f(100.0,100.0);
	glVertex2f(100.0,150.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex2f(55.0,145.0);
	glVertex2f(55.0,105.0);
	glVertex2f(95.0,105.0);
	glVertex2f(95.0,145.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0.5,1);
	glVertex2f(40.0,80.0);
	glVertex2f(35.0,60.0);
	glVertex2f(115,60.0);
	glVertex2f(110.,80.0);
	glEnd();
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1,1,1);
	drawstring(50.0,40.0,1.0,"System1");
	glFlush();
	//bob's server
	glBegin(GL_POLYGON);
	glColor3f(0,0.5,1);
	glVertex2f(125.0,450);
	glVertex2f(125.0,300.0);
	glVertex2f(175.0,300.0);
	glVertex2f(175.0,450.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(130,435.0);
	glVertex2f(130.0,425.0);
	glVertex2f(170,425.0);
	glVertex2f(170.,435.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(130.0,415.0);
	glVertex2f(130.0,405.0);
	glVertex2f(170,405.0);
	glVertex2f(170.,415.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(130.0,395.0);
	glVertex2f(130.0,385.0);
	glVertex2f(170,385.0);
	glVertex2f(170.,395.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(130.0,375.0);
	glVertex2f(130.0,365.0);
	glVertex2f(170,365.0);
	glVertex2f(170.,375.0);
	glEnd();

	glPointSize(20.0);
	glBegin(GL_POINTS);
	glVertex2f(140.0,345.0);
	glVertex2f(160.0,345.0);
	glEnd();

	glColor3f(1,1,1);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(110.0,280.0,1.0,"System1's server");
	glFlush();

}

void aliceside(){

	glBegin(GL_POLYGON);
	glColor3f(0.5,0.5,0.5);
	glVertex2f(400.0,150.0);
	glVertex2f(400.0,100.0);
	glVertex2f(450.0,100.0);
	glVertex2f(450.0,150.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex2f(405.0,145.0);
	glVertex2f(405.0,105.0);
	glVertex2f(445.0,105.0);
	glVertex2f(445.0,145.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0.5,1);
	glVertex2f(390.0,80.0);
	glVertex2f(385.0,60.0);
	glVertex2f(465.0,60.0);
	glVertex2f(460.,80.0);
	glEnd();
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1,1,1);
	drawstring(400.0,40.0,1.0,"System2");
	glFlush();

	//alice's server

	glBegin(GL_POLYGON);
	glColor3f(0,0.5,1);
	glVertex2f(325.0,450);
	glVertex2f(325.0,300.0);
	glVertex2f(375.0,300.0);
	glVertex2f(375.0,450.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(330,435.0);
	glVertex2f(330.0,425.0);
	glVertex2f(370,425.0);
	glVertex2f(370.,435.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(330.0,415.0);
	glVertex2f(330.0,405.0);
	glVertex2f(370,405.0);
	glVertex2f(370.,415.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(330.0,395.0);
	glVertex2f(330.0,385.0);
	glVertex2f(370,385.0);
	glVertex2f(370.,395.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(330.0,375.0);
	glVertex2f(330.0,365.0);
	glVertex2f(370,365.0);
	glVertex2f(370.,375.0);
	glEnd();

	glPointSize(20.0);
	glBegin(GL_POINTS);
	glVertex2f(340.0,345.0);
	glVertex2f(360.0,345.0);
	glEnd();
	glColor3f(1,1,1);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(310.0,280.0,1.0,"System2's server");
	glFlush();
}

void myInit(){
	glClearColor(0.2,0.20,0.4,0);
	glColor3f(1.0f,0.5f,0.5f);
	glPointSize(5.0);
	gluOrtho2D(0.0,500.0,0.0,500.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	setFont(GLUT_BITMAP_HELVETICA_18);
}

void contr(){

	glClear(GL_COLOR_BUFFER_BIT);
	char *ptrS="A / a: 2 --> 1.";
	int lenS=strlen(ptrS);
	glColor3f(0,1, 0);
	glRasterPos2f(250,120);
	for(int i=0;i<lenS;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,ptrS[i]);
	glFlush();

	ptrS="L / l: 1 --> 2.";
	lenS=strlen(ptrS);
	glColor3f(0, 1,0);
	glRasterPos2f(250,100);
	for(int i=0;i<lenS;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,ptrS[i]);
	glFlush();

	ptrS="P / p: 2 IS ONLINE";
	lenS=strlen(ptrS);
	glColor3f(0,1,1);
	glRasterPos2f(250,80);
	for(int i=0;i<lenS;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,ptrS[i]);
	glFlush();

	ptrS="q / Q: 1 IS ONLINE";
	lenS=strlen(ptrS);
	glColor3f(0,1,1);
	glRasterPos2f(250,60);
	for(int i=0;i<lenS;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,ptrS[i]);
	glFlush();
}

void draw_key_int(void)/* text for keyboard interaction*/{       glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,135);
	glVertex2f(500,135);
	glVertex2f(500,0);
	glEnd();
	glFlush();

}

void myfunc(){

	glClearColor(0.0f,0.0f,0.0f,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	contr();
	bobside();	
	aliceside();
	glFlush();

}

void title(){  
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,1,1);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(180.0,475.0,1.0,"     ATRIA INSTITUTE OF TECHNOLOGY");
	glColor3f(1.0,1,1);
	drawstring(55.0,435.0,1.0,"                                                                         SMTP Simulation");
	glColor3f(1.0,1.0,1.0);
	drawstring(210.0,365.0,1.0,"           SUBMITTED   BY");                          
	glColor3f(0,1.0,1.0);
	drawstring(150.0,340.0,1.0," DEEKSHITH LOBO                                   1AT16CS028");
	glColor3f(0.0,1.0,1.0);
	drawstring(150.0,300.0,1.0," CHANDAN G RAJ                                       1AT15CS017");
	glColor3f(1.0,1.0,1.0);
	drawstring(195.0,240.0,1.0,"          UNDER THE GUIDANCE OF");
	glColor3f(1.0,1.0,0.0);
	drawstring(140.0,200.0,1.0,"                                             Mr. Satisha G ");
	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(0,1,0.6);
	drawstring(130.0,180.0,1.0,"                                                             Assistant Professor");
	glColor3f(0,1,0.6);
	drawstring(130.0,160.0,1.0,"                                                                 Dept. of CSE ");
	glColor3f(0,1,0.6);
	drawstring(140.0,140.0,1.0,"                                                                   AIT");
	glColor3f(1.0f,0.3f,0.5f);
	setFont(GLUT_BITMAP_HELVETICA_12);
	drawstring(360.0,100.0,1.0,"PRESS S TO CONTINUE...");
	//draw_key_int();
	glFlush();
}

void bobtoalice(){
	bobflow(message_count_alice);

}

void alicetobob(){
	aliceflow(message_count_bob);
}
int start=0;
void mykeyboard(unsigned char key,int x,int y){  
	if (start==0){
		if(key=='s' || key=='S')
		{      glClear(GL_COLOR_BUFFER_BIT);
		 	start=1;
			//draw();
			myfunc();
			//text();
		}
	}
	else if(key=='l'|| key=='L'){
		message_count_alice++;
		bobtoalice();
	}
	else if(key=='a'|| key=='A'){
		message_count_bob++;
		alicetobob();

	}
	else if(key=='p' || key=='P'){
		int nt=0;
		while(message_count_alice>0){
			if(nt==0){
				glPointSize(8);
				glBegin(GL_POINTS);
				glColor3f(1,1,1);
				glVertex2f(390,140);
				glEnd();
				glFlush();
				nt=1;
			}
			alice_online(message_count_alice);
			message_count_alice--;
		}
		glPointSize(8);
		glBegin(GL_POINTS);
		glColor3f(0,0,0);
		glVertex2f(390,140);
		glEnd();

		glPointSize(10);
		glColor3f(0,0,0);
		glBegin(GL_POINTS);
		glVertex2f(350,470);
		glEnd();

		glFlush();
	}
	else if(key=='q'||key=='Q'){
		int cnt=0;
		while(message_count_bob>0){
			if(cnt==0){
				glPointSize(8);
				glBegin(GL_POINTS);
				glColor3f(1,1,1);
				glVertex2f(110,140);
				glEnd();
				glFlush();
				cnt=1;
			}
			bob_online(message_count_bob);
			message_count_bob--;

		}
		glPointSize(8);
		glBegin(GL_POINTS);
		glColor3f(0,0,0);
		glVertex2f(110,140);
		glEnd();

		glPointSize(10);
		glColor3f(0,0,0);
		glBegin(GL_POINTS);
		glVertex2f(150,470);
		glEnd();

		glFlush();

	}

}

void display(void){       
	glClear(GL_COLOR_BUFFER_BIT);
	if(flag==0){
		title();
		flag=1;
	}else{
		myfunc();
	}
	glutSwapBuffers();

}

void menufunc(int n){
	switch(n)
	{
		case 1: display();
			break;
		
		case 2:controls();
			break;
		  

		case 3: exit(0);
	}
}

int main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1000,1000);
	
	glutCreateWindow("SMTP simulation");
	glutDisplayFunc(display);

	submenu=glutCreateMenu(menufunc);
	glutCreateMenu(menufunc);
	glutAddMenuEntry("RESTART",1);
	glutAddMenuEntry("CONTROLS",2);
	glutAddMenuEntry("EXIT",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glBlendFunc(GL_SRC_ALPHA,GL_DST_ALPHA);
	glutKeyboardFunc(mykeyboard);
	//sglutIdleFunc(animate);
	myInit();
	glutMainLoop();

	return 0;
}
