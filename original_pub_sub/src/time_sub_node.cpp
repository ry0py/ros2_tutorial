#include <rclcpp/rclcpp.hpp>
#include "time_sub_node.hpp"

TimeSubscriber::TimeSubscriber(const rclcpp::NodeOptions options)
: Node("time_node",options){
    time_sub = this->create_subscription<std_msgs::msg::Int16>(
        "time_topic",10,std::bind(&TimeSubscriber::TimeCallback,this,std::placeholders::_1)
    );
}
void TimeSubscriber::TimeCallback(std_msgs::msg::Int16 msg){
    RCLCPP_INFO(this->get_logger(),"時間は%d",msg.data);
}