#include <estia-image.h>
#include <stddef.h> 
#include <stdio.h> 
#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

void color_red(char *source_path){
    unsigned char* data=NULL;
    int W,H,CH,X,Y;
    read_image_data(source_path,&data,&W,&H,&CH);
    for(Y=0;Y<H;Y++){
        for(X=0;X<W;X++){
            pixelRGB*pixel=get_pixel(data,W,H,CH,X,Y);
            pixel->G=0;
            pixel->B=0;
        }
    }
    write_image_data("image_out.bmp",data,W,H);
}


void color_green (char *source_path) {
    unsigned char *data;
    int W,H,CH;
    read_image_data(source_path,&data,&W,&H,&CH);
    for(int k=0;k<W*H;k++) {
        data[3*k]=0;
        data[2+3*k]=0;  
    }
    write_image_data("image_verte.bmp",data,W,H);
    printf("color_green\n");
}

void color_blue (char *source_path) {
    unsigned char *data;
    int W,H,CH;
    read_image_data(source_path, &data, &W, &H, &CH);
    for(int k=0;k<W*H;k++) {
        data[3*k]=0;
        data[1+3*k]=0;
    }
    write_image_data("image_bleu.bmp",data,W,H);
    printf("color_blue\n");
}
