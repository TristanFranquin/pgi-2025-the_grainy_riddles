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