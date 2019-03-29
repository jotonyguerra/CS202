#include <iomanip>
/*

NOTES FROM 2/28. classes inhertance.
*/


/*

inheritance 
type				Base class member

				public			private			protected


public			*public			N/A				protected

private			private			N/A 			private

protected		protected						protected
*/
class rectangle
{

public:

	void setDim(double len, double width)
	{
		l = len;
		w = width;
	}
	double area() const 
	{
		return l*w;

	}
	double perimeter() const 
	{
		return 2*l + 2*w;
	}

private:

	double l, w;

};

//Square class inherits all public function from rectangle class.
class square : private rectangle //: private rectangle. // or public
{
	/* THESE FUNCTIONS ARE INHERITED but as private members.
	void setDim(double, double);
	double area() const;
	double perimeter() const;
	*/

	// N/A private members from recatngle are not derived so double l, w are not inherited.

public:

	void setDimSquare(double len)
	{
		//called private function setDim from rectangle within this function.
		setDim(len,len);
	}

	double areaSquare() const
	{
		return area(); // grabs the length width from setDim function.
	}
	double perimeterSquare() const
	{
		return perimeter(); // call private function from rectangle ^^^.

	}

	/// new class functions
	double area() const
	{
		return rectangle::area(); // example of function override. 
	}
};



//main function

int main()
{
	rectangle r;
	r.setDim(3.0, 4.0);
	cout << r.area() << endl; //should return 12
	square s;
	s.setDim(3.0, 3.0);

	//using square with private rectange inheritance

	square s;

	//s.setDim(3.0,3.0);// compiler error
	s.setDimSquare(3.0); // this calls the public function from class square.
}