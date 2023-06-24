#include "behaviortree_cpp/bt_factory.h"

using namespace BT;

// clang-format off
static const char* xml_text = R"(

 <root BTCPP_format="4" >

     <BehaviorTree ID="MainTree">
        <Sequence name="root">
            <GameStart>
            <AddBullet>
            <Patrol>
            <Attack>
            <Retreat>
        </Sequence>
     </BehaviorTree>

 </root>
 )";
// clang-format on

class GameStart : public BT::SyncActionNode
{
  public:
  GameStart(const std::string& name, const BT::NodeConfig& config) :
        BT::SyncActionNode(name, config)
  {}

  BT::NodeStatus tick() override
  {
    std::cout << "Game Start!" << std::endl;
    return BT::NodeStatus::SUCCESS;
  }
};

class AddBullet : public BT::SyncActionNode
{
  public:
  AddBullet(const std::string& name, const BT::NodeConfig& config) :
        BT::SyncActionNode(name, config)
  {}

  BT::NodeStatus tick() override
  {
    // Add bullets
    std::cout << "Add Bullet" << std::endl;
    return BT::NodeStatus::SUCCESS;
  }
};

class Patrol : public BT::SyncActionNode
{
  public:
  Patrol(const std::string& name, const BT::NodeConfig& config) :
        BT::SyncActionNode(name, config)
  {}

  BT::NodeStatus tick() override
  {
    // Patrol
    std::cout << "Patroling!" << std::endl;
    return BT::NodeStatus::SUCCESS;
  }
};

class Retreat : public BT::SyncActionNode
{
  public:
  Retreat(const std::string& name, const BT::NodeConfig& config) :
        BT::SyncActionNode(name, config)
  {}

  BT::NodeStatus tick() override
  {
    // Retreat
    std::cout << "Retreating!" << std::endl;
    return BT::NodeStatus::SUCCESS;
  }
};

class Attack : public BT::SyncActionNode
{
  public:
  Attack(const std::string& name, const BT::NodeConfig& config) :
        BT::SyncActionNode(name, config)
  {}

  BT::NodeStatus tick() override
  {
    // Attack
    std::cout << "Attacking!" << std::endl;
    return BT::NodeStatus::SUCCESS;
  }
};

int main()
{

  BehaviorTreeFactory factory;

  factory.registerNodeType<GameStart>("GameStart");
  factory.registerNodeType<AddBullet>("AddBullet");
  factory.registerNodeType<Patrol>("Patrol");
  factory.registerNodeType<Retreat>("Retreat");
  factory.registerNodeType<Attack>("Attack");

  auto tree = factory.createTreeFromText(xml_text);

  tree.tickWhileRunning();

  return 0;
}
