#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include <chrono>
#include <iostream>
#include <ctime>
#include <cstdlib>

int fib_1(int n)
{
  if (n == 0)
  {
    return 0;
  }
  else if (n == 1)
  {
    return 1;
  }
  else
  {
    int f = fib_1(n - 1) + fib_1(n - 2);
    std::cout << "This is f: " << f << std::endl;
    return f;
  }
}

int fib_2(int n)
{
  if (n == 0)
  {
    return 0;
  }
  std::vector<int> f(n);
  f[0] = 0;
  f[1] = 1;
  int i;
  for (i = 2; i < n; i++)
  {
    f[i] = f[i - 1] + f[i - 2];
  }
  return f[n];
}

int main(int argc, char **argv)
{
  // argv[1] is the fibanacci number that should be calculated ( 1 - 40 )
  std::string arg(argv[1]);
  std::stringstream ss(arg);
  int N;
  ss >> N;

  // reps (argv[2]) are the number of times it's performed on a single term
  int reps;
  arg = argv[2];
  ss.clear();
  ss.str(arg);
  ss >> reps;

  clock_t t1 = clock();
  int i;
  for (i = 0; i < reps; i++)
  {
    int s = fib_1(N);
  }
  clock_t t2 = clock();
  clock_t dt = t2 - t1;
  double clocks_per_rep = ((double)dt);
  double seconds = clocks_per_rep / CLOCKS_PER_SEC;

  //std::cout << "time: " << dt << " " << seconds << std::endl;
  std::cout << N << "," << seconds << std::endl;

  return 0;
}
