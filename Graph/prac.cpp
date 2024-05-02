// #include <iostream>
// #include <algorithm>

// using namespace std;

// int max_length(int x, int y, int z) {
//   // Initialize the maximum length.
//   int max_length = 0;

//   // Check if x is greater than 0, and update the maximum length if it is.
//   if (x > 0) {
//     max_length = max(max_length, 2 * x);
//   }

//   // Check if y is greater than 0, and update the maximum length if it is.
//   if (y > 0) {
//     max_length = max(max_length, 2 * y);
//   }

//   // Check if z is greater than 0, and update the maximum length if it is.
//   if (z > 0) {
//     max_length = max(max_length, 2 * z - 1);
//   }

//   // Check if the maximum length is greater than 50.
//   if (max_length > 50) {
//     max_length = 50;
//   }

//   // Return the maximum length.
//   return max_length;
// }

// int main() {
//   // Initialize the values of x, y, and z.
//   int x = 2;
//   int y = 5;
//   int z = 1;

//   // Print the maximum length.
//   cout << max_length(x, y, z) << endl;

//   // Return 0.
//   return 0;
// }
#include <iostream>
#include <algorithm>
using namespace std;

int maxLength(int x, int y, int z) {
    int countAA = min(x, y);  // The maximum number of "AA" strings we can choose without forming "AAA"
    int countBB = min(y - countAA, z);  // The maximum number of "BB" strings we can choose without forming "BBB"

    return (countAA * 2) + (countBB * 2);
}

int main() {
    int x, y, z;
    cout << "Enter the values of x, y, and z: ";
    cin >> x >> y >> z;

    int maxLen = maxLength(x, y, z);
    cout << "Maximum possible length of the new string: " << maxLen << endl;

    return 0;
}
