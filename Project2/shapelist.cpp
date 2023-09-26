#include "shapelist.h"

void ShapeList::moveToFront(shape *sp) {
    int index = -1;
    for (int i = 0; i < size(); i++) {
        if (get(i) == sp) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        shape *temp = get(index);
        remove(index);
        add(temp);
    }
}

void ShapeList::moveToBack(shape *sp) {
    int index = -1;
    for (int i = 0; i < size(); i++) {
        if (get(i) == sp) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        shape *temp = get(index);
        remove(index);
        insert(0, temp);
    }
}

void ShapeList::moveForward(shape *sp) {
    int index = -1;
    for (int i = 0; i < size(); i++) {
        if (get(i) == sp) {
            index = i;
            break;
        }
    }
    if (index != -1 && index < size() - 1) {
        shape *temp = get(index);
        remove(index);
        insert(index + 1, temp);
    }
}

void ShapeList::moveBackward(shape *sp) {
    int index = -1;
    for (int i = 0; i < size(); i++) {
        if (get(i) == sp) {
            index = i;
            break;
        }
    }
    if (index != -1 && index > 0) {
        shape *temp = get(index);
        remove(index);
        insert(index - 1, temp);
    }
}
shape *ShapeList::getShapeAt(double x, double y) const {
    for (int i = size() - 1; i >= 0; i--) {
        shape *sp = get(i);
        if (sp->contains(x, y)) {
            return sp; // Return the first shape that contains the point
        }
    }
    return nullptr; // No shape contains the point
}