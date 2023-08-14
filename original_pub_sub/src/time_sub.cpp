#include <std_msgs/msg/int16.hpp>
#include <rclcpp/rclcpp.hpp>

class TimeSubNode :public rclcpp::Node{
public:
    TimeSubNode():Node("time_sub_node"){
        time_sub_ = this->create_subscription<std_msgs::msg::Int16>
        ("time_topic",10,std::bind(&TimeSubNode::TimeCallback,this,std::placeholders::_1));
    }
private:
    std::shared_ptr<rclcpp::Subscription<std_msgs::msg::Int16>> time_sub_;
    void TimeCallback(const std_msgs::msg::Int16 &msg){
        RCLCPP_INFO(this->get_logger(),"Subscribe: %d",msg.data);
    }
};
int main(int argc, char * argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<TimeSubNode>());
    rclcpp::shutdown();
}
