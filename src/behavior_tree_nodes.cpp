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
  if (_open_cnt < 2) {
    _open_cnt++;
    std::cout << "\033[1;31m"
              << "GripperInterface::open failed!"
              << "\033[0m" << std::endl;
    return BT::NodeStatus::FAILURE;
  }
  _open = true;
  _open_cnt = 0;
  std::cout << "\033[1;32m"
            << "GripperInterface::open successfully!"
            << "\033[0m" << std::endl;
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