#ifndef BEHAVIOR_TREE_NODES_H
#define BEHAVIOR_TREE_NODES_H

#include "behaviortree_cpp/bt_factory.h"
#include <iostream>

// ͬ�������ڵ� (�޶˿�)
class ApproachObject : public BT::SyncActionNode {
public:
  ApproachObject(const std::string &name, const BT::NodeConfig &config)
      : BT::SyncActionNode(name, config) {}

  // �˿��ǽڵ���ڰ壨Blackboard��֮��������ݽ����Ľӿ�
  // ����ʵ�־�̬�˿���������
  static BT::PortsList providedPorts() {
    return {}; // �޶˿�
  }

  BT::NodeStatus tick() override;
};

// ��צ���ƽӿ�
class GripperInterface {
public:
  GripperInterface() : _open(true) {}

  BT::NodeStatus open();
  BT::NodeStatus close();

private:
  bool _open = false;
  int _open_cnt = 0;
};

// ������ƽӿ�
class CameraInterface {
public:
  CameraInterface() : _open(true) {}

  BT::NodeStatus open();
  BT::NodeStatus close();

private:
  bool _open; // ����״̬
};

// ��ؼ�麯������
BT::NodeStatus CheckBattery();

#endif // BEHAVIOR_TREE_NODES_H
