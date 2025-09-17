#include "gp.h"

int main() {
  BT::BehaviorTreeFactory factory;

  // 注册自定义节点
  factory.registerNodeType<BTNodes::CalculateGoal>("CalculateGoal");
  factory.registerNodeType<BTNodes::PrintTarget>("PrintTarget");

  try {
    // 从XML文件 创建行为树
    const std::string tree_xml_path = "../../BT_tree/gp.xml";
    auto tree = factory.createTreeFromFile(tree_xml_path);

    // 打印树结构
    std::cout << "------ Behavior Tree Structure ------" << std::endl;
    BT::printTreeRecursively(tree.rootNode());
    std::cout << "------------------------------------" << std::endl;

    // 执行行为树
    tree.tickWhileRunning();

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}