#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace Eigen;
using namespace std;

int main()
{
  Matrix3f ra, rb;
  ra = AngleAxisf(EIGEN_PI/4, Vector3f::UnitZ())
       * AngleAxisf(0, Vector3f::UnitY())
       * AngleAxisf(EIGEN_PI/3, Vector3f::UnitX());

  rb = AngleAxisf(0, Vector3f::UnitZ())
       * AngleAxisf(EIGEN_PI/4, Vector3f::UnitY())
       * AngleAxisf(-EIGEN_PI/3, Vector3f::UnitX());

  Quaternionf qa;
  Quaternionf qb;
  Quaternionf qc;
  Quaternionf qd;
  Quaternionf qe;
  Quaternionf qf;

  qa = ra;
  qb = rb;
  qc = qa * qb;
  qd = qb * qa;
  qe = qa * qb.inverse();
  qf = qe * qb;

  cout << "Ra matrix: \n";
  cout << ra << "\n\n" << endl;
  cout << "Rb matrix: \n";
  cout << rb << "\n\n" << endl;
  cout << "Ra quat: \n";
  cout << qa.w() << "\n" << qa.vec() << "\n\n" << endl;
  cout << "Rb quat: \n";
  cout << qb.w() << "\n" << qb.vec() << "\n\n" << endl;
  cout << "Qc quat: \n";
  cout << qc.w() << "\n" << qc.vec() << "\n\n" << endl;
  cout << "Qd quat: \n";
  cout << qd.w() << "\n" << qd.vec() << "\n\n" << endl;
  cout << "Qe quat: \n";
  cout << qe.w() << "\n" << qe.vec() << "\n\n" << endl;
  cout << "Qf quat: \n";
  cout << qf.w() << "\n" << qf.vec() << "\n\n" << endl;

}
