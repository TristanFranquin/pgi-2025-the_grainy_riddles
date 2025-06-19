#ifndef FEATURES_H
#define FEATURES_H

void helloWorld();
void mirror_horizontal(char *source_path);
void rotate_acw(char *source_path);
void mirror_vertical(char *source_path);
void scale_crop(char *sourcepath, int center_X, int center_Y, int W, int H);
#endif

char* max_component(char *source_path, char color_pixel);
char* min_component(char *source_path, char color_pixel);
void stat_report(char *source_path);
