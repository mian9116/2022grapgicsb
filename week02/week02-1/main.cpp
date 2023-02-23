#include <GL/glut.h>

void display()
{
    glColor3f(0,3,0);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glutMainLoop();
}
