#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include<stdio.h>


GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
GLboolean bRotate = false, uRotate = false;

float ex=2,ey=2,ez=9,lx=2,ly=2,lz=8;

GLfloat ambient[]    = { 0.2f, 0.2f, 0.2f, 1.0f  };
GLfloat diffuse[]    = { 0.8, 0.8, 0.8, 1.0};
GLfloat specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat shininess[] = { 3.0f };
bool ambient_on = true;
bool specular_on = true;
bool diffuse_on = true;

bool light_1_on = true;

float linear_attenuation = 0.01f;
float constant_attenuation = 2.0f;

GLfloat light_position[] = { 1.0,1.5,1.0, 1.0 };
GLfloat mat_zero[] = {0.0f, 0.0f, 0.0f, 1.0};

void set_material(GLfloat* ambient_col, GLfloat* diffuse_col, GLfloat* specular_col, GLfloat* shininess)
{
    if (ambient_on == true)
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_col);
    else
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_zero);

    if (diffuse_on == true)
        glMaterialfv(GL_FRONT, GL_DIFFUSE,  diffuse_col);
    else
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_zero);

    if (specular_on == true)
        glMaterialfv(GL_FRONT, GL_SPECULAR,  specular_col);
    else
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_zero);

        glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

}
bool a11=true,d11=true,s11=true;
bool a12=true,d12=true,s12=true;
bool a21=true,d21=true,s21=true;
bool a22=true,d22=true,s22=true;

void setLight11(int light_id, bool light_on, GLfloat* ambient, GLfloat* diffuse, GLfloat* specular, GLfloat* position)
{
    int id;
    if (light_id == 0)
        id = GL_LIGHT0;

    if (light_on == true)
        glEnable(id);
    else
        glDisable(id);

    if (a11 == true)
        glLightfv(id, GL_AMBIENT,  ambient);
    else
        glLightfv(id, GL_AMBIENT,  mat_zero);

    if (d11 == true)
        glLightfv(id, GL_DIFFUSE,  diffuse);
    else
        glLightfv(id, GL_DIFFUSE,  mat_zero);

    if (s11 == true)
        glLightfv(id, GL_SPECULAR, specular);
    else
        glLightfv(id, GL_SPECULAR, mat_zero);

    glLightfv(id, GL_POSITION, position);

    glLightf(id, GL_LINEAR_ATTENUATION, linear_attenuation );
    glLightf(id,GL_CONSTANT_ATTENUATION, constant_attenuation);
}

void setLight21(int light_id, bool light_on, GLfloat* ambient, GLfloat* diffuse, GLfloat* specular, GLfloat* position)
{
    int id;
    if (light_id == 0)
        id = GL_LIGHT0;

    if (light_on == true)
        glEnable(id);
    else
        glDisable(id);

    if (a21 == true)
        glLightfv(id, GL_AMBIENT,  ambient);
    else
        glLightfv(id, GL_AMBIENT,  mat_zero);

    if (d21 == true)
        glLightfv(id, GL_DIFFUSE,  diffuse);
    else
        glLightfv(id, GL_DIFFUSE,  mat_zero);

    if (s21 == true)
        glLightfv(id, GL_SPECULAR, specular);
    else
        glLightfv(id, GL_SPECULAR, mat_zero);

    glLightfv(id, GL_POSITION, position);

    glLightf(id, GL_LINEAR_ATTENUATION, linear_attenuation );
    glLightf(id,GL_CONSTANT_ATTENUATION, constant_attenuation);
}


