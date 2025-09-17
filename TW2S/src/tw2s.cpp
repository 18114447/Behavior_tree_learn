#include "tw2s.h"

using namespace BT;

SaySomething::SaySomething(const std::string &name, const NodeConfig &config)
    : SyncActionNode(name, config){};

PortsList SaySomething::providedPorts() {
  return {InputPort<std::string>("message")};
}

NodeStatus SaySomething::tick() {
  BT::Expected<std::string> msg = getInput<std::string>("message");
  if (!msg) {
    throw BT::RuntimeError("missing required input [message]: ", msg.error());
  }
  std::cout << "SaySomething: " << msg.value() << std::endl;
  return NodeStatus::SUCCESS;
}

// ThinkWhatToSay写入到输出端口
ThinkWhatToSay::ThinkWhatToSay(const std::string &name,
                               const NodeConfig &config)
    : SyncActionNode(name, config){};

PortsList ThinkWhatToSay::providedPorts() {
  return {InputPort<std::string>("info"), OutputPort<std::string>("text")};
}

NodeStatus ThinkWhatToSay::tick() {
  auto msg = getInput<std::string>("info");
  if (!msg) {
    throw BT::RuntimeError("missing required input [info]: ", msg.error());
  }
  _info = msg.value();
  setOutput("text", _info);
  std::cout << "ThinkWhatToSay: " << _info << std::endl;
  return NodeStatus::SUCCESS;
}