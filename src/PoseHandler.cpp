#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::PoseHandler(const Pose &pose) noexcept : pose(pose)
    {
    }
    void PoseHandler::Fast(void) noexcept
    {
        fast = !fast;
    }
    bool PoseHandler::isFast(void) const noexcept
    {
        return fast;
    }
    void PoseHandler::Move() noexcept
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

    void PoseHandler::TurnLeft(void) noexcept
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
    void PoseHandler::TurnRight(void) noexcept
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
    Pose PoseHandler::Query(void) const noexcept
    {
        return pose;
    }
}