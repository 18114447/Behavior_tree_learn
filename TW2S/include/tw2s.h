#ifndef TW2S_H
#define TW2S_H

#include <behaviortree_cpp/bt_factory.h>
#include <iostream>

namespace BT {
//带输入端口的同步动作节点
class SaySomething : public SyncActionNode {
public:
  SaySomething(const std::string &name, const NodeConfig &config);
  //必须实现静态端口声明方法
  static PortsList providedPorts();

  //节点执行函数
  NodeStatus tick() override;
};

//带输出端口的同步动作节点
class ThinkWhatToSay : public SyncActionNode {
public:
  ThinkWhatToSay(const std::string &name, const NodeConfig &config);
  //必须实现静态端口声明方法
  static PortsList providedPorts();

  //节点执行函数
  NodeStatus tick() override;
  std::string _info = "The result is 42.";
};
} // namespace BT

#endif // TW2S_H
