
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <math.h>
int d=20,p,gx=0,hy=0,hxc=495,gyc=795,ha,gb;
float theta=0;
float mv=0,st=0,mv1=0;
float tmx=0,tmy=0;
void render5BitmapString(float x,float y,char *string){
    int len;
    glRasterPos2i(x,y);
    glDisable(GL_TEXTURE);
    glDisable(GL_TEXTURE_2D);
    for(int i=0,len=strlen(string);i<len;i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)string[i]);
    }
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE);
}
void render5BitmapString1(float x,float y,char *string){
    int len;
    glRasterPos2i(x,y);
    glDisable(GL_TEXTURE);
    glDisable(GL_TEXTURE_2D);
    for(int i=0,len=strlen(string);i<len;i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(int)string[i]);
    }
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE);
}


void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/


//wall left-right 1
glColor3ub (10,87,62);
glBegin(GL_POLYGON);
glVertex3f (0, 250, 0);
glVertex3f (390, 350, 0);
glVertex3f (390, 1000, 0);
glVertex3f (0, 1000, 0);
glEnd();

//wall right-left---2
glColor3ub (13,108,92);
glBegin(GL_POLYGON);
glVertex3f (390,350, 0);
glVertex3f (1000,250, 0);
glVertex3f (1000, 1000, 0);
glVertex3f (390, 1000, 0);
glEnd();


///


//photo frame - outer
glColor3ub (255,108,92);
glBegin(GL_POLYGON);
glVertex3f (450,700, 0);
glVertex3f (540,700, 0);
glVertex3f (540, 870, 0);
glVertex3f (450, 870, 0);
glEnd();

//photo frame - inner
glColor3ub (178,235,242);
glBegin(GL_POLYGON);
glVertex3f (455,705, 0);
glVertex3f (535,705, 0);
glVertex3f (535, 865, 0);
glVertex3f (455, 865, 0);
glEnd();

//photo frame - man
glColor3ub (171,39,176);
glBegin(GL_POLYGON);
glVertex3f (455,705, 0);
glVertex3f (535,705, 0);
glVertex3f (535, 745, 0);
glVertex3f (525, 770, 0);
glVertex3f (465, 770, 0);
glVertex3f (455, 745, 0);
glEnd();






///Calender
glColor3ub(178,2,221);
render5BitmapString1(465,840,"Tuesday");
render5BitmapString1(470,810,"18,Dec");
render5BitmapString1(480,780,"2018");






//roof  top --3
glColor3ub (15,142,126);
glBegin(GL_POLYGON);
glVertex3f (650, 1000, 0);
glVertex3f (390, 950, 0);
glVertex3f (180, 1000, 0);
glEnd();

//wall right-right --- 4
glColor3ub (19,182,166);
glBegin(GL_POLYGON);
glVertex3f (600, 300, 0);
glVertex3f (1000, 250, 0);
glVertex3f (1000, 1000, 0);
glVertex3f (600, 1000, 0);
glEnd();

//clock outer--5
glColor3ub (55,71,79);
glBegin(GL_POLYGON);
glVertex3f (680, 800, 0);
glVertex3f (630, 800, 0);
glVertex3f (630, 900, 0);
glVertex3f (680, 900, 0);
glEnd();
//clock inner--8
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (675, 805, 0);
glVertex3f (635, 805, 0);
glVertex3f (635, 895, 0);
glVertex3f (675, 895, 0);
glEnd();




if(theta<360)
    theta-=.05;
else theta=0;

glutPostRedisplay();

///
//clock second
glColor3ub (0,0,0);
glPushMatrix();
glTranslated(655,850,0);
glPushMatrix();
glRotated(theta,0,0,1);
glBegin(GL_LINES);
//glBegin(GL_POINT_SIZE);
glVertex3f (0,0,0);
glVertex3f (0,40, 0);
glEnd();
glPopMatrix();
glPopMatrix();
///

///proxy
glColor3ub (19,182,166);
glBegin(GL_POLYGON);
glVertex3f (680, 800, 0);
glVertex3f (680, 900, 0);
glVertex3f (700, 900, 0);
glVertex3f (700, 800, 0);
glEnd();
glPushMatrix();
glTranslated(-70,0,0);
glBegin(GL_POLYGON);
glVertex3f (680, 800, 0);
glVertex3f (680, 900, 0);
glVertex3f (700, 900, 0);
glVertex3f (700, 800, 0);
glEnd();
glPopMatrix();
/// proxy end

//clock minute
glColor3ub (0,0,0);
glBegin(GL_LINES);
//glBegin(GL_POINT_SIZE);
glVertex3f (655, 850, 0);
glVertex3f (670, 850, 0);
glEnd();


//clock hour
glColor3ub (0,0,0);
glBegin(GL_LINES);
//glBegin(GL_POINT_SIZE);
glVertex3f (655, 850, 0);
glVertex3f (645, 810, 0);
glEnd();

//ac front --7
glColor3ub (120,144,156);
glBegin(GL_POLYGON);
glVertex3f (700, 850, 0);
glVertex3f (850, 850, 0);
glVertex3f (850, 900, 0);
glVertex3f (700, 900, 0);
glEnd();

//ac top--8
glColor3ub (69,90,100);
glBegin(GL_POLYGON);
glVertex3f (710, 920, 0);
glVertex3f (860, 920, 0);
glVertex3f (850, 900, 0);
glVertex3f (700, 900, 0);
glEnd();

//ac bottom---9
glColor3ub (69,90,100);
glBegin(GL_POLYGON);
glVertex3f (700, 850, 0);
glVertex3f (850, 850, 0);
glVertex3f (860, 840, 0);
glVertex3f (710, 840, 0);
glEnd();

//ac side--10
glColor3ub (38,50,56);
glBegin(GL_POLYGON);
glVertex3f (860, 840, 0);
glVertex3f (850, 850, 0);
glVertex3f (850, 900, 0);
glVertex3f (860, 920, 0);
glEnd();


