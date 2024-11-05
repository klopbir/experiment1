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

    public:
        void Move(void) noexcept;
        void TurnLeft(void) noexcept;
        void TurnRight(void) noexcept;
        void Fast(void) noexcept;
        bool isFast(void) const noexcept;
        // nested classes can be later declared as if functions, nested classes friends are not friends with encloser class
        // u can access encloses classes private members as nested class is considered another member

    private:
        Pose pose;
        bool fast{false};
    };
}