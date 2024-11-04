#pragma once

#include "Executor.hpp"
#include <string>

namespace adas
{
    class ExecutorImpl : public Executor
    {
    public:
        explicit ExecutorImpl(const Pose &pose) noexcept; // explicit is used to avoid uwnanted type cast of single data types
                                                          // to ExecutorImpl data types, conversion will still be available but has to be made
                                                          // explicit.
                                                          // constructors with single arguments act like conversion constructor
        ~ExecutorImpl() noexcept = default;
        ExecutorImpl(const ExecutorImpl &) = delete;
        ExecutorImpl &operator=(const ExecutorImpl &) = delete;

    public:
        Pose Query(void) const noexcept override;
        void Execute(const std::string &commands) noexcept override;

    private:
        void Move(void) noexcept;
        void TurnLeft(void) noexcept;
        void TurnRight(void) noexcept;
        void Fast(void) noexcept;
        bool isFast(void) const noexcept;
        // nested classes can be later declared as if functions, nested classes friends are not friends with encloser class
        // u can access encloses classes private members as nested class is considered another member
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
                if (executor.fast)
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
                if (executor.fast)
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
                if (executor.fast)
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

    private:
        Pose pose;
        bool fast{false};
    };
}