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
#include<graphics.h>
 
main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
 
   outtext("Press any key to change the background color to GREEN.");
   getch();
 
   setbkcolor(2);
 
   getch();
   closegraph();
   return 0;
}