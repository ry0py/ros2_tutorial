#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int16.hpp>

class TimeSubscriber :public rclcpp::Node{
    public:
        TimeSubscriber(rclcpp::NodeOptions options);
        void TimeCallback(std_msgs::msg::Int16 msg);
    private:
        rclcpp::Subscription<std_msgs::msg::Int16>::SharedPtr time_sub;
};
