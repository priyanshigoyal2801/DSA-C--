#include <iostream>

void print_diamond_recursive(int n, int row) {
  if (row <= 0) {
    return;
  }

  // Print spaces for indentation
  

  // Print stars
  for (int i = 0; i < 2 * row - 1; ++i) {
    std::cout << "*";
  }
for (int i = 0; i < n - row; ++i) {
    std::cout << " ";
  }
  std::cout << std::endl;

  // Recursively print the next row
  print_diamond_recursive(n, row - 1);

  
  for (int i = 0; i < 2 * row - 1; ++i) {
    std::cout << "*";
  }// Print the same row again (for the bottom half)
  for (int i = 0; i < n - row; ++i) {
    std::cout << " ";
  }
  std::cout << std::endl;
}

int main() {
  int n;
  std::cout << "Enter the value of n: ";
  std::cin >> n;

  print_diamond_recursive(n, n);

  return 0;
}