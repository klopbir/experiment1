#pragma once
#include <string>

namespace adas
{
    struct Pose
    {
        int x;
        int y;
        char heading;
        Pose(int x, int y, char heading) : x(x), y(y), heading(heading) {}
    };

    class Executor
    {
    public:
        static Executor *NewExecutor(const Pose &pose = {0, 0, 'N'}) noexcept;

    public:
        Executor(void) = default;
        virtual ~Executor(void) = default; // so if there is base class pointer that points to derived class, it will actually call derived classes
                                           // destructor
        Executor(const Executor &) = delete;
        Executor &operator=(const Executor &) = delete;

    public:
        virtual Pose Query(void) const noexcept = 0;
        virtual void Execute(const std::string &commands) noexcept = 0;
    };

}