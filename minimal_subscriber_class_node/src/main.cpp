#include <rclcpp/rclcpp.hpp>
#include "minimal_subscriber.hpp"

int main(int argc,char * argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<MinimalSubscriber>()); //spinの中にノードを作る
    rclcpp::shutdown();
    return 0;
}