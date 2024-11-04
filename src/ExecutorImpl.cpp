#include "ExecutorImpl.hpp"
#include <new>
// to switch branches in git just write git checkout <branch_name>
namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose) {}

    void ExecutorImpl::Move()
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

    void ExecutorImpl::TurnLeft(void)
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
                Move();
            }
            if (cmd == 'L')
            {
                TurnLeft();
            }
            if (cmd == 'R')
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
        }
    }
}