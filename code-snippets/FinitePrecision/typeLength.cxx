#include <iostream>
using namespace std;
int main() {
  cout << "Size of char (bits): " << 8 * sizeof(char) << endl;
  cout << "Size of short int (bits): " << 8 * sizeof(short int) << endl;
  cout << "Size of int (bits): " << 8 * sizeof(int) << endl;
  cout << "Size of unsigned int (bits): " << 8 * sizeof(unsigned int) << endl;
  cout << "Size of float (bits): " << 8 * sizeof(float) << endl;
  cout << "Size of double (bits): " << 8 * sizeof(double) << endl;

  cout << "\nMore exotic types:\n";
  cout << "Size of long int (bits): " << 8 * sizeof(long int) << endl;
  cout << "Size of long long int (bits): " << 8 * sizeof(long long int) << endl;
  cout << "Size of long double (bits): " << 8 * sizeof(long double) << endl;

  return 0;
}