// left wall - right---11
glColor3ub(20,192,183);
glBegin(GL_POLYGON);
glVertex3f (200, 250, 0);
glVertex3f (0, 250, 0);
glVertex3f (0, 1000, 0);
glVertex3f (200, 1000, 0);
glEnd();


//floor - white --12
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (0, 0, 0);
glVertex3f (0, 250, 0);
glVertex3f (390, 350, 0);
glVertex3f (1000, 250, 0);
glVertex3f (1000, 0, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (0, 0, 0);
glVertex3f (0, 50, 0);
glVertex3f (50, 50, 0);
glVertex3f (50, 0, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (0, 100, 0);
glVertex3f (0, 150, 0);
glVertex3f (50, 150, 0);
glVertex3f (50, 100, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (0, 200, 0);
glVertex3f (0, 250, 0);
glVertex3f (50,250, 0);
glVertex3f (50,200, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (100, 0, 0);
glVertex3f (100, 50, 0);
glVertex3f (150, 50, 0);
glVertex3f (150, 0, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (100, 100, 0);
glVertex3f (100, 150, 0);
glVertex3f (150,150, 0);
glVertex3f (150, 100, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (100, 200, 0);
glVertex3f (100, 250, 0);
glVertex3f (150, 250, 0);
glVertex3f (150, 200, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (200, 0, 0);
glVertex3f (200, 50, 0);
glVertex3f (250, 50, 0);
glVertex3f (250, 0, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (200, 100, 0);
glVertex3f (200, 150, 0);
glVertex3f (250, 150, 0);
glVertex3f (250, 100, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (200, 200, 0);
glVertex3f (200, 250, 0);
glVertex3f (250, 250, 0);
glVertex3f (250, 200, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (200, 300, 0);
glVertex3f (200, 315, 0);
glVertex3f (250, 315, 0);
glVertex3f (250, 300, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (300, 0, 0);
glVertex3f (300, 50, 0);
glVertex3f (350, 50, 0);
glVertex3f (350, 0, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (300, 300, 0);
glVertex3f (300, 328, 0);
glVertex3f (350, 340, 0);
glVertex3f (350, 300, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (400, 0, 0);
glVertex3f (400, 50, 0);
glVertex3f (450, 50, 0);
glVertex3f (450, 0, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (500, 0, 0);
glVertex3f (500, 50, 0);
glVertex3f (550, 50, 0);
glVertex3f (550, 0, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (600, 0, 0);
glVertex3f (600, 50, 0);
glVertex3f (650, 50, 0);
glVertex3f (650, 0, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (600, 100, 0);
glVertex3f (600, 150, 0);
glVertex3f (650, 150, 0);
glVertex3f (650, 100, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (700, 0, 0);
glVertex3f (700, 50, 0);
glVertex3f (750, 50, 0);
glVertex3f (750, 0, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (700, 100, 0);
glVertex3f (700, 150, 0);
glVertex3f (750, 150, 0);
glVertex3f (750, 100, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (800, 0, 0);
glVertex3f (800, 50, 0);
glVertex3f (850, 50, 0);
glVertex3f (850, 0, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (800, 100, 0);
glVertex3f (800, 150, 0);
glVertex3f (850, 150, 0);
glVertex3f (850, 100, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (800, 200, 0);
glVertex3f (800, 250, 0);
glVertex3f (850, 250, 0);
glVertex3f (850, 200, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (900, 0, 0);
glVertex3f (900, 50, 0);
glVertex3f (950, 50, 0);
glVertex3f (950, 0, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (900, 100, 0);
glVertex3f (900, 150, 0);
glVertex3f (950, 150, 0);
glVertex3f (950, 100, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (50, 50, 0);
glVertex3f (50, 100, 0);
glVertex3f (100, 100, 0);
glVertex3f (100, 50, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (50, 150, 0);
glVertex3f (50, 200, 0);
glVertex3f (100, 200, 0);
glVertex3f (100, 150, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (150, 50, 0);
glVertex3f (150, 100, 0);
glVertex3f (200, 100, 0);
glVertex3f (200, 50, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (150, 150, 0);
glVertex3f (150, 200, 0);
glVertex3f (200, 200, 0);
glVertex3f (200, 150, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (250, 50, 0);
glVertex3f (250, 100, 0);
glVertex3f (300, 100, 0);
glVertex3f (300, 50, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (250, 250, 0);
glVertex3f (250, 300, 0);
glVertex3f (300, 300, 0);
glVertex3f (300, 250, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (350, 50, 0);
glVertex3f (350, 100, 0);
glVertex3f (400, 100, 0);
glVertex3f (400, 50, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (450, 50, 0);
glVertex3f (450, 100, 0);
glVertex3f (500, 100, 0);
glVertex3f (500, 50, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (550, 50, 0);
glVertex3f (550, 100, 0);
glVertex3f (600, 100, 0);
glVertex3f (600, 50, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (650, 50, 0);
glVertex3f (650, 100, 0);
glVertex3f (700, 100, 0);
glVertex3f (700, 50, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (750, 50, 0);
glVertex3f (750, 100, 0);
glVertex3f (800, 100, 0);
glVertex3f (800, 50, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (750, 150, 0);
glVertex3f (750, 200, 0);
glVertex3f (800, 200, 0);
glVertex3f (800, 150, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (850, 50, 0);
glVertex3f (850, 100, 0);
glVertex3f (900, 100, 0);
glVertex3f (900, 50, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (950, 50, 0);
glVertex3f (950, 100, 0);
glVertex3f (1000, 100, 0);
glVertex3f (1000, 50, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (950,200, 0);
glVertex3f (950, 150, 0);
glVertex3f (1000, 150, 0);
glVertex3f (1000, 200, 0);
glEnd();
//floor - black
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (950,260, 0);
glVertex3f (950, 250, 0);
glVertex3f (1000, 250, 0);
glVertex3f (1000, 260, 0);
glEnd();


//window left---13
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (230, 500, 0);
glVertex3f (325, 520, 0);
glVertex3f (325, 900, 0);
glVertex3f (230, 900, 0);
glEnd();

//window left - right inner
glColor3ub (131,102,92);
glBegin(GL_POLYGON);
glVertex3f (310, 890, 0);
glVertex3f (325, 900, 0);
glVertex3f (325, 520, 0);
glVertex3f (310, 525, 0);
glEnd();

//window left - bottom
glColor3ub (195,182,166);
glBegin(GL_POLYGON);
glVertex3f (230, 500, 0);
glVertex3f (325, 520, 0);
glVertex3f (310, 525, 0);
glVertex3f (230, 510, 0);
glEnd();

//window left - top
glColor3ub (195,182,166);
glBegin(GL_POLYGON);
glVertex3f (230, 900, 0);
glVertex3f (325, 900, 0);
glVertex3f (310, 890, 0);
glVertex3f (230, 890, 0);
glEnd();

//window left grill-middle-vertical
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (275, 512, 0);
glVertex3f (280, 512, 0);
glVertex3f (280, 895, 0);
glVertex3f (275, 895, 0);
glEnd();

//window left grill-bottom
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (230, 600, 0);
glVertex3f (320, 615, 0);
glVertex3f (320, 625, 0);
glVertex3f (230, 610, 0);
glEnd();

//window left grill-middle
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (230, 700, 0);
glVertex3f (320, 715, 0);
glVertex3f (320, 725, 0);
glVertex3f (230, 710, 0);
glEnd();

//window left grill-top-horizontal
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (230, 800, 0);
glVertex3f (320, 810, 0);
glVertex3f (320, 820, 0);
glVertex3f (230, 810, 0);
glEnd();

//wear drop front ---15
glColor3ub (89,39,25);
glBegin(GL_POLYGON);
glVertex3f (460, 660, 0);
glVertex3f (470, 670, 0);
glVertex3f (330, 670,0);
glVertex3f (340, 660, 0);
glVertex3f (340, 320, 0);
glVertex3f (460, 320, 0);
glEnd();

//wear drop front-drawer 1 - outer
glColor3ub (42,23,15);
glBegin(GL_POLYGON);
glVertex3f (455, 431, 0);
glVertex3f (345, 431, 0);
glVertex3f (345, 324, 0);
glVertex3f (455, 324, 0);
glEnd();

//wear drop front-drawer 1 - handel
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (410, 381, 0);
glVertex3f (390, 381, 0);
glVertex3f (390, 375, 0);
glVertex3f (410, 375, 0);
glEnd();

//wear drop front-drawer 2 - outer
glColor3ub (42,23,15);
glBegin(GL_POLYGON);
glVertex3f (455, 435, 0);
glVertex3f (345, 435, 0);
glVertex3f (345, 541, 0);
glVertex3f (455, 541, 0);
glEnd();

//wear drop front-drawer 2 - handel
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (410, 481, 0);
glVertex3f (390, 481, 0);
glVertex3f (390, 475, 0);
glVertex3f (410, 475, 0);
glEnd();
//wear drop front-drawer 3 - outer
glColor3ub (42,23,15);
glBegin(GL_POLYGON);
glVertex3f (455, 653, 0);
glVertex3f (345, 653, 0);
glVertex3f (345, 545, 0);
glVertex3f (455, 545, 0);
glEnd();

//wear drop front-drawer 3 - handel
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (410, 585, 0);
glVertex3f (390, 585, 0);
glVertex3f (390, 579, 0);
glVertex3f (410, 579, 0);
glEnd();

//wear drop side
glColor3ub (39,32,21);
glBegin(GL_POLYGON);
glVertex3f (470, 670, 0);
glVertex3f (500, 667, 0);
glVertex3f (492, 657, 0);
glVertex3f (492, 330, 0);
glVertex3f (460, 320, 0);
glVertex3f (460, 660, 0);
glEnd();

//dressing table - front--16
glColor3ub (98,47,29);
glBegin(GL_POLYGON);
glVertex3f (50, 150,0);
glVertex3f (245, 230, 0);
glVertex3f (245, 460, 0);
glVertex3f (50, 400, 0);
glEnd();

//dressing table - front  - left part
glColor3ub (42,23,15);
glBegin(GL_POLYGON);
glVertex3f (55, 160,0);
glVertex3f (115, 185, 0);
glVertex3f (115, 410, 0);
glVertex3f (55, 390, 0);
glEnd();
//dressing table - front  - left part - front handel
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (70, 305,0);
glVertex3f (75, 305, 0);
glVertex3f (75, 255, 0);
glVertex3f (70, 255, 0);
glEnd();

//dressing table - front  - left part - handel bottom
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (64, 262,0);
glVertex3f (75, 262, 0);
glVertex3f (75, 255, 0);
glVertex3f (64, 255, 0);
glEnd();

//dressing table - front  - left part - handel top
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (64, 305,0);
glVertex3f (75, 305, 0);
glVertex3f (75, 310, 0);
glVertex3f (64, 310, 0);
glEnd();

//dressing table side
glColor3ub (42,23,15);
glBegin(GL_POLYGON);
glVertex3f (50, 150, 0);
glVertex3f (20, 170, 0);
glVertex3f (20, 420, 0);
glVertex3f (50, 400, 0);
glEnd();

//dressing table - front  - middle part
glColor3ub (42,23,15);
glBegin(GL_POLYGON);
glVertex3f (120, 185,0);
glVertex3f (180, 210, 0);
glVertex3f (180, 430, 0);
glVertex3f (120, 410, 0);
glEnd();

//dressing table - front  - middle part - handel - top
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (135, 275,0);
glVertex3f (140, 275, 0);
glVertex3f (140, 323, 0);
glVertex3f (135, 323, 0);
glEnd();

//dressing table - front  - middle part - handel - down
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (130, 328,0);
glVertex3f (140, 328, 0);
glVertex3f (140, 323, 0);
glVertex3f (130, 323, 0);
glEnd();
//dressing table - front  - middle part - handel - top-down
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (130, 275,0);
glVertex3f (140, 275, 0);
glVertex3f (140, 280, 0);
glVertex3f (130, 280, 0);
glEnd();

//dressing table - front  - right part
glColor3ub (42,23,15);
glBegin(GL_POLYGON);
glVertex3f (185, 213,0);
glVertex3f (240, 235, 0);
glVertex3f (240, 450, 0);
glVertex3f (185, 430, 0);
glEnd();

//dressing table - front  - right part - handel - top
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (200, 300,0);
glVertex3f (205, 300, 0);
glVertex3f (205, 343, 0);
glVertex3f (200, 343, 0);
glEnd();

//dressing table - front  - right part - handel - down
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (194, 300,0);
glVertex3f (205, 300, 0);
glVertex3f (205, 295, 0);
glVertex3f (194, 295, 0);
glEnd();
//dressing table - front  - right part - handel - top-down
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (194, 343,0);
glVertex3f (205, 343, 0);
glVertex3f (205, 348, 0);
glVertex3f (194, 348, 0);
glEnd();

//dressing table top
glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (20, 420,0);
glVertex3f (50, 400, 0);
glVertex3f (245,460, 0);
glVertex3f (215,480, 0);
glEnd();

//dressing table glass frame
glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (190, 470, 0);
glVertex3f (48, 427, 0);
glVertex3f (48, 770, 0);
glVertex3f (190, 800, 0);
glEnd();

//dressing table glass
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (180, 467, 0);
glVertex3f (58, 430, 0);
glVertex3f (58, 750, 0);
glVertex3f (180, 777, 0);
glEnd();

//object reflection
glColor3ub (158,158,158);
glBegin(GL_POLYGON);
glVertex3f (130, 460, 0);
glVertex3f (150, 460, 0);
glVertex3f (160, 575, 0);
glVertex3f (120, 570, 0);
glEnd();
//object flower1 reflection
glColor3ub (229,115,115);
glBegin(GL_POLYGON);
glVertex3f (140, 600, 0);
glVertex3f (150, 650, 0);
glVertex3f (130, 650, 0);
glEnd();
//object flower4 reflection
glColor3ub (255,213,79);
glBegin(GL_POLYGON);
glVertex3f (150, 690, 0);
glVertex3f (140, 740, 0);
glVertex3f (130, 690, 0);
glEnd();
//object flower2 reflection
glColor3ub (129,199,132);
glBegin(GL_POLYGON);
glVertex3f (130, 690, 0);
glVertex3f (100, 670, 0);
glVertex3f (130, 650, 0);
glEnd();

//object flower3 reflection
glColor3ub (2,136,209);
glBegin(GL_POLYGON);
glVertex3f (150, 690, 0);
glVertex3f (180, 670, 0);
glVertex3f (150, 650, 0);
glEnd();


//object flower5 - reflection
glColor3ub (206,140,216);
glBegin(GL_POLYGON);
glVertex3f (150, 690, 0);
glVertex3f (130, 690, 0);
glVertex3f (130, 650, 0);
glVertex3f (150, 650, 0);
glEnd();

//object flower stand reflection
glColor3ub (165,214,167);
glBegin(GL_POLYGON);
glVertex3f (137, 655, 0);
glVertex3f (143, 655, 0);
glVertex3f (143, 570, 0);
glVertex3f (137, 570, 0);
glEnd();


//dressing table glass frame-bottom
glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (190, 470, 0);
glVertex3f (48, 427, 0);
glVertex3f (48, 442, 0);
glVertex3f (190, 485, 0);
glEnd();

//object
glColor3ub (117,117,117);
glBegin(GL_POLYGON);
glVertex3f (170, 450, 0);
glVertex3f (190, 455, 0);
glVertex3f (200, 575, 0);
glVertex3f (160, 570, 0);
glEnd();

//object flower stand
glColor3ub (76,175,80);
glBegin(GL_POLYGON);
glVertex3f (177, 650, 0);
glVertex3f (183, 650, 0);
glVertex3f (183, 570, 0);
glVertex3f (177, 570, 0);
glEnd();

//object flower1
glColor3ub (244,67,54);
glBegin(GL_POLYGON);
glVertex3f (180, 600, 0);
glVertex3f (190, 650, 0);
glVertex3f (170, 650, 0);
glEnd();

//object flower2
glColor3ub (27,94,32);
glBegin(GL_POLYGON);
glVertex3f (170, 690, 0);
glVertex3f (140, 670, 0);
glVertex3f (170, 650, 0);
glEnd();

//object flower3
glColor3ub (2,136,209);
glBegin(GL_POLYGON);
glVertex3f (190, 690, 0);
glVertex3f (220, 670, 0);
glVertex3f (190, 650, 0);
glEnd();

//object flower4
glColor3ub (251,140,0);
glBegin(GL_POLYGON);
glVertex3f (190, 690, 0);
glVertex3f (180, 740, 0);
glVertex3f (170, 690, 0);
glEnd();

//object flower5
glColor3ub (123,31,62);
glBegin(GL_POLYGON);
glVertex3f (190, 690, 0);
glVertex3f (170, 690, 0);
glVertex3f (170, 650, 0);
glVertex3f (190, 650, 0);
glEnd();

///Start




//bed
//bed head
glColor3ub (77,40,26);
glBegin(GL_POLYGON);
glVertex3f (550, 600, 0);
glVertex3f (810, 550, 0);
glVertex3f (810, 250, 0);
glVertex3f (550, 300, 0);
glEnd();

//bed leg
glColor3ub (88,40,19);
glBegin(GL_POLYGON);
glVertex3f (250, 200, 0);
glVertex3f (550, 150, 0);
glVertex3f (550, 50, 0);
glVertex3f (250, 100, 0);
glEnd();


//bed right side
glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (850, 250, 0);
glVertex3f (550, 50, 0);
glVertex3f (550, 150, 0);
glVertex3f (850, 350, 0);
glEnd();

//bed right side - box left
glColor3ub (77,40,26);
glBegin(GL_POLYGON);
glVertex3f (695, 160, 0);
glVertex3f (555, 65, 0);
glVertex3f (555, 140, 0);
glVertex3f (695, 235, 0);
glEnd();

//bed right side - box left - handle

glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (650, 160, 0);
glVertex3f (600, 125, 0);
glVertex3f (600, 140, 0);
glVertex3f (650, 175, 0);
glEnd();

//bed right side - 2nd box
glColor3ub (77,40,26);
glBegin(GL_POLYGON);
glVertex3f (845, 260, 0);
glVertex3f (705, 165, 0);
glVertex3f (705, 240, 0);
glVertex3f (845, 335, 0);
glEnd();

//bed right side - 2nd box - handle

glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (800, 260, 0);
glVertex3f (750, 225, 0);
glVertex3f (750, 240, 0);
glVertex3f (800, 275, 0);
glEnd();

//bed rig
//bed top right
glColor3ub (198,40,40);
glBegin(GL_POLYGON);
glVertex3f (550, 150, 0);
glVertex3f (850, 350, 0);
glVertex3f (850, 400, 0);
glVertex3f (550, 200, 0);
glEnd();

//bed leg left
glColor3ub (177,160,140);
glBegin(GL_POLYGON);
glVertex3f (250, 200, 0);
glVertex3f (250, 250, 0);
glVertex3f (550, 450, 0);
glVertex3f (550, 400, 0);

glEnd();

//bed leg top
glColor3ub (183,28,28);
glBegin(GL_POLYGON);
glVertex3f (250, 200, 0);
glVertex3f (550, 150, 0);
glVertex3f (550, 200, 0);
glVertex3f (250, 250, 0);
glEnd();

//bed sheet
glColor3ub (222,6,55);
glBegin(GL_POLYGON);
glVertex3f (550, 200, 0.0);
glVertex3f (250, 250, 0.0);
glVertex3f (550, 450, 0.0);
glVertex3f (850, 400, 0.0);
glEnd();

//bed pillo

//bed pillo - left
glColor3ub (255,245,157);
glBegin(GL_POLYGON);
glVertex3f (604, 375, 0.0);
glVertex3f (500, 395, 0.0);
glVertex3f (550, 435, 0.0);
glVertex3f (655, 415, 0.0);
glEnd();


//bed pillo - left - side
glColor3ub (255,145,0);
glBegin(GL_POLYGON);
glVertex3f (604, 375, 0.0);
glVertex3f (655, 415, 0.0);
glVertex3f (655, 405, 0.0);
glVertex3f (604, 365, 0.0);
glEnd();

//bed pillo - left - bottom
glColor3ub (255,145,0);
glBegin(GL_POLYGON);
glVertex3f (604, 375, 0.0);
glVertex3f (500, 395, 0.0);
glVertex3f (500, 385, 0.0);
glVertex3f (604, 365, 0.0);
glEnd();

//bed pillo right
glColor3ub (222,231,215);
glBegin(GL_POLYGON);
glVertex3f (737, 360, 0.0);
glVertex3f (624, 375, 0.0);
glVertex3f (675, 410, 0.0);
glVertex3f (790, 390, 0.0);
glEnd();
//bed pillo right-side
glColor3ub (255,145,0);
glBegin(GL_POLYGON);
glVertex3f (737, 360, 0.0);
glVertex3f (790, 390, 0.0);
glVertex3f (790, 380, 0.0);
glVertex3f (737, 350, 0.0);
glEnd();

//bed pillo bottom
glColor3ub (255,145,0);
glBegin(GL_POLYGON);
glVertex3f (737, 360, 0.0);
glVertex3f (624, 375, 0.0);
glVertex3f (624, 365, 0.0);
glVertex3f (737, 350, 0.0);
glEnd();

//bed blanket
glColor3ub (119,53,177);
glBegin(GL_POLYGON);
glVertex3f (550, 220, 0.0);
glVertex3f (280, 260, 0.0);
glVertex3f (400, 340, 0.0);
glVertex3f (670, 300, 0.0);
glEnd();




///END













//window right
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (1000, 500, 0);
glVertex3f (900, 500, 0);
glVertex3f (900, 900,0);
glVertex3f (1000,900, 0);
glEnd();
//window right-inner bottom
glColor3ub (105,87,62);
glBegin(GL_POLYGON);
glVertex3f (1000, 500, 0);
glVertex3f (900, 500, 0);
glVertex3f (910, 510,0);
glVertex3f (1000,510, 0);
glEnd();
//window right-inner left
glColor3ub (131,102,92);
glBegin(GL_POLYGON);
glVertex3f (900, 900, 0);
glVertex3f (910, 890, 0);
glVertex3f (910, 510,0);
glVertex3f (900,500, 0);
glEnd();

//window right-inner top
glColor3ub (102,87,62);
glBegin(GL_POLYGON);
glVertex3f (900, 900, 0);
glVertex3f (910, 890, 0);
glVertex3f (1000, 890,0);
glVertex3f (1000,900, 0);
glEnd();

//window right grill bottom-vertical
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (905, 600, 0);
glVertex3f (1000, 600, 0);
glVertex3f (1000, 610,0);
glVertex3f (905,610, 0);
glEnd();

//window right grill middle-vertical
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (905, 700, 0);
glVertex3f (1000, 700, 0);
glVertex3f (1000, 710,0);
glVertex3f (905,710, 0);
glEnd();

//window right grill top-vertical
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (905, 800, 0);
glVertex3f (1000, 800, 0);
glVertex3f (1000, 810,0);
glVertex3f (905,810, 0);
glEnd();

//window right grill bottom-horizontal
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (965, 505, 0);
glVertex3f (965, 895, 0);
glVertex3f (970, 895,0);
glVertex3f (970,505, 0);
glEnd();





glPushMatrix();
glTranslated(350,-100,0);
glScaled(12,14,1);

///human start
         //body
         //glColor3f(1,0,1);
       //glColor3ub(91,115,15);
       glColor3ub(0, 38, 77);
         glBegin(GL_POLYGON);
         glVertex2d(30,24);
         glVertex2d(30.4,23);
         glVertex2d(31,21);
         glVertex2d(32,20);
         glVertex2d(33,18.5);
         glVertex2d(33.4,18);
         glVertex2d(33.4,17.7);
         glVertex2d(33,17.3);//
         glVertex2d(32,17);
         glVertex2d(24,17);
         glVertex2d(23,17.2);
         glVertex2d(22,17.5);
         glVertex2d(21,18.1);
         glVertex2d(20,19.7);
         glVertex2d(19,21.2);
         glVertex2d(18,24);
         glVertex2d(17.3,27);
         glVertex2d(17.1,27.4);
         glVertex2d(17.5,30);
         glVertex2d(17.8,31);
         glVertex2d(18,32.1);//
         glVertex2d(19,35);
         glVertex2d(27,31);
         glVertex2d(29,29);
         glVertex2d(29.1,27);
         glVertex2d(29.2,26);
         glVertex2d(29.4,25);
         glEnd();
         glBegin(GL_POLYGON);
         glVertex2d(30,32.3);
         glVertex2d(30,35);
         glVertex2d(29.7,36);
         glVertex2d(29.3,37);
         glVertex2d(29,38);
         glVertex2d(28.4,39);
         glVertex2d(28,40);
         glVertex2d(27.4,40.3);
         glVertex2d(25.3,41.8);
         glVertex2d(25,42);
         glVertex2d(23.3,42.1);
         glVertex2d(22.4,40.4);
         glEnd();
        glBegin(GL_POLYGON);
         glVertex2d(22.4,40.4);
         glVertex2d(22,40.9);
         glVertex2d(20,39);
         glVertex2d(19.4,38);
         glVertex2d(19.5,37.3);
         glVertex2d(18,37);
         glVertex2d(18,36);
         glVertex2d(19,35);
         glVertex2d(29,29);
         glVertex2d(30,32.3);
         glEnd();
         //neck
         glColor3ub(255, 219, 155);
         glBegin(GL_QUADS);
         glVertex2d(28.2,42);
         glVertex2d(27.4,40.3);
         glVertex2d(25.3,41.8);
         glVertex2d(26.7,43.1);
         glEnd();
         //FACE
         glColor3ub(255, 219, 155);
         glBegin(GL_POLYGON);
         glVertex2d(28.2,42);
         glVertex2d(30,41);
         glVertex2d(31,40.8);
         glVertex2d(31.7,41);
         glVertex2d(31.9,41.3);
         glVertex2d(31.8,42.2);
         glVertex2d(32,42.8);
         glVertex2d(32.3,43.6);
         glVertex2d(32.9,44.7);
         glVertex2d(33.7,45.3);
         glVertex2d(33.9,46.2);
         glVertex2d(33.7,47);
         glVertex2d(33.6,48);
         glVertex2d(32,52);
         glVertex2d(27,48);
         glVertex2d(26.7,43.1);
         glEnd();

         //hair
         glColor3f(0,0,0);
         glBegin(GL_POLYGON);
         glVertex2d(26,50.3);
         glVertex2d(24.5,46.7);
         glVertex2d(25.5,47.4);
         glVertex2d(24.8,45.2);
         glVertex2d(26.1,46.1);
         glVertex2d(24.3,43.2);
         glVertex2d(26.2,44.1);
         glVertex2d(26.9,42);
         glVertex2d(27.4,43);
         glVertex2d(28.2,42.2);
         glVertex2d(28.4,43.3);
         glVertex2d(29,43);
         glVertex2d(28.7,44.6);
         glVertex2d(29.2,44);
         glVertex2d(28.9,45.7);
         glVertex2d(30,45);
         glVertex2d(28.8,46.2);
         glVertex2d(29.8,45.3);
         glVertex2d(29.2,47);
         glVertex2d(29.7,47.9);
         glVertex2d(30,48);
         glVertex2d(31.2,48);
         glVertex2d(32.2,46.2);
         glVertex2d(32.3,48.9);
         glVertex2d(34.3,47.1);
         glVertex2d(34,49.7);
         glVertex2d(35.1,48.1);
         glVertex2d(34.9,50);
         glVertex2d(34.5,51);
         glVertex2d(34,52);
         glVertex2d(33,53);
         glVertex2d(32,53.5);
         glVertex2d(31,53.7);
         glVertex2d(30,53.5);
         glVertex2d(29,53.2);
         glVertex2d(28,52.8);
         glVertex2d(27,52);
         glEnd();
         glBegin(GL_POLYGON);
         glVertex2d(30,48);
         glVertex2d(30.3,47);
         glVertex2d(30.2,46);
         glVertex2d(30.1,45);
         glVertex2d(29.8,44);
         glVertex2d(30.8,45);
         glVertex2d(31.1,46);
         glVertex2d(31.1,47);
         glVertex2d(31.2,48);
         glEnd();
         //eye
         glBegin(GL_POLYGON);
         glVertex2d(31.8,45.6);
         glVertex2d(32.3,45.5);
         glVertex2d(32.8,45.4);
         glVertex2d(32.7,45.7);
         glVertex2d(32.4,45.9);
         glEnd();
         glBegin(GL_POLYGON);
         for(int i=0;i<1000;++i)
         glVertex2f(cos(2*3.14159*i/1000.0)*0.2+32.2,sin(2*3.14159*i/1000.0)*0.2+45);
         glEnd();
         //lip
         glColor3ub(255, 219, 155);
         glBegin(GL_TRIANGLES);
         glVertex2d(31.6,42.2);
         glVertex2d(32.2,42.4);
         glVertex2d(32,42.8);

         glVertex2d(32,42.8);
         glVertex2d(32.4,43);
         glVertex2d(32.3,43.6);
         //NOSE
         glColor3ub(255, 219, 155);
         glVertex2d(32.3,43.6);
         glVertex2d(33.4,43.3);
         glVertex2d(32.2,44.9);
         glEnd();

         //chair
         glColor3f(0,0,0);
         glBegin(GL_POLYGON);
         glVertex2d(16,18);
         glVertex2d(16.2,17);
         glVertex2d(16.5,16.5);
         glVertex2d(16.9,16);
         glVertex2d(18.1,15.3);
         glVertex2d(19.2,15);
         glVertex2d(32.5,15);
         glVertex2d(32.5,17);
         glVertex2d(24,17);
         glVertex2d(23,17.2);
         glVertex2d(22,17.5);
         glVertex2d(21,18.1);
         glVertex2d(20,19.7);
         glEnd();
         glBegin(GL_POLYGON);
         glVertex2d(20,19.7);
         glVertex2d(19,21.2);
         glVertex2d(18,24);
         glVertex2d(17.2,27.2);
         glVertex2d(16,25);
         glVertex2d(16,18);
         glEnd();
         glBegin(GL_POLYGON);
         glVertex2d(17.2,27);
         glVertex2d(17.5,30);
         glVertex2d(17.8,31);
         glVertex2d(18,32.1);
         glVertex2d(18,33);
         glVertex2d(17,34.6);
         glVertex2d(16.2,35);
         glVertex2d(15.6,34.5);
         glVertex2d(15,33);
         glVertex2d(15.3,30);
         glVertex2d(16,18);
         glEnd();
         //chair leg
         glBegin(GL_QUADS);
         glVertex2d(21,15);
         glVertex2d(21.4,9);
         glVertex2d(20.4,9);
         glVertex2d(20,15);
         glEnd();
         glBegin(GL_QUADS);
         glVertex2d(18.1,15.3);
         glVertex2d(17.3,7);
         glVertex2d(16.3,7);
         glVertex2d(17,16);
         glEnd();
///human end

glPopMatrix();



///table
glPushMatrix();
glTranslated(-1200,-720,0);
glScaled(2.25,2.25,1);
//bed side box front
glColor3ub (60,23,9);
glBegin(GL_POLYGON);
glVertex3f (960, 410,0);
glVertex3f (960, 120,0);
glVertex3f (830, 135,0);
glVertex3f (830, 415, 0);
glVertex3f (820, 435,0);
glVertex3f (970, 435, 0);
glEnd();

//bed side box front - box bottom
glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (955, 260,0);
glVertex3f (955, 130,0);
glVertex3f (835, 145,0);
glVertex3f (835, 270, 0);
glEnd();

//bed side box front - box bottom - handel
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (907, 200,0);
glVertex3f (907, 190,0);
glVertex3f (883, 190,0);
glVertex3f (883, 200, 0);
glEnd();

//bed side box front - box top
glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (955, 265,0);
glVertex3f (955, 400,0);
glVertex3f (835, 405,0);
glVertex3f (835, 275, 0);
glEnd();

//bed side box front - box top - handel
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (907, 337.5,0);
glVertex3f (907, 327.5,0);
glVertex3f (883, 327.5,0);
glVertex3f (883, 337.5, 0);
glEnd();
//bed side box side
glColor3ub (113,55,34);
glBegin(GL_POLYGON);
glVertex3f (970, 435,0);
glVertex3f (960, 410, 0);
glVertex3f (960, 120,0);
glVertex3f (985, 140, 0);
glVertex3f (985, 430, 0);
glVertex3f (995, 460, 0);
glEnd();

//bed side box top
glColor3ub (192,99,82);
glBegin(GL_POLYGON);
glVertex3f (820, 435,0);
glVertex3f (970, 435,0);
glVertex3f (995+30+20, 480+20,0);
glVertex3f (845+30+20, 480+20,0);
glEnd();
glPopMatrix();
///table end


glPushMatrix();
//glTranslated(85,-55,0);
glTranslated(-20,-20,0);
//bed side box lamp base
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (875, 440,0);
glVertex3f (915, 440,0);
glVertex3f (910, 450,0);
glVertex3f (890, 450,0);
glEnd();

//bed side box lamp stand
glColor3ub (77,49,26);
glBegin(GL_POLYGON);
glVertex3f (895, 445,0);
glVertex3f (905, 445,0);
glVertex3f (905, 550,0);
glVertex3f (895, 550,0);
glEnd();

//bed side box lamp stand
glColor3ub (244,67,59);
glBegin(GL_POLYGON);
glVertex3f (875, 650,0);
glVertex3f (925, 650,0);
glVertex3f (935, 550,0);
glVertex3f (865, 550,0);
glEnd();
glPopMatrix();


///desktop pc
    glPushMatrix();
    glTranslated(725,280,0);
    glScaled(3,3.5,0);
    ///mouse
    glColor3f(.11, .9, 1);
    glPushMatrix();
    glTranslated(35,-8,0);
    glRotated(-60,0,0,1);
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*4-10,sin(2*3.14159*i/1000.0)*6+12);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(-10,12);
    glVertex2d(-10,18);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2d(-14,12);
    glVertex2d(-6,12);
    glEnd();
    glPopMatrix();
    ///mouse end



    ///monitor
    glColor3f(0.7, 0.8, 0.709);
    glBegin(GL_POLYGON);
    glVertex2d(60,29);
    glVertex2d(66,29);
    glVertex2d(67,24);
    glVertex2d(60.4,24);
    glEnd();
    glColor3f(0.55, 0.635, 0.60);
    glBegin(GL_POLYGON);
    glVertex2d(67,24);
    glVertex2d(60.4,24);
    glVertex2d(55,23);
    glVertex2d(51,20);
    glVertex2d(57,19);
    glVertex2d(67,19);
    glVertex2d(70,20);
    glVertex2d(70.3,20.3);
    glEnd();

    glColor3f(0.7, 0.8, 0.709);
    glBegin(GL_POLYGON);
    glVertex2d(42,29);
    glVertex2d(42,58);
    glVertex2d(87,63);
    glVertex2d(86,27);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
     // glColor3f(0.564, 0.6, 0.619);
   // glColor3ub(255,240,240);
    glBegin(GL_POLYGON);
    glVertex2d(43,30);
    glVertex2d(43,57);
    glVertex2d(85.5,61.7);
    glVertex2d(84.5,28.7);
    glEnd();
    ///monitor end
glPopMatrix();
///pc end


///keyboard

glPushMatrix();
glTranslated(520,-580,0);
glScaled(.25,2,0);


glColor3ub (0, 0, 0);
glBegin(GL_POLYGON);
glVertex3f (818, 433,0);
glVertex3f (968, 433,0);
glVertex3f (995+300-2, 480-2,0);
glVertex3f (845+300-2, 480-2,0);
glEnd();

glColor3ub (63, 182, 191);
glBegin(GL_POLYGON);
glVertex3f (820, 435,0);
glVertex3f (970, 435,0);
glVertex3f (995+300, 480,0);
glVertex3f (845+300, 480,0);
glEnd();
glPopMatrix();

///keyboard end


///human hand 2
glPushMatrix();
glTranslated(480,-135,0);

glScaled(7,18,1);

        //HAND
         glColor3ub(234, 201, 144);
         glBegin(GL_POLYGON);
         glVertex2d(32.2,30);
         glVertex2d(35.3,29);
         glVertex2d(40,28.1);
         glVertex2d(41,28);
         glVertex2d(42,27.7);
         glVertex2d(42.3,27.5);
         glVertex2d(42.1,26.5);
         glVertex2d(41,26.5);
         glVertex2d(39,26.7);
         glVertex2d(37,26.8);
         glVertex2d(35,26.9);
         glVertex2d(33,27);
         glVertex2d(31.7,27);
         glEnd();
         //finger
         glBegin(GL_POLYGON);
         glVertex2d(42,26.5);
         glVertex2d(42.8,26.2);
         glVertex2d(44.1,27);
         glVertex2d(44.4,28.1);
         glVertex2d(42.2,27.5);
         glEnd();

         glBegin(GL_POLYGON);
         glVertex2d(44.1,27);
         //glVertex2d(44.9,26.4+mv);
         glVertex2d(45.3,26.2+mv);
         glVertex2d(46,26.1+mv);
         glVertex2d(46.2,26.2+mv);
         glVertex2d(44.4,28.1);
         glEnd();

glPopMatrix();
///human hand 2 end



///human hand 1
glPushMatrix();
glTranslated(400,-175,0);
glScaled(10,18,1);

        //HAND
         glColor3ub(255, 219, 155);
         glBegin(GL_QUADS);
         glVertex2d(32.2,30);
         glVertex2d(31.7,27);
         glVertex2d(29,29);
         glVertex2d(30,32.3);
         glEnd();
         glBegin(GL_POLYGON);
         glVertex2d(32.2,30);
         glVertex2d(35.3,29);
         glVertex2d(40,28.1);
         glVertex2d(41,28);
         glVertex2d(42,27.7);
         glVertex2d(42.3,27.5);
         glVertex2d(42.1,26.5);
         glVertex2d(41,26.5);
         glVertex2d(39,26.7);
         glVertex2d(37,26.8);
         glVertex2d(35,26.9);
         glVertex2d(33,27);
         glVertex2d(31.7,27);
         glEnd();
         //finger
         glColor3ub(255, 219, 155);
         glBegin(GL_POLYGON);
         glVertex2d(42,26.5);
         glVertex2d(42.8,26.2);
         glVertex2d(44.1,27);
         glVertex2d(44.4,28.1);
         glVertex2d(42.2,27.5);
         glEnd();

         glBegin(GL_POLYGON);
         glVertex2d(44.1,27);
         //glVertex2d(44.9,26.4+mv);
         glVertex2d(45.3,26.2+mv1);
         glVertex2d(46,26.1+mv1);
         glVertex2d(46.2,26.2+mv1);
         glVertex2d(44.4,28.1);
         glEnd();

glPopMatrix();
///human hand 1 end

if(mv<1)
    mv+=.009;
else mv=0;


if(mv1<1)
    mv1+=.003;
else mv1=0;

glColor3ub(240,0,0);
render5BitmapString(925,475,"|Compile|");

glColor3ub(240,0,0);
render5BitmapString(960,477,"|Run|");

glPushMatrix();



glColor3ub(232,213,212);
render5BitmapString(855,460+tmx,"#include<stdio.h>");

glColor3ub(232,213,212);
render5BitmapString(860,450+tmx,"int main () {");
glColor3ub(232,213,212);
render5BitmapString(860,435+tmx,"Printf (' Hello World ');");
glColor3ub(232,213,212);
render5BitmapString(860,415+tmx,"Printf (' TUTUL_191 ');");

glColor3ub(232,213,212);
render5BitmapString(865,400+tmx,"return 0;");
glColor3ub(232,213,212);
render5BitmapString(860,390,"}");

glPopMatrix();

if(tmx<15)
    tmx+=.03;
else tmx=3;






glFlush ();
}
void init (void)
{

glClearColor (0.0, 0.0, 0.0, 0.0);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1000, 0.0, 1000.0, -1000, 1000.0);


PlaySound("tone.wav",NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1200, 650);
glutInitWindowPosition (10, 10);
glutCreateWindow ("Programmer Life");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}


