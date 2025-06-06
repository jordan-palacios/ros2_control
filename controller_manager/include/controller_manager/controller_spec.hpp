// Copyright 2020 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*
 * Author: Wim Meeussen
 */

#ifndef CONTROLLER_MANAGER__CONTROLLER_SPEC_HPP_
#define CONTROLLER_MANAGER__CONTROLLER_SPEC_HPP_

#include <memory>
#include <string>
#include <vector>
#include "controller_interface/controller_interface_base.hpp"
#include "hardware_interface/controller_info.hpp"
#include "libstatistics_collector/moving_average_statistics/moving_average.hpp"

namespace controller_manager
{

using MovingAverageStatistics =
  libstatistics_collector::moving_average_statistics::MovingAverageStatistics;
/// Controller Specification
/**
 * This struct contains both a pointer to a given controller, \ref c, as well
 * as information about the controller, \ref info.
 *
 */
struct ControllerSpec
{
  ControllerSpec()
  {
    last_update_cycle_time = std::make_shared<rclcpp::Time>(0, 0, RCL_CLOCK_UNINITIALIZED);
    execution_time_statistics = std::make_shared<MovingAverageStatistics>();
    periodicity_statistics = std::make_shared<MovingAverageStatistics>();
  }

  hardware_interface::ControllerInfo info;
  controller_interface::ControllerInterfaceBaseSharedPtr c;
  std::shared_ptr<rclcpp::Time> last_update_cycle_time;
  std::shared_ptr<MovingAverageStatistics> execution_time_statistics;
  std::shared_ptr<MovingAverageStatistics> periodicity_statistics;
};

struct ControllerChainSpec
{
  std::vector<std::string> following_controllers;
  std::vector<std::string> preceding_controllers;
};
}  // namespace controller_manager
#endif  // CONTROLLER_MANAGER__CONTROLLER_SPEC_HPP_
