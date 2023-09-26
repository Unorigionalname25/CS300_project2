/*
*File: shape.h

This file defines a simple hierarchy of graphical shape classes*/


#ifndef _shape_h
#define _shape_h

#include <string>
#include <stdio.h>
#include "gwindow.h"
/*class: shape

this class is the root of the hierarchy and emcompasses all shapes*/
class shape {
    public:
/*these are all public methods that the user can manipulate freely*/
    void setLocation(double x, double y); //Sets the inital location of a shape as (x,y) cords 

    void move(double x, double y); //adds x and y to the coordinates of the shape

    void setColor(std::string color); // sets the color of the shape when drawing

    virtual void draw(GWindow & gw)=0; // Draws the shape on the GraphicalWindow 

    virtual bool contains(double x, double y) = 0; //returns a bool value that is true if a point is in a solid shape or near a line





protected:

    shape();
    std::string color;
    double x, y;

};
/*these are all subclasses of the shape class. They represent different shapes that can be drawn and their parameters*/

class Line : public shape {
    public:
    /*Constructor: line: creates a line that extends from x1 y1 to x2 y2*/
    Line (double x1, double y1,double x2,double y2);

    virtual void draw(GWindow&gw);
    virtual bool contains(double x, double y);


private:
    double dx;
    double dy;

};


class Rect : public shape {
    public:
    /*Constructor: rect: creates a rectangle of specified size and upper left corner at (x,y)*/
    Rect(double x, double y, double width, double height);
    virtual void draw(GWindow&gw);
    virtual bool contains(double x, double y);


private:
    double width, height;

};
class Oval: public shape {
    public:

    /*constructor: Oval: creates an oval at (x,y) with a width and height which creates an ellipse*/
        Oval (double x, double y, double width, double height);
        virtual void draw(GWindow&gw);
        virtual bool contains(double x, double y);


    private: 
    double width, height;

};

class Square: public shape {
    public:
    /*constructor: square: creates a square at (x,y) that is (size) pixles large*/
        Square (double x, double y, double size);
        virtual void draw(GWindow& gw);
        virtual bool contains(double x, double y);
    private:
        double size;    
};







#endif








