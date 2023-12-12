#include <deepstate/DeepState.hpp>
#include "BlackJack.h"
using namespace deepstate;

#define MAX_CARDS 52

TEST(SimpleBlackJack, ConvertJKQ_Fail) {
  // Generate an input that should fail the expected conditions
  int a = DeepState_Int();
  LOG(TRACE) << "Generated input: " << a;

  int result = convert_jkq(a);

  // Intentionally fail the test if the expected condition is met
  ASSERT_FALSE((a % 100 >= 11 && a % 100 <= 13) && result != (a / 100) * 100 + 10);
}

TEST(SimpleBlackJack, ConvertJKQ) {
  int a = DeepState_IntInRange(1, 13);
  int result = convert_jkq(a);

  if ((a % 100 >= 11 && a % 100 <= 13)) {
    LOG(TRACE);
    ASSERT_EQ(result, (a / 100) * 100 + 10);
  } else {
    LOG(TRACE);
    ASSERT_EQ(result, a);
  }
}
