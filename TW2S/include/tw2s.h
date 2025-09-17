#ifndef TW2S_H
#define TW2S_H

#include <behaviortree_cpp/bt_factory.h>
#include <iostream>

namespace BT {
//������˿ڵ�ͬ�������ڵ�
class SaySomething : public SyncActionNode {
public:
  SaySomething(const std::string &name, const NodeConfig &config);
  //����ʵ�־�̬�˿���������
  static PortsList providedPorts();

  //�ڵ�ִ�к���
  NodeStatus tick() override;
};

//������˿ڵ�ͬ�������ڵ�
class ThinkWhatToSay : public SyncActionNode {
public:
  ThinkWhatToSay(const std::string &name, const NodeConfig &config);
  //����ʵ�־�̬�˿���������
  static PortsList providedPorts();

  //�ڵ�ִ�к���
  NodeStatus tick() override;
  std::string _info = "The result is 42.";
};
} // namespace BT

#endif // TW2S_H
