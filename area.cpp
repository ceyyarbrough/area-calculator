#include <iostream>
#include <typeinfo>       // operator typeid
#include <exception>      // exception handler
using namespace std;

class Shape{//master class for circle and class
public:
        void setRadius(int r){//function to set radius
            try{//starts exception handling at beginning of function
                radius = r;
                if (radius <= 0){
                    throw r;//checks value for invalid dimmnsions
                }
            }
                catch(int e){//stores value for the exception
                    cout<< "This not a valid radius"<< endl;

                }
        }
        //The same concept is used with different variables
        void setLength(int l){
            try{
                length = l;
                if (length <= 0){
                    throw l;
                }
            }
                catch(int e){
                    cout<< "This not a valid length" << endl;

                }


        }
protected://restricted variables in class
        int radius;
        int length;
};
//first derived class storing type of shape
class Square: public Shape{
public:
    //function for area to be called after input
    int getArea(){
        return (length * 4);
    }
};
class Circle: public Shape{
public:
    int getArea(){
        return (radius * radius) * 3.14;
    }
};



int main(){
    //declares selector character when selecting circle or square
	char selector;
	int num;

	cout << "Circle or Square?" << endl;
	cout << "Enter either c for circle, or s for square" << endl;
	//initiates selector
	cin >> selector;
    //if square
	if(selector == 's'){
		//square1 as Square object
		Square square1;
		cout << "Enter Length "<< endl;
		//num stores value for setLength function
		cin >> num;
		square1.setLength(num);

        //initiates getArea function and prints to console
		cout << "Area is: " << square1.getArea() << endl;
		return 1;


	}
	//the same concept applied to square1
	else if(selector == 'c'){
		Circle circle1;
		cout << "Enter Radius" << endl;
		cin >> num;
		circle1.setRadius(num);


		cout << "Area is: " << circle1.getArea() << endl;
		return 1;


	} else {
		cout<< "Error. Invalid Input";
		return 0;
	}


}
