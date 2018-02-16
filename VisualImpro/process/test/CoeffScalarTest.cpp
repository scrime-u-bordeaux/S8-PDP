#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE CoeffScalarTest
#include "../CoeffScalar.hpp"
#include <boost/test/unit_test.hpp>

#define N 1000

using namespace std;

BOOST_AUTO_TEST_CASE(coeff_scalar_test) {
  std::vector<float> v(N, 1.0f);
  BOOST_CHECK(CoeffScalar(v, v) == 1.0f);
}
