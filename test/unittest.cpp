#include <tuw_graph_msgs/graph.hpp>
#include <tuw_graph_msgs/graph_json.hpp>
#include <tuw_json/json.hpp>

#include "gtest/gtest.h"

TEST(json, tuw_geometry_msgs)
{
  std::string filename = "/tmp/tuw_json.json";
  tuw_geometry_msgs::Pose pose0(0, 0, 0);
  tuw_geometry_msgs::Pose pose1(1, 0, 0);
  tuw_geometry_msgs::Pose pose2(2, 0, 0);
  tuw_geometry_msgs::Pose pose3(2, 1, 0);
  tuw_geometry_msgs::Pose pose4(3, 1, 0);
  tuw_geometry_msgs::Pose pose5(5, 5, 0);
  tuw_graph_msgs::Node node0(0, pose0);
  tuw_graph_msgs::Node node1(1, pose4);
  tuw_graph_msgs::Node node2(2, pose5);
  tuw_graph_msgs::Edge edge0(1, true, true, 0.2, 0, 1);
  edge0.path = {pose1, pose2, pose3};
  edge0.flags.push_back(tuw_graph_msgs::msg::Edge::FLAG_OPEN);
  tuw_graph_msgs::Edge edge1(2, false, false, 0.3, 1, 2);
  tuw_graph_msgs::Graph graph0("r0_map", tuw_geometry_msgs::Pose(-1, -2, 0));
  graph0.edges = {edge0, edge1};
  graph0.nodes = {node0, node1, node2};
  tuw_json::write(filename, "graph", tuw_json::toJson(graph0));

  tuw_graph_msgs::Graph graph1;
  tuw_json::fromJson(tuw_json::read(filename, "graph"), graph1);
  ASSERT_EQ(graph0, graph1);
  ASSERT_EQ(graph1.nodes[0].id, node0.id);
  ASSERT_EQ(graph1.nodes[1].id, node1.id);
  ASSERT_NE(graph1.nodes[1].id, node0.id);
  ASSERT_EQ(graph1.edges[0], edge0);
  ASSERT_EQ(graph1.edges[1], edge1);
  ASSERT_NE(graph1.edges[1], edge0);
}
