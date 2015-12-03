#include <bits/stdc++.h>

using namespace std;


double bruteTheory(int N)
{
  double result;
  result = N*N*N;
  return result;
}
double quickTheory(int N)
{
  double result;
  result = N * log10(N);
  return result;
}


int main ()
{
  
  int N = 0;
  double bruteTime = 0;
  double quickTime = 0;

  cout << "Enter input size N: " << endl;
  cin >> N; cin.ignore();

  cout << "Enter brute-force performance time(cycles): " << endl;
  cin >> bruteTime; cin.ignore();

  cout << "Enter quick-hull performance time(cycles): " << endl;
  cin >> quickTime; cin.ignore();

  double empiricalRatio = bruteTime/quickTime;
  double theoRatio = bruteTheory(N)/quickTheory(N);

  double percentDiff = (theoRatio - empiricalRatio)/theoRatio;
  percentDiff = percentDiff * 100;

  cout << "Percent difference between theoretical and empirical ratios: " << percentDiff << "%" << endl;

  return 0;
}



