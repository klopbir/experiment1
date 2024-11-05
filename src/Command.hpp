#include <ExecutorImpl.hpp>
#include <iostream>
#include <memory>
#include <tuple>

namespace adas
{
    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void DoOperate(ExecutorImpl &) const noexcept = 0;
    };

    class MoveCommand final : public ICommand
    {
    public: // enclosed class does not have access to private members of nested class
        void DoOperate(ExecutorImpl &executor) const noexcept override
        {
            if (executor.isFast())
            {
                executor.Move();
            }
            executor.Move();
        }
    };

    class TurnLeftCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl &executor) const noexcept override
        {
            if (executor.isFast())
            {
                executor.Move();
            }
            executor.TurnLeft();
        }
    };

    class TurnRightCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl &executor) const noexcept override
        {
            if (executor.isFast())
            {
                executor.Move();
            }
            executor.TurnRight();
        }
    };

    class FastCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl &executor) const noexcept override
        {
            executor.Fast();
        }
    };
}