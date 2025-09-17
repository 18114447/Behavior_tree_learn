#include "behavior_tree_nodes.h"
#include <behaviortree_cpp/bt_factory.h>

/**
始化阶段：创建硬件对象并注册到工厂

加载行为树：从XML文件加载行为树定义

节点实例化：当遇到 <OpenCamera> 节点时，工厂调用注册的Lambda函数

执行阶段：行为树tick到该节点时，执行 camera.open()

状态返回：根据硬件操作结果返回成功、失败或运行中状态
 */

int main() {

  //创建行为树工厂
  BT::BehaviorTreeFactory factory;

  // checkbatter--->opencamera--->opengripper--->approachobject--->closegripper--->closecamera

  //注册自定义的行为树节点
  factory.registerNodeType<ApproachObject>("ApproachObject");

  //注册简单条件节点（使用正确的lambda签名）
  factory.registerSimpleCondition(
      "CheckBattery", [](BT::TreeNode &) { return CheckBattery(); });

  //创建相机、夹爪实例
  CameraInterface camera;
  GripperInterface gripper;

  //注册相机和夹爪的打开、关闭动作
  factory.registerSimpleAction(
      "OpenCamera", [&camera](BT::TreeNode &) { return camera.open(); });
  factory.registerSimpleAction(
      "OpenGripper", [&gripper](BT::TreeNode &) { return gripper.open(); });
  factory.registerSimpleAction(
      "CloseCamera", [&camera](BT::TreeNode &) { return camera.close(); });
  factory.registerSimpleAction(
      "CloseGripper", [&gripper](BT::TreeNode &) { return gripper.close(); });

  //从xml文件加载行为树
  try {
    auto tree = factory.createTreeFromFile("../BT_tree/my_tree.xml");
    //打印树结构
    std::cout << "------ Behavior Tree Structure ------" << std::endl;
    BT::printTreeRecursively(tree.rootNode());
    std::cout << "-------------------------------------" << std::endl;

    //执行行为树
    tree.tickWhileRunning();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}