#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

  if (argc != 3) {
    cout << "This_program.exe infile.txt outfile.txt" << endl;
    return -1;
  }

  cout << "file name: " << argv[0] << endl;
  cout << "infile name: " << argv[1] << endl;
  cout << "outfile name: " << argv[2] << endl;

  char *infile = argv[1];
  char *outfile = argv[2];

  ifstream my_in(infile);

  if (!my_in.is_open()) {
    cout << "File " << infile << " is not opened!" << endl;
    return -2;
  }

  int a[3];
  my_in >> a[0] >> a[1] >> a[2];

  if (my_in.fail()) {
    cout << "Can't read file " << infile << endl;
    return -3;
  }
  my_in.close();

  ofstream my_out(outfile);
  if (!my_out.is_open()) {
    cout << "File " << outfile << " is not opened" << endl;
    return -2;
  }

  int sum = a[0] + a[1] + a[2];
  my_out << a[0] << " + " << a[1] << " + " << a[2] << " = " << sum << endl;
  my_out.close();

  return 0;
}
