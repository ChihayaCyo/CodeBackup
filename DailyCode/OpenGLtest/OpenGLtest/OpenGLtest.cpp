#include "stdafx.h"

#include<GL/glut.h>

void myDisplay(void)

{

	glClear(GL_COLOR_BUFFER_BIT); //�����ɫ

	glRectf(-0.5f, -0.5f, 0.5f, 0.5f); //��һ������

//	pDC->MoveTo(100, 200);
//	pDC->LineTo(200, 200);
//	SetPixel(1, 2, 0);

	glFlush(); //��ǰ�����������ִ�ж������ڻ���������fflush(stdout)��������

}

int _tmain(int argc, _TCHAR* argv[])

{

	glutInit(&argc, (char**)argv); //��ʼ��glut,������ã����������仰����

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //������ʾ��ʽ��RGB�������塣��Ȼ����GLUT_INDEX������ɫ GLUT_DOUBLE˫����(Qt�п�����˫����)

	glutInitWindowPosition(100, 100); //λ��

	glutInitWindowSize(400, 400);//���ڴ�С

	glutCreateWindow("��һ��OpenGL����"); //�������ڣ����ñ���

	glutDisplayFunc(&myDisplay); // �����ƴ���ʱ����myDisplay����Cocos2d-xˢ֡Draw�еĲ���

	glutMainLoop(); //��Ϣѭ��

	return 0;

}