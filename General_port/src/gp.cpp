#include "gp.h"

using namespace BTNodes;
// CalculateGoal ʵ��
CalculateGoal::CalculateGoal(const std::string &name,
                             const BT::NodeConfig &config)
    : BT::SyncActionNode(name, config) {}

BT::PortsList CalculateGoal::providedPorts() {
  return {BT::OutputPort<Pose2D>("goal")};
}

BT::NodeStatus CalculateGoal::tick() {
  // ����Ŀ��λ��
  Pose2D mygoal = {1.1, 2.3, 0.0};
  setOutput<Pose2D>("goal", mygoal);
  return BT::NodeStatus::SUCCESS;
}

// PrintTarget ʵ��
PrintTarget::PrintTarget(const std::string &name, const BT::NodeConfig &config)
    : BT::SyncActionNode(name, config) {}

BT::PortsList PrintTarget::providedPorts() {
  // ��ѡ���������ɶ�������
  const char *description = "��ӡĿ��λ�õ�����̨";
  return {BT::InputPort<Pose2D>("target", description)};
}

BT::NodeStatus PrintTarget::tick() {
  auto res = getInput<Pose2D>("target");
  if (!res) {
    throw BT::RuntimeError("error reading port [target]: " + res.error());
  }
  Pose2D target = res.value();
  printf("Ŀ��λ��: [%.1f, %.1f, %.1f]\n", target.x, target.y, target.yaw);
  return BT::NodeStatus::SUCCESS;
}
