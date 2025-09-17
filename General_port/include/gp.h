#ifndef GP_H
#define GP_H

#include <behaviortree_cpp/bt_factory.h>
#include <iostream>
#include <sstream>

struct Pose2D {
  double x;
  double y;
  double yaw;
};

// ��BT�����ռ����ػ��ַ���ת��
namespace BT {
template <> inline Pose2D convertFromString(BT::StringView str) {
  // ʹ���ַ�������� splitString
  std::string input(str.data(), str.size());
  std::istringstream ss(input);
  Pose2D output;
  char delimiter;

  // ������ʽ: "x;y;yaw"
  if (!(ss >> output.x >> delimiter >> output.y >> delimiter >> output.yaw) ||
      delimiter != ';') {
    throw BT::RuntimeError("invalid input for Pose2D: " + input);
  }

  return output;
}
} // end namespace BT

namespace BTNodes {
// д��˿� "goal"
class CalculateGoal : public BT::SyncActionNode {
public:
  CalculateGoal(const std::string &name, const BT::NodeConfig &config);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;
};

// ��ȡ�˿�
class PrintTarget : public BT::SyncActionNode {
public:
  PrintTarget(const std::string &name, const BT::NodeConfig &config);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;
};

} // namespace BTNodes

#endif // GP_H