#include <gtest/gtest.h>
#include "../classes/Triangle.h"

TEST(Tests, TriangleTest) {
  Triangle t;
  t.setSides(3, 4, 5);

  EXPECT_EQ(t.calculatePerimeter(), 12);
}
