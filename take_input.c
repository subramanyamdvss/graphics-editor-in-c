
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>





void rect(int x,int y,int l,int b,int fc,int bkc){

   int gd = DETECT, gm;
   
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   setbkcolor(bkc);
   setcolor(fc);
   rectangle(x,y,l,b);
   floodfill((x+l)/2,(y+b)/2,fc);
   getch();
   closegraph();
   return ;
}

void poly(int n, int points[])
{
   int gd=DETECT,gm,sumx=0,sumy=0,i;
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");
 
   

   drawpoly(n, points);


   getch();
   closegraph();
   return ;
}


void lin(int x1,int y1,int x2,int y2,int fc,int bkc)
{
   int gd = DETECT, gm;
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");
 
   
   setbkcolor(bkc);
   setcolor(fc);
   
   line(x1,y1,x2,y2);
   getch();
   closegraph();
   return ;
}


void ellpse(int x,int y,int l,int b,int fc,int bkc)
{
   int gd = DETECT, gm;
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");
 
   setbkcolor(bkc);
   setcolor(fc);
   ellipse(x, y, 0, 360, l, b);
   floodfill(x,y,fc);
   
 
   getch();
   closegraph();
   return ;

}

void circ(int x,int y,int r,int fc,int bkc)
{
   int gd = DETECT, gm;
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   setbkcolor(bkc);
   setcolor(fc);
   circle(x,y,r);
   floodfill(x,y,fc);
   
 
   getch();
   closegraph();
   return ;
}



// available colors are

//      BLACK          BLUE          GREEN         CYAN

//      RED            MAGENTA       BROWN         LIGHTGRAY

//      DARKGRAY       LIGHTBLUE     LIGHTGREEN    LIGHTCYAN

//      LIGHTRED       LIGHTMAGENTA  YELLOW        WHITE

//this is used to convert color strings to numbers

int getcnum(char *str){
   if(!strcmp(str,"black")){
      return 0;
   }
   if(!strcmp(str,"blue")){
      return 1;
   }
   if(!strcmp(str,"green")){
      return 2;
   }
   if(!strcmp(str,"cyan")){
      return 3;
   }
   if(!strcmp(str,"red")){
      return 4;
   }
   if(!strcmp(str,"magenta")){
      return 5;
   }
   if(!strcmp(str,"brown")){
      return 6;
   }
   if(!strcmp(str,"lightgray")){
      return 7;
   }
   if(!strcmp(str,"darkgray")){
      return 8;
   }
   if(!strcmp(str,"lightblue")){
      return 9;
   }
   if(!strcmp(str,"lightgreen")){
      return 10;
   }
   if(!strcmp(str,"lightcyan")){
      return 11;
   }
   if(!strcmp(str,"lightred")){
      return 12;
   }
   if(!strcmp(str,"lightmagenta")){
      return 13;
   }
   if(!strcmp(str,"yellow")){
      return 14;
   }
   if(!strcmp(str,"white")){
      return 15;
   }

}

int main(){
	FILE *fp;
   	
      char buff[255];
   	int x,y,l,b,n,i,r,fc,bkc;

   	fp = fopen("/home/surya/graphics-editor-in-c/input.txt", "r");

      int gd = DETECT, gm;
   
      initgraph(&gd, &gm, "C:\\TC\\BGI");


   	while(1){
         
   		fscanf(fp,"%s",buff);
         if(!strcmp(buff,"setcolor")){
            //here color is taken as input to set the color which your floodfill uses
            fscanf(fp,"%s",buff);
            setcolor(getcnum(buff));

         }

   		if(!strcmp(buff,"rectangle")){
   			
            //here x,y - are coordinates of topleft corner of rectangle l,b- are length and breadth
   			
            fscanf(fp," %d %d %d %d",&x,&y,&l,&b);
            
            rectangle(x,y,x+l,y+b);

   		}
   		
   		if(!strcmp(buff,"square")){
   			
            //user need to enter the coordinates of topleft corner and side length
   			
            fscanf(fp," %d %d %d ",&x,&y,&l);
            fscanf(fp,"%s",buff);
            
            rectangle(x,y,x+l,y+l);

   		}

   		if(!strcmp(buff,"polygon")){
   			
            // user need to enter n- number of points, 
   			
            fscanf(fp," %d ",&n);
            
            int tmp[2*n+2];
            
            for(i=0;i<=2*n-1;i++){
               fscanf(fp,"%d",tmp+i);
            }
            
            tmp[2*n]=tmp[0];
            tmp[2*n+1]=tmp[1];

            drawpoly(n+1, tmp);
   		}
         if(!strcmp(buff,"line")){
            
            // user should enter coordinates of both ends
            
            fscanf(fp," %d %d %d %d",&x,&y,&l,&b);
           
            line(x,y,l,b);

         }
         if(!strcmp(buff,"ellipse")){
            
            // user should enter coordinates of center, x-radius , y-radius
            
            fscanf(fp," %d %d %d %d",&x,&y,&l,&b);
            
            ellipse(x, y, 0, 360, l, b);
          
         }

         if(!strcmp(buff,"circle")){
            
            // user should enter coordinates of center, x-radius , y-radius
            
            fscanf(fp," %d %d %d",&x,&y,&r);
           
            circle(x,y,r);

         }
         if (!strcmp(buff,"endprogram")){
            
            getch();
            
            closegraph();
            
            break;
         }
         if (!strcmp(buff,"fillcolor")){

            fscanf(fp," %s %d %d",buff,&x,&y);

            floodfill(x,y,getcnum(buff));

            fscanf(fp,"%s",buff);
         }
   	}
      return 0;
}





















































