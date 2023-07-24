#include <rclcpp/rclcpp.hpp>
//#include "minimal_class_node/minimal_node.hpp"
#include "minimal_node.hpp"

int main(int argc,char * argv[]){
    rclcpp::init(argc,argv);
    auto node = std::make_shared<MinimalNode>(); //nodeの作成
    rclcpp::spin(node);//実際にnodeを実行
    rclcpp::shutdown();
    return 0;
}