#include "mac.h"
#include <stdint.h>

static void mac_baseline(int32_t *a, int32_t b, int32_t c) { *a += b * c; }

int main() {
  int32_t a_base = 9;
  int32_t a_mac = a_base;
  int32_t b = 3;
  int32_t c = 5;
  mac_baseline(&a_base, b, c);
  MAC(a_mac, b, c);
  return a_base == a_mac ? 1 : -1;
}
