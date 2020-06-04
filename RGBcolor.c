
#include <stdio.h>
#include <stdlib.h>
//function to print RGB and alpha of a given 32bit color value
void printEachColor(uint32_t colorInt){
    uint8_t Red,Green,Blue,Alpha;
    Alpha=(uint8_t)colorInt&255;colorInt>>=8;
    Blue=(uint8_t)colorInt&255;colorInt>>=8;
    Green=(uint8_t)colorInt&255;colorInt>>=8;
    Red=(uint8_t)colorInt&255;
    printf("Red: %u\nGreen: %u\nBlue: %u\nAlpha: %u\n",Red,Green,Blue,Alpha);
}
//function to synthesize a 32bit color value from RGB and alpha
uint32_t getColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha){
    uint32_t color=0;
    color +=red;//add color red
    color<<=8;//shift to left 8 bits
    color +=green;//add color green
    color<<=8;
    color +=blue;//add color blue
    color<<=8;
    color +=alpha;//add alpha
    return color;
}
int main() {
    //initialize color values for testing
    uint8_t red=25, green=100, blue=50, alpha=255;
    uint32_t colorInt;
    //synthesizing the color value from RGB values
    colorInt=getColor(red,green,blue,alpha);
    puts("Color created from RGB values");
    //Performing the reverse operation
    //extracting and printing RGB values of the color
    printEachColor(colorInt);
    return 0;
}
