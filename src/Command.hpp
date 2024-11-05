#include <ExecutorImpl.hpp>
#include "PoseHandler.hpp"
#include <iostream>
#include <memory>
#include <tuple>

namespace adas
{
    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void DoOperate(PoseHandler &posehandler) const noexcept = 0;
    };

    class MoveCommand final : public ICommand
    {
    public: // enclosed class does not have access to private members of nested class
        void DoOperate(PoseHandler &posehandler) const noexcept override
        {
            if (posehandler.isFast())
            {
                posehandler.Move();
            }
            posehandler.Move();
        }
    };

    class TurnLeftCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &posehandler) const noexcept override
        {
            if (posehandler.isFast())
            {
                posehandler.Move();
            }
            posehandler.TurnLeft();
        }
    };

    class TurnRightCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &posehandler) const noexcept override
        {
            if (posehandler.isFast())
            {
                posehandler.Move();
            }
            posehandler.TurnRight();
        }
    };

    class FastCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &posehandler) const noexcept override
        {
            posehandler.Fast();
        }
    };
}