/***************************************************************************************
     ��Ŀ:���Ӹ��٣����ٵ�����

     ����˵�������� 1 2 3 4 5 6 7 ��������

     �޸����ڣ�2019��12��29��

     ���ߣ�Ф����

     ���ߣ�vc6.0  EasyX_2018;

     ��Χ��C���  ͼ�ο�

     ͼƬ·�������·��

     ˼���Ż����⣺

	     1.�ӡ������Ĳ��
		    1.1������ȥ��
			1.2������ȥ��

		 2.�����Ĳ��
		    2.1 �ظ��ԣ������Ż�
		    2.2 �����

*************************************************************************************/
 
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define WINDOW_WIDTH 560
#define WINDOW_HEIGHT 408
IMAGE img[7];//�������ͼƬ
IMAGE down;
void loadResource()//��ʼ����������������Դ
{
	char fileName[50]=" ";
	for(int i=0;i<7;i++)
	{
		memset(fileName,0,20);
		sprintf(fileName,"images\\%d.jpg",i+1);
		loadimage(img+i,fileName);
	}
	loadimage(&down,".//images//down.jpg");
}
void drawWindow()
{
	initgraph(WINDOW_WIDTH,WINDOW_HEIGHT);
	for(int i=0;i<7;i++)
	{
		putimage(i*80,0,img+i);
	}

}
void playMusic(const char *musicName)
{
	int num=musicName[0]-'1';
	putimage(num*80,0,&down);//����һ˲���л�ͼƬ
	char musicFile[50]=" ";
	sprintf(musicFile,"open .\\music\\%s alias music",musicName);
	mciSendString(musicFile,0,0,0);
	mciSendString("play music",0,0,0);
    Sleep(50);//����Ч����ʾʱ��
	putimage(num*80,0,img+num);//��������һ˲�䷵��ԭ����״̬
	Sleep(1000);//������ʾʱ��
	mciSendString("close music",0,0,0);

}
void keyDown()//�˵���������
{
	char userKey=_getch();//getchar()����ʾ������
	switch(userKey)
	{
		case '1':
			 playMusic("1.mp3");
			break;
		case '2':
			playMusic("2.mp3");
			break;
		case '3':
			playMusic("3.mp3");
			break;
		case '4':
			playMusic("4.mp3");
			break;
		case '5':
			playMusic("5.mp3");
			break;
		case '6':
			playMusic("6.mp3");
			break;
		case '7':
			playMusic("7.mp3");
			break;
	}

}
int main()
{
	loadResource();
	drawWindow();
	while(1)
	{
    keyDown();
	}
	_getch();
	closegraph();
	return 0;

}
