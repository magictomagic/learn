#include <iostream>
#include <ranges>

int main()
{
  using namespace std::ranges;
  for (int i : views::iota(1)
    | views::transform( [] (int i) { return i*i; } )
    | views::filter( [] (int i) { return i % 4 == 0; } )
    | views::take(5)) {
    std::cout << i << ' ';
  }
    
  std::cout << '\n';
  // 4 16 36 64 100
}