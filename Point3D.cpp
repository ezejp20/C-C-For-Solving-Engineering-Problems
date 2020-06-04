#include "Point3D.h"
//toString method that overrides Point's toString
string Point3D::toString(){
    string str="("+to_string(getX())+","+to_string(getY())+","+to_string(h)+")";
    return str;
}
