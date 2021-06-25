#include <iostream>
#include <memory>

#include "DatabaseReader.h"

/*
GLOBAL VARIABLES
*/
int numTrees = 5;

using namespace std;

int main()
{
  cout << "Hello World!" << endl;
  shared_ptr<DatabaseReader> reader(new DatabaseReader(4));

  return 0;
}