void setLight12(int light_id, bool light_on, GLfloat* ambient, GLfloat* diffuse, GLfloat* specular, GLfloat* position)
{
    int id;
    if (light_id == 0)
        id = GL_LIGHT0;

    if (light_on == true)
        glEnable(id);
    else
        glDisable(id);

    if (a12 == true)
        glLightfv(id, GL_AMBIENT,  ambient);
    else
        glLightfv(id, GL_AMBIENT,  mat_zero);

    if (d12 == true)
        glLightfv(id, GL_DIFFUSE,  diffuse);
    else
        glLightfv(id, GL_DIFFUSE,  mat_zero);

    if (s12 == true)
        glLightfv(id, GL_SPECULAR, specular);
    else
        glLightfv(id, GL_SPECULAR, mat_zero);

    glLightfv(id, GL_POSITION, position);

    glLightf(id, GL_LINEAR_ATTENUATION, linear_attenuation );
    glLightf(id,GL_CONSTANT_ATTENUATION, constant_attenuation);
}


void setLight22(int light_id, bool light_on, GLfloat* ambient, GLfloat* diffuse, GLfloat* specular, GLfloat* position)
{
    int id;
    if (light_id == 0)
        id = GL_LIGHT0;

    if (light_on == true)
        glEnable(id);
    else
        glDisable(id);

    if (a22 == true)
        glLightfv(id, GL_AMBIENT,  ambient);
    else
        glLightfv(id, GL_AMBIENT,  mat_zero);

    if (d22 == true)
        glLightfv(id, GL_DIFFUSE,  diffuse);
    else
        glLightfv(id, GL_DIFFUSE,  mat_zero);

    if (s22 == true)
        glLightfv(id, GL_SPECULAR, specular);
    else
        glLightfv(id, GL_SPECULAR, mat_zero);

    glLightfv(id, GL_POSITION, position);

    glLightf(id, GL_LINEAR_ATTENUATION, linear_attenuation );
    glLightf(id,GL_CONSTANT_ATTENUATION, constant_attenuation);
}

