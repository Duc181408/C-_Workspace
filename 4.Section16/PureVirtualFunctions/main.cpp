// Section 16
// Pure virtual functions and abstract base classes
#include <iostream>
#include <vector>

class Shape {			// Abstract Base class
private:
       // attributes common to all shapes
public:
      virtual void draw() = 0;	 // pure virtual function
      virtual void rotate() = 0;   // pure virtual function
      virtual ~Shape() { }
};

class Open_Shape: public Shape {    // Abstract class can not be created object from
public:
    virtual ~Open_Shape() { }
};

class Closed_Shape : public Shape {  // Abstract class
public:
    virtual ~Closed_Shape() { };
};

class Line: public Open_Shape {     // Concrete class can be create object from
public:
    virtual void draw() override {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line() {}
};

class Circle: public Closed_Shape {     // Concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a circle" << std::endl;
    }
    virtual ~Circle() {}
};

class Square: public Closed_Shape {     // Concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a square" << std::endl;
    }
    virtual ~Square() {}
};


void screen_refresh(const std::vector<Shape *> &shapes) {
    std::cout << "Refreshing" << std::endl;
    for (const auto p: shapes) 
        p->draw();
}

int main() {
//    Shape s;
//    Shape *p = new Shape();

//        Circle c;
//        c.draw();

//    Shape *ptr = new Circle();
//    ptr->draw();
//    ptr->rotate();

    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();
    
    std::vector<Shape *> shapes {s1,s2,s3};
    
//    for (const auto p: shapes) 
//        p->draw();
        
    screen_refresh(shapes);
    
    delete s1;
    delete s2;
    delete s3;
    
    return 0;
}

// Lưu ý cho pure virtual function:
// 	1. Class được coi là abstract class nếu nó chứa ít nhất 1 pure virtual function. Không thể tạo ra object từ abstract class 
// 	(Do  có hàm được định nghĩa pure)
// 	2. Ta có thể sử dụng con trỏ/ tham chiếu kiểu Base trỏ đến Derived.
// 	3. Nếu không override pure virtual function ở Derived class, Derived class cũng trở thành một abstract class.
// 	4. Abstract class có thể có constructor
// Tương tự với struct
