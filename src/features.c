#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"
#include <stdlib.h>


/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

/// @brief 
void helloWorld() {
    printf("Hello World !!!");
}

void dimension(char* source_path) {

    unsigned char* data = NULL;
    int W=0,H=0,CH=0;
    read_image_data(source_path,&data,&W,&H,&CH);
    printf("dimension :%d,%d\n",W,H);
}

void first_pixel(char* source_path){

    unsigned char* data = NULL;
    int W,H,CH;
   
    read_image_data(source_path,&data,&W,&H,&CH);
   
    unsigned char R=data[0];
    unsigned char G=data[1];
    unsigned char B=data[2];
 
    printf("first_pixel:%d,%d,%d",R,G,B);
}void mirror_horizontal(char *source_path){
    unsigned char* data=NULL;
    int W,H,CH,X,Y;
    read_image_data(source_path,&data,&W,&H,&CH);
    unsigned char* mirror_hor_data=malloc(W*H*CH);
    for(Y=0;Y<H;Y++){
        for(X=0;X<W;X++){
            pixelRGB*current_pixel=get_pixel(data,W,H,CH,X,Y);
            int Xnew=W-1-X;
            int Ynew=Y;
            pixelRGB*mirror_hor_pixel = get_pixel(mirror_hor_data,W,H,CH,Xnew,Ynew);
            mirror_hor_pixel->R=current_pixel->R;
            mirror_hor_pixel->G=current_pixel->G;
            mirror_hor_pixel->B=current_pixel->B;
        }
    }
    write_image_data("image_out.bmp", mirror_hor_data,W,H);
}

void tenth_pixel (char *source_path) {
    unsigned char *data;
    int W,H,CH;
    read_image_data(source_path,&data,&W,&H,&CH);
    printf("tenth_pixel:%d,%d,%d\n",data[27],data[28],data[29]);
}

void second_line (char *source_path) {
    unsigned char *data;
    int W,H,CH;
    read_image_data(source_path,&data,&W,&H,&CH);
    printf("second_line:%d,%d,%d\n",data[W*3],data[W*3+1],data[W*3+2]);
}

void print_pixel(char* source_path,int X,int Y){
 
    unsigned char* data=NULL;
    int W,H,CH;
    read_image_data(source_path,&data,&W,&H,&CH);
    pixelRGB * pixel = get_pixel(data,W,H,CH,X,Y);
    printf("print_pixel(%d %d):%d,%d,%d\n",X,Y,pixel->R,pixel->G,pixel->B);
}

char* max_pixel(char* source_path){
    unsigned char* data=NULL;
    int W,H,CH,X,Y;
	int S=0;
    int Xmax=0;
    int Ymax=0;
    read_image_data(source_path,&data,&W,&H,&CH);
    pixelRGB*max_pixel=get_pixel(data,W,H,CH,0,0);
	pixelRGB*first_pixel=get_pixel(data,W,H,CH,0,0);
	int Smax=first_pixel->R+first_pixel->G+first_pixel->B;
    for(Y=0;Y<H;Y++){
        for(X=0;X<W;X++){
            pixelRGB*pixel=get_pixel(data,W,H,CH,X,Y);
            S=pixel->R+pixel->G+pixel->B;
            if(S>Smax){
			    Ymax=Y;
				Xmax=X;
				max_pixel=pixel;
                Smax=S;                
            }
        }
    }
    printf("max_pixel(%d %d):%d,%d,%d\n",Xmax,Ymax,max_pixel->R,max_pixel->G,max_pixel->B);
    char* res=malloc(100);
    sprintf(res,"max_pixel(%d %d):%d,%d,%d\n",Xmax,Ymax,max_pixel->R,max_pixel->G,max_pixel->B);
    return res;  

}