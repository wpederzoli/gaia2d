#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
    private:
        int x, y, width, height;
    
    public:
        Rectangle();
        Rectangle(int x, int y, int width, int height);
        ~Rectangle();

        void set(int x, int y, int width, int height);
        void setPosition(int x, int y);
        void setSize(int width, int height);
        void setX(int x);
        void setY(int y);
        void setWidth(int width);
        void setHeight(int height);
        void setX2(int x2);
        void setY2(int y2);
        void setCenterX(int x);
        void setCenterY(int y);

        int getX();
        int getY();
        int getWidth();
        int getHeight();
        int getX2();
        int getY2();
        int getCenterX();
        int getCenterY();

        bool overlaps(Rectangle rect);
        bool contains(int x, int y);
};

#endif