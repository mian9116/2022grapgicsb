#include <GL/glut.h>
float angle=0,NewAngle=0,OldAngle=0,oldX=0;
void timer(int t)
{
    if(t<100) glutTimerFunc(33,timer,t+1);
    float alpha=t/100.0;
    angle=alpha*NewAngle+(1-alpha)*OldAngle;
    glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y)
{
    glutTimerFunc(0,timer,0);
}

void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN)OldAngle=angle;
    if(state==GLUT_UP)NewAngle=angle;
    oldX=x;
    glutPostRedisplay();
}
void motion(int x,int y)
{
    angle+=x-oldX;
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14");

    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    glutDisplayFunc(display);

    glutMainLoop();
}
