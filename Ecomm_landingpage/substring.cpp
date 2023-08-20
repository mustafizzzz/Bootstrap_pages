#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool possibleToBloom(vector<int> &bloomDay, int day, int m, int k)
{
  int cnt = 0;
  int boquets = 0;
  for (int i = 0; i < bloomDay.size(); i++)
  {
    if (bloomDay[i] <= day)
    {
      cnt++;
    }
    else
    {
      boquets += (cnt / k);
      cnt = 0;
    }
  }
  // end case
  boquets += (cnt / k);
  cout << "Possible boq: " << boquets << " >= " << m << "Days is : " << day << endl;

  return boquets >= m;
}

int main()
{

  vector<int> bloomDay = {1, 10, 3, 10, 2};
  int m = 3;
  int k = 1;
  long long val = m * 1LL * k * 1LL;

  if (bloomDay.size() < val)
  {
    cout << "Not Valid" << endl;
  }

  int mini = INT_MAX, maxi = INT_MIN;
  for (int i = 0; i < bloomDay.size(); i++)
  {
    mini = min(mini, bloomDay[i]);
    maxi = max(maxi, bloomDay[i]);
  }
  int s = mini;
  int e = maxi;
  cout << "S: " << s << endl;
  cout << "E: " << e << endl;
  int mid = s + (e - s) / 2;
  int ans = e;

  while (s <= e)
  {
    int mid = s + (e - s) / 2;

    if (possibleToBloom(bloomDay, mid, m, k) == true)
    {
      e = mid - 1;
      ans = min(ans, mid);
      cout << "Mid is " << mid << endl;
    }
    else
    {
      s = mid + 1;
    }
    mid = s + (e - s) / 2;
  }

  cout << "Final : " << ans << endl;

  return 0;
}
