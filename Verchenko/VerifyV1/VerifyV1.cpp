#include <iostream>
#include <climits>

using namespace std;

int swap(int value, int start, int len)

{

  len = len % (sizeof(value) * 8);

  start = start % (sizeof(value) * 8);



  int bits = (INT_MAX >> ((sizeof(value) * 8) - len - 1));

  bits = bits << start;



  int buf = (value >> len) & bits;

  int res = value & bits;

  res = res << len;

  res |= buf;



  int rest = value & ~bits;

  rest = rest & ~(bits << len);



  return rest | res;

}



//////////////////////////////////////////////////////

void scrambler(int keyword)

{

  int res = keyword;

  for (int i = 1; i < 16; i = i * 2)

  {

    for (int j = 0; j < 32 - i; j = j + i * 2)

      res = swap(res, j, i);

  }



  if (res == 1268560121)

    std::cout << "Password is correct\n";

  else

    std::cout << "Password is wrong\n";
    std::cout << res;

}
// 
int main() {
    int res;
    cin >> res;
    scrambler(res);
}