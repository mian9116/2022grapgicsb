#include <GL/glut.h>
float teapotX=0,teapotY=0;

void motion(int x,int y)
{
    teapotX=(x-150/150.0);
    teapotY=(150-y/150.0);
    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrix();
        glTranslatef(teapotX,teapotY,0);
        glutSollidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
    /*
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex2f(1,1);
        glVertex2f(-1,1);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
    glEnd();

    glColor3f(0,1,0);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
    */
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);

    glutMainLoop();
}
