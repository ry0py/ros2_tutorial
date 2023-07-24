#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/msg/string.hpp>

class MinimalSubscriber : public rclcpp::Node{
public:
    // コンストラクタを二種類用意する
    // 一つは名前空間を指定しない場合、もう一つは名前空間を指定する場合
    //NodeOptionsはノードのオプションを指定するもので、
    //名前空間を指定する場合は、NodeOptionsに名前空間を指定する
    MinimalSubscriber(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());
    MinimalSubscriber(
        const std::string& name_space,
        const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
    );
private:
    // subscriberを作るときのお決まりの書き方
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr _subscription;
    void _topic_callback(const example_interfaces::msg::String::SharedPtr msg);

};