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
void rotate_acw(char *source_path){
    unsigned char* data=NULL;
    int W,H,CH,X,Y;
    read_image_data(source_path,&data,&W,&H,&CH);
    unsigned char* rotate_acw_data = calloc(W*H*CH,sizeof(unsigned char));
    for(Y=0;Y<H;Y++){
        for(X=0;X<W;X++){
            pixelRGB*current_pixel=get_pixel(data,W,H,CH,X,Y);
            int Xnew=Y;
            int Ynew=W-1-X;
            pixelRGB*rotate_acw_pixel=get_pixel(rotate_acw_data,H,W,CH,Xnew,Ynew);
            rotate_acw_pixel->R=current_pixel->R;
            rotate_acw_pixel->G=current_pixel->G;
            rotate_acw_pixel->B=current_pixel->B;
        }
    }
    write_image_data("image_out.bmp", rotate_acw_data,H,W);
}
void mirror_vertical(char *source_path){
   unsigned char* data=NULL;
    int W,H,CH,X,Y;
    read_image_data(source_path,&data,&W,&H,&CH);
    unsigned char* mirror_vert_data = calloc(W*H*CH,sizeof(unsigned char));
    for(Y=0;Y<H;Y++){
        for(X=0;X<W;X++){
            pixelRGB*current_pixel=get_pixel(data,W,H,CH,X,Y);
            int Xnew=X;
            int Ynew=H-1-Y;
            pixelRGB*mirror_vert_pixel=get_pixel(mirror_vert_data,W,H,CH,Xnew,Ynew);
            mirror_vert_pixel->R=current_pixel->R;
            mirror_vert_pixel->G=current_pixel->G;
            mirror_vert_pixel->B=current_pixel->B;
        }
    }
    write_image_data("image_out.bmp", mirror_vert_data,W,H);
}
void mirror_total(char *source_path){
    unsigned char* data=NULL;
    int W,H,CH,X,Y;
    read_image_data(source_path,&data,&W,&H,&CH);
    unsigned char* mirror_tot_data = calloc(W*H*CH,sizeof(unsigned char));
    for(Y=0;Y<H;Y++){
        for(X=0;X<W;X++){      
            pixelRGB*current_pixel=get_pixel(data,W,H,CH,X,Y);
            int Xnew=W-1-X;
            int Ynew=H-1-Y;
            pixelRGB*mirror_tot_pixel=get_pixel(mirror_tot_data,W,H,CH,Xnew,Ynew);
            mirror_tot_pixel->R=current_pixel->R;
            mirror_tot_pixel->G=current_pixel->G;
            mirror_tot_pixel->B=current_pixel->B;
        }
    }
    write_image_data("image_out.bmp", mirror_tot_data,W,H);
}
void scale_crop(char *sourcepath,int center_X,int center_Y,int W,int H){
    unsigned char* data=NULL;
    int og_W,og_H,CH,X,Y;
    read_image_data(sourcepath,&data,&og_W,&og_H,&CH);
    int first_X=center_X-W/2;
    int first_Y=center_Y-H/2;
    if (first_X<0) first_X=0;
    if (first_Y<0) first_Y=0;
    if (first_X+W>og_W) W=og_W-first_X;
    if (first_Y+H>og_H) H=og_H-first_Y;

    unsigned char* cropped_data = malloc(W*H*CH);
    for(Y=0;Y<H;Y++){
        for(X=0;X<W;X++){
            pixelRGB*current_og_pixel = get_pixel(data,og_W,og_H,CH,X+first_X,Y+first_Y);
            pixelRGB*current_data_cropped_pixel = get_pixel(cropped_data,W,H,CH,X,Y);
            current_data_cropped_pixel->R=current_og_pixel->R;
            current_data_cropped_pixel->G=current_og_pixel->G;
            current_data_cropped_pixel->B=current_og_pixel->B;
        }
    }
    write_image_data("image_out.bmp",cropped_data,W,H);
}

char* max_component(char *source_path,char color_pixel){
    unsigned char* data=NULL;
    int W,H,CH,X,Y;
    int Xmax=0;
    int Ymax=0;
    int color_pixel_val=0;
    int color_pixel_max=0;
    read_image_data(source_path,&data,&W,&H,&CH);
    for(Y=0;Y<H;Y++){
        for(X=0;X<W;X++){
            pixelRGB*pixel=get_pixel(data,W,H,CH,X,Y);
            if (color_pixel=='R'){
                color_pixel_val=pixel->R;
            }
            else if (color_pixel=='G'){
                color_pixel_val=pixel->G;
            }
            else if (color_pixel=='B'){
                color_pixel_val=pixel->B;
            }
            if(color_pixel_val>color_pixel_max){
                color_pixel_max=color_pixel_val;
                Xmax=X;
                Ymax=Y;
            }
        }
    }
    printf("max_component %c (%d %d):%d\n",color_pixel,Xmax,Ymax,color_pixel_max);
    char* res=malloc(100);
    sprintf(res,"max_component %c (%d %d): %d\n",color_pixel,Xmax,Ymax,color_pixel_max);
    return res;
}
