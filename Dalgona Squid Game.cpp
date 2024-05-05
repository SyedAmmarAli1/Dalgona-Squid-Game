#include <graphics.h>
#include <bits/stdc++.h>
#include <Windows.h>
#include<iostream>
using namespace std;

int click,x1,y2;
bool TimeRemaining = true;

void click_handler(int x, int y)

{

    if(TimeRemaining == true)
    {
        click= click + 1;
        if (getpixel(x,y) == WHITE && click < 3)
        {
            settextstyle(6,0,5);
            outtextxy(110, 230, "YOU WIN!!");
            cout<<"\n YOU WIN!!";
            click=3;
        }
        else if (getpixel(x,y) != RED && click < 3)
        {
            settextstyle(10,0,5);
            outtextxy(110, 230, "Player Elimenated!");
            cout<<"\n Player Elimenated!";
            click=3;
        }
        if(click == 1)
        {
            x1=x;
            y2=y;
        }
        if(click == 2)
        {
            setcolor(WHITE);
            setlinestyle(SOLID_LINE,0xFFFF,3);
            //cout<<x1<<" "<<y2<<" "<<x<<" "<<y<<"\n";
            double distance = sqrt(pow(x1 - x, 2) + pow(y2 - y, 2));
            //cout<<distance<<"\n";
            if(distance < 30)
            {
                line(x1, y2, x, y);
                x1=x;
                y2=y;

            }
            click=1;
        }

    }
    else
    {
        settextstyle(10,0,5);
        outtextxy(140, 230, "TIME OUT!");
        click=3;
    }

}
void timer(int x,int y)
{
    int counter = 1; //amount of seconds
    Sleep(1000);
    cout<<endl;
    char str[3];
    settextstyle(10,0,4);
    while (counter <= 60 && click < 3)
    {
        cout << "\r Time remaining in sec: " << counter << flush;
        outtextxy(x,y, "Sec:");
        sprintf(str,"%d",counter);
        outtextxy( x+75,y,str);
        Sleep(1000);
        counter++;
    }
    if(counter>60)
    {
        outtextxy(140, 230, "TIME OUT!");
        TimeRemaining = false;
        cout << "\n TIME OUT ";
        click = 3;
    }
}

//driver code
int main()
{
    click,x1,y2=0;
    int choice=0;
    cout<<" \n\n\n        SQUID GAME \n\n ";
    cout<<"   Lets Play Dalgone Game \n\n ";
    cout<<"\n\n Select Your Desired Shape:\n ";
    cout<<"1: Circle\n ";
    cout<<"2: Square\n ";
    cout<<"3: Triangle\n ";
    cout<<"4: Star \n ";
    cout<<" \n Enter Your Choice: ";
    cin>>choice;


    if(choice == 1 )
    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");
        registermousehandler(WM_LBUTTONDOWN, click_handler);
        // circle function
        outtextxy(205, 20, "BEST WISHES!");
        setfillstyle(SOLID_FILL,BROWN);
        setlinestyle(SOLID_LINE,0xFFFF,5);
        circle(250, 250, 200);
        floodfill(200,250,15);
        setlinestyle(SOLID_LINE,0xFFFF,10);
        setcolor(RED);
        circle(250, 250, 130);
        timer(200, 230);
        getch();
        closegraph();

    }
   if(choice == 2 )
    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");
        registermousehandler(WM_LBUTTONDOWN, click_handler);
        outtextxy(205, 20, "BEST WISHES!");
        int left = 135, top = 130;
        int right = 360, bottom = 360;
        // circle function
        setfillstyle(SOLID_FILL,BROWN);
        setlinestyle(SOLID_LINE,0xFFFF,5);
        circle(250, 250, 200);
        floodfill(200,250,15);
         setlinestyle(SOLID_LINE,0xFFFF,10);
        setcolor(RED);
        rectangle(left, top, right, bottom);
        timer(200,230);
        getch();
        closegraph();
    }
    if(choice == 3 )
    {

        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");
        registermousehandler(WM_LBUTTONDOWN, click_handler);
        // circle function
        outtextxy(245, 450, "BEST WISHES!");
        setfillstyle(SOLID_FILL,BROWN);
        setlinestyle(SOLID_LINE,0xFFFF,5);
        circle(300, 210, 200);
        floodfill(200,250,15);
        // line for x1, y1, x2, y2
        setlinestyle(SOLID_LINE,0xFFFF,10);
        setcolor(RED);
        line(150, 150, 450, 150);
        // line for x1, y1, x2, y2
        line(150, 150, 300, 300);
        // line for x1, y1, x2, y2
        line(450, 150, 300, 300);
        timer(250,170);
        getch();
        closegraph();
    }
    if(choice == 4 )
    {

        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");
        registermousehandler(WM_LBUTTONDOWN, click_handler);
        // circle function
        outtextxy(180, 450, "BEST WISHES!");
        setfillstyle(SOLID_FILL,BROWN);
        setlinestyle(SOLID_LINE,0xFFFF,7);
        circle(215, 210, 200);
        floodfill(200,250,15);
        setfillstyle(1,14);
        setlinestyle(SOLID_LINE,0xFFFF,10);
        setcolor(RED);
        line(80,142,157,202);
        line(157,202,128,301);
        line(128,301,213,243);
        line(213,243,293,301);
        line(293,301,263,201);
        line(263,201,343,143);
        line(343,143,245,141);
        line(245,141,211,44);
        line(211,44,178,139);
        line(178,139,80,142);

        timer(155,160);
        getch();
        closegraph();
    }


    return 0;

}
