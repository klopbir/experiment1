#include <ExecutorImpl.hpp>
#include "PoseHandler.hpp"
#include <iostream>
#include <memory>
#include <tuple>
#include <functional>
namespace adas
{
    // class ICommand
    // {
    // public:
    //     virtual ~ICommand() = default;
    //     virtual void DoOperate(PoseHandler &posehandler) const noexcept = 0;
    // };

    class MoveCommand final
    {
    public: // enclosed class does not have access to private members of nested class
        // void DoOperate(PoseHandler &posehandler) const noexcept override
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.isFast())
            {
                if (poseHandler.IsReverse())
                {
                    poseHandler.Backward();
                }
                else
                    poseHandler.Forward();
            }
            if (poseHandler.IsReverse())
            {
                poseHandler.Backward();
            }
            else
            {
                poseHandler.Move();
            }
        }
    };

    class TurnLeftCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.isFast())
            {
                poseHandler.Move();
            }
            poseHandler.TurnLeft();
        }
    };

    class TurnRightCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.isFast())
            {
                poseHandler.Move();
            }
            poseHandler.TurnRight();
        }
    };

    class FastCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Fast();
        }
    };
    class ReverseCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Reverse();
        }
    };
}