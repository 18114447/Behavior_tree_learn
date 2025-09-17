#include "gp.h"

using namespace BTNodes;
// CalculateGoal 实现
CalculateGoal::CalculateGoal(const std::string &name,
                             const BT::NodeConfig &config)
    : BT::SyncActionNode(name, config) {}

BT::PortsList CalculateGoal::providedPorts() {
  return {BT::OutputPort<Pose2D>("goal")};
}

BT::NodeStatus CalculateGoal::tick() {
  // 设置目标位置
  Pose2D mygoal = {1.1, 2.3, 0.0};
  setOutput<Pose2D>("goal", mygoal);
  return BT::NodeStatus::SUCCESS;
}

// PrintTarget 实现
PrintTarget::PrintTarget(const std::string &name, const BT::NodeConfig &config)
    : BT::SyncActionNode(name, config) {}

BT::PortsList PrintTarget::providedPorts() {
  // 可选：添加人类可读的描述
  const char *description = "打印目标位置到控制台";
  return {BT::InputPort<Pose2D>("target", description)};
}

BT::NodeStatus PrintTarget::tick() {
  auto res = getInput<Pose2D>("target");
  if (!res) {
    throw BT::RuntimeError("error reading port [target]: " + res.error());
  }
  Pose2D target = res.value();
  printf("目标位置: [%.1f, %.1f, %.1f]\n", target.x, target.y, target.yaw);
  return BT::NodeStatus::SUCCESS;
}
