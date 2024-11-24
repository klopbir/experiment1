#include "ExecutorImpl.hpp"
#include <iostream>
#include <memory>
#include <new>
#include "Command.hpp"
#include <unordered_map>
// to switch branches in git just write git checkout <branch_name>
namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : posehandler(pose) {}

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }
    Pose ExecutorImpl::Query(void) const noexcept
    {
        return posehandler.Query();
    }
    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        for (const auto cmd : commands)
        {
            std::unordered_map<char, std::function<void(PoseHandler & PoseHandler)>> cmderMap;
            cmderMap.emplace('M', MoveCommand());
            cmderMap.emplace('L', TurnLeftCommand());
            cmderMap.emplace('R', TurnRightCommand());
            cmderMap.emplace('F', FastCommand());
            // cmderMap.emplace('B', std::make_unique<ReverseCommand>);
            // std::unique_ptr<ICommand> cmder;
            const auto it = cmderMap.find(cmd); // find return pair<const Key, T> type if it finds the key, and unordered_map::end if it does not(end is element past the end of container)
            if (it != cmderMap.end())           // end returns iterator to end (iterator uses pair type as return value)
            {
                it->second(posehandler); // second indicates mapped value
            } // second actually points to the object itself
        }
    }
}