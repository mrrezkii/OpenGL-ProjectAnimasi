#include <stdlib.h>
#include <glut.h>
#include <math.h>

const double PI = 3.141592653589793;
int i;
int r;

void timer(int value) {
	r += 1;
	glutPostRedisplay();
	glutTimerFunc(60, timer, 10);
}


void lingkaran(int jari2, int jumlah_titik, int x_tengah, int y_tengah) {
	glBegin(GL_POLYGON);
	for (i = 0;i <= 360;i++) {
		float sudut = i*(2 * PI / jumlah_titik);
		float x = x_tengah + jari2*cos(sudut);
		float y = y_tengah + jari2*sin(sudut);
		glVertex2f(x, y);
	}
	glEnd();
}

void segitiga() {
	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 0);
	glRotatef(90, 0, 0, 1);
	glVertex2f(80, 40);
	glVertex2f(80, -40);
	glVertex2f(150, 0);
	glEnd();
}

void render() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glColor3f(1, 1, 0);
	glRotatef(r, 0, 0, 1);
	lingkaran(80, 80, 0, 0);

	glPushMatrix();
	segitiga();
	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 0, 1);
	segitiga();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	segitiga();
	glPopMatrix();

	glPushMatrix();
	glRotatef(135, 0, 0, 1);
	segitiga();
	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 0, 1);
	segitiga();
	glPopMatrix();

	glPushMatrix();
	glRotatef(225, 0, 0, 1);
	segitiga();
	glPopMatrix();

	glPushMatrix();
	glRotatef(270, 0, 0, 1);
	segitiga();
	glPopMatrix();

	glPushMatrix();
	glRotatef(315, 0, 0, 1);
	segitiga();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 1);//warna ungu
	glRotatef(-r, 0, 0, 1);
	glScalef(2, 2, 0);
	glTranslated(0, 150, 0);
	lingkaran(50, 50, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 1);//warna biru
	glRotatef(r, 0, 0, 1);
	glScalef(1, 1, 0);
	glTranslated(0, 700, 0);
	lingkaran(50, 50, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);//warna merah
	glRotatef(-r, 0, 0, 1);
	glScalef(1, 1, 0);
	glTranslated(0, -300, 0);
	lingkaran(80, 80, 0, 0);
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}


void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Muhamad Zidane Arfani - 22 - XIR5");
	gluOrtho2D(-1000., 1000., -1000., 1000.);
	glutDisplayFunc(render);
	glutTimerFunc(1, timer, 10);

	glutMainLoop();
}