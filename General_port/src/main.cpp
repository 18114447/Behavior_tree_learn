#include "gp.h"

int main() {
  BT::BehaviorTreeFactory factory;

  // ע���Զ���ڵ�
  factory.registerNodeType<BTNodes::CalculateGoal>("CalculateGoal");
  factory.registerNodeType<BTNodes::PrintTarget>("PrintTarget");

  try {
    // ��XML�ļ� ������Ϊ��
    const std::string tree_xml_path = "../../BT_tree/gp.xml";
    auto tree = factory.createTreeFromFile(tree_xml_path);

    // ��ӡ���ṹ
    std::cout << "------ Behavior Tree Structure ------" << std::endl;
    BT::printTreeRecursively(tree.rootNode());
    std::cout << "------------------------------------" << std::endl;

    // ִ����Ϊ��
    tree.tickWhileRunning();

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}