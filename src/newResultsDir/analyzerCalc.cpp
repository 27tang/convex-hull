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
  
  int numOfResults = 0;
  int N = 0;

  cin >> numOfResults; cin.ignore();
  
  double bruteTimes[numOfResults];
  double quickTimes[numOfResults];
  double percentDiffs[numOfResults];
  int Nvalues[numOfResults];
  double theoRatios[numOfResults];
  double empiricalRatios[numOfResults];

  for(int i = 0; i < numOfResults; ++i)
  {
    cin >> Nvalues[i]; cin.ignore();
  
    cin >> bruteTimes[i]; cin.ignore();
  }
  for(int i = 0; i < numOfResults; ++i)
  {
    cin >> N; cin.ignore();
  
    cin >> quickTimes[i]; cin.ignore();
  }

  for(int i = 0; i < numOfResults; ++i)
  {
    empiricalRatios[i] = bruteTimes[i]/quickTimes[i];
    theoRatios[i] = bruteTheory(N)/quickTheory(N);
    double percentDiff = (theoRatios[i] - empiricalRatios[i])/theoRatios[i];
    
    percentDiff = percentDiff * 100;
    percentDiffs[i] = percentDiff;
  }


  for(int i = 0; i < numOfResults; ++i)
  {
    cout << "N: " << Nvalues[i] << endl;
    cout << "theo ratio: " << theoRatios[i] << endl;
    cout << "emp ratio: " << empiricalRatios[i] << endl;
    cout << "Percent difference between theoretical and empirical ratios: " << percentDiffs[i] << "%" << endl;
  }
  return 0;
}

