#ifndef __Points__Point3D__
#define __Points__Point3D__

#include <stdio.h>
#include "Point.h"
class Point3D : public Point{
public:
    void setH(double hI){h=hI;};
    double getH(){return h;}
    string toString();
private:
    double h;
};
#endif /* defined(__Points__Point3D__) */

