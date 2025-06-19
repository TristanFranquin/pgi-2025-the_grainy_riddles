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


