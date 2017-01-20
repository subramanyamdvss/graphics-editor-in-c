
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>


// available colors are

//      BLACK          BLUE          GREEN         CYAN

//      RED            MAGENTA       BROWN         LIGHTGRAY

//      DARKGRAY       LIGHTBLUE     LIGHTGREEN    LIGHTCYAN

//      LIGHTRED       LIGHTMAGENTA  YELLOW        WHITE


void rect(int x,int y,int l,int b){

   int gd = DETECT, gm;
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");
 
   rectangle(x,y,l,b);
 
   getch();
   closegraph();
   return ;
}




void poly(int n, int points[])
{
   int gd=DETECT,gm;
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");
 
   drawpoly(n, points);
 
   getch();
   closegraph();
   return ;
}


void lin(int x1,int y1,int x2,int y2)
{
   int gd = DETECT, gm;
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");
 
   line(x1,y1,x2,y2);
 
   getch();
   closegraph();
   return ;
}


void ellpse(int x,int y,int l,int b)
{
   int gd = DETECT, gm;
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");
 
   ellipse(x, y, 0, 360, l, b);
 
   getch();
   closegraph();
   return ;

}

void circ(int x,int y,int r)
{
   int gd = DETECT, gm;
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");
 
   circle(x,y,r);
 
   getch();
   closegraph();
   return ;
}


// void background(int n)
// {
//    int gd = DETECT, gm;
//    initgraph(&gd, &gm, "C:\\TC\\BGI");
 
//    outtext("Press any key to change the background color to GREEN.");
//    getch();
 
//    setbkcolor(n);
 
//    getch();
//    closegraph();
//    return 0;
// }


int main(){
	FILE *fp;
   	char buff[255];
   	int x,y,l,b,n,i,r;
   	fp = fopen("/home/surya/graphics-editor-in-c/input.txt", "r");
   	/*fscanf(fp, "%s", buff);
   	printf("1 : %s\n", buff );

   	fgets(buff, 255, (FILE*)fp);
   	printf("2: %s\n", buff );
   
   	fgets(buff, 255, (FILE*)fp);
   	printf("3: %s\n", buff );
   	fclose(fp);*/
      


   	while(1){
         
   		fscanf(fp,"%s",buff);
   		if(!strcmp(buff,"rectangle")){
   			//here x,y - are coordinates of topleft corner of rectangle l,b- are length and breadth
   			fscanf(fp," %d %d %d %d",&x,&y,&l,&b);
            
   			rect(x,y,x+l,y+b);
            // outtextxy(0, 0, "Press any button to exit");
   		}
   		
   		if(!strcmp(buff,"square")){
   			//user need to enter the coordinates of topleft corner and side length
   			fscanf(fp," %d %d %d ",&x,&y,&l);
   			rect(x,y,x+l,y+l);
   		}

   		if(!strcmp(buff,"polygon")){
   			// user need to enter n- number of points, 
   			fscanf(fp," %d ",&n);
            int tmp[2*n];
            for(i=0;i<=2*n-1;i++){
               fscanf(fp,"%d",tmp+i);
            }
            poly(n,tmp);
   		}
         if(!strcmp(buff,"line")){
            // user should enter coordinates of both ends
            fscanf(fp," %d %d %d %d",&x,&y,&l,&b);
            lin(x,y,l,b);
         }
         if(!strcmp(buff,"ellipse")){
            // user should enter coordinates of center, x-radius , y-radius
            fscanf(fp," %d %d %d %d",&x,&y,&l,&b);
            ellpse(x,y,l,b) ;
         }
         // if (!strcmp(buff,"setbackground")){
         //    // user should enter the number corresponding to the color he wants to set the background to
         //    fscanf(fp," %d",&n);
         //    setbkcolor(GREEN);
         // }
         // if (!strcmp(buff,"closegraph")){
         //    clsgraph()
         // }
         if(!strcmp(buff,"circle")){
            // user should enter coordinates of center, x-radius , y-radius
            fscanf(fp," %d %d %d",&x,&y,&r);
            circ(x,y,r) ;
         }
         if (!strcmp(buff,"endprogram")){
            break;
         }
   	}
      return 0;
}





















































