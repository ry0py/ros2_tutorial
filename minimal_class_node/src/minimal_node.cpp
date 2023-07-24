#include <rclcpp/rclcpp.hpp>
#include "minimal_node.hpp"

MinimalNode::MinimalNode(const std::string& name_space,const rclcpp::NodeOptions& options)
//nodeの名前をminimal_node_testにしている
: Node("minimal_node_test" , name_space,options){
    RCLCPP_INFO(this->get_logger(),"minimal_node_test");
}