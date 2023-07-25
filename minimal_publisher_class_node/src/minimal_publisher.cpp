#include <rclcpp/rclcpp.hpp>
#include <rclcpp/qos.hpp>
#include <example_interfaces/msg/string.hpp>
#include "minimal_publisher.hpp"

using namespace std::chrono_literals;

MinimalPublisher::MinimalPublisher(
    const std::string& name_space,
    const rclcpp::NodeOptions& options
): Node("minimal_publisher",name_space,options), count_(0){
    publisher_ = this->create_publisher<example_interfaces::msg::String>("topic_test",rclcpp::QoS(10));
    //create_wall_timerの引数は、コールバック関数と、周期を指定する
    timer_ = this->create_wall_timer(
        500ms,
        [this](){
            auto msg = std::make_shared<example_interfaces::msg::String>();
            msg->data = "Hello "+ std::to_string(count_++);
            RCLCPP_INFO(this->get_logger(),"Pub %s",msg->data.c_str());
            publisher_->publish(*msg);
        }
    );
}