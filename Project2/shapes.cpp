#include <string>
#include "Shapes.h"
#include <cmath>


shape::shape() {
    setColor("BLACK"); // sets the default color of any shape to black
}


void shape::setLocation(double x, double y) {
    this->x = x;
    this->y = y;
}

void shape::move(double dx, double dy){
    x+=dx;
    y+=dy;
}

void shape::setColor(std::string color){
    this->color = color;
};


Line::Line(double x1, double y1, double x2, double y2){
    this ->x = x1;
    this ->y = y1;
    this ->dx = x2 - x1 ;
    this ->dy = y2 - y1;
}
void Line::draw(GWindow&gw){
    gw.setColor(color);
    gw.drawLine(x,y,x+dx,y+dy);
}

bool Line::contains(double px, double py) {
    // Calculate the direction vector of the line
    double lineDirX = dx;
    double lineDirY = dy;

    // Calculate the vector from the starting point of the line to the point
    double vecToPtX = px - x;
    double vecToPtY = py - y;

    // Calculate the perpendicular distance between the point and the line
    double distance = std::abs(vecToPtX * lineDirY - vecToPtY * lineDirX) /
                      std::sqrt(lineDirX * lineDirX + lineDirY * lineDirY);

    return distance <= 0.5; // 0.5 represents half a pixel's distance
}

Rect::Rect(double x, double y, double width, double height){
    this ->x = x;
    this ->y = y;
    this ->width = width;
    this ->height = height;
}
void Rect::draw(GWindow&gw){
    gw.setColor(color);
    gw.fillRect(x , y , width , height);
}
bool Rect::contains(double px, double py) {
    // Check if the point is within the rectangle's bounds
    return px >= x && px <= x + width && py >= y && py <= y + height;
}


Oval::Oval(double x, double y, double width, double height){
    this ->x = x;
    this ->y = y;
    this ->width = width;
    this ->height = height;
}
void Oval::draw(GWindow&gw){
    gw.setColor(color);
    gw.fillRect(x , y , width , height);
}
bool Oval::contains(double px, double py) {
    // Calculate the semi-axes of the ellipse
    // the semi-axes are the longest and shortest radiuses of the elipse
    double a = width / 2.0;
    double b = height / 2.0;

    // Calculate the center of the ellipse
    double centerX = x + a;
    double centerY = y + b;

    // Check if the point is inside the ellipse
    double term1 = ((px - centerX) * (px - centerX)) / (a * a);
    double term2 = ((py - centerY) * (py - centerY)) / (b * b);
    
    return term1 + term2 <= 1.0;
}



Square::Square(double x, double y, double size) {
    setLocation(x, y); 
    this->size = size; 
}

void Square::draw(GWindow& gw) {
    gw.setColor(color);
    gw.fillRect(x, y, size, size);
}
