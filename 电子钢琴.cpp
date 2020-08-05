/***************************************************************************************
     项目:电子钢琴（钢琴单音）

     操作说明：键盘 1 2 3 4 5 6 7 控制音符

     修改日期：2019年12月29日

     作者：肖本杰

     工具：vc6.0  EasyX_2018;

     范围：C语句  图形库

     图片路径：相对路径

     思考优化问题：

	     1.从“看“的层次
		    1.1代码上去看
			1.2界面上去看

		 2.从量的层次
		    2.1 重复性：函数优化
		    2.2 耦合性

*************************************************************************************/
 
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define WINDOW_WIDTH 560
#define WINDOW_HEIGHT 408
IMAGE img[7];//储存八张图片
IMAGE down;
void loadResource()//初始化化变量，加载资源
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
	putimage(num*80,0,&down);//按下一瞬间切换图片
	char musicFile[50]=" ";
	sprintf(musicFile,"open .\\music\\%s alias music",musicName);
	mciSendString(musicFile,0,0,0);
	mciSendString("play music",0,0,0);
    Sleep(50);//按键效果显示时间
	putimage(num*80,0,img+num);//按键结束一瞬间返回原来的状态
	Sleep(1000);//音乐显示时间
	mciSendString("close music",0,0,0);

}
void keyDown()//菜单按键交互
{
	char userKey=_getch();//getchar()会显示出按键
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
