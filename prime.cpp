#include <iostream>
using namespace std;
int main()
{
   int n;
   float temp;
   cin >> n;
   for (int j = 2; j <= (n - 1); j++)
   {
      temp = (n % j);
      if (temp == 0)
         cout << ("This number is not prime");
      break;
   }
   return 0;
}
