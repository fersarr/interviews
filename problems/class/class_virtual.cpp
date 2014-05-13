#include <iostream>
using namespace std;

//using virtual methods


class Animal{
	protected:
		string name;
		int age;
		
	public:
		Animal(string _name,int _age){
			name=_name;
			age=_age;
		}
		virtual void sayHi(){
			cout<<"Animal: hello"<<endl;
		}
	
};

class Dog:public Animal{

	public:
		//Although the constructors and destructors of the base class are not inherited as constructors and destructors in the derived class, they are still called by the derived class's constructor. Unless otherwise specified, the constructors of derived classes
		//call the default constructors of their base classes (i.e., the constructor taking no arguments), which must exist.
		Dog(string _name,int _age):Animal(_name,_age){

		}
		virtual void sayHi(){
			cout<<"Dog: guau"<<endl;
		}
};


int main(){
	
	Animal animal=Animal("Pablo",21);
	animal.sayHi();
	
	//virtual only needed when using pointers or references, not when on stack
	Animal *perro=new Dog("maurice",29);
	perro->sayHi();
	
	//here the object is on the stack, so virtual doesn't help
	Animal perro2=Dog("maurice",29);
	perro2.sayHi();
	
}
