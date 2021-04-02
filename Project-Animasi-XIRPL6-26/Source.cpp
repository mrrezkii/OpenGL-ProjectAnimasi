#include <glut.h>

void garisbelakang() {
	glColor3f(1, 1, 1);
	for (int i = -400; i <= 400; i += 50) {
		glBegin(GL_LINES);
		glVertex2f(i, -400);
		glVertex2f(i, 400);
		glEnd();
	}
	for (int j = -400; j <= 400; j += 50) {
		glBegin(GL_LINES);
		glVertex2f(-400, j);
		glVertex2f(400, j);
		glEnd();
	}
	glColor3f(0, 1, 1);
	glLineWidth(1);
	glBegin(GL_LINES);
	glEnd();

}
int r;
void timer(int value) {
	r += -1;
	glutPostRedisplay();
	glutTimerFunc(10, timer, 0);
}

void persegi() {
	glBegin(GL_QUADS);
	glVertex2f(100, 100);
	glVertex2f(-100, 100);
	glVertex2f(-100, -100);
	glVertex2f(100, -100);
	glEnd();
}
void tiga() {
	glBegin(GL_TRIANGLES);
	glVertex2f(100, 0);
	glVertex2f(0, 100);
	glVertex2f(0, 0);
	glEnd();
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(r, 0, 0, 1);

	glPushMatrix();
	glColor3f(0, 0, 1);
	persegi();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 1, 1);
	glTranslatef(0, 100, 0);
	tiga();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 1, 1);
	glRotatef(90, 0, 0, 1);
	glTranslatef(0, 100, 0);
	tiga();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 1, 1);
	glRotatef(180, 0, 0, 1);
	glTranslatef(0, 100, 0);
	tiga();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 1, 1);
	glRotatef(270, 0, 0, 1);
	glTranslatef(0, 100, 0);
	tiga();
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
	//garisbelakang();
	glFlush();
}

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutTimerFunc(5, timer, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Lucky Ardisa Fanani");
	gluOrtho2D(-400, 400, -400, 400);
	glutDisplayFunc(render);
	glutMainLoop();
}