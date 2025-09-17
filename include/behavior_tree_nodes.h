#ifndef BEHAVIOR_TREE_NODES_H
#define BEHAVIOR_TREE_NODES_H

#include "behaviortree_cpp/bt_factory.h"
#include <iostream>

// 同步动作节点 (无端口)
class ApproachObject : public BT::SyncActionNode {
public:
  ApproachObject(const std::string &name, const BT::NodeConfig &config)
      : BT::SyncActionNode(name, config) {}

  // 端口是节点与黑板（Blackboard）之间进行数据交换的接口
  // 必须实现静态端口声明方法
  static BT::PortsList providedPorts() {
    return {}; // 无端口
  }

  BT::NodeStatus tick() override;
};

// 夹爪控制接口
class GripperInterface {
public:
  GripperInterface() : _open(true) {}

  BT::NodeStatus open();
  BT::NodeStatus close();

private:
  bool _open = false;
  int _open_cnt = 0;
};

// 相机控制接口
class CameraInterface {
public:
  CameraInterface() : _open(true) {}

  BT::NodeStatus open();
  BT::NodeStatus close();

private:
  bool _open; // 共享状态
};

// 电池检查函数声明
BT::NodeStatus CheckBattery();

#endif // BEHAVIOR_TREE_NODES_H
