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
        Pose pose;
        void Move(void) noexcept;
        void TurnLeft(void) noexcept;
        // void Move(void) noexcept;
    };
}