void drawRoom(float x, float y , float z)
{
    glPushMatrix();
    //glColor4f(0,0.5,0.2,1);
        GLfloat diffuse7[] = {0,0.5,0.2,1};
    set_material(ambient,diffuse7,specular,shininess);
    glTranslatef(x+2.5,y+0.025,z+2.5);
    glScalef(5,0.05*9,5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(0.498039, 1,0,1);
        GLfloat diffuse8[] = {0.498039, 1,0,1};
    set_material(ambient,diffuse8,specular,shininess);
    glTranslatef(x+0.025,y+1.5,z+2.5);
    glScalef(0.05,3,5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(1, 0.843137, 0,1);
        GLfloat diffuse9[] = {1, 0.843137, 0,1};
    set_material(ambient,diffuse9,specular,shininess);
    glTranslatef(x+2.5,y+1.5,z+0.025);
    glScalef(5,3,0.05);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(1, 0.270588, 0,1);
        GLfloat diffuse10[] = {1, 0.270588, 0,1};
    set_material(ambient,diffuse10,specular,shininess);
    glTranslatef(x+2.5,y+3.025,z+2.5);
    glScalef(5,0.05,5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(0.4, 0.803922, 0.666667,1);
        GLfloat diffuse11[] = {0.4, 0.803922, 0.666667,1};
    set_material(ambient,diffuse11,specular,shininess);
    glTranslatef(x+4.95,y+1.5,z+2.5);
    glScalef(0.05,3,5);
    glutSolidCube(1);
    glPopMatrix();

}

void drawSofa(float x, float y , float z)
{
    glPushMatrix();
    //glColor4f(0.662745, 0.662745, 0.662745,1);
    GLfloat diffuse1[] = {0.662745, 0.662745, 0.662745,1};
    set_material(ambient,diffuse1,specular,shininess);
    glTranslatef(x,y+.5,z);
    glScalef(.6,0.25,1.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(0,0.5,0.2,1);
    GLfloat diffuse2[] = {0,0.5,0.2,1};
    set_material(ambient,diffuse2,specular,shininess);
    glTranslatef(x,y+.4,z);
    glScalef(.65,0.1,1.1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(1, 0.388235, 0.278431,1);
    GLfloat diffuse3[] = {1, 0.388235, 0.278431,1};
    set_material(ambient,diffuse3,specular,shininess);
    glTranslatef(x,y+.7,z-.7);
    glScalef(.6,0.2,0.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(1, 0.388235, 0.278431,1);
    GLfloat diffuse4[] = {0.388235, 0.278431,1};
    set_material(ambient,diffuse4,specular,shininess);
    glTranslatef(x,y+.7,z+.71);
    glScalef(.6,0.2,0.1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(0.690196, 0.188235, 0.376471,1);
    GLfloat diffuse5[] = {0.690196, 0.188235, 0.376471,1};
    set_material(ambient,diffuse5,specular,shininess);
    glTranslatef(x-.2,y+.8,z);
    glScalef(.2,.30,1.5);
    glutSolidCube(1);
    glPopMatrix();
}


void table(float x, float y, float z)
{
    glPushMatrix();
    //glColor4f(0.729412, 0.333333, 0.827451,1);
    GLfloat diffuse5[] = {0.729412, 0.333333, 0.827451,1};
    set_material(ambient,diffuse5,specular,shininess);
    glTranslatef(x,y+1,z+1);
    glScalef(1.5,.10,1.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(0.333333,0.333333,0.333333,1);
    GLfloat diffuse6[] = {0.333333,0.333333,0.333333,1};
    set_material(ambient,diffuse6,specular,shininess);
    glTranslatef(x-.5,y+.5,z+.1);
    glScalef(0.1,1.0,0.1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(0.333333,0.333333,0.333333,1);
    //GLfloat diffuse5[] = {0.333333,0.333333,0.333333,1};
    set_material(ambient,diffuse6,specular,shininess);
    glTranslatef(x+.5,y+.5,z+.1);
    glScalef(0.1,1.0,0.1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(0.333333,0.333333,0.333333,1);
    //GLfloat diffuse5[] = {0.333333,0.333333,0.333333,1};
    set_material(ambient,diffuse6,specular,shininess);
    glTranslatef(x-.5,y+.5,z+1.7);
    glScalef(0.1,1.0,0.1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(0.333333,0.333333,0.333333,1);
    //GLfloat diffuse5[] = {0.333333,0.333333,0.333333,1};
    set_material(ambient,diffuse6,specular,shininess);
    glTranslatef(x+.5,y+.5,z+1.7);
    glScalef(0.1,1.0,0.1);
    glutSolidCube(1);
    glPopMatrix();
}


void circle(double radius)
{
    int i;
    glBegin(GL_TRIANGLE_FAN);
    for(i = 0; i <= 360; i++)
    {
        //glColor3f(1, 0, 0);
        GLfloat diffuse5[] = {1, 0, 0,1};
        set_material(ambient,diffuse5,specular,shininess);
        glVertex2f((radius * cos(i *  3.1416 / 180)),
                   (radius * sin(i * 3.1416 / 180)));
    }
    glEnd();
}


void shahidMinar(float x,float y,float z)
{
    glPushMatrix();
    //glColor4f(1,1,1,1);
    GLfloat diffuse1[] = {1,1,1,1};
        set_material(ambient,diffuse1,specular,shininess);
    glTranslatef(x,y+.3,z);
    glScalef(0.15,0.5,0.15);
    glutSolidCube(1);
    glPopMatrix();

    //glRotatef();

    glPushMatrix();
    //glColor4f(1,1,1,1);
    //GLfloat diffuse5[] = {1, 0, 0,1};
        set_material(ambient,diffuse1,specular,shininess);
    glTranslatef(x+.2,y+.5,z);
    glScalef(0.1,0.9,0.15);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(0.333333,0,0.333333,1);
    GLfloat diffuse2[] = {0.333333,0,0.333333,1};
        set_material(ambient,diffuse2,specular,shininess);
    glTranslatef(x+.2,y+1.15,z);
    glRotatef(30,1,0,0);
    glScalef(0.1,0.4,0.15);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(1,1,1,1);
    //GLfloat diffuse5[] = {1, 0, 0,1};
        set_material(ambient,diffuse1,specular,shininess);
    glTranslatef(x+.4,y+.5,z);
    glScalef(0.1,0.9,0.15);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(0.333333,0,0.333333,1);
    //GLfloat diffuse5[] = {1, 0, 0,1};
        set_material(ambient,diffuse2,specular,shininess);
    glTranslatef(x+.4,y+1.15,z);
    glRotatef(30,1,0,0);
    glScalef(0.1,0.4,0.15);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(1,1,1,1);
    //GLfloat diffuse5[] = {1, 0, 0,1};
        set_material(ambient,diffuse1,specular,shininess);
    glTranslatef(x+.6,y+.5,z);
    glScalef(0.1,0.9,0.15);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(0.333333,0,0.333333,1);
    //GLfloat diffuse5[] = {1, 0, 0,1};
        set_material(ambient,diffuse2,specular,shininess);
    glTranslatef(x+.6,y+1.15,z);
    glRotatef(30,1,0,0);
    glScalef(0.1,0.4,0.15);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(1,1,1,1);
    //GLfloat diffuse5[] = {1, 0, 0,1};
        set_material(ambient,diffuse1,specular,shininess);
    glTranslatef(x+.4,y+1.35,z+.15);
    glScalef(.5,0.1,0.15);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(1,1,1,1);
    //GLfloat diffuse5[] = {1, 0, 0,1};
        set_material(ambient,diffuse1,specular,shininess);
    glTranslatef(x+.8,y+.3,z);
    glScalef(0.15,0.5,0.15);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    //glColor4f(1,0,0,1);
    GLfloat diffuse3[] = {1, 0, 0,1};
        set_material(ambient,diffuse3,specular,shininess);
    glTranslatef(x+.4,y+.5,z-0.1);
//    glScalef(0.15,0.5,0.15);
    //  glutSolidCube(1);
    circle(.2);
    glPopMatrix();

}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    gluPerspective(65,1,1,100);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    //set_light(0,true,ambient,diffuse,specular,light_position);
    gluLookAt(ex,ey,ez, lx,ly,lz, 0,1,0);

    glViewport(0,0,400,400);
    glPushMatrix();
    GLfloat d3[] = {1,1,1,1};
    setLight11(0,true,ambient,d3,specular,light_position);
    glRotatef( theta, 1, 0, 0.0 );
    glRotatef( alpha, 0, 1, 0.0 );
    drawRoom(0,0,0);
    drawSofa(1,0,4);
    glTranslated(4,0,4);
    glRotatef(-180, 0, 1, 0 );
    drawSofa(0,0,0);
    glRotatef(180, 0, 1, 0 );
    glTranslated(-4,0,-4);

    table(2.5,0,3);
    shahidMinar(2,1,4);
    glPopMatrix();

    glViewport(400,0,400,400);
    glPushMatrix();
    GLfloat d[] = {1,0,0,1};
    setLight21(0,true,ambient,d,specular,light_position);
    glRotatef( theta, 1, 0, 0.0 );
    glRotatef( alpha, 0, 1, 0.0 );
    drawRoom(0,0,0);
    drawSofa(1,0,4);
    glTranslated(4,0,4);
    glRotatef(-180, 0, 1, 0 );
    drawSofa(0,0,0);
    glRotatef(180, 0, 1, 0 );
    glTranslated(-4,0,-4);

    table(2.5,0,3);
    shahidMinar(2,1,4);
    glPopMatrix();

    glViewport(0,400,400,400);
    glPushMatrix();
    GLfloat d4[] = {0.913725, 0.588235, 0.478431,1};
    setLight12(0,true,ambient,d4,specular,light_position);
    glRotatef( theta, 1, 0, 0.0 );
    glRotatef( alpha, 0, 1, 0.0 );
    drawRoom(0,0,0);
    drawSofa(1,0,4);
    glTranslated(4,0,4);
    glRotatef(-180, 0, 1, 0 );
    drawSofa(0,0,0);
    glRotatef(180, 0, 1, 0 );
    glTranslated(-4,0,-4);

    table(2.5,0,3);
    shahidMinar(2,1,4);
    glPopMatrix();

    glViewport(400,400,400,400);
    glPushMatrix();
    GLfloat d2[] = {1,1,0,1};
    setLight22(0,true,ambient,d2,specular,light_position);
    glRotatef( theta, 1, 0, 0.0 );
    glRotatef( alpha, 0, 1, 0.0 );
    drawRoom(0,0,0);
    drawSofa(1,0,4);
    glTranslated(4,0,4);
    glRotatef(-180, 0, 1, 0 );
    drawSofa(0,0,0);
    glRotatef(180, 0, 1, 0 );
    glTranslated(-4,0,-4);

    table(2.5,0,3);
    shahidMinar(2,1,4);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

float mm,xx,yy,zz;
float cam_angle = 270/180.0f * 3.1416;

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 'j':
        cam_angle = cam_angle - 0.01f;

        lx = ex + cos(cam_angle);
        ly = ey;
        lz = ez + sin(cam_angle);

        break;
    case 'k':
        cam_angle = cam_angle + 0.01f;

        lx = ex + cos(cam_angle);
        ly = ey;
        lz = ez + sin(cam_angle);

        break;

    case 'z':
        ex = ex + cos(cam_angle) * 0.5f;
        ez = ez + sin(cam_angle) * 0.5f;

        lx = ex + cos(cam_angle);
        ly = ey;
        lz = ez + sin(cam_angle);

        break;
    case 'x':
        ex = ex - cos(cam_angle) * 0.5f;
        ez = ez - sin(cam_angle) * 0.5f;

        lx = ex + cos(cam_angle);
        ly = ey;
        lz = ez + sin(cam_angle);
        //printf("%lf   %lf  %lf  %lf  %lf  %lf\n",ex,ey,ez,lx,ly,lz);
        break;

    case 's':
    case 'S':
        bRotate = !bRotate;
        uRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        break;

    case 'r':
    case 'R':
        uRotate = !uRotate;
        bRotate = false;
        axis_x=1.0;
        axis_y=0.0;
        break;
    case '1':
        a11 = !a11;
        break;
    case '2':
        d11 = !d11;
        break;
    case '3':
        s11 = !s11;
        break;
    case '!':
        a21 = !a21;
        break;
    case '@':
        d21 = !d21;
        break;
    case '#':
        s21 = !s21;
        break;
    case '4':
        a12 = !a12;
        break;
    case '5':
        d12 = !d12;
        break;
    case '6':
        s12 = !s12;
        break;
    case '$':
        a22 = !a22;
        break;
    case '%':
        d22 = !d22;
        break;
    case '^':
        s22 = !s22;
        break;
    case '7':
        ambient_on = !ambient_on;
        break;
    case '8':
        diffuse_on = !diffuse_on;
        break;
    case '9':
        specular_on = !specular_on;
        break;
    case 'q':	// Escape key
        exit(1);
    }
}

void animate()
{
    if (bRotate == true)
    {
        theta += 0.2;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
    }

    if (uRotate == true)
    {
        alpha += 0.2;
        if(alpha > 360.0)
            alpha -= 360.0*floor(alpha/360.0);
    }
    glutPostRedisplay();

}
int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(0,0);
    glutInitWindowSize(1200,1200);
    glutCreateWindow("Room and Shahid Minar");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);

    glutKeyboardFunc(myKeyboardFunc);

    glutDisplayFunc(display);

    glutIdleFunc(animate);
    //set_light(0,true,ambient,diffuse,specular,light_position);

    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glutMainLoop();

    return 0;
}
