#include <rclcpp/rclcpp.hpp>
#include <rclcpp/qos.hpp>
#include <example_interfaces/msg/string.hpp>
#include "minimal_subscriber.hpp"

void MinimalSubscriber::_topic_callback(const example_interfaces::msg::String::SharedPtr msg){
    RCLCPP_INFO(this->get_logger(),"I heard:%s",msg->data.c_str());
}
// 名前空間を指定する場合のコンストラクタ
// このコンストラクタが呼ばれた時の初期化処理を書いている
MinimalSubscriber::MinimalSubscriber(
    const rclcpp::NodeOptions& options
): MinimalSubscriber("",options){} //このコンストラクタは直後に定義されている

//ここ以下が大きく書き換えるところ
MinimalSubscriber::MinimalSubscriber(
    const std::string& name_space,
    const rclcpp::NodeOptions& options
): Node("minimal_subscriber",name_space,options){ //ここでNodeを初期化している
    // subscriberを作るときのお決まりの書き方
    _subscription = this->create_subscription<example_interfaces::msg::String>(
        "topic_test",
        rclcpp::QoS(10),//Quality of Serviceの設定
        std::bind(&MinimalSubscriber::_topic_callback,this,std::placeholders::_1)
    );

}