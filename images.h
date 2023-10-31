#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>
#include <string.h>

// Define the Matrix type for kernel matrices
typedef double Matrix[3][3];

// Define the Image structure to store image data
typedef struct {
    uint8_t* data;
    int width;
    int height;
    int bpp;
} Image;

// Enum to represent different kernel types
enum KernelTypes { EDGE = 0, SHARPEN = 1, BLUR = 2, GAUSE_BLUR = 3, EMBOSS = 4, IDENTITY = 5 };

// Function to compute the value of a specific pixel using a convolution kernel
uint8_t getPixelValue(Image* srcImage, int x, int y, int bit, Matrix algorithm);

// Function to apply convolution to an image
void convolute(Image* srcImage, Image* destImage, Matrix algorithm);

// Function to print usage information
int Usage();

// Function to convert the string name of a convolution into a KernelTypes enumeration
enum KernelTypes GetKernelType(char* type);

// Additional function declaration for multi-threading with OpenMP
void rows(Image* srcImage, Image* destImage, enum KernelTypes type, int start, int end);

#endif