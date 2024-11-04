#include "ExecutorImpl.hpp"
#include <iostream>
#include <memory>
#include <new>
// to switch branches in git just write git checkout <branch_name>
namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose) {}
    void ExecutorImpl::Fast(void) noexcept
    {
        fast = !fast;
    }
    bool ExecutorImpl::isFast(void) const noexcept
    {
        return fast;
    }
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
                cmder->DoOperate(*this);
            }
        }
    }
}