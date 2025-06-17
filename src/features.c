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

void dimension(char* source){
    unsigned char* data = NULL;
    int W = 0 , H = 0 , ch = 0;
    read_image_data( source_path, &data, &W, &H, &ch);
    printf("dimension : %d, %d\n", W, H);
}