#include <behaviortree_cpp/bt_factory.h>
#include <iostream>
#include <tw2s.h>

int main(int argc, char const *argv[]) {
  std::string think_info = "The result is 43.";
  BT::BehaviorTreeFactory factory;
  factory.registerNodeType<BT::ThinkWhatToSay>("ThinkWhatToSay");
  factory.registerNodeType<BT::SaySomething>("SaySomething");

  if (argc > 1) {
    think_info = argv[1];
    std::cout << "Using command line argument: " << think_info << std::endl;
  } else {
    std::cout << "Using default value: " << think_info << std::endl;
  }

  try {
    auto tree = factory.createTreeFromFile("../../BT_tree/ThinkWhatToSay.xml");
    tree.rootBlackboard()->set("topic1", think_info); // ÉèÖÃºÚ°å²ÎÊı
    std::cout << "------ Behavior Tree Structure ------" << std::endl;
    BT::printTreeRecursively(tree.rootNode());
    std::cout << "-------------------------------------" << std::endl;
    tree.tickWhileRunning();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
