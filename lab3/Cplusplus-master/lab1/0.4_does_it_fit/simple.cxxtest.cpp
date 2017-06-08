#include <cxxtest/TestSuite.h>

#include "count_if_followed_by.h"


class MyTestSuite : public CxxTest::TestSuite {
  public:
    void test1 () {
      char const  data[6] = {};
      int  const test_len = 4;

      int  const   result = count_if_followed_by (data, test_len, 'X', 'G');

      // SYNOPSIS:
      //   result should be 0 since there are no [X, G] in data.

      TS_ASSERT_EQUALS(result, 0);
    }

    void test2 () {
      char const  data[4] = {'G','G','X','G'};
      int  const test_len = 3;

      int  const   result = count_if_followed_by (data, test_len, 'X', 'G');

      // SYNOPSIS:
      //   result should be 0 unless the program have a bug.

      TS_ASSERT_EQUALS(result, 0);
    }

    void test3 () {
      char const  data[6] = {'X','G','X','G','X','G'};
      int  const test_len = 70;

      int  const   result = count_if_followed_by (data, test_len, 'X', 'G');

      // SYNOPSIS:
      //   result should be 3 since the data is 6 and it should not go out of bounds.

      TS_ASSERT_EQUALS(result, 3);
    }
};
