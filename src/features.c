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
void dimension(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;

    if (read_image_data(source_path, &data, &width, &height, &channels) != 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image\n");
        return;
    }

    printf("dimension: %d, %d\n", width, height);

    free(data);
}

