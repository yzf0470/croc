#include "mac.h"
#include <stdint.h>

#define MIN_INT (1 << 31)
#define MAX_INT (~MIN_INT)

static void mac_baseline(int32_t *a, int32_t b, int32_t c) { *a += b * c; }

int failed_case = -1;
int test_case = 0;
static int check_mac(int32_t a, int32_t b, int32_t c) {
  int32_t a_mac = a;
  ++test_case;
  mac_baseline(&a, b, c);
  MAC(a_mac, b, c);
  if (a != a_mac && failed_case == -1) {
    failed_case = test_case;
  }
}
int main() {

  // Standard positive numbers
  check_mac(5, 10, 20);
  // Zero multiplier
  check_mac(100, 0, 50);
  // Zero multiplicand
  check_mac(10, 50, 0);
  // Negative multiplicand
  check_mac(7, 3, -4);
  // Negative multiplier
  check_mac(15, -2, 8);
  // All zeros
  check_mac(0, 0, 0);
  // Large numbers
  check_mac(100000, 20000, 3000);
  // Negative acc
  check_mac(-20, 2, 15);
  // max positive
  check_mac(0, MAX_INT, 1);
  // max negative
  check_mac(0, 1, MIN_INT);

  // returns -1 on success, the number of the failed test case on failure
  return failed_case;
}
