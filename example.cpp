#include <iostream>
#include <cstring>
using namespace std;

struct student {
  char name[10];
  int id;
  float gpa;
};

int main()
{
  student george;
  cin >> george.name;
  george.id = 12354;
  george.gpa = 3.0;

  cout << "Name: " << george.name << " ID: " << george.id << " GPA:" << george.gpa << endl;
  
  return 0;
}
