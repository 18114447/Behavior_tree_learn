#include "behavior_tree_nodes.h"

BT::NodeStatus CameraInterface::open() {
  _open = true;
  std::cout << "camerainterface:: open" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus CameraInterface::close() {
  _open = false;
  std::cout << "camerainterface:: close" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus GripperInterface::open() {
  _open = true;
  std::cout << "GripperInterface::open successfully!" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus GripperInterface::close() {
  _open = false;
  std::cout << "GripperInterface:: close" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus CheckBattery() {
  std::cout << "[ Battery: OK ]" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus ApproachObject::tick() {
  std::cout << "ApproachObject: approach_object" << std::endl;
  return BT::NodeStatus::SUCCESS;
}