#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/msg/string.hpp>

class MinimalPublisher :rclcpp::Node{
public:
    MinimalPublisher(const std::string& name_space = "",
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions());
private:
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    //同じこと？
    //std::shared_ptr<rclcpp::Pblisher<example_interfaces::msg::String>> publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    size_t count_;
};