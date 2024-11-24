#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::PoseHandler(const Pose &pose) noexcept : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading))
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
        point += facing->Move();
    }

    void PoseHandler::TurnLeft(void) noexcept
    {
        facing = &(facing->LeftOne());
    }
    void PoseHandler::TurnRight(void) noexcept
    {
        facing = &(facing->RightOne());
    }
    Pose PoseHandler::Query(void) const noexcept
    {
        return Pose(point.GetX(), point.GetY(), facing->GetHeading());
    }
}