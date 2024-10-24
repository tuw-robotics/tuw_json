#include <tuw_std_msgs/value_float64_json.hpp>
#include <tuw_json/json.hpp>

#include "gtest/gtest.h"

TEST(json, value_float64_json)
{
  std::string filename = "/tmp/value_float64_json.json";
  tuw_std_msgs::ValueFloat64 o("Radius", 3.52);
  tuw_json::write(filename, "point", tuw_json::toJson(o)); 
}
