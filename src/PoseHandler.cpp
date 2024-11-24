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
    void PoseHandler::Reverse(void) noexcept
    {
        reverse = !reverse;
    }
    bool PoseHandler::isFast(void) const noexcept
    {
        return fast;
    }
    bool PoseHandler::IsReverse(void) const noexcept
    {
        return reverse;
    }
    void PoseHandler::Forward(void) noexcept
    {
        point += facing->Move();
    }
    void PoseHandler::Backward(void) noexcept
    {
        point -= facing->Move();
    }
    void PoseHandler::Move() noexcept
    {
        if (IsReverse())
            point -= facing->Move();
        else
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