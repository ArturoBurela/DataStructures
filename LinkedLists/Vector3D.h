#include <iostream>
/*
Class to store vectors in 3D space

Arturo Burela A01019906
*/
using namespace std;
class Vector3D {
private:
  double x;
  double y;
  double z;
public:
  Vector3D (double _x=0, double _y=0, double _z=0);//Default values, only set the values in the function declarations in headers
  void setCoordinates(double _x=0, double _y=0, double _z=0);
  Vector3D & operator= (const Vector3D & other);
  Vector3D & operator += (const Vector3D & other);
  Vector3D & operator-= (const Vector3D & other);
  const Vector3D operator + (const Vector3D & other);
  const Vector3D operator - (const Vector3D & other);
  bool operator== (const Vector3D & other);
  bool operator!= (const Vector3D & other);

  friend ostream & operator<< (ostream & stream, const Vector3D & vector);
};
