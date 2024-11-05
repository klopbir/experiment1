#include "ExecutorImpl.hpp"
#include <iostream>
#include <memory>
#include <new>
#include "Command.hpp"
// to switch branches in git just write git checkout <branch_name>
namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : posehandler(pose) {}

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }
    Pose ExecutorImpl::Query(void) const noexcept
    {
        return posehandler.Query();
    }
    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        for (const auto cmd : commands)
        {
            std::unique_ptr<ICommand> cmder;
            if (cmd == 'M')
            {
                cmder = std::make_unique<MoveCommand>();
            }
            else if (cmd == 'L')
            {
                cmder = std::make_unique<TurnLeftCommand>();
            }
            else if (cmd == 'R')
            {
                cmder = std::make_unique<TurnRightCommand>();
            }
            else if (cmd == 'F')
            {
                cmder = std::make_unique<FastCommand>();
            }
            if (cmder)
            {
                cmder->DoOperate(posehandler);
            }
        }
    }
}