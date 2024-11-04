#include "ExecutorImpl.hpp"
#include <iostream>
#include <memory>
#include <new>
// to switch branches in git just write git checkout <branch_name>
namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose) {}

    void ExecutorImpl::Move() noexcept
    {
        if (pose.heading == 'E')
        {
            ++pose.x;
        }
        if (pose.heading == 'W')
        {
            --pose.x;
        }
        if (pose.heading == 'N')
        {
            ++pose.y;
        }
        if (pose.heading == 'S')
        {
            --pose.y;
        }
    }

    void ExecutorImpl::TurnLeft(void) noexcept
    {
        if (pose.heading == 'N')
        {
            pose.heading = 'W';
        }
        else if (pose.heading == 'S')
        {
            pose.heading = 'E';
        }
        else if (pose.heading == 'E')
        {
            pose.heading = 'N';
        }
        else if (pose.heading == 'W')
        {
            pose.heading = 'S';
        }
    }
    void ExecutorImpl::TurnRight(void) noexcept
    {
        if (pose.heading == 'N')
        {
            pose.heading = 'E';
        }
        else if (pose.heading == 'S')
        {
            pose.heading = 'W';
        }
        else if (pose.heading == 'E')
        {
            pose.heading = 'S';
        }
        else if (pose.heading == 'W')
        {
            pose.heading = 'N';
        }
    }
    Pose ExecutorImpl::Query(void) const noexcept
    {
        return pose;
    }

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        for (const auto cmd : commands)
        {
            if (cmd == 'M')
            {
                std::unique_ptr<MoveCommand> cmder = std::make_unique<MoveCommand>();
                cmder->DoOperate(*this);
            }
            if (cmd == 'L')
            {
                std::unique_ptr<TurnLeftCommand> cmder = std::make_unique<TurnLeftCommand>();
                cmder->DoOperate(*this);
            }
            if (cmd == 'R')
            {
                TurnRight();
            }
        }
    }
}