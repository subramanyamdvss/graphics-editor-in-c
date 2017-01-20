/*#include<graphics.h>

main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
 
   outtext("Press any key to change the background color to GREEN.");
   getch();
 
   setbkcolor(GREEN);
 
   getch();
   closegraph();
   return 0;
}*/
/*   #include<graphics.h>
 
main()
{
   int gd = DETECT, gm;
   initgraph(&gd,&gm,"C:\\TC\\BGI");
 
   circle(100,100,50);           
   setcolor(RED);
   circle(200,200,50);          
 
   getch();
   closegraph();
   return 0;
}
*/
#include <graphics.h>
 

void main(){
   int x=50,int y=60,int l=90,int b=100,int fc=,int bkc;
   int gd = DETECT, gm;
   
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   setbkcolor(bkc);
   setcolor(fc);
   rectangle(x,y,l,b);
   floodfill(100,100,fc);
   getch();
   closegraph();
   return ;
}