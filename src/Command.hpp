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
        // {
        //     if (posehandler.isFast())
        //     {
        //         posehandler.Move();
        //     }
        //     posehandler.Move();
        // }
        const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        {
            if (poseHandler.isFast())
            {
                poseHandler.Move();
            }
            poseHandler.Move();
        };
    };

    class TurnLeftCommand final
    {
    public:
        const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        {
            if (poseHandler.isFast())
            {
                poseHandler.Move();
            }
            poseHandler.TurnLeft();
        };
    };

    class TurnRightCommand final
    {
    public:
        const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        {
            if (poseHandler.isFast())
            {
                poseHandler.Move();
            }
            poseHandler.TurnRight();
        };
    };

    class FastCommand final
    {
    public:
        const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        {
            poseHandler.Fast();
        };
    };
}