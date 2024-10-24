#include <tuw_graph_msgs/graph.hpp>
#include <tuw_graph_msgs/graph_json.hpp>
#include <tuw_object_map_msgs/object_point_json.hpp>
#include <tuw_object_map_msgs/objects_json.hpp>
#include <tuw_json/json.hpp>

#include "gtest/gtest.h"

TEST(json, tuw_object_map_point_msgs)
{
  std::string filename = "/tmp/tuw_object_point_msgs.json";
  tuw_object_map_msgs::GeoPoint point(563938.78, 5183454.78, 296);
  tuw_geometry_msgs::Point wgs84(10.0, 20.0, 30.0);
  tuw_object_map_msgs::ObjectPoint o(wgs84);
  tuw_json::write(filename, "point", tuw_json::toJson(o)); 
}

TEST(json, tuw_object_map_msgs)
{
  std::string filename = "/tmp/tuw_object_map_msgs.json";
  tuw_geometry_msgs::Point pose0(563938.78, 5183454.78, 296);
  tuw_geometry_msgs::Point pose1(563923.96, 5183458.61, 299);
  tuw_object_map_msgs::Object obj0(0, tuw_object_map_msgs::msg::Object::TYPE_PLANT_WINE_ROW);
  obj0.map_points = {pose0, pose1};
  obj0.enflation_radius = {0.3, 0.3};
  obj0.bondary_radius = {2.0, 2.0};
  tuw_geometry_msgs::Point pose2(563887.05, 5183464.3, 305);
  tuw_geometry_msgs::Point pose3(563887.32, 5183467.21, 305);
  tuw_object_map_msgs::Object obj1(1, tuw_object_map_msgs::msg::Object::TYPE_PLANT_WINE_ROW);
  obj1.map_points = {pose2, pose3};
  obj1.enflation_radius = {0.3, 0.3};
  obj1.bondary_radius = {2.0, 2.0};

  tuw_object_map_msgs::Objects map;
  map.header.frame_id = "map";
  map.objects = {obj0, obj1};
  tuw_json::write(filename, "objects", tuw_json::toJson(map)); 
}
