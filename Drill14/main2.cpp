#include <iostream>

using namespace std;

struct B1{
	public:
		virtual void pvf() const { cout<<"B1::pvf\n";}
		virtual void vf() const {cout<<"B1::vf\n";};
		void f() const {cout<<"B1::f\n";};

};

struct D1 : B1{
	public:
		virtual void pvf() const { cout<<"D1::pvf\n";}
		void vf() const override {cout<<"D1::vf\n";};
		void f() const {cout<<"D1::f\n";};

};

struct D2 : D1{
	public:
		void pvf() const override {cout<<"D2::pvf\n";}
		void vf() const {cout<<"D2::vf\n";};
		void f() const {cout<<"D2::f\n";};

};

void call (const B1& b){
	b.pvf();
	b.vf();
	b.f();
};


struct B2{
	virtual void pvf() const=0;
};

struct D21 : B2{
	void pvf() const override {print_message(8.5);}
	void print_message(double a) const {cout<<"D21::pvf="<<a<<endl;}
};

struct D22 : B2{
	void pvf() const override {print_message(8.5);}
	void print_message(int a) const {cout<<"D22::pvf="<<a<<endl;}
};

void f (const B2& b){
	b.pvf();
};

int main()
{
   B1 b;
   D1 d;
   D2 dd;
   
   call(b);
   call(d);
   call(dd);
   
 
   D21 d21;
   D22 d22;
   
   f(d21);
   f(d22);
   
   cout<<"Call end\n";
	return 0;
}
