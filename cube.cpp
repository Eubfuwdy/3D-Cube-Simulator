#include <GL/glut.h>

// angulos de rotacao
float angleX = 0.0f;
float angleY = 0.0f;

// function initialize from OpenGL
void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// function display
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // rotation apply
    glRotatef(angleX, 1.0f, 0.0f, 0.0f); // rotation about the axis X
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); // rotation about the axis Y

    // pint the cube
    glutWireCube(1.0);


    glutSwapBuffers();
}


// function animation updation
void update(int value) {
    angleX += 2.0f;
    angleY += 3.0f;
    if (angleX > 360) angleX -= 360;
    if (angleY > 360) angleY -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rotation 3D cube");

    init();

    // function callback
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);

    // Start the main GLUT loop
    glutMainLoop();

    return 0;
}