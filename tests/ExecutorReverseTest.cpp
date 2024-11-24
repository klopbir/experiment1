#include <Executor.hpp> // since this file in the include folder it can be included without specifying the path
#include <PoseEq.hpp>
#include <gtest/gtest.h>
#include <memory>

namespace adas
{
    TEST(ExecutorReverseFastTest, should_return_x_minus_2_given_status_is_fast_and_reverse_command_is_M_and_facing_is_E)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        executor->Execute("FBM");
        const Pose target({-2, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    // FBL
    TEST(ExecutorReverseFastTest, should_return_S_and_x_minus_1_given_status_is_fast_and_reverse_command_is_L_and_facing_is_E)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        executor->Execute("FBL");
        const Pose target({-1, 0, 'S'});
        ASSERT_EQ(target, executor->Query());
    }
    // FBR
    TEST(ExecutorReverseFastTest, should_return_N_and_x_minus_1_given_status_is_fast_and_reverse_command_is_R_and_facing_is_E)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        executor->Execute("FBR");
        const Pose target({-1, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }

}