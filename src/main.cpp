#include "behavior_tree_nodes.h"
#include <behaviortree_cpp/bt_factory.h>

/**
ʼ���׶Σ�����Ӳ������ע�ᵽ����

������Ϊ������XML�ļ�������Ϊ������

�ڵ�ʵ������������ <OpenCamera> �ڵ�ʱ����������ע���Lambda����

ִ�н׶Σ���Ϊ��tick���ýڵ�ʱ��ִ�� camera.open()

״̬���أ�����Ӳ������������سɹ���ʧ�ܻ�������״̬
 */

int main() {

  //������Ϊ������
  BT::BehaviorTreeFactory factory;

  // checkbatter--->opencamera--->opengripper--->approachobject--->closegripper--->closecamera

  //ע���Զ������Ϊ���ڵ�
  factory.registerNodeType<ApproachObject>("ApproachObject");

  //ע��������ڵ㣨ʹ����ȷ��lambdaǩ����
  factory.registerSimpleCondition(
      "CheckBattery", [](BT::TreeNode &) { return CheckBattery(); });

  //�����������צʵ��
  CameraInterface camera;
  GripperInterface gripper;

  //ע������ͼ�צ�Ĵ򿪡��رն���
  factory.registerSimpleAction(
      "OpenCamera", [&camera](BT::TreeNode &) { return camera.open(); });
  factory.registerSimpleAction(
      "OpenGripper", [&gripper](BT::TreeNode &) { return gripper.open(); });
  factory.registerSimpleAction(
      "CloseCamera", [&camera](BT::TreeNode &) { return camera.close(); });
  factory.registerSimpleAction(
      "CloseGripper", [&gripper](BT::TreeNode &) { return gripper.close(); });

  //��xml�ļ�������Ϊ��
  try {
    auto tree = factory.createTreeFromFile("../BT_tree/my_tree.xml");
    //��ӡ���ṹ
    std::cout << "------ Behavior Tree Structure ------" << std::endl;
    BT::printTreeRecursively(tree.rootNode());
    std::cout << "-------------------------------------" << std::endl;

    //ִ����Ϊ��
    tree.tickWhileRunning();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}