#include <tuw_std_msgs/parameter_float64_json.hpp>
#include <tuw_std_msgs/parameter_json.hpp>

#include <tuw_json/json.hpp>

#include "gtest/gtest.h"

TEST(json, parameter_float64_json)
{
  std::string filename = "/tmp/parameter_float64_json.json";
  double data = 3.52;
  tuw_std_msgs::ParameterFloat64 src("Radius", data);
  tuw_json::write(filename, "value", tuw_json::toJson(src));
  tuw_std_msgs::ParameterFloat64 des;
  tuw_json::fromJson(tuw_json::read(filename, "value"), des);
  ASSERT_EQ(des.name, src.name);
  ASSERT_NEAR(des.get(), data, 1e-6);
}
TEST(json, generic_parameter)
{
  {
    std::string filename = "/tmp/generic_parameter_float.json";
    double value = 3.52;
    tuw_std_msgs::Parameter src("Radius", value);
    tuw_json::write(filename, "float", tuw_json::toJson(src));
    tuw_std_msgs::Parameter des;
    tuw_json::fromJson(tuw_json::read(filename, "float"), des);
    ASSERT_EQ(des.name, src.name);
    ASSERT_EQ(des.value, src.value);
    ASSERT_EQ(des.type, src.type);
  }

  {
    std::string filename = "/tmp/generic_parameter_int.json";
    tuw_std_msgs::Parameter src("count", 445);
    tuw_json::write(filename, "int", tuw_json::toJson(src));
    tuw_std_msgs::Parameter des;
    tuw_json::fromJson(tuw_json::read(filename, "int"), des);
    ASSERT_EQ(des.name, src.name);
    ASSERT_EQ(des.value, src.value);
    ASSERT_EQ(des.type, src.type);
  }

  {
    std::string filename = "/tmp/generic_parameter_float_array.json";
    std::vector<double> data = {1.23, 4.56, 7.89};
    tuw_std_msgs::Parameter src("timeings", data);
    tuw_json::write(filename, "float_array", tuw_json::toJson(src));
    tuw_std_msgs::Parameter des;
    tuw_json::fromJson(tuw_json::read(filename, "float_array"), des);
    ASSERT_EQ(des.name, src.name);
    ASSERT_EQ(des.value, src.value);
    ASSERT_EQ(des.type, src.type);
    std::vector<double> data_des;
    des.get(data_des);
    ASSERT_EQ(data, data_des);
  }

  {
    std::string filename = "/tmp/generic_parameter_int_array.json";
    std::vector<int> data = {1, 4, 7};
    tuw_std_msgs::Parameter src("countings", data);
    tuw_json::write(filename, "int_array", tuw_json::toJson(src));
    tuw_std_msgs::Parameter des;
    tuw_json::fromJson(tuw_json::read(filename, "int_array"), des);
    ASSERT_EQ(des.name, src.name);
    ASSERT_EQ(des.value, src.value);
    ASSERT_EQ(des.type, src.type);
    std::vector<int> data_des;
    des.get(data_des);
    ASSERT_EQ(data, data_des);
  }
}
