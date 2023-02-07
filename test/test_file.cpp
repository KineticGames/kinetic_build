#include <gtest/gtest.h>

extern "C" {
#include <library.h>
}

TEST(LibraryTests, basic_assert) { ASSERT_EQ(2 + 2, 4); }
