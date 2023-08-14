#include <chrono>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int16.hpp>
#include <std_msgs/msg/string.hpp>
using namespace std::chrono_literals;

class TimePubNode : public rclcpp::Node{
    public :
        //ただのコンストラクタ、インスタンス生成したときに初期化されるだけ
        TimePubNode():Node("time_pub_node"){
        time_pub_ = this->create_publisher<std_msgs::msg::Int16>("time_topic",10);
        // time_sub_ = this->create_subscription<std_msgs::msg::Int16>("time_topic",10,std::bind(&TimePubNode::TimerCallback,this,std::placeholders::_1));
        timer_ = this ->create_wall_timer(
            500ms,std::bind(&TimePubNode::TimerCallback,this));
        }
    private:
        std::shared_ptr<rclcpp::Publisher<std_msgs::msg::Int16>> time_pub_;
        // std::shared_ptr<rclcpp::Subscription<std_msgs::msg::Int16>> time_sub_;
        int count_ = 0;
        rclcpp::TimerBase::SharedPtr timer_;
        void TimerCallback(){
            auto msg = std_msgs::msg::Int16();
            msg.data = count_++;
            RCLCPP_INFO(this->get_logger(),"Publish: %d",msg.data);
            time_pub_->publish(msg);
        }    
};
int main(int argc,char * argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<TimePubNode>());
    rclcpp::shutdown();
}