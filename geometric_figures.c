
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main()
{
   int gd=DETECT,gm,sumx=0,sumy=0,i;
   int n=3; int points[]={1,2,56,57,89,69,1,2};int fc=1;int bkc=4;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
 
   
   setbkcolor(bkc);
   setcolor(fc);
   drawpoly(n, points);

   for(i=0;i<2*n-1;i+=2){
      sumx+=points[i];
      sumy+=points[i+1];
   }
   sumx/=n;
   printf("%d ",sumx);
   sumy/=n;
   printf("%d \n",sumy);

   floodfill(sumx/2,sumy/2,fc);
   getch();
   closegraph();
   return ;
}