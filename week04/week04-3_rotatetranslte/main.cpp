#include <GL/glut.h>

float angle=0;

void display()
{
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

     glPushMatrix();
        glTranslatef(0.5,0,0);///移動到哪
        glRotatef(angle,0,1,0);///旋轉中的
        glColor3f(0,0,1);///顏色
        glutSolidTeapot(0.3);
    glPopMatrix();

    glPushMatrix();
        glRotatef(angle,0,1,0);///旋轉中的
        glTranslatef(0.5,0,0);///移動到哪
        glColor3f(1,1,0);///顏色
        glTranslatef(0,0.55,0);
        glutSolidTeapot(0.3);
    glPopMatrix();

    glutSwapBuffers();
    angle++;

}



int main(int argc,char* argv[])
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();

}

