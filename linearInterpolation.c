//  Linear interpolation
//  Lec1 example

#include <stdio.h>

//Your code starts here
//implement findY() which finds the y point given x, and c here
float findY(float x, float m, float c){
    return (m*x+c);
}
//Your code ends here

int main() {
    float x1, y1, x2, y2, xnew, m, c;
    
    printf("Please specify the first point's x and y coordinates\n");
    scanf("%f %f",&x1,&y1);
    
    printf("Please specify the second point's x and y coordinates\n");
    scanf("%f %f",&x2,&y2);
    
    //Your code starts here
    //implement computation of slope m and constant c here
    m=(y2-y1)/(x2-x1);
    c=(y1*x2-y2*x1)/(x2-x1);
    //Your code ends here
    
    printf("Please specify the x coordinate of the new point\n");
    scanf("%f",&xnew);
    printf("Here is the y coordinate: %f\n",findY(xnew,m,c));
    
    return 0;
}

