#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include <chrono>
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(int argc, char **argv)
{
  // expects two command-line arguments, the data size (an integer) and the number of repetitions (an integer)
  std::string arg(argv[1]);
  // string stream is used to convert string to int if using C++03 or earlier
  std::stringstream ss(arg);
  int N;
  ss >> N;

  int reps;
  arg = argv[2];
  ss.clear();
  ss.str(arg);
  ss >> reps;

  // create random numbers
  // before beginning the timer
  unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_int_distribution<int> distribution(-100 * N, 100 * N);

  std::vector<std::vector<int>> nums(reps);
  int i, j;
  for (j = 0; j < reps; j++)
  {
    for (i = 0; i < N; i++)
    {
      int r = distribution(generator);
      nums[j].push_back(r);
    }
  }

  // sort numbers
  clock_t t1 = clock();
  for (i = 0; i < reps; i++)
  {
    std::sort(nums[i].begin(), nums[i].end());
  }
  clock_t t2 = clock();
  clock_t dt = t2 - t1;
  double clocks_per_rep = ((double)dt) / reps;
  double seconds = clocks_per_rep / CLOCKS_PER_SEC;

  //std::cout << "time: " << dt << " " << seconds << std::endl;
  std::cout << N << "," << seconds << std::endl;

  // // show we're done
  // for(i = 0; i < N; i++)
  //   {
  //     std::cout << i << " " << nums[i] << std::endl;
  //   }

  return 0;
}
