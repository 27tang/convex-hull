#include <iostream>
using namespace std;

int main()
{
  long cycles = 0;
  long total = 0;
  cin >> cycles; cin.ignore();
  cin >> cycles; cin.ignore();
  cin >> cycles; cin.ignore();

  for(int i = 0; i < 10; ++i)
  {
    cin >> cycles; cin.ignore();
    total += cycles;
  
  }

  cout << total/10.0 << endl;


  }
