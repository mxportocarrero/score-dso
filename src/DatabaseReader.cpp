#include "DatabaseReader.h"

DatabaseReader::DatabaseReader(int n)
{
  cout << "Creating a DatabaseReader" << endl;
  x = n;
}

DatabaseReader::~DatabaseReader()
{
  cout << "Destroying DatabaseReader" << endl;
}