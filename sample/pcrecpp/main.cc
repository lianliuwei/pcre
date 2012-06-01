#include "pcrecpp.h"

#define NULL_PTR ((void *)0)
// no support wchar_t*
// RE::no_arg is for sense the arg length. if you no need the 
int main(int argc, char** argv) {
  bool ret = pcrecpp::RE("Hello, (\\w)+").FullMatch("Hello, World");
  ret = pcrecpp::RE("Hel+o").FullMatch("Hello");
  
  // test floating point march
  // partten = ^[+-]?(\d+|\d+\.\d+)$
  string simple_floating_point("^[+-]?(\\d+|\\d+\\.\\d+)$");
  ret = pcrecpp::RE(simple_floating_point).FullMatch("1");
  ret = pcrecpp::RE(simple_floating_point).FullMatch("1.1");
  // partten = ^[+-]?(\d+|\d+\.\d+)([eE][+-]?\d+)?$
  string floating_point("^[+-]?(\\d+|\\d+\\.\\d+)([eE][+-]?\\d+)?$");
  ret = pcrecpp::RE(floating_point).FullMatch("1");
  ret = pcrecpp::RE(floating_point).FullMatch("1.1");
  ret = pcrecpp::RE(floating_point).FullMatch("1.1e1");
  ret = pcrecpp::RE(floating_point).FullMatch("1.1e-1");
  ret = pcrecpp::RE(floating_point).FullMatch("1.1e");
  // partten = ^([+-]?(\d+|\d+\.\d+)([eE][+-]?\d+)?)\s*(\w)*$
  string floating_point_with_unit("^([+-]?(\\d+|\\d+\\.\\d+)([eE][+-]?\\d+)?)\\s*(\\w*)$");
  ret = pcrecpp::RE(floating_point_with_unit).FullMatch("1.1e1");
  ret = pcrecpp::RE(floating_point_with_unit).FullMatch("1.1e-1");
  ret = pcrecpp::RE(floating_point_with_unit).FullMatch("1.1e");
  ret = pcrecpp::RE(floating_point_with_unit).FullMatch("1.1e1");
  ret = pcrecpp::RE(floating_point_with_unit).FullMatch("1.1e1 unit");
  string floating, unit;
  ret = pcrecpp::RE(floating_point_with_unit).FullMatch("1.1e1",
    &floating, NULL_PTR, NULL_PTR, &unit);
  ret = pcrecpp::RE(floating_point_with_unit).FullMatch("1.1e1 unit",
    &floating, NULL_PTR, NULL_PTR, &unit);
  ret = pcrecpp::RE(floating_point_with_unit).FullMatch("-123451.1e-123 verylong2unit",
    &floating, NULL_PTR, NULL_PTR, &unit);
  // extract to double
  double value;
  ret = pcrecpp::RE(floating_point_with_unit).FullMatch("-123451.1e-123 verylong2unit",
    &value, NULL_PTR, NULL_PTR, &unit);
  // partten = ^[+-]?((\d*)|(\d+\.\d*)|((\d+|\d+\.\d+)[eE][+-]?\d*)|((\d+|\d+\.\d+)([eE][+-]?\d+)?\s*\w*))$
  string part_match("^[+-]?((\\d*)|(\\d+\\.\\d*)|((\\d+|\\d+\\.\\d+)[eE][+-]?\\d*)|((\\d+|\\d+\\.\\d+)([eE][+-]?\\d+)?\\s*\\w*))$");
  ret = pcrecpp::RE(part_match).FullMatch("1");

  return 0;
}