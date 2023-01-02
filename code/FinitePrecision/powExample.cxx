#include <iostream>
using namespace std;

/**
 * \brief Template function. Intended to be called with double and float types.
 *
 * This function first divides the number testValue by a power of whichBase.
 * Then multiplies the result by the same power of whichBase and compares with
 * testValue. This is done below in two different ways.
 * - first way: testValue - (testValue/whichBase^power)*whichBase^power
 * - the second way: testValue - (testValue/whichBase/...)*whichBase^power
 *
 * In math form, the one-shot error is computed as \f$E_1 = x -
 * \left[x/(y^z)\right] \cdot y^z\f$. In the second case; i.e., the piecewise
 * approach, the error is computed as \f$E_2 = x - (x/y/y/y/.../y) \cdot y^z\f$,
 * where there are \f$z\f$ divisions of \f$x\f$ by \f$y\f$. Finite precision
 * arithmetic errors might prevent \f$E_1\f$ and \f$E_2\f$ from being zero. If
 * it wasn't for finite precision arithmetic we end up using in our
 * computations, the errors in both cases would be zero.
 *
 * \param powValue [in] See \f$z\f$ above
 * \param testValue [in] See \f$x\f$ above
 * \param whichBase [in] See \f$y\f$ above
 */
template <class T>
void measureError(unsigned short powValue, T testValue, T whichBase) {
  T refValueOneShot = testValue;
  T refValuePiecewise = testValue;

  T compoundVal = (T)1;

  for (unsigned short indx = 0; indx < powValue; indx++) {
    refValuePiecewise /= whichBase;
    compoundVal *= whichBase;
  }
  refValueOneShot /= (compoundVal);

  T resultOneShot = testValue - refValueOneShot * compoundVal;
  T resultPieceWise = testValue - refValuePiecewise * compoundVal;

  cout << "***********************************************\n";
  cout << "Power of base: " << powValue << endl;
  cout << "One shot error  : " << resultOneShot << endl;
  cout << "Piece-wise error: " << resultPieceWise << endl;
}

int main() {
  std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
  std::cout.precision(16);
  const unsigned short maxPow = 15;

  // Go with single precision
  float testValue_f = 3.3f;
  float base_f = 10.f;
  cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n";
  cout << "Test value: " << testValue_f << endl;
  cout << "Base value: " << base_f << endl;
  for (unsigned short i = 0; i < maxPow; i++)
    measureError<float>(i, testValue_f, base_f);

  // Go with double precision
  double testValue_d = 3.3;
  double base_d = 10.;
  cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n";
  cout << "Test value: " << testValue_d << endl;
  cout << "Base value: " << base_d << endl;
  for (unsigned short i = 0; i < maxPow; i++)
    measureError<double>(i, testValue_d, base_d);

  return 0;
}
