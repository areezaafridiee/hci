#include <GL/glut.h>

void drawCloud(float x, float y, float scale) {
    glColor3f(1.0, 1.0, 1.0); // White clouds
    glBegin(GL_POLYGON);
        glVertex2f(x - 0.8f * scale, y);
        glVertex2f(x - 0.6f * scale, y + 0.4f * scale);
        glVertex2f(x - 0.3f * scale, y + 0.6f * scale);
        glVertex2f(x,               y + 0.5f * scale);
        glVertex2f(x + 0.3f * scale, y + 0.6f * scale);
        glVertex2f(x + 0.6f * scale, y + 0.4f * scale);
        glVertex2f(x + 0.8f * scale, y);
        glVertex2f(x + 0.6f * scale, y - 0.3f * scale);
        glVertex2f(x + 0.3f * scale, y - 0.5f * scale);
        glVertex2f(x,               y - 0.4f * scale);
        glVertex2f(x - 0.3f * scale, y - 0.5f * scale);
        glVertex2f(x - 0.6f * scale, y - 0.3f * scale);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f); // Sky blue

    // ========== SUN ==========
    glColor3f(1.0, 0.9, 0.1); // Bright yellow
    glPushMatrix();
        glTranslatef(450, 330, 0); // Adjusted position
        glutSolidSphere(30, 50, 50);
    glPopMatrix();

    // ========== CLOUDS ==========
    drawCloud(100, 350, 20);  // Left cloud
    drawCloud(250, 330, 25);  // Middle cloud
    drawCloud(400, 360, 22);  // Right cloud

    // ========== GRASS ==========
    glColor3f(0.3, 0.7, 0.3);
    glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(500, 0);
        glVertex2f(500, 100);
        glVertex2f(0, 100);
    glEnd();

    // ========== HOUSE ==========
    glColor3f(0.9, 0.8, 0.7);
    glBegin(GL_POLYGON);
        glVertex2f(200, 100);
        glVertex2f(300, 100);
        glVertex2f(300, 200);
        glVertex2f(200, 200);
    glEnd();

    // Roof
    glColor3f(0.5, 0.2, 0.1);
    glBegin(GL_TRIANGLES);
        glVertex2f(190, 200);
        glVertex2f(250, 250);
        glVertex2f(310, 200);
    glEnd();

    // Door
    glColor3f(0.4, 0.3, 0.2);
    glBegin(GL_POLYGON);
        glVertex2f(235, 100);
        glVertex2f(265, 100);
        glVertex2f(265, 160);
        glVertex2f(235, 160);
    glEnd();

    // Windows
    glColor3f(0.8, 0.9, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(210, 150);
        glVertex2f(230, 150);
        glVertex2f(230, 170);
        glVertex2f(210, 170);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(270, 150);
        glVertex2f(290, 150);
        glVertex2f(290, 170);
        glVertex2f(270, 170);
    glEnd();

    // ========== TREES ==========
    // Left Tree
    glColor3f(0.4, 0.3, 0.2);
    glBegin(GL_POLYGON);
        glVertex2f(100, 100);
        glVertex2f(110, 100);
        glVertex2f(110, 160);
        glVertex2f(100, 160);
    glEnd();

    glColor3f(0.1, 0.5, 0.1);
    glBegin(GL_TRIANGLES);
        glVertex2f(90, 160);
        glVertex2f(120, 160);
        glVertex2f(105, 200);
    glEnd();

    // Right Tree
    glColor3f(0.4, 0.3, 0.2);
    glBegin(GL_POLYGON);
        glVertex2f(400, 100);
        glVertex2f(410, 100);
        glVertex2f(410, 160);
        glVertex2f(400, 160);
    glEnd();

    glColor3f(0.1, 0.5, 0.1);
    glBegin(GL_TRIANGLES);
        glVertex2f(390, 160);
        glVertex2f(420, 160);
        glVertex2f(405, 200);
    glEnd();

    glFlush();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 400); // Consistent 2D view
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Countryside Scene");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
