// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::depends(RcppThread)]]
#define R_NO_REMAP
#define RCPPTHREAD_OVERRIDE_THREAD 1
#include <Rcpp.h>
#include <cstdlib>
#include "../inst/include/libsegmentrr.h"

using namespace Rcpp;

//' Tiny Segmenter
//'
//' This function bridges between Rcpp and libsegmentrr
//'
//' @param v character vector
//' @return character vector
//'
//' @export
//'
// [[Rcpp::interfaces(r, cpp)]]
// [[Rcpp::export]]
Rcpp::CharacterVector segmenter(Rcpp::CharacterVector v) {

  char* response;

  std::function< Rcpp::String(Rcpp::String) > func = [&](Rcpp::String x) {
    const char* s = x.get_cstring();
    const std::size_t n = std::strlen(s);
    const std::ptrdiff_t len = n;
    const GoString m = { s, len };

    response = segment(m);
    const std::string res = response;

    const Rcpp::String result = res;
    return result;
  };

  const Rcpp::CharacterVector result = sapply(v, func);

  free(response);

  return result;
